//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_H
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_H


//----------------------------------------
//-- Message OSD_PARAM_SHOW_CONFIG_REPLY
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_osd_param_show_config_reply_t {
    uint32_t request_id;
    float min_value;
    float max_value;
    float increment;
    uint8_t result;
    char param_id[16];
    uint8_t config_type;
}) fmav_osd_param_show_config_reply_t;


#define FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY  11036


#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MIN  34
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX  34
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN  34
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_CRCEXTRA  177

#define FASTMAVLINK_MSG_ID_11036_LEN_MIN  34
#define FASTMAVLINK_MSG_ID_11036_LEN_MAX  34
#define FASTMAVLINK_MSG_ID_11036_LEN  34
#define FASTMAVLINK_MSG_ID_11036_CRCEXTRA  177

#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_FIELD_PARAM_ID_LEN  16

#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_FLAGS  0
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)
#define FASTMAVLINK_MSG_ID_11036_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_ID_11036_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)


//----------------------------------------
//-- Message OSD_PARAM_SHOW_CONFIG_REPLY packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_reply_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, const char* param_id, uint8_t config_type, float min_value, float max_value, float increment,
    fmav_status_t* _status)
{
    fmav_osd_param_show_config_reply_t* _payload = (fmav_osd_param_show_config_reply_t*)msg->payload;

    _payload->request_id = request_id;
    _payload->min_value = min_value;
    _payload->max_value = max_value;
    _payload->increment = increment;
    _payload->result = result;
    _payload->config_type = config_type;
    memcpy(&(_payload->param_id), param_id, sizeof(char)*16);

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_reply_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_osd_param_show_config_reply_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_osd_param_show_config_reply_pack(
        msg, sysid, compid,
        _payload->request_id, _payload->result, _payload->param_id, _payload->config_type, _payload->min_value, _payload->max_value, _payload->increment,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_reply_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, const char* param_id, uint8_t config_type, float min_value, float max_value, float increment,
    fmav_status_t* _status)
{
    fmav_osd_param_show_config_reply_t* _payload = (fmav_osd_param_show_config_reply_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->request_id = request_id;
    _payload->min_value = min_value;
    _payload->max_value = max_value;
    _payload->increment = increment;
    _payload->result = result;
    _payload->config_type = config_type;
    memcpy(&(_payload->param_id), param_id, sizeof(char)*16);

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_reply_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_osd_param_show_config_reply_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_osd_param_show_config_reply_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->request_id, _payload->result, _payload->param_id, _payload->config_type, _payload->min_value, _payload->max_value, _payload->increment,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_reply_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, const char* param_id, uint8_t config_type, float min_value, float max_value, float increment,
    fmav_status_t* _status)
{
    fmav_osd_param_show_config_reply_t _payload;

    _payload.request_id = request_id;
    _payload.min_value = min_value;
    _payload.max_value = max_value;
    _payload.increment = increment;
    _payload.result = result;
    _payload.config_type = config_type;
    memcpy(&(_payload.param_id), param_id, sizeof(char)*16);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_osd_param_show_config_reply_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_osd_param_show_config_reply_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message OSD_PARAM_SHOW_CONFIG_REPLY unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_osd_param_show_config_reply_decode(fmav_osd_param_show_config_reply_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY  11036

#define mavlink_osd_param_show_config_reply_t  fmav_osd_param_show_config_reply_t

#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY_LEN  34
#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY_MIN_LEN  34
#define MAVLINK_MSG_ID_11036_LEN  34
#define MAVLINK_MSG_ID_11036_MIN_LEN  34

#define MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY_CRC  177
#define MAVLINK_MSG_ID_11036_CRC  177

#define MAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_FIELD_PARAM_ID_LEN 16


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_osd_param_show_config_reply_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint32_t request_id, uint8_t result, const char* param_id, uint8_t config_type, float min_value, float max_value, float increment)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_osd_param_show_config_reply_pack(
        msg, sysid, compid,
        request_id, result, param_id, config_type, min_value, max_value, increment,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_osd_param_show_config_reply_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, const char* param_id, uint8_t config_type, float min_value, float max_value, float increment)
{
    return fmav_msg_osd_param_show_config_reply_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        request_id, result, param_id, config_type, min_value, max_value, increment,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_osd_param_show_config_reply_decode(const mavlink_message_t* msg, mavlink_osd_param_show_config_reply_t* payload)
{
    fmav_msg_osd_param_show_config_reply_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_OSD_PARAM_SHOW_CONFIG_REPLY_H
