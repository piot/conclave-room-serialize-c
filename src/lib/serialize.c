/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <clog/clog.h>
#include <conclave-room-serialize/serialize.h>
#include <flood/in_stream.h>
#include <flood/out_stream.h>

void clvRoomSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix)
{
    (void)prefix;
    // CLOG_VERBOSE("%s: cmd: %s", prefix, clvSerializeCmdToString(cmd));
    fldOutStreamWriteUInt8(outStream, cmd);
}

void clvSerializeWriteUserSessionId(
    struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId)
{
    if (userSessionId == 0) {
        CLOG_ERROR("userSessionId zero is reserved")
    }
    fldOutStreamWriteMarker(stream, 0x86);
    fldOutStreamWriteUInt64(stream, userSessionId);
}

int clvSerializeReadUserSessionId(
    struct FldInStream* stream, ClvSerializeUserSessionId* userSessionId)
{
    fldInStreamCheckMarker(stream, 0x86);
    return fldInStreamReadUInt64(stream, userSessionId);
}

void clvSerializeWriteUserId(struct FldOutStream* stream, ClvSerializeUserId userId)
{
    fldOutStreamWriteUInt64(stream, userId);
}

int clvSerializeReadUserId(struct FldInStream* stream, ClvSerializeUserId* userId)
{
    return fldInStreamReadUInt64(stream, userId);
}

void clvSerializeWriteTerm(struct FldOutStream* stream, ClvSerializeTerm term)
{
    fldOutStreamWriteMarker(stream, 0x89);
    fldOutStreamWriteUInt16(stream, term);
}

int clvSerializeReadTerm(struct FldInStream* stream, ClvSerializeTerm* term)
{
    fldInStreamCheckMarker(stream, 0x89);
    return fldInStreamReadUInt16(stream, term);
}
