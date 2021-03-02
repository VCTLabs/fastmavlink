//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_ADAP_TUNING_H
#define FASTMAVLINK_MSG_ADAP_TUNING_H


//----------------------------------------
//-- Message ADAP_TUNING
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_adap_tuning_t {
    float desired;
    float achieved;
    float error;
    float theta;
    float omega;
    float sigma;
    float theta_dot;
    float omega_dot;
    float sigma_dot;
    float f;
    float f_dot;
    float u;
    uint8_t axis;
}) fmav_adap_tuning_t;


#define FASTMAVLINK_MSG_ID_ADAP_TUNING  11010

#define FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX  49
#define FASTMAVLINK_MSG_ADAP_TUNING_CRCEXTRA  46

#define FASTMAVLINK_MSG_ADAP_TUNING_FLAGS  0
#define FASTMAVLINK_MSG_ADAP_TUNING_TARGET_SYSTEM_OFS  0
#define FASTMAVLINK_MSG_ADAP_TUNING_TARGET_COMPONENT_OFS  0

#define FASTMAVLINK_MSG_ADAP_TUNING_FRAME_LEN_MAX  74



#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_DESIRED_OFS  0
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_ACHIEVED_OFS  4
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_ERROR_OFS  8
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_THETA_OFS  12
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_OMEGA_OFS  16
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_SIGMA_OFS  20
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_THETA_DOT_OFS  24
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_OMEGA_DOT_OFS  28
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_SIGMA_DOT_OFS  32
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_F_OFS  36
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_F_DOT_OFS  40
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_U_OFS  44
#define FASTMAVLINK_MSG_ADAP_TUNING_FIELD_AXIS_OFS  48


//----------------------------------------
//-- Message ADAP_TUNING packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_adap_tuning_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    uint8_t axis, float desired, float achieved, float error, float theta, float omega, float sigma, float theta_dot, float omega_dot, float sigma_dot, float f, float f_dot, float u,
    fmav_status_t* _status)
{
    fmav_adap_tuning_t* _payload = (fmav_adap_tuning_t*)msg->payload;

    _payload->desired = desired;
    _payload->achieved = achieved;
    _payload->error = error;
    _payload->theta = theta;
    _payload->omega = omega;
    _payload->sigma = sigma;
    _payload->theta_dot = theta_dot;
    _payload->omega_dot = omega_dot;
    _payload->sigma_dot = sigma_dot;
    _payload->f = f;
    _payload->f_dot = f_dot;
    _payload->u = u;
    _payload->axis = axis;


    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_ADAP_TUNING;

    msg->target_sysid = 0;
    msg->target_compid = 0;
    msg->crc_extra = FASTMAVLINK_MSG_ADAP_TUNING_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_adap_tuning_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_adap_tuning_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_adap_tuning_pack(
        msg, sysid, compid,
        _payload->axis, _payload->desired, _payload->achieved, _payload->error, _payload->theta, _payload->omega, _payload->sigma, _payload->theta_dot, _payload->omega_dot, _payload->sigma_dot, _payload->f, _payload->f_dot, _payload->u,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_adap_tuning_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    uint8_t axis, float desired, float achieved, float error, float theta, float omega, float sigma, float theta_dot, float omega_dot, float sigma_dot, float f, float f_dot, float u,
    fmav_status_t* _status)
{
    fmav_adap_tuning_t* _payload = (fmav_adap_tuning_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

    _payload->desired = desired;
    _payload->achieved = achieved;
    _payload->error = error;
    _payload->theta = theta;
    _payload->omega = omega;
    _payload->sigma = sigma;
    _payload->theta_dot = theta_dot;
    _payload->omega_dot = omega_dot;
    _payload->sigma_dot = sigma_dot;
    _payload->f = f;
    _payload->f_dot = f_dot;
    _payload->u = u;
    _payload->axis = axis;


    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_ADAP_TUNING;
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_ADAP_TUNING >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_ADAP_TUNING >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ADAP_TUNING_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_adap_tuning_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_adap_tuning_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_adap_tuning_pack_to_frame_buf(
        buf, sysid, compid,
        _payload->axis, _payload->desired, _payload->achieved, _payload->error, _payload->theta, _payload->omega, _payload->sigma, _payload->theta_dot, _payload->omega_dot, _payload->sigma_dot, _payload->f, _payload->f_dot, _payload->u,
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_adap_tuning_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    uint8_t axis, float desired, float achieved, float error, float theta, float omega, float sigma, float theta_dot, float omega_dot, float sigma_dot, float f, float f_dot, float u,
    fmav_status_t* _status)
{
    fmav_adap_tuning_t _payload;

    _payload.desired = desired;
    _payload.achieved = achieved;
    _payload.error = error;
    _payload.theta = theta;
    _payload.omega = omega;
    _payload.sigma = sigma;
    _payload.theta_dot = theta_dot;
    _payload.omega_dot = omega_dot;
    _payload.sigma_dot = sigma_dot;
    _payload.f = f;
    _payload.f_dot = f_dot;
    _payload.u = u;
    _payload.axis = axis;


    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_ADAP_TUNING,
        FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ADAP_TUNING_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_adap_tuning_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_adap_tuning_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_ADAP_TUNING,
        FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_ADAP_TUNING_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message ADAP_TUNING unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_adap_tuning_decode(fmav_adap_tuning_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_ADAP_TUNING_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_desired(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[0]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_achieved(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[4]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_error(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[8]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_theta(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[12]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_omega(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[16]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_sigma(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[20]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_theta_dot(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[24]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_omega_dot(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[28]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_sigma_dot(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[32]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_f(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[36]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_f_dot(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[40]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR float fmav_msg_adap_tuning_get_field_u(const fmav_message_t* msg)
{
    float r;
    memcpy(&r, &(msg->payload[44]), sizeof(float));
    return r;
}


FASTMAVLINK_FUNCTION_DECORATOR uint8_t fmav_msg_adap_tuning_get_field_axis(const fmav_message_t* msg)
{
    uint8_t r;
    memcpy(&r, &(msg->payload[48]), sizeof(uint8_t));
    return r;
}





//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_ADAP_TUNING  11010

#define mavlink_adap_tuning_t  fmav_adap_tuning_t

#define MAVLINK_MSG_ID_ADAP_TUNING_LEN  49
#define MAVLINK_MSG_ID_ADAP_TUNING_MIN_LEN  49
#define MAVLINK_MSG_ID_11010_LEN  49
#define MAVLINK_MSG_ID_11010_MIN_LEN  49

#define MAVLINK_MSG_ID_ADAP_TUNING_CRC  46
#define MAVLINK_MSG_ID_11010_CRC  46




#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_adap_tuning_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    uint8_t axis, float desired, float achieved, float error, float theta, float omega, float sigma, float theta_dot, float omega_dot, float sigma_dot, float f, float f_dot, float u)
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_adap_tuning_pack(
        msg, sysid, compid,
        axis, desired, achieved, error, theta, omega, sigma, theta_dot, omega_dot, sigma_dot, f, f_dot, u,
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_adap_tuning_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    uint8_t axis, float desired, float achieved, float error, float theta, float omega, float sigma, float theta_dot, float omega_dot, float sigma_dot, float f, float f_dot, float u)
{
    return fmav_msg_adap_tuning_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        axis, desired, achieved, error, theta, omega, sigma, theta_dot, omega_dot, sigma_dot, f, f_dot, u,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_adap_tuning_decode(const mavlink_message_t* msg, mavlink_adap_tuning_t* payload)
{
    fmav_msg_adap_tuning_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_ADAP_TUNING_H
