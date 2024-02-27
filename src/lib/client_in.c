/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <conclave-room-serialize/client_in.h>
#include <conclave-room-serialize/serialize.h>
#include <flood/in_stream.h>
#include <imprint/allocator.h>
#include <tiny-libc/tiny_libc.h>

int clvRoomSerializeClientInPingResponse(FldInStream* stream, ClvSerializePingResponse* pingResponse)
{
    clvSerializeReadTerm(stream, &pingResponse->term);

    uint8_t memberCount;
    fldInStreamReadUInt8(stream, &memberCount);
    pingResponse->roomInfo.memberCount = memberCount;

    for (size_t i = 0; i < memberCount; ++i) {
        ClvSerializeUserId* userId = &pingResponse->roomInfo.members[i];
        uint8_t connectionIndex;
        fldInStreamReadUInt8(stream, &connectionIndex);
        clvSerializeReadUserId(stream, userId);
    }

    return fldInStreamReadUInt8(stream, &pingResponse->roomInfo.indexOfOwner);
}
