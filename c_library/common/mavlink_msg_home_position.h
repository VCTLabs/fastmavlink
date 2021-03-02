//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_HOME_POSITION_H
#define FASTMAVLINK_MSG_HOME_POSITION_H


//----------------------------------------
//-- Message HOME_POSITION
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_home_position_t {
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;
    float x;
    float y;
    float z;
    float q[4];
    float approach_x;
    float approach_y;
    float approach_z;
    uint64_t time_usec;
}) fmav_home_position_t;


#define FASTMAVLINK_MSG_ID_HOME_POSITION  242

#define FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX  60
#define FASTMAVLINK_MSG_HOME_POSITION_CRCEXTRA  104

#define FASTMAVLINK_MSG_HOME_POSITION_FLAGS  0
#define FASTMAVLINK_MSG_HOME_POSITION_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_HOME_POSITION_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_HOME_POSITION_FRAME_LEN_MAX  85

#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_Q_NUM  4 // number of elements in array
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_Q_LEN  16 // length of array = number of bytes

#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_LATITUDE_OFS  0
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_LONGITUDE_OFS  4
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_ALTITUDE_OFS  8
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_X_OFS  12
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_Y_OFS  16
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_Z_OFS  20
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_Q_OFS  24
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_APPROACH_X_OFS  40
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_APPROACH_Y_OFS  44
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_APPROACH_Z_OFS  48
#define FASTMAVLINK_MSG_HOME_POSITION_FIELD_TIME_USEC_OFS  52


//----------------------------------------
//-- Message HOME_POSITION packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_home_position_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, float x, float y, float z, const float* q, float approach_x, float approach_y, float approach_z, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_home_position_t* _payload = (fmav_home_position_t*)msg->payload;

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->x = x;
    _payload->y = y;
    _payload->z = z;
    _payload->approach_x = approach_x;
    _payload->approach_y = approach_y;
    _payload->approach_z = approach_z;
    _payload->time_usec = time_usec;
    memcpy(&(_payload->q), q, sizeof(float)*4);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_HOME_POSITION;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_HOME_POSITION_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_home_position_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_home_position_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_home_position_pack(
        msg, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->x, _payload->y, _payload->z, _payload->q, _payload->approach_x, _payload->approach_y, _payload->approach_z, _payload->time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_home_position_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, float x, float y, float z, const float* q, float approach_x, float approach_y, float approach_z, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_home_position_t* _payload = (fmav_home_position_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->x = x;
    _payload->y = y;
    _payload->z = z;
    _payload->approach_x = approach_x;
    _payload->approach_y = approach_y;
    _payload->approach_z = approach_z;
    _payload->time_usec = time_usec;
    memcpy(&(_payload->q), q, sizeof(float)*4);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_HOME_POSITION;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_HOME_POSITION >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_HOME_POSITION >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HOME_POSITION_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_home_position_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_home_position_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_home_position_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->x, _payload->y, _payload->z, _payload->q, _payload->approach_x, _payload->approach_y, _payload->approach_z, _payload->time_usec,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_home_position_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, float x, float y, float z, const float* q, float approach_x, float approach_y, float approach_z, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_home_position_t _payload;

    _payload.latitude = latitude;
    _payload.longitude = longitude;
    _payload.altitude = altitude;
    _payload.x = x;
    _payload.y = y;
    _payload.z = z;
    _payload.approach_x = approach_x;
    _payload.approach_y = approach_y;
    _payload.approach_z = approach_z;
    _payload.time_usec = time_usec;
    memcpy(&(_payload.q), q, sizeof(float)*4);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_HOME_POSITION,
        FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HOME_POSITION_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_home_position_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_home_position_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_HOME_POSITION,
        FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HOME_POSITION_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message HOME_POSITION unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_home_position_decode(fmav_home_position_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_HOME_POSITION_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_home_position_get_field_latitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_home_position_get_field_longitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_home_position_get_field_altitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[8]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_x(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[12]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_y(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[16]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_z(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[20]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_approach_x(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[40]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_approach_y(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[44]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_approach_z(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[48]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_home_position_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[52]), sizeof(uint64_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float* fmav_msg_home_position_get_field_q_ptr(const fmav_message_t* msg)
{
    return (float*)&(msg->payload[24]);
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_home_position_get_field_q(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_HOME_POSITION_FIELD_Q_NUM) return 0;
    return ((float*)&(msg->payload[24]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_HOME_POSITION  242

#define mavlink_home_position_t  fmav_home_position_t

#define MAVLINK_MSG_ID_HOME_POSITION_LEN  60
#define MAVLINK_MSG_ID_HOME_POSITION_MIN_LEN  52
#define MAVLINK_MSG_ID_242_LEN  60
#define MAVLINK_MSG_ID_242_MIN_LEN  52

#define MAVLINK_MSG_ID_HOME_POSITION_CRC  104
#define MAVLINK_MSG_ID_242_CRC  104

#define MAVLINK_MSG_HOME_POSITION_FIELD_Q_LEN 4


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_home_position_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    int32_t latitude, int32_t longitude, int32_t altitude, float x, float y, float z, const float* q, float approach_x, float approach_y, float approach_z, uint64_t time_usec)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_home_position_pack(
        msg, sysid, compid,
        latitude, longitude, altitude, x, y, z, q, approach_x, approach_y, approach_z, time_usec,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_home_position_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, float x, float y, float z, const float* q, float approach_x, float approach_y, float approach_z, uint64_t time_usec)
{
    return fmav_msg_home_position_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        latitude, longitude, altitude, x, y, z, q, approach_x, approach_y, approach_z, time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_home_position_decode(const mavlink_message_t* msg, mavlink_home_position_t* payload)
{
    fmav_msg_home_position_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_HOME_POSITION_H
