//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_H
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_H


//----------------------------------------
//-- Message DEVICE_OP_READ_REPLY
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_device_op_read_reply_t {
    uint32_t request_id;
    uint8_t result;
    uint8_t regstart;
    uint8_t count;
    uint8_t data[128];
    uint8_t bank;
}) fmav_device_op_read_reply_t;


#define FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY  11001

#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX  136
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_CRCEXTRA  15

#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FLAGS  0
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FRAME_LEN_MAX  161

#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_DATA_NUM  128 // number of elements in array
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_DATA_LEN  128 // length of array = number of bytes

#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_REQUEST_ID_OFS  0
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_RESULT_OFS  4
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_REGSTART_OFS  5
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_COUNT_OFS  6
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_DATA_OFS  7
#define FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_BANK_OFS  135


//----------------------------------------
//-- Message DEVICE_OP_READ_REPLY packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_device_op_read_reply_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, uint8_t regstart, uint8_t count, const uint8_t* data, uint8_t bank,
    fmav_status_t* _status)
{
    fmav_device_op_read_reply_t* _payload = (fmav_device_op_read_reply_t*)_msg->payload;

    _payload->request_id = request_id;
    _payload->result = result;
    _payload->regstart = regstart;
    _payload->count = count;
    _payload->bank = bank;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*128);

    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_CRCEXTRA;

    return fmav_finalize_msg(
        _msg,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_device_op_read_reply_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_device_op_read_reply_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_device_op_read_reply_pack(
        _msg, sysid, compid,
        _payload->request_id, _payload->result, _payload->regstart, _payload->count, _payload->data, _payload->bank,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_device_op_read_reply_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, uint8_t regstart, uint8_t count, const uint8_t* data, uint8_t bank,
    fmav_status_t* _status)
{
    fmav_device_op_read_reply_t* _payload = (fmav_device_op_read_reply_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->request_id = request_id;
    _payload->result = result;
    _payload->regstart = regstart;
    _payload->count = count;
    _payload->bank = bank;
    memcpy(&(_payload->data), data, sizeof(uint8_t)*128);

    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_device_op_read_reply_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_device_op_read_reply_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_device_op_read_reply_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->request_id, _payload->result, _payload->regstart, _payload->count, _payload->data, _payload->bank,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_device_op_read_reply_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, uint8_t regstart, uint8_t count, const uint8_t* data, uint8_t bank,
    fmav_status_t* _status)
{
    fmav_device_op_read_reply_t _payload;

    _payload.request_id = request_id;
    _payload.result = result;
    _payload.regstart = regstart;
    _payload.count = count;
    _payload.bank = bank;
    memcpy(&(_payload.data), data, sizeof(uint8_t)*128);

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_device_op_read_reply_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_device_op_read_reply_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_DEVICE_OP_READ_REPLY,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message DEVICE_OP_READ_REPLY unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_device_op_read_reply_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_device_op_read_reply_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_device_op_read_reply_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_device_op_read_reply_decode(fmav_device_op_read_reply_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR uint32_t fmav_msg_device_op_read_reply_get_field_request_id(const fmav_message_t* msg)
{
    uint32_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint32_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_device_op_read_reply_get_field_result(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[4]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_device_op_read_reply_get_field_regstart(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[5]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_device_op_read_reply_get_field_count(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[6]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_device_op_read_reply_get_field_bank(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[135]), sizeof(uint8_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t* fmav_msg_device_op_read_reply_get_field_data_ptr(const fmav_message_t* msg)
{
    return (uint8_t*)&(msg->payload[7]);
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_device_op_read_reply_get_field_data(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_DATA_NUM) return 0;
    return ((uint8_t*)&(msg->payload[7]))[index];
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY  11001

#define mavlink_device_op_read_reply_t  fmav_device_op_read_reply_t

#define MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY_LEN  136
#define MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY_MIN_LEN  135
#define MAVLINK_MSG_ID_11001_LEN  136
#define MAVLINK_MSG_ID_11001_MIN_LEN  135

#define MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY_CRC  15
#define MAVLINK_MSG_ID_11001_CRC  15

#define MAVLINK_MSG_DEVICE_OP_READ_REPLY_FIELD_DATA_LEN 128


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_device_op_read_reply_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint32_t request_id, uint8_t result, uint8_t regstart, uint8_t count, const uint8_t* data, uint8_t bank)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_device_op_read_reply_pack(
        _msg, sysid, compid,
        request_id, result, regstart, count, data, bank,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_device_op_read_reply_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint32_t request_id, uint8_t result, uint8_t regstart, uint8_t count, const uint8_t* data, uint8_t bank)
{
    return fmav_msg_device_op_read_reply_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        request_id, result, regstart, count, data, bank,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_device_op_read_reply_decode(const mavlink_message_t* msg, mavlink_device_op_read_reply_t* payload)
{
    fmav_msg_device_op_read_reply_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_DEVICE_OP_READ_REPLY_H
