#include "utest.h"
#include <conclave-room-serialize/client_in.h>
#include <flood/in_stream.h>

UTEST(RoomSerialize, verify)
{
    const uint8_t EXPECTED_LEADER_INDEX = 0xff;

    uint8_t octets[] = {
        0x00, // Term
        0x4A, // Term (lower)
        0x00, // Number of client infos that follows
        EXPECTED_LEADER_INDEX, // Leader index
    };

    struct FldInStream inStream;
    fldInStreamInit(&inStream, octets, sizeof(octets));

    ClvSerializePingResponse pingResponse;

    int error = clvRoomSerializeClientInPingResponse(&inStream, &pingResponse);
    ASSERT_EQ(0, error);

    ASSERT_EQ(0x4A, pingResponse.term);
    ASSERT_EQ(0, pingResponse.roomInfo.memberCount);
    ASSERT_EQ(EXPECTED_LEADER_INDEX, pingResponse.roomInfo.indexOfOwner);
}
