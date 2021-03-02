//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_HIGHRES_IMU_H
#define FASTMAVLINK_MSG_HIGHRES_IMU_H


//----------------------------------------
//-- Message HIGHRES_IMU
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_highres_imu_t {
    uint64_t time_usec;
    float xacc;
    float yacc;
    float zacc;
    float xgyro;
    float ygyro;
    float zgyro;
    float xmag;
    float ymag;
    float zmag;
    float abs_pressure;
    float diff_pressure;
    float pressure_alt;
    float temperature;
    uint16_t fields_updated;
    uint8_t id;
}) fmav_highres_imu_t;


#define FASTMAVLINK_MSG_ID_HIGHRES_IMU  105

#define FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX  63
#define FASTMAVLINK_MSG_HIGHRES_IMU_CRCEXTRA  93

#define FASTMAVLINK_MSG_HIGHRES_IMU_FLAGS  0
#define FASTMAVLINK_MSG_HIGHRES_IMU_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_HIGHRES_IMU_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_HIGHRES_IMU_FRAME_LEN_MAX  88



#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_TIME_USEC_OFS  0
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_XACC_OFS  8
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_YACC_OFS  12
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_ZACC_OFS  16
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_XGYRO_OFS  20
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_YGYRO_OFS  24
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_ZGYRO_OFS  28
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_XMAG_OFS  32
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_YMAG_OFS  36
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_ZMAG_OFS  40
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_ABS_PRESSURE_OFS  44
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_DIFF_PRESSURE_OFS  48
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_PRESSURE_ALT_OFS  52
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_TEMPERATURE_OFS  56
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_FIELDS_UPDATED_OFS  60
#define FASTMAVLINK_MSG_HIGHRES_IMU_FIELD_ID_OFS  62


