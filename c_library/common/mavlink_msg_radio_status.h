//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_RADIO_STATUS_H
#define FASTMAVLINK_MSG_RADIO_STATUS_H


//----------------------------------------
//-- Message RADIO_STATUS
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_radio_status_t {
    uint16_t rxerrors;
    uint16_t fixed;
    uint8_t rssi;
    uint8_t remrssi;
    uint8_t txbuf;
    uint8_t noise;
    uint8_t remnoise;
}) fmav_radio_status_t;


#define FASTMAVLINK_MSG_ID_RADIO_STATUS  109


#define FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MIN  9
#define FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX  9
#define FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN  9
#define FASTMAVLINK_MSG_RADIO_STATUS_CRCEXTRA  185

#define FASTMAVLINK_MSG_ID_109_LEN_MIN  9
#define FASTMAVLINK_MSG_ID_109_LEN_MAX  9
#define FASTMAVLINK_MSG_ID_109_LEN  9
#define FASTMAVLINK_MSG_ID_109_CRCEXTRA  185



#define FASTMAVLINK_MSG_RADIO_STATUS_FLAGS  0
#define FASTMAVLINK_MSG_RADIO_STATUS_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_RADIO_STATUS_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_RADIO_STATUS_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)
#define FASTMAVLINK_MSG_ID_109_FRAME_LEN_MAX  (FASTMAVLINK_HEADER_V2_LEN+FASTMAVLINK_MSG_ID_109_PAYLOAD_LEN_MAX+FASTMAVLINK_CHECKSUM_LEN+FASTMAVLINK_SIGNATURE_LEN)


//----------------------------------------
//-- Message RADIO_STATUS packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_radio_status_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed,
    fmav_status_t* _status)
{
    fmav_radio_status_t* _payload = (fmav_radio_status_t*)msg->payload;

    _payload->rxerrors = rxerrors;
    _payload->fixed = fixed;
    _payload->rssi = rssi;
    _payload->remrssi = remrssi;
    _payload->txbuf = txbuf;
    _payload->noise = noise;
    _payload->remnoise = remnoise;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_RADIO_STATUS;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_RADIO_STATUS_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_radio_status_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_radio_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_radio_status_pack(
        msg, sysid, compid,
        _payload->rssi, _payload->remrssi, _payload->txbuf, _payload->noise, _payload->remnoise, _payload->rxerrors, _payload->fixed,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_radio_status_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed,
    fmav_status_t* _status)
{
    fmav_radio_status_t* _payload = (fmav_radio_status_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->rxerrors = rxerrors;
    _payload->fixed = fixed;
    _payload->rssi = rssi;
    _payload->remrssi = remrssi;
    _payload->txbuf = txbuf;
    _payload->noise = noise;
    _payload->remnoise = remnoise;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_RADIO_STATUS;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_RADIO_STATUS >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_RADIO_STATUS >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_RADIO_STATUS_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_radio_status_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_radio_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_radio_status_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->rssi, _payload->remrssi, _payload->txbuf, _payload->noise, _payload->remnoise, _payload->rxerrors, _payload->fixed,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_radio_status_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed,
    fmav_status_t* _status)
{
    fmav_radio_status_t _payload;

    _payload.rxerrors = rxerrors;
    _payload.fixed = fixed;
    _payload.rssi = rssi;
    _payload.remrssi = remrssi;
    _payload.txbuf = txbuf;
    _payload.noise = noise;
    _payload.remnoise = remnoise;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_RADIO_STATUS,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_RADIO_STATUS_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_radio_status_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_radio_status_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_RADIO_STATUS,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MIN,
        FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_RADIO_STATUS_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message RADIO_STATUS unpacking routines, for receiving
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_radio_status_decode(fmav_radio_status_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX;

    memset(payload, 0, FASTMAVLINK_MSG_RADIO_STATUS_PAYLOAD_LEN_MAX);
    memcpy(payload, msg->payload, len);
}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_RADIO_STATUS  109

#define mavlink_radio_status_t  fmav_radio_status_t

#define MAVLINK_MSG_ID_RADIO_STATUS_LEN  9
#define MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN  9
#define MAVLINK_MSG_ID_109_LEN  9
#define MAVLINK_MSG_ID_109_MIN_LEN  9

#define MAVLINK_MSG_ID_RADIO_STATUS_CRC  185
#define MAVLINK_MSG_ID_109_CRC  185




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_radio_status_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_radio_status_pack(
        msg, sysid, compid,
        rssi, remrssi, txbuf, noise, remnoise, rxerrors, fixed,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_radio_status_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t rssi, uint8_t remrssi, uint8_t txbuf, uint8_t noise, uint8_t remnoise, uint16_t rxerrors, uint16_t fixed)
{
    return fmav_msg_radio_status_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        rssi, remrssi, txbuf, noise, remnoise, rxerrors, fixed,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_radio_status_decode(const mavlink_message_t* msg, mavlink_radio_status_t* payload)
{
    fmav_msg_radio_status_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_RADIO_STATUS_H
