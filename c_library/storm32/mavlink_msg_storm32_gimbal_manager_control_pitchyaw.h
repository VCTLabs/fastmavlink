//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_H
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_H


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_storm32_gimbal_manager_control_pitchyaw_t {
    float pitch;
    float yaw;
    float pitch_rate;
    float yaw_rate;
    uint16_t device_flags;
    uint16_t manager_flags;
    uint8_t target_system;
    uint8_t target_component;
    uint8_t gimbal_id;
    uint8_t client;
}) fmav_storm32_gimbal_manager_control_pitchyaw_t;


#define FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW  60013


#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MIN  24
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX  24
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN  24
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_CRCEXTRA  129

#define FASTMAVLINK_MSG_ID_60013_LEN_MIN  24
#define FASTMAVLINK_MSG_ID_60013_LEN_MAX  24
#define FASTMAVLINK_MSG_ID_60013_LEN  24
#define FASTMAVLINK_MSG_ID_60013_CRCEXTRA  129



#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_FLAGS  3
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_TARGET_SYSTEM_OFS  20
#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_TARGET_COMPONENT_OFS  21

#define FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)
#define FASTMAVLINK_MSG_ID_60013_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_ID_60013_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, uint16_t device_flags, uint16_t manager_flags, float pitch, float yaw, float pitch_rate, float yaw_rate,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_control_pitchyaw_t* _payload = (fmav_storm32_gimbal_manager_control_pitchyaw_t*)msg->payload;

    _payload->pitch = pitch;
    _payload->yaw = yaw;
    _payload->pitch_rate = pitch_rate;
    _payload->yaw_rate = yaw_rate;
    _payload->device_flags = device_flags;
    _payload->manager_flags = manager_flags;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->gimbal_id = gimbal_id;
    _payload->client = client;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_control_pitchyaw_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_control_pitchyaw_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->gimbal_id, _payload->client, _payload->device_flags, _payload->manager_flags, _payload->pitch, _payload->yaw, _payload->pitch_rate, _payload->yaw_rate,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, uint16_t device_flags, uint16_t manager_flags, float pitch, float yaw, float pitch_rate, float yaw_rate,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_control_pitchyaw_t* _payload = (fmav_storm32_gimbal_manager_control_pitchyaw_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->pitch = pitch;
    _payload->yaw = yaw;
    _payload->pitch_rate = pitch_rate;
    _payload->yaw_rate = yaw_rate;
    _payload->device_flags = device_flags;
    _payload->manager_flags = manager_flags;
    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->gimbal_id = gimbal_id;
    _payload->client = client;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_control_pitchyaw_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_control_pitchyaw_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->gimbal_id, _payload->client, _payload->device_flags, _payload->manager_flags, _payload->pitch, _payload->yaw, _payload->pitch_rate, _payload->yaw_rate,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, uint16_t device_flags, uint16_t manager_flags, float pitch, float yaw, float pitch_rate, float yaw_rate,
    fmav_status_t* _status)
{
    fmav_storm32_gimbal_manager_control_pitchyaw_t _payload;

    _payload.pitch = pitch;
    _payload.yaw = yaw;
    _payload.pitch_rate = pitch_rate;
    _payload.yaw_rate = yaw_rate;
    _payload.device_flags = device_flags;
    _payload.manager_flags = manager_flags;
    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.gimbal_id = gimbal_id;
    _payload.client = client;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_storm32_gimbal_manager_control_pitchyaw_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_storm32_gimbal_manager_control_pitchyaw_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_storm32_gimbal_manager_control_pitchyaw_decode(fmav_storm32_gimbal_manager_control_pitchyaw_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW  60013

#define mavlink_storm32_gimbal_manager_control_pitchyaw_t  fmav_storm32_gimbal_manager_control_pitchyaw_t

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_LEN  24
#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_MIN_LEN  24
#define MAVLINK_MSG_ID_60013_LEN  24
#define MAVLINK_MSG_ID_60013_MIN_LEN  24

#define MAVLINK_MSG_ID_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_CRC  129
#define MAVLINK_MSG_ID_60013_CRC  129




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_manager_control_pitchyaw_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, uint16_t device_flags, uint16_t manager_flags, float pitch, float yaw, float pitch_rate, float yaw_rate)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack(
        msg, sysid, compid,
        target_system, target_component, gimbal_id, client, device_flags, manager_flags, pitch, yaw, pitch_rate, yaw_rate,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_storm32_gimbal_manager_control_pitchyaw_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, uint8_t gimbal_id, uint8_t client, uint16_t device_flags, uint16_t manager_flags, float pitch, float yaw, float pitch_rate, float yaw_rate)
{
    return fmav_msg_storm32_gimbal_manager_control_pitchyaw_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, gimbal_id, client, device_flags, manager_flags, pitch, yaw, pitch_rate, yaw_rate,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_storm32_gimbal_manager_control_pitchyaw_decode(const mavlink_message_t* msg, mavlink_storm32_gimbal_manager_control_pitchyaw_t* payload)
{
    fmav_msg_storm32_gimbal_manager_control_pitchyaw_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_STORM32_GIMBAL_MANAGER_CONTROL_PITCHYAW_H
