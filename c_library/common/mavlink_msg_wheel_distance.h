//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_WHEEL_DISTANCE_H
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_H


//----------------------------------------
//-- Message WHEEL_DISTANCE
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_wheel_distance_t {
    uint64_t time_usec;
    double distance[16];
    uint8_t count;
}) fmav_wheel_distance_t;


#define FASTMAVLINK_MSG_ID_WHEEL_DISTANCE  9000

#define FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX  137
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_CRCEXTRA  113

#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FLAGS  0
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FRAME_LEN_MAX  162

#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FIELD_DISTANCE_NUM  16 // number of elements in array
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FIELD_DISTANCE_LEN  128 // length of array = number of bytes

#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FIELD_TIME_USEC_OFS  0
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FIELD_DISTANCE_OFS  8
#define FASTMAVLINK_MSG_WHEEL_DISTANCE_FIELD_COUNT_OFS  136


//----------------------------------------
//-- Message WHEEL_DISTANCE packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_wheel_distance_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint8_t count, const double* distance,
    fmav_status_t* _status)
{
    fmav_wheel_distance_t* _payload = (fmav_wheel_distance_t*)_msg->payload;

    _payload->time_usec = time_usec;
    _payload->count = count;
    memcpy(&(_payload->distance), distance, sizeof(double)*16);

    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_WHEEL_DISTANCE;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_WHEEL_DISTANCE_CRCEXTRA;

    return fmav_finalize_msg(
        _msg,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_wheel_distance_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_wheel_distance_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_wheel_distance_pack(
        _msg, sysid, compid,
        _payload->time_usec, _payload->count, _payload->distance,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_wheel_distance_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint8_t count, const double* distance,
    fmav_status_t* _status)
{
    fmav_wheel_distance_t* _payload = (fmav_wheel_distance_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_usec = time_usec;
    _payload->count = count;
    memcpy(&(_payload->distance), distance, sizeof(double)*16);

    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_WHEEL_DISTANCE;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_WHEEL_DISTANCE >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_WHEEL_DISTANCE >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_wheel_distance_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_wheel_distance_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_wheel_distance_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->time_usec, _payload->count, _payload->distance,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_wheel_distance_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint8_t count, const double* distance,
    fmav_status_t* _status)
{
    fmav_wheel_distance_t _payload;

    _payload.time_usec = time_usec;
    _payload.count = count;
    memcpy(&(_payload.distance), distance, sizeof(double)*16);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_WHEEL_DISTANCE,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_wheel_distance_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_wheel_distance_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_WHEEL_DISTANCE,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_WHEEL_DISTANCE_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message WHEEL_DISTANCE unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_wheel_distance_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_wheel_distance_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_wheel_distance_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_wheel_distance_decode(fmav_wheel_distance_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_WHEEL_DISTANCE_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_wheel_distance_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint64_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_wheel_distance_get_field_count(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[136]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR double* fmav_msg_wheel_distance_get_field_distance_ptr(const fmav_message_t* msg)
{
    return (double*)&(msg->payload[8]);
}


FASTMAVLINK_FUNCTION_DECORATOR double fmav_msg_wheel_distance_get_field_distance(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_WHEEL_DISTANCE_FIELD_DISTANCE_NUM) return 0;
    return ((double*)&(msg->payload[8]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_WHEEL_DISTANCE  9000

#define mavlink_wheel_distance_t  fmav_wheel_distance_t

#define MAVLINK_MSG_ID_WHEEL_DISTANCE_LEN  137
#define MAVLINK_MSG_ID_WHEEL_DISTANCE_MIN_LEN  137
#define MAVLINK_MSG_ID_9000_LEN  137
#define MAVLINK_MSG_ID_9000_MIN_LEN  137

#define MAVLINK_MSG_ID_WHEEL_DISTANCE_CRC  113
#define MAVLINK_MSG_ID_9000_CRC  113

#define MAVLINK_MSG_WHEEL_DISTANCE_FIELD_DISTANCE_LEN 16


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_wheel_distance_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint64_t time_usec, uint8_t count, const double* distance)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_wheel_distance_pack(
        _msg, sysid, compid,
        time_usec, count, distance,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_wheel_distance_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, uint8_t count, const double* distance)
{
    return fmav_msg_wheel_distance_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        time_usec, count, distance,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_wheel_distance_decode(const mavlink_message_t* msg, mavlink_wheel_distance_t* payload)
{
    fmav_msg_wheel_distance_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_WHEEL_DISTANCE_H
