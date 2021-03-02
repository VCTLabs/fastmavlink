//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_H
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_H


//----------------------------------------
//-- Message OPEN_DRONE_ID_BASIC_ID
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_open_drone_id_basic_id_t {
    uint8_t target_system;
    uint8_t target_component;
    uint8_t id_or_mac[20];
    uint8_t id_type;
    uint8_t ua_type;
    uint8_t uas_id[20];
}) fmav_open_drone_id_basic_id_t;


#define FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID  12900

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX  44
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_CRCEXTRA  114

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FLAGS  3
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_TARGET_COMPONENT_OFS  1

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FRAME_LEN_MAX  69

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_ID_OR_MAC_NUM  20 // number of elements in array
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_ID_OR_MAC_LEN  20 // length of array = number of bytes
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_UAS_ID_NUM  20 // number of elements in array
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_UAS_ID_LEN  20 // length of array = number of bytes

#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_TARGET_COMPONENT_OFS  1
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_ID_OR_MAC_OFS  2
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_ID_TYPE_OFS  22
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_UA_TYPE_OFS  23
#define FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_UAS_ID_OFS  24


//----------------------------------------
//-- Message OPEN_DRONE_ID_BASIC_ID packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_basic_id_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, const uint8_t* id_or_mac, uint8_t id_type, uint8_t ua_type, const uint8_t* uas_id,
    fmav_status_t* _status)
{
    fmav_open_drone_id_basic_id_t* _payload = (fmav_open_drone_id_basic_id_t*)msg->payload;

    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->id_type = id_type;
    _payload->ua_type = ua_type;
    memcpy(&(_payload->id_or_mac), id_or_mac, sizeof(uint8_t)*20);
    memcpy(&(_payload->uas_id), uas_id, sizeof(uint8_t)*20);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_basic_id_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_basic_id_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_open_drone_id_basic_id_pack(
        msg, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->id_or_mac, _payload->id_type, _payload->ua_type, _payload->uas_id,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_basic_id_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, const uint8_t* id_or_mac, uint8_t id_type, uint8_t ua_type, const uint8_t* uas_id,
    fmav_status_t* _status)
{
    fmav_open_drone_id_basic_id_t* _payload = (fmav_open_drone_id_basic_id_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->target_system = target_system;
    _payload->target_component = target_component;
    _payload->id_type = id_type;
    _payload->ua_type = ua_type;
    memcpy(&(_payload->id_or_mac), id_or_mac, sizeof(uint8_t)*20);
    memcpy(&(_payload->uas_id), uas_id, sizeof(uint8_t)*20);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_basic_id_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_basic_id_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_open_drone_id_basic_id_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->target_system, _payload->target_component, _payload->id_or_mac, _payload->id_type, _payload->ua_type, _payload->uas_id,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_basic_id_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, const uint8_t* id_or_mac, uint8_t id_type, uint8_t ua_type, const uint8_t* uas_id,
    fmav_status_t* _status)
{
    fmav_open_drone_id_basic_id_t _payload;

    _payload.target_system = target_system;
    _payload.target_component = target_component;
    _payload.id_type = id_type;
    _payload.ua_type = ua_type;
    memcpy(&(_payload.id_or_mac), id_or_mac, sizeof(uint8_t)*20);
    memcpy(&(_payload.uas_id), uas_id, sizeof(uint8_t)*20);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_open_drone_id_basic_id_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_open_drone_id_basic_id_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message OPEN_DRONE_ID_BASIC_ID unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_open_drone_id_basic_id_decode(fmav_open_drone_id_basic_id_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_basic_id_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_basic_id_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[1]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_basic_id_get_field_id_type(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[22]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_basic_id_get_field_ua_type(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[23]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_open_drone_id_basic_id_get_field_id_or_mac_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[2]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_basic_id_get_field_id_or_mac(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_ID_OR_MAC_NUM) return 0;
    return ((uint8_t*)&(msg->payload[2]))[index];
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_open_drone_id_basic_id_get_field_uas_id_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[24]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_open_drone_id_basic_id_get_field_uas_id(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_UAS_ID_NUM) return 0;
    return ((uint8_t*)&(msg->payload[24]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID  12900

#define mavlink_open_drone_id_basic_id_t  fmav_open_drone_id_basic_id_t

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID_LEN  44
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID_MIN_LEN  44
#define MAVLINK_MSG_ID_12900_LEN  44
#define MAVLINK_MSG_ID_12900_MIN_LEN  44

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_BASIC_ID_CRC  114
#define MAVLINK_MSG_ID_12900_CRC  114

#define MAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_ID_OR_MAC_LEN 20
#define MAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_FIELD_UAS_ID_LEN 20


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_open_drone_id_basic_id_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t target_system, uint8_t target_component, const uint8_t* id_or_mac, uint8_t id_type, uint8_t ua_type, const uint8_t* uas_id)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_open_drone_id_basic_id_pack(
        msg, sysid, compid,
        target_system, target_component, id_or_mac, id_type, ua_type, uas_id,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_open_drone_id_basic_id_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t target_system, uint8_t target_component, const uint8_t* id_or_mac, uint8_t id_type, uint8_t ua_type, const uint8_t* uas_id)
{
    return fmav_msg_open_drone_id_basic_id_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        target_system, target_component, id_or_mac, id_type, ua_type, uas_id,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_open_drone_id_basic_id_decode(const mavlink_message_t* msg, mavlink_open_drone_id_basic_id_t* payload)
{
    fmav_msg_open_drone_id_basic_id_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_OPEN_DRONE_ID_BASIC_ID_H
