//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_BATTERY2_H
#define FASTMAVLINK_MSG_BATTERY2_H


//----------------------------------------
//-- Message BATTERY2
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_battery2_t {
    uint16_t voltage;
    int16_t current_battery;
}) fmav_battery2_t;


#define FASTMAVLINK_MSG_ID_BATTERY2  181

#define FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX  4
#define FASTMAVLINK_MSG_BATTERY2_CRCEXTRA  174

#define FASTMAVLINK_MSG_BATTERY2_FLAGS  0
#define FASTMAVLINK_MSG_BATTERY2_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_BATTERY2_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_BATTERY2_FRAME_LEN_MAX  29



#define FASTMAVLINK_MSG_BATTERY2_FIELD_VOLTAGE_OFS  0
#define FASTMAVLINK_MSG_BATTERY2_FIELD_CURRENT_BATTERY_OFS  2


//----------------------------------------
//-- Message BATTERY2 packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_pack(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    uint16_t voltage, int16_t current_battery,
    fmav_status_t* _status)
{
    fmav_battery2_t* _payload = (fmav_battery2_t*)_msg->payload;

    _payload->voltage = voltage;
    _payload->current_battery = current_battery;


    _msg->sysid = sysid;
    _msg->compid = compid;
    _msg->msgid = FASTMAVLINK_MSG_ID_BATTERY2;
    _msg->target_sysid = 0;
    _msg->target_compid = 0;
    _msg->crc_extra = FASTMAVLINK_MSG_BATTERY2_CRCEXTRA;

    return fmav_finalize_msg(
        _msg,
        FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_encode(
    fmav_message_t* _msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_battery2_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_battery2_pack(
        _msg, sysid, compid,
        _payload->voltage, _payload->current_battery,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_pack_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    uint16_t voltage, int16_t current_battery,
    fmav_status_t* _status)
{
    fmav_battery2_t* _payload = (fmav_battery2_t*)(&_buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->voltage = voltage;
    _payload->current_battery = current_battery;


    _buf[5] = sysid;
    _buf[6] = compid;
    _buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_BATTERY2;
    _buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_BATTERY2 >> 8);
    _buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_BATTERY2 >> 16);

    return fmav_finalize_frame_buf(
        _buf,
        FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_BATTERY2_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_encode_to_frame_buf(
    uint8_t* _buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_battery2_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_battery2_pack_to_frame_buf(
        _buf, sysid, compid,
        _payload->voltage, _payload->current_battery,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint16_t voltage, int16_t current_battery,
    fmav_status_t* _status)
{
    fmav_battery2_t _payload;

    _payload.voltage = voltage;
    _payload.current_battery = current_battery;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_BATTERY2,
        FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_BATTERY2_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_battery2_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_BATTERY2,
        FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_BATTERY2_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message BATTERY2 unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before
// while for the fmav_msg_battery2_decode() function, this could be accounted for,
// there is no easy&reasonable way to do it for the fmav_msg_battery2_get_field_yyy() functions.
// So, we generally require it.

// this should not be needed, but we provide it just in case
FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_battery2_zero_fill(fmav_message_t* msg)
{
    if (msg->len < FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX) {
        memset(&(((uint8_t*)msg->payload)[msg->len]), 0, FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    }
}


FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_battery2_decode(fmav_battery2_t* payload, const fmav_message_t* msg)
{
    // this assumes msg payload has been zero filled
    //memcpy(payload, msg->payload, FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX);

    // let's assume it is not zero filled, this should not be needed, but let's just play it safe
    if (msg->len < FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX) {
        memcpy(payload, msg->payload, msg->len);
        memset(&(((uint8_t*)payload)[msg->len]), 0, FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX - msg->len); // zero-fill
    } else {
        memcpy(payload, msg->payload, FASTMAVLINK_MSG_BATTERY2_PAYLOAD_LEN_MAX);
    }
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_battery2_get_field_voltage(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR int16_t fmav_msg_battery2_get_field_current_battery(const fmav_message_t* msg)
{
    int16_t r;
    memcpy(&r, &(msg->payload[2]), sizeof(int16_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_BATTERY2  181

#define mavlink_battery2_t  fmav_battery2_t

#define MAVLINK_MSG_ID_BATTERY2_LEN  4
#define MAVLINK_MSG_ID_BATTERY2_MIN_LEN  4
#define MAVLINK_MSG_ID_181_LEN  4
#define MAVLINK_MSG_ID_181_MIN_LEN  4

#define MAVLINK_MSG_ID_BATTERY2_CRC  174
#define MAVLINK_MSG_ID_181_CRC  174




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_battery2_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* _msg,
    uint16_t voltage, int16_t current_battery)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_battery2_pack(
        _msg, sysid, compid,
        voltage, current_battery,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_battery2_pack_txbuf(
    char* _buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint16_t voltage, int16_t current_battery)
{
    return fmav_msg_battery2_pack_to_frame_buf(
        (uint8_t*)_buf,
        sysid,
        compid,
        voltage, current_battery,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_battery2_decode(const mavlink_message_t* msg, mavlink_battery2_t* payload)
{
    fmav_msg_battery2_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_BATTERY2_H
