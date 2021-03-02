//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_COMMAND_ACK_H
#define FASTMAVLINK_MSG_COMMAND_ACK_H


//----------------------------------------
//-- Message COMMAND_ACK
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_command_ack_t {
    uint16_t command;
    uint8_t result;
    uint8_t progress;
    int32_t result_param2;
    uint8_t target_system;
    uint8_t target_component;
}) fmav_command_ack_t;


#define FASTMAVLINK_MSG_ID_COMMAND_ACK  77

#define FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX  10
#define FASTMAVLINK_MSG_COMMAND_ACK_CRCEXTRA  143

#define FASTMAVLINK_MSG_COMMAND_ACK_FLAGS  3
#define FASTMAVLINK_MSG_COMMAND_ACK_TARGET_SYSTEM_OFS  8
#define FASTMAVLINK_MSG_COMMAND_ACK_TARGET_COMPONENT_OFS  9

#define FASTMAVLINK_MSG_COMMAND_ACK_FRAME_LEN_MAX  35



#define FASTMAVLINK_MSG_COMMAND_ACK_FIELD_COMMAND_OFS  0
#define FASTMAVLINK_MSG_COMMAND_ACK_FIELD_RESULT_OFS  2
#define FASTMAVLINK_MSG_COMMAND_ACK_FIELD_PROGRESS_OFS  3
#define FASTMAVLINK_MSG_COMMAND_ACK_FIELD_RESULT_PARAM2_OFS  4
#define FASTMAVLINK_MSG_COMMAND_ACK_FIELD_TARGET_SYSTEM_OFS  8
#define FASTMAVLINK_MSG_COMMAND_ACK_FIELD_TARGET_COMPONENT_OFS  9


//----------------------------------------
//-- Message COMMAND_ACK packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint16_t command, uint8_t result, uint8_t progress, int32_t result_param2, uint8_t target_system, uint8_t target_component,
    fmav_status_t* _status)
{
    fmav_command_ack_t* _payload = (fmav_command_ack_t*)msg->payload;

    _payload->command = command;
    _payload->result = result;
    _payload->progress = progress;
    _payload->result_param2 = result_param2;
    _payload->target_system = target_system;
    _payload->target_component = target_component;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_COMMAND_ACK;

    msg->target_sysid = target_system;
    msg->target_compid = target_component;
    msg->crc_extra = FASTMAVLINK_MSG_COMMAND_ACK_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_command_ack_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_command_ack_pack(
        msg, sysid, compid,
        _payload->command, _payload->result, _payload->progress, _payload->result_param2, _payload->target_system, _payload->target_component,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint16_t command, uint8_t result, uint8_t progress, int32_t result_param2, uint8_t target_system, uint8_t target_component,
    fmav_status_t* _status)
{
    fmav_command_ack_t* _payload = (fmav_command_ack_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->command = command;
    _payload->result = result;
    _payload->progress = progress;
    _payload->result_param2 = result_param2;
    _payload->target_system = target_system;
    _payload->target_component = target_component;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_COMMAND_ACK;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_COMMAND_ACK >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_COMMAND_ACK >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_COMMAND_ACK_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_command_ack_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_command_ack_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->command, _payload->result, _payload->progress, _payload->result_param2, _payload->target_system, _payload->target_component,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint16_t command, uint8_t result, uint8_t progress, int32_t result_param2, uint8_t target_system, uint8_t target_component,
    fmav_status_t* _status)
{
    fmav_command_ack_t _payload;

    _payload.command = command;
    _payload.result = result;
    _payload.progress = progress;
    _payload.result_param2 = result_param2;
    _payload.target_system = target_system;
    _payload.target_component = target_component;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_COMMAND_ACK,
        FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_COMMAND_ACK_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_command_ack_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_COMMAND_ACK,
        FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_COMMAND_ACK_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message COMMAND_ACK unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_command_ack_decode(fmav_command_ack_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_COMMAND_ACK_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_command_ack_get_field_command(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_command_ack_get_field_result(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[2]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_command_ack_get_field_progress(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[3]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int32_t fmav_msg_command_ack_get_field_result_param2(const fmav_message_t* msg)
{
    int32_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(int32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_command_ack_get_field_target_system(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[8]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_command_ack_get_field_target_component(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[9]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_COMMAND_ACK  77

#define mavlink_command_ack_t  fmav_command_ack_t

#define MAVLINK_MSG_ID_COMMAND_ACK_LEN  10
#define MAVLINK_MSG_ID_COMMAND_ACK_MIN_LEN  3
#define MAVLINK_MSG_ID_77_LEN  10
#define MAVLINK_MSG_ID_77_MIN_LEN  3

#define MAVLINK_MSG_ID_COMMAND_ACK_CRC  143
#define MAVLINK_MSG_ID_77_CRC  143




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_command_ack_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint16_t command, uint8_t result, uint8_t progress, int32_t result_param2, uint8_t target_system, uint8_t target_component)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_command_ack_pack(
        msg, sysid, compid,
        command, result, progress, result_param2, target_system, target_component,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_command_ack_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint16_t command, uint8_t result, uint8_t progress, int32_t result_param2, uint8_t target_system, uint8_t target_component)
{
    return fmav_msg_command_ack_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        command, result, progress, result_param2, target_system, target_component,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_command_ack_decode(const mavlink_message_t* msg, mavlink_command_ack_t* payload)
{
    fmav_msg_command_ack_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_COMMAND_ACK_H
