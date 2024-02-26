/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_SERIALIZE_CLIENT_OUT_H
#define CONCLAVE_SERIALIZE_CLIENT_OUT_H

#include <conclave-room-serialize/commands.h>
#include <conclave-room-serialize/types.h>
#include <stdint.h>
#include <stdlib.h>

struct FldOutStream;

int clvRoomSerializeClientOutPing(struct FldOutStream* stream, ClvSerializeUserSessionId userSessionId,
    ClvSerializeKnowledge knowledge, ClvSerializeTerm term, ClvSerializeConnectedToOwnerState connectedToOwner);

#endif
