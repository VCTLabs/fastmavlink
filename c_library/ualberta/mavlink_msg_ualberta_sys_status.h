//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_H
#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_H


//----------------------------------------
//-- Message UALBERTA_SYS_STATUS
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_ualberta_sys_status_t {
    uint8_t mode;
    uint8_t nav_mode;
    uint8_t pilot;
}) fmav_ualberta_sys_status_t;


#define FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS  222

#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX  3
#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_CRCEXTRA  15

#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_FLAGS  0
#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_FRAME_LEN_MAX  28



#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_FIELD_MODE_OFS  0
#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_FIELD_NAV_MODE_OFS  1
#define FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_FIELD_PILOT_OFS  2


//----------------------------------------
//-- Message UALBERTA_SYS_STATUS packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_ualberta_sys_status_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t mode, uint8_t nav_mode, uint8_t pilot,
    fmav_status_t* _status)
{
    fmav_ualberta_sys_status_t* _payload = (fmav_ualberta_sys_status_t*)_msg->payload;

    _payload->mode = mode;
    _payload->nav_mode = nav_mode;
    _payload->pilot = pilot;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_CRCEXTRA;

    return fmav_finalize_msg(
        _msg,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_ualberta_sys_status_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_ualberta_sys_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_ualberta_sys_status_pack(
        _msg, sysid, compid,
        _payload->mode, _payload->nav_mode, _payload->pilot,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_ualberta_sys_status_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t mode, uint8_t nav_mode, uint8_t pilot,
    fmav_status_t* _status)
{
    fmav_ualberta_sys_status_t* _payload = (fmav_ualberta_sys_status_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->mode = mode;
    _payload->nav_mode = nav_mode;
    _payload->pilot = pilot;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_ualberta_sys_status_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_ualberta_sys_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_ualberta_sys_status_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->mode, _payload->nav_mode, _payload->pilot,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_ualberta_sys_status_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t mode, uint8_t nav_mode, uint8_t pilot,
    fmav_status_t* _status)
{
    fmav_ualberta_sys_status_t _payload;

    _payload.mode = mode;
    _payload.nav_mode = nav_mode;
    _payload.pilot = pilot;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_ualberta_sys_status_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_ualberta_sys_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_UALBERTA_SYS_STATUS,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message UALBERTA_SYS_STATUS unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_ualberta_sys_status_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_ualberta_sys_status_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_ualberta_sys_status_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_ualberta_sys_status_decode(fmav_ualberta_sys_status_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_ualberta_sys_status_get_field_mode(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_ualberta_sys_status_get_field_nav_mode(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[1]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_ualberta_sys_status_get_field_pilot(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[2]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_UALBERTA_SYS_STATUS  222

#define mavlink_ualberta_sys_status_t  fmav_ualberta_sys_status_t

#define MAVLINK_MSG_ID_UALBERTA_SYS_STATUS_LEN  3
#define MAVLINK_MSG_ID_UALBERTA_SYS_STATUS_MIN_LEN  3
#define MAVLINK_MSG_ID_222_LEN  3
#define MAVLINK_MSG_ID_222_MIN_LEN  3

#define MAVLINK_MSG_ID_UALBERTA_SYS_STATUS_CRC  15
#define MAVLINK_MSG_ID_222_CRC  15




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_ualberta_sys_status_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint8_t mode, uint8_t nav_mode, uint8_t pilot)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_ualberta_sys_status_pack(
        _msg, sysid, compid,
        mode, nav_mode, pilot,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_ualberta_sys_status_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t mode, uint8_t nav_mode, uint8_t pilot)
{
    return fmav_msg_ualberta_sys_status_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        mode, nav_mode, pilot,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_ualberta_sys_status_decode(const mavlink_message_t* msg, mavlink_ualberta_sys_status_t* payload)
{
    fmav_msg_ualberta_sys_status_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_UALBERTA_SYS_STATUS_H
