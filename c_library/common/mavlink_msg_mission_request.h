//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_MISSION_REQUEST_H
#define FASTMAVLINK_MSG_MISSION_REQUEST_H


//----------------------------------------
//-- Message MISSION_REQUEST
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_mission_request_t {
    uint16_t seq;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t mission_type;
}) fmav_mission_request_t;


#define FASTMAVLINK_MSG_ID_MISSION_REQUEST  40


#define FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MIN  4
#define FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX  5
#define FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN  5
#define FASTMAVLINK_MSG_MISSION_REQUEST_CRCEXTRA  230

#define FASTMAVLINK_MSG_ID_40_LEN_MIN  4
#define FASTMAVLINK_MSG_ID_40_LEN_MAX  5
#define FASTMAVLINK_MSG_ID_40_LEN  5
#define FASTMAVLINK_MSG_ID_40_CRCEXTRA  230



#define FASTMAVLINK_MSG_MISSION_REQUEST_FLAGS  3
#define FASTMAVLINK_MSG_MISSION_REQUEST_TARGET_SYSTEM_OFS  2
#define FASTMAVLINK_MSG_MISSION_REQUEST_TARGET_COMPONENT_OFS  3

#define FASTMAVLINK_MSG_MISSION_REQUEST_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)
#define FASTMAVLINK_MSG_ID_40_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_ID_40_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)


//----------------------------------------
//-- Message MISSION_REQUEST packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mission_request_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t mission_type,
    fmav_status_t* _status)
{
    fmav_mission_request_t* _payload = (fmav_mission_request_t*)msg->payload;

    _payload->seq = seq;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->mission_type = mission_type;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_MISSION_REQUEST;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_MISSION_REQUEST_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mission_request_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_mission_request_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_mission_request_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->seq, _payload->mission_type,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mission_request_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t mission_type,
    fmav_status_t* _status)
{
    fmav_mission_request_t* _payload = (fmav_mission_request_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->seq = seq;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->mission_type = mission_type;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_MISSION_REQUEST;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_MISSION_REQUEST >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_MISSION_REQUEST >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MISSION_REQUEST_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mission_request_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_mission_request_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_mission_request_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->seq, _payload->mission_type,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mission_request_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t mission_type,
    fmav_status_t* _status)
{
    fmav_mission_request_t _payload;

    _payload.seq = seq;
    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.mission_type = mission_type;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_MISSION_REQUEST,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MISSION_REQUEST_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_mission_request_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_mission_request_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_MISSION_REQUEST,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_MISSION_REQUEST_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message MISSION_REQUEST unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_mission_request_decode(fmav_mission_request_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_MISSION_REQUEST_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_MISSION_REQUEST  40

#define mavlink_mission_request_t  fmav_mission_request_t

#define MAVLINK_MSG_ID_MISSION_REQUEST_LEN  5
#define MAVLINK_MSG_ID_MISSION_REQUEST_MIN_LEN  4
#define MAVLINK_MSG_ID_40_LEN  5
#define MAVLINK_MSG_ID_40_MIN_LEN  4

#define MAVLINK_MSG_ID_MISSION_REQUEST_CRC  230
#define MAVLINK_MSG_ID_40_CRC  230




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_mission_request_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t mission_type)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_mission_request_pack(
        msg, sysid, compid,
        target_system, target_component, seq, mission_type,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_mission_request_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t mission_type)
{
    return fmav_msg_mission_request_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, seq, mission_type,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_mission_request_decode(const mavlink_message_t* msg, mavlink_mission_request_t* payload)
{
    fmav_msg_mission_request_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_MISSION_REQUEST_H
