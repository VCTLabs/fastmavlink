//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_H
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_H


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_gps_global_origin_t {
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;
    uint64_t time_usec;
}) fmav_gps_global_origin_t;


#define FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN  49

#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX  20
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA  39

#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FLAGS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FRAME_LEN_MAX  45



#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_LATITUDE_OFS  0
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_LONGITUDE_OFS  4
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_ALTITUDE_OFS  8
#define FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_FIELD_TIME_USEC_OFS  12


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t* _payload = (fmav_gps_global_origin_t*)msg->payload;

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->time_usec = time_usec;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gps_global_origin_pack(
        msg, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t* _payload = (fmav_gps_global_origin_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->latitude = latitude;
    _payload->longitude = longitude;
    _payload->altitude = altitude;
    _payload->time_usec = time_usec;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_gps_global_origin_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->latitude, _payload->longitude, _payload->altitude, _payload->time_usec,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec,
    fmav_status_t* _status)
{
    fmav_gps_global_origin_t _payload;

    _payload.latitude = latitude;
    _payload.longitude = longitude;
    _payload.altitude = altitude;
    _payload.time_usec = time_usec;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_gps_global_origin_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_gps_global_origin_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message GPS_GLOBAL_ORIGIN unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_gps_global_origin_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_gps_global_origin_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_gps_global_origin_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_gps_global_origin_decode(fmav_gps_global_origin_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_gps_global_origin_get_field_latitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_gps_global_origin_get_field_longitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_gps_global_origin_get_field_altitude(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[8]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_gps_global_origin_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[12]), sizeof(uint64_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN  49

#define mavlink_gps_global_origin_t  fmav_gps_global_origin_t

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_LEN  20
#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_MIN_LEN  12
#define MAVLINK_MSG_ID_49_LEN  20
#define MAVLINK_MSG_ID_49_MIN_LEN  12

#define MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN_CRC  39
#define MAVLINK_MSG_ID_49_CRC  39




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gps_global_origin_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_gps_global_origin_pack(
        msg, sysid, compid,
        latitude, longitude, altitude, time_usec,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_gps_global_origin_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    int32_t latitude, int32_t longitude, int32_t altitude, uint64_t time_usec)
{
    return fmav_msg_gps_global_origin_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        latitude, longitude, altitude, time_usec,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_gps_global_origin_decode(const mavlink_message_t* msg, mavlink_gps_global_origin_t* payload)
{
    fmav_msg_gps_global_origin_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_GPS_GLOBAL_ORIGIN_H
