/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/conclave-room-serialize-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#ifndef CONCLAVE_ROOM_SERIALIZE_TYPES_H
#define CONCLAVE_ROOM_SERIALIZE_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef uint64_t ClvSerializeUserId;
typedef uint64_t ClvSerializeUserSessionId;
typedef uint64_t ClvSerializeTerm;
typedef uint64_t ClvSerializeKnowledge;

typedef enum ClvSerializeConnectedToOwnerState {
    ClvSerializeConnectedToOwnerStateUndefined,
    ClvSerializeConnectedToOwnerStateConnected,
    ClvSerializeConnectedToOwnerStateDisconnected
} ClvSerializeConnectedToOwnerState;

struct BlobStreamOutEntry;

#define CLV_MAX_MEMBERS_IN_ROOM (16)

typedef struct ClvSerializeRoomWithMembersInfo {
    ClvSerializeUserId members[CLV_MAX_MEMBERS_IN_ROOM];
    size_t memberCount;
    uint8_t indexOfOwner;
} ClvSerializeRoomWithMembersInfo;

typedef struct ClvSerializePingResponse {
    ClvSerializeTerm term;
    ClvSerializeRoomWithMembersInfo roomInfo;
} ClvSerializePingResponse;

typedef struct ClvSerializePing {
    ClvSerializeKnowledge knowledge;
    ClvSerializeTerm term;
    ClvSerializeConnectedToOwnerState connectedToOwner;
} ClvSerializePing;

#endif
