/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <conclave-room-serialize/client_in.h>
#include <conclave-room-serialize/serialize.h>
#include <flood/in_stream.h>
#include <imprint/allocator.h>
#include <tiny-libc/tiny_libc.h>

int clvRoomSerializeClientInPingResponse(FldInStream* stream, ClvSerializePingResponseOptions* options)
{
    clvSerializeReadTerm(stream, &options->term);

    uint8_t memberCount;
    fldInStreamReadUInt8(stream, &memberCount);
    options->roomInfo.memberCount = memberCount;

    for (size_t i = 0; i < memberCount; ++i) {
        ClvSerializeUserId* userId = &options->roomInfo.members[i];

        clvSerializeReadUserId(stream, userId);
    }

    return fldInStreamReadUInt8(stream, &options->roomInfo.indexOfOwner);
}
