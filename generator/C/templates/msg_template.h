//------------------------------
// The fastMavlink library
// (c) OlliW, OlliW42, www.olliw.eu
//------------------------------

#pragma once
#ifndef FASTMAVLINK_MSG_${name}_H
#define FASTMAVLINK_MSG_${name}_H


//----------------------------------------
//-- Message ${name}
//----------------------------------------

// fields are ordered, as they are on the wire
FASTMAVLINK_PACK(
typedef struct _fmav_${name_lower}_t {
${{ordered_fields:    ${type} ${name}${array_suffix};
}}
}) fmav_${name_lower}_t;


#define FASTMAVLINK_MSG_ID_${name}  ${id}

#define FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX  ${payload_max_length}
#define FASTMAVLINK_MSG_${name}_CRCEXTRA  ${crc_extra}

#define FASTMAVLINK_MSG_${name}_FLAGS  ${message_flags}
#define FASTMAVLINK_MSG_${name}_TARGET_SYSTEM_OFS  ${target_system_ofs}
#define FASTMAVLINK_MSG_${name}_TARGET_COMPONENT_OFS  ${target_component_ofs}

#define FASTMAVLINK_MSG_${name}_FRAME_LEN_MAX  ${frame_max_length}

${{array_fields:#define FASTMAVLINK_MSG_${msg_name}_FIELD_${name_upper}_NUM  ${array_length} // number of elements in array
#define FASTMAVLINK_MSG_${msg_name}_FIELD_${name_upper}_LEN  ${field_length} // length of array = number of bytes
}}

${{ordered_fields:#define FASTMAVLINK_MSG_${msg_name}_FIELD_${name_upper}_OFS  ${payload_offset}
}}


