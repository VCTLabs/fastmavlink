//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_ARRAY_TEST_5_H
#define FASTMAVLINK_MSG_ARRAY_TEST_5_H


//----------------------------------------
//-- Message ARRAY_TEST_5
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_array_test_5_t {
    char c1[5];
    char c2[5];
}) fmav_array_test_5_t;


#define FASTMAVLINK_MSG_ID_ARRAY_TEST_5  17155

#define FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX  10
#define FASTMAVLINK_MSG_ARRAY_TEST_5_CRCEXTRA  27

#define FASTMAVLINK_MSG_ARRAY_TEST_5_FLAGS  0
#define FASTMAVLINK_MSG_ARRAY_TEST_5_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_ARRAY_TEST_5_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_ARRAY_TEST_5_FRAME_LEN_MAX  35

#define FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C1_NUM  5 // number of elements in array
#define FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C1_LEN  5 // length of array = number of bytes
#define FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C2_NUM  5 // number of elements in array
#define FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C2_LEN  5 // length of array = number of bytes

#define FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C1_OFS  0
#define FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C2_OFS  5


//----------------------------------------
//-- Message ARRAY_TEST_5 packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_array_test_5_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const char* c1, const char* c2,
    fmav_status_t* _status)
{
    fmav_array_test_5_t* _payload = (fmav_array_test_5_t*)msg->payload;


    memcpy(&(_payload->c1), c1, sizeof(char)*5);
    memcpy(&(_payload->c2), c2, sizeof(char)*5);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_ARRAY_TEST_5;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_ARRAY_TEST_5_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_array_test_5_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_array_test_5_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_array_test_5_pack(
        msg, sysid, compid,
        _payload->c1, _payload->c2,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_array_test_5_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const char* c1, const char* c2,
    fmav_status_t* _status)
{
    fmav_array_test_5_t* _payload = (fmav_array_test_5_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);


    memcpy(&(_payload->c1), c1, sizeof(char)*5);
    memcpy(&(_payload->c2), c2, sizeof(char)*5);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_ARRAY_TEST_5;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_ARRAY_TEST_5 >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_ARRAY_TEST_5 >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ARRAY_TEST_5_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_array_test_5_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_array_test_5_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_array_test_5_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->c1, _payload->c2,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_array_test_5_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const char* c1, const char* c2,
    fmav_status_t* _status)
{
    fmav_array_test_5_t _payload;


    memcpy(&(_payload.c1), c1, sizeof(char)*5);
    memcpy(&(_payload.c2), c2, sizeof(char)*5);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_ARRAY_TEST_5,
        FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ARRAY_TEST_5_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_array_test_5_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_array_test_5_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_ARRAY_TEST_5,
        FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ARRAY_TEST_5_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message ARRAY_TEST_5 unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_array_test_5_decode(fmav_array_test_5_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_ARRAY_TEST_5_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}





FASTMAVLINK_FUNCTION_DECORATOR char* fmav_msg_array_test_5_get_field_c1_ptr(const fmav_message_t* msg)
{
    return (char*)&(msg->payload[0]);
}


FASTMAVLINK_FUNCTION_DECORATOR char fmav_msg_array_test_5_get_field_c1(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C1_NUM) return 0;
    return ((char*)&(msg->payload[0]))[index];
}


FASTMAVLINK_FUNCTION_DECORATOR char* fmav_msg_array_test_5_get_field_c2_ptr(const fmav_message_t* msg)
{
    return (char*)&(msg->payload[5]);
}


FASTMAVLINK_FUNCTION_DECORATOR char fmav_msg_array_test_5_get_field_c2(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_ARRAY_TEST_5_FIELD_C2_NUM) return 0;
    return ((char*)&(msg->payload[5]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_ARRAY_TEST_5  17155

#define mavlink_array_test_5_t  fmav_array_test_5_t

#define MAVLINK_MSG_ID_ARRAY_TEST_5_LEN  10
#define MAVLINK_MSG_ID_ARRAY_TEST_5_MIN_LEN  10
#define MAVLINK_MSG_ID_17155_LEN  10
#define MAVLINK_MSG_ID_17155_MIN_LEN  10

#define MAVLINK_MSG_ID_ARRAY_TEST_5_CRC  27
#define MAVLINK_MSG_ID_17155_CRC  27

#define MAVLINK_MSG_ARRAY_TEST_5_FIELD_C1_LEN 5
#define MAVLINK_MSG_ARRAY_TEST_5_FIELD_C2_LEN 5


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_array_test_5_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    const char* c1, const char* c2)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_array_test_5_pack(
        msg, sysid, compid,
        c1, c2,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_array_test_5_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    const char* c1, const char* c2)
{
    return fmav_msg_array_test_5_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        c1, c2,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_array_test_5_decode(const mavlink_message_t* msg, mavlink_array_test_5_t* payload)
{
    fmav_msg_array_test_5_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_ARRAY_TEST_5_H
