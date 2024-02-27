/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_ROOM_SERIALIZE_SERIALIZE_H
#define CONCLAVE_ROOM_SERIALIZE_SERIALIZE_H

#include <stdint.h>
#include <stdlib.h>

#include <conclave-room-serialize/types.h>

struct FldOutStream;
struct FldInStream;

void clvRoomSerializeWriteCommand(struct FldOutStream* outStream, uint8_t cmd, const char* prefix);

void clvSerializeWriteTerm(struct FldOutStream* stream, ClvSerializeTerm term);
int clvSerializeReadTerm(struct FldInStream* stream, ClvSerializeTerm* term);

void clvSerializeWriteUserSessionId(
    struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId);
int clvSerializeReadUserSessionId(
    struct FldInStream* stream, ClvSerializeUserSessionId* userSessionId);

void clvSerializeWriteUserId(
    struct FldOutStream* stream, ClvSerializeUserId userId);
int clvSerializeReadUserId(
    struct FldInStream* stream, ClvSerializeUserId* userId);


#endif