//----------------------------------------
//-- Message HIGHRES_IMU packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float abs_pressure, float diff_pressure, float pressure_alt, float temperature, uint16_t fields_updated, uint8_t id,
    fmav_status_t* _status)
{
    fmav_highres_imu_t* _payload = (fmav_highres_imu_t*)msg->payload;

    _payload->time_usec = time_usec;
    _payload->xacc = xacc;
    _payload->yacc = yacc;
    _payload->zacc = zacc;
    _payload->xgyro = xgyro;
    _payload->ygyro = ygyro;
    _payload->zgyro = zgyro;
    _payload->xmag = xmag;
    _payload->ymag = ymag;
    _payload->zmag = zmag;
    _payload->abs_pressure = abs_pressure;
    _payload->diff_pressure = diff_pressure;
    _payload->pressure_alt = pressure_alt;
    _payload->temperature = temperature;
    _payload->fields_updated = fields_updated;
    _payload->id = id;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_HIGHRES_IMU;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_HIGHRES_IMU_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_highres_imu_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_highres_imu_pack(
        msg, sysid, compid,
        _payload->time_usec, _payload->xacc, _payload->yacc, _payload->zacc, _payload->xgyro, _payload->ygyro, _payload->zgyro, _payload->xmag, _payload->ymag, _payload->zmag, _payload->abs_pressure, _payload->diff_pressure, _payload->pressure_alt, _payload->temperature, _payload->fields_updated, _payload->id,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float abs_pressure, float diff_pressure, float pressure_alt, float temperature, uint16_t fields_updated, uint8_t id,
    fmav_status_t* _status)
{
    fmav_highres_imu_t* _payload = (fmav_highres_imu_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->time_usec = time_usec;
    _payload->xacc = xacc;
    _payload->yacc = yacc;
    _payload->zacc = zacc;
    _payload->xgyro = xgyro;
    _payload->ygyro = ygyro;
    _payload->zgyro = zgyro;
    _payload->xmag = xmag;
    _payload->ymag = ymag;
    _payload->zmag = zmag;
    _payload->abs_pressure = abs_pressure;
    _payload->diff_pressure = diff_pressure;
    _payload->pressure_alt = pressure_alt;
    _payload->temperature = temperature;
    _payload->fields_updated = fields_updated;
    _payload->id = id;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_HIGHRES_IMU;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_HIGHRES_IMU >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_HIGHRES_IMU >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HIGHRES_IMU_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_highres_imu_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_highres_imu_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->time_usec, _payload->xacc, _payload->yacc, _payload->zacc, _payload->xgyro, _payload->ygyro, _payload->zgyro, _payload->xmag, _payload->ymag, _payload->zmag, _payload->abs_pressure, _payload->diff_pressure, _payload->pressure_alt, _payload->temperature, _payload->fields_updated, _payload->id,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float abs_pressure, float diff_pressure, float pressure_alt, float temperature, uint16_t fields_updated, uint8_t id,
    fmav_status_t* _status)
{
    fmav_highres_imu_t _payload;

    _payload.time_usec = time_usec;
    _payload.xacc = xacc;
    _payload.yacc = yacc;
    _payload.zacc = zacc;
    _payload.xgyro = xgyro;
    _payload.ygyro = ygyro;
    _payload.zgyro = zgyro;
    _payload.xmag = xmag;
    _payload.ymag = ymag;
    _payload.zmag = zmag;
    _payload.abs_pressure = abs_pressure;
    _payload.diff_pressure = diff_pressure;
    _payload.pressure_alt = pressure_alt;
    _payload.temperature = temperature;
    _payload.fields_updated = fields_updated;
    _payload.id = id;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_HIGHRES_IMU,
        FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HIGHRES_IMU_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_highres_imu_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_HIGHRES_IMU,
        FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_HIGHRES_IMU_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message HIGHRES_IMU unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_highres_imu_decode(fmav_highres_imu_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_HIGHRES_IMU_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}


FASTMAVLINK_FUNCTION_DECORATOR uint64_t fmav_msg_highres_imu_get_field_time_usec(const fmav_message_t* msg)
{
    uint64_t r;
    memcpy(&r, &(msg->payload[0]), sizeof(uint64_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_xacc(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[8]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_yacc(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[12]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_zacc(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[16]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_xgyro(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[20]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_ygyro(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[24]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_zgyro(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[28]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_xmag(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[32]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_ymag(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[36]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_zmag(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[40]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_abs_pressure(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[44]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_diff_pressure(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[48]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_pressure_alt(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[52]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_highres_imu_get_field_temperature(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[56]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_highres_imu_get_field_fields_updated(const fmav_message_t* msg)
{
    uint16_t r;
    memcpy(&r, &(msg->payload[60]), sizeof(uint16_t));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_highres_imu_get_field_id(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[62]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_HIGHRES_IMU  105

#define mavlink_highres_imu_t  fmav_highres_imu_t

#define MAVLINK_MSG_ID_HIGHRES_IMU_LEN  63
#define MAVLINK_MSG_ID_HIGHRES_IMU_MIN_LEN  62
#define MAVLINK_MSG_ID_105_LEN  63
#define MAVLINK_MSG_ID_105_MIN_LEN  62

#define MAVLINK_MSG_ID_HIGHRES_IMU_CRC  93
#define MAVLINK_MSG_ID_105_CRC  93




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_highres_imu_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float abs_pressure, float diff_pressure, float pressure_alt, float temperature, uint16_t fields_updated, uint8_t id)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_highres_imu_pack(
        msg, sysid, compid,
        time_usec, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag, abs_pressure, diff_pressure, pressure_alt, temperature, fields_updated, id,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_highres_imu_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float abs_pressure, float diff_pressure, float pressure_alt, float temperature, uint16_t fields_updated, uint8_t id)
{
    return fmav_msg_highres_imu_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        time_usec, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag, abs_pressure, diff_pressure, pressure_alt, temperature, fields_updated, id,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_highres_imu_decode(const mavlink_message_t* msg, mavlink_highres_imu_t* payload)
{
    fmav_msg_highres_imu_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_HIGHRES_IMU_H