//----------------------------------------
//-- Message ${name} packing routines, for sending
//----------------------------------------

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_${name_lower}_pack(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    ${{arg_fields:${array_const}${type}${array_prefix} ${name}, }},
    fmav_status_t* _status)
{
    fmav_${name_lower}_t* _payload = (fmav_${name_lower}_t*)msg->payload;

${{scalar_fields:    _payload->${name} = ${name_for_setting_payload};
}}
${{array_fields:    memcpy(&(_payload->${name}), ${name}, sizeof(${type})*${array_length});
}}

    msg->sysid = sysid;
    msg->compid = compid;
    msg->msgid = FASTMAVLINK_MSG_ID_${name};

    msg->target_sysid = ${target_system_field_name};
    msg->target_compid = ${target_component_field_name};
    msg->crc_extra = FASTMAVLINK_MSG_${name}_CRCEXTRA;

    return fmav_finalize_msg(
        msg,
        FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_${name_lower}_encode(
    fmav_message_t* msg,
    uint8_t sysid,
    uint8_t compid,
    const fmav_${name_lower}_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_${name_lower}_pack(
        msg, sysid, compid,
        ${{arg_fields:_payload->${name}, }},
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_${name_lower}_pack_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    ${{arg_fields:${array_const}${type}${array_prefix} ${name}, }},
    fmav_status_t* _status)
{
    fmav_${name_lower}_t* _payload = (fmav_${name_lower}_t*)(&buf[FASTMAVLINK_HEADER_V2_LEN]);

${{scalar_fields:    _payload->${name} = ${name_for_setting_payload};
}}
${{array_fields:    memcpy(&(_payload->${name}), ${name}, sizeof(${type})*${array_length});
}}

    buf[5] = sysid;
    buf[6] = compid;
    buf[7] = (uint8_t)FASTMAVLINK_MSG_ID_${name};
    buf[8] = ((uint32_t)FASTMAVLINK_MSG_ID_${name} >> 8);
    buf[9] = ((uint32_t)FASTMAVLINK_MSG_ID_${name} >> 16);

    return fmav_finalize_frame_buf(
        buf,
        FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_${name}_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_${name_lower}_encode_to_frame_buf(
    uint8_t* buf,
    uint8_t sysid,
    uint8_t compid,
    const fmav_${name_lower}_t* _payload,
    fmav_status_t* _status)
{
    return fmav_msg_${name_lower}_pack_to_frame_buf(
        buf, sysid, compid,
        ${{arg_fields:_payload->${name}, }},
        _status);
}


#ifdef FASTMAVLINK_SERIAL_WRITE_CHAR

FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_${name_lower}_pack_to_serial(
    uint8_t sysid,
    uint8_t compid,
    ${{arg_fields:${array_const}${type}${array_prefix} ${name}, }},
    fmav_status_t* _status)
{
    fmav_${name_lower}_t _payload;

${{scalar_fields:    _payload.${name} = ${name_for_setting_payload};
}}
${{array_fields:    memcpy(&(_payload.${name}), ${name}, sizeof(${type})*${array_length});
}}

    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)&_payload,
        FASTMAVLINK_MSG_ID_${name},
        FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_${name}_CRCEXTRA,
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR uint16_t fmav_msg_${name_lower}_encode_to_serial(
    uint8_t sysid,
    uint8_t compid,
    const fmav_${name_lower}_t* _payload,
    fmav_status_t* _status)
{
    return fmav_finalize_serial(
        sysid,
        compid,
        (uint8_t*)_payload,
        FASTMAVLINK_MSG_ID_${name},
        FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX,
        FASTMAVLINK_MSG_${name}_CRCEXTRA,
        _status);
}
#endif


//----------------------------------------
//-- Message ${name} unpacking routines, for receiving
//----------------------------------------
// for these functions to work correctly, msg payload must have been zero filled before

FASTMAVLINK_FUNCTION_DECORATOR void fmav_msg_${name_lower}_decode(fmav_${name_lower}_t* payload, const fmav_message_t* msg)
{
    uint8_t len = (msg->len < FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX) ? msg->len : FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX;

    // memset(payload, 0, FASTMAVLINK_MSG_${name}_PAYLOAD_LEN_MAX); not needed, must have been done before
    memcpy(payload, msg->payload, len);
}


${{scalar_fields:FASTMAVLINK_FUNCTION_DECORATOR ${type} fmav_msg_${name_lower}_get_field_${name}(const fmav_message_t* msg)
{
    ${type} r; 
    memcpy(&r, &(msg->payload[${payload_offset}]), sizeof(${type})); 
    return r;     
}


}}


${{array_fields:FASTMAVLINK_FUNCTION_DECORATOR ${type}* fmav_msg_${name_lower}_get_field_${name}_ptr(const fmav_message_t* msg)
{
    return (${type}*)&(msg->payload[${payload_offset}]);
}


FASTMAVLINK_FUNCTION_DECORATOR ${type} fmav_msg_${name_lower}_get_field_${name}(uint16_t index, const fmav_message_t* msg)
{
    if (index >= FASTMAVLINK_MSG_${msg_name}_FIELD_${name_upper}_NUM) return 0;
    return ((${type}*)&(msg->payload[${payload_offset}]))[index];     
}


}}


//----------------------------------------
//-- Pymavlink wrappers
//----------------------------------------
#ifdef FASTMAVLINK_PYMAVLINK_ENABLED

#define MAVLINK_MSG_ID_${name}  ${id}

#define mavlink_${name_lower}_t  fmav_${name_lower}_t

#define MAVLINK_MSG_ID_${name}_LEN  ${payload_max_length}
#define MAVLINK_MSG_ID_${name}_MIN_LEN  ${payload_min_length}
#define MAVLINK_MSG_ID_${id}_LEN  ${payload_max_length}
#define MAVLINK_MSG_ID_${id}_MIN_LEN  ${payload_min_length}

#define MAVLINK_MSG_ID_${name}_CRC  ${crc_extra}
#define MAVLINK_MSG_ID_${id}_CRC  ${crc_extra}

${{array_fields:#define MAVLINK_MSG_${msg_name}_FIELD_${name_upper}_LEN ${array_length}
}}


#if MAVLINK_COMM_NUM_BUFFERS > 0

FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_${name_lower}_pack(
    uint8_t sysid,
    uint8_t compid,
    mavlink_message_t* msg,
    ${{arg_fields:${array_const}${type}${array_prefix} ${name}, }})
{
    fmav_status_t* _status = mavlink_get_channel_status(MAVLINK_COMM_0);
    return fmav_msg_${name_lower}_pack(
        msg, sysid, compid,
        ${{arg_fields:${name}, }},
        _status);
}

#endif


FASTMAVLINK_FUNCTION_DECORATOR uint16_t mavlink_msg_${name_lower}_pack_txbuf(
    char* buf,
    fmav_status_t* _status,
    uint8_t sysid,
    uint8_t compid,
    ${{arg_fields:${array_const}${type}${array_prefix} ${name}, }})
{
    return fmav_msg_${name_lower}_pack_to_frame_buf(
        (uint8_t*)buf,
        sysid,
        compid,
        ${{arg_fields:${name}, }},
        _status);
}


FASTMAVLINK_FUNCTION_DECORATOR void mavlink_msg_${name_lower}_decode(const mavlink_message_t* msg, mavlink_${name_lower}_t* payload)
{
    fmav_msg_${name_lower}_decode(payload, msg);
}

#endif // FASTMAVLINK_PYMAVLINK_ENABLED


#endif // FASTMAVLINK_MSG_${name}_H
