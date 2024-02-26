/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <conclave-room-serialize/client_out.h>
#include <conclave-room-serialize/serialize.h>
#include <flood/out_stream.h>
#include <tiny-libc/tiny_libc.h>

#define COMMAND_DEBUG "ClvClientOut"

int clvRoomSerializeClientOutPing(struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
    ClvSerializeKnowledge knowledge, ClvSerializeTerm term, ClvSerializeConnectedToOwnerState connectedToOwner)
{
    clvRoomSerializeWriteCommand(stream, clvRoomSerializeCmdPing, COMMAND_DEBUG);
    clvSerializeWriteUserSessionId(stream, userSessionId);
    clvSerializeWriteTerm(stream, term);
    fldOutStreamWriteUInt8(stream, (uint8_t)connectedToOwner);
    return fldOutStreamWriteUInt64(stream, knowledge);
}
