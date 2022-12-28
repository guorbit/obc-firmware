#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#if defined( __unix__ ) || defined( __MSP430__ )
#include <stdlib.h> /* for size_t */
#else
typedef unsigned size_t;
#endif

#ifndef STATIC
#define STATIC
#endif


#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_CounterK_UPER
int Encode_UPER_CounterK(void *pBuffer, size_t iMaxBufferSize, const asn1SccCounterK *pSrc);
#endif

#ifdef __NEED_CounterK_ACN
int Encode_ACN_CounterK(void *pBuffer, size_t iMaxBufferSize, asn1SccCounterK *pSrc);
#endif

#ifdef __NEED_CounterK_NATIVE
int Encode_NATIVE_CounterK(void *pBuffer, size_t iMaxBufferSize, const asn1SccCounterK *pSrc);
#endif

#ifdef __NEED_CounterK_UPER
int Decode_UPER_CounterK(asn1SccCounterK *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_CounterK_ACN
int Decode_ACN_CounterK(asn1SccCounterK *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_CounterK_NATIVE
int Decode_NATIVE_CounterK(asn1SccCounterK *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Time_UNIX_UPER
int Encode_UPER_Time_UNIX(void *pBuffer, size_t iMaxBufferSize, const asn1SccTime_UNIX *pSrc);
#endif

#ifdef __NEED_Time_UNIX_ACN
int Encode_ACN_Time_UNIX(void *pBuffer, size_t iMaxBufferSize, asn1SccTime_UNIX *pSrc);
#endif

#ifdef __NEED_Time_UNIX_NATIVE
int Encode_NATIVE_Time_UNIX(void *pBuffer, size_t iMaxBufferSize, const asn1SccTime_UNIX *pSrc);
#endif

#ifdef __NEED_Time_UNIX_UPER
int Decode_UPER_Time_UNIX(asn1SccTime_UNIX *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Time_UNIX_ACN
int Decode_ACN_Time_UNIX(asn1SccTime_UNIX *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Time_UNIX_NATIVE
int Decode_NATIVE_Time_UNIX(asn1SccTime_UNIX *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Latitude_WGS84_UPER
int Encode_UPER_Latitude_WGS84(void *pBuffer, size_t iMaxBufferSize, const asn1SccLatitude_WGS84 *pSrc);
#endif

#ifdef __NEED_Latitude_WGS84_ACN
int Encode_ACN_Latitude_WGS84(void *pBuffer, size_t iMaxBufferSize, asn1SccLatitude_WGS84 *pSrc);
#endif

#ifdef __NEED_Latitude_WGS84_NATIVE
int Encode_NATIVE_Latitude_WGS84(void *pBuffer, size_t iMaxBufferSize, const asn1SccLatitude_WGS84 *pSrc);
#endif

#ifdef __NEED_Latitude_WGS84_UPER
int Decode_UPER_Latitude_WGS84(asn1SccLatitude_WGS84 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Latitude_WGS84_ACN
int Decode_ACN_Latitude_WGS84(asn1SccLatitude_WGS84 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Latitude_WGS84_NATIVE
int Decode_NATIVE_Latitude_WGS84(asn1SccLatitude_WGS84 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Longitude_WGS84_UPER
int Encode_UPER_Longitude_WGS84(void *pBuffer, size_t iMaxBufferSize, const asn1SccLongitude_WGS84 *pSrc);
#endif

#ifdef __NEED_Longitude_WGS84_ACN
int Encode_ACN_Longitude_WGS84(void *pBuffer, size_t iMaxBufferSize, asn1SccLongitude_WGS84 *pSrc);
#endif

#ifdef __NEED_Longitude_WGS84_NATIVE
int Encode_NATIVE_Longitude_WGS84(void *pBuffer, size_t iMaxBufferSize, const asn1SccLongitude_WGS84 *pSrc);
#endif

#ifdef __NEED_Longitude_WGS84_UPER
int Decode_UPER_Longitude_WGS84(asn1SccLongitude_WGS84 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Longitude_WGS84_ACN
int Decode_ACN_Longitude_WGS84(asn1SccLongitude_WGS84 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Longitude_WGS84_NATIVE
int Decode_NATIVE_Longitude_WGS84(asn1SccLongitude_WGS84 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Location_UPER
int Encode_UPER_Location(void *pBuffer, size_t iMaxBufferSize, const asn1SccLocation *pSrc);
#endif

#ifdef __NEED_Location_ACN
int Encode_ACN_Location(void *pBuffer, size_t iMaxBufferSize, asn1SccLocation *pSrc);
#endif

#ifdef __NEED_Location_NATIVE
int Encode_NATIVE_Location(void *pBuffer, size_t iMaxBufferSize, const asn1SccLocation *pSrc);
#endif

#ifdef __NEED_Location_UPER
int Decode_UPER_Location(asn1SccLocation *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Location_ACN
int Decode_ACN_Location(asn1SccLocation *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Location_NATIVE
int Decode_NATIVE_Location(asn1SccLocation *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Location_Fix_Packet_UPER
int Encode_UPER_Location_Fix_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccLocation_Fix_Packet *pSrc);
#endif

#ifdef __NEED_Location_Fix_Packet_ACN
int Encode_ACN_Location_Fix_Packet(void *pBuffer, size_t iMaxBufferSize, asn1SccLocation_Fix_Packet *pSrc);
#endif

#ifdef __NEED_Location_Fix_Packet_NATIVE
int Encode_NATIVE_Location_Fix_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccLocation_Fix_Packet *pSrc);
#endif

#ifdef __NEED_Location_Fix_Packet_UPER
int Decode_UPER_Location_Fix_Packet(asn1SccLocation_Fix_Packet *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Location_Fix_Packet_ACN
int Decode_ACN_Location_Fix_Packet(asn1SccLocation_Fix_Packet *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Location_Fix_Packet_NATIVE
int Decode_NATIVE_Location_Fix_Packet(asn1SccLocation_Fix_Packet *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Temperature_Generic_UPER
int Encode_UPER_Temperature_Generic(void *pBuffer, size_t iMaxBufferSize, const asn1SccTemperature_Generic *pSrc);
#endif

#ifdef __NEED_Temperature_Generic_ACN
int Encode_ACN_Temperature_Generic(void *pBuffer, size_t iMaxBufferSize, asn1SccTemperature_Generic *pSrc);
#endif

#ifdef __NEED_Temperature_Generic_NATIVE
int Encode_NATIVE_Temperature_Generic(void *pBuffer, size_t iMaxBufferSize, const asn1SccTemperature_Generic *pSrc);
#endif

#ifdef __NEED_Temperature_Generic_UPER
int Decode_UPER_Temperature_Generic(asn1SccTemperature_Generic *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Temperature_Generic_ACN
int Decode_ACN_Temperature_Generic(asn1SccTemperature_Generic *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Temperature_Generic_NATIVE
int Decode_NATIVE_Temperature_Generic(asn1SccTemperature_Generic *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Deployment_Digital_UPER
int Encode_UPER_Deployment_Digital(void *pBuffer, size_t iMaxBufferSize, const asn1SccDeployment_Digital *pSrc);
#endif

#ifdef __NEED_Deployment_Digital_ACN
int Encode_ACN_Deployment_Digital(void *pBuffer, size_t iMaxBufferSize, asn1SccDeployment_Digital *pSrc);
#endif

#ifdef __NEED_Deployment_Digital_NATIVE
int Encode_NATIVE_Deployment_Digital(void *pBuffer, size_t iMaxBufferSize, const asn1SccDeployment_Digital *pSrc);
#endif

#ifdef __NEED_Deployment_Digital_UPER
int Decode_UPER_Deployment_Digital(asn1SccDeployment_Digital *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Deployment_Digital_ACN
int Decode_ACN_Deployment_Digital(asn1SccDeployment_Digital *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Deployment_Digital_NATIVE
int Decode_NATIVE_Deployment_Digital(asn1SccDeployment_Digital *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Deployment_Analogue_UPER
int Encode_UPER_Deployment_Analogue(void *pBuffer, size_t iMaxBufferSize, const asn1SccDeployment_Analogue *pSrc);
#endif

#ifdef __NEED_Deployment_Analogue_ACN
int Encode_ACN_Deployment_Analogue(void *pBuffer, size_t iMaxBufferSize, asn1SccDeployment_Analogue *pSrc);
#endif

#ifdef __NEED_Deployment_Analogue_NATIVE
int Encode_NATIVE_Deployment_Analogue(void *pBuffer, size_t iMaxBufferSize, const asn1SccDeployment_Analogue *pSrc);
#endif

#ifdef __NEED_Deployment_Analogue_UPER
int Decode_UPER_Deployment_Analogue(asn1SccDeployment_Analogue *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Deployment_Analogue_ACN
int Decode_ACN_Deployment_Analogue(asn1SccDeployment_Analogue *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Deployment_Analogue_NATIVE
int Decode_NATIVE_Deployment_Analogue(asn1SccDeployment_Analogue *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_System_Mode_UPER
int Encode_UPER_System_Mode(void *pBuffer, size_t iMaxBufferSize, const asn1SccSystem_Mode *pSrc);
#endif

#ifdef __NEED_System_Mode_ACN
int Encode_ACN_System_Mode(void *pBuffer, size_t iMaxBufferSize, asn1SccSystem_Mode *pSrc);
#endif

#ifdef __NEED_System_Mode_NATIVE
int Encode_NATIVE_System_Mode(void *pBuffer, size_t iMaxBufferSize, const asn1SccSystem_Mode *pSrc);
#endif

#ifdef __NEED_System_Mode_UPER
int Decode_UPER_System_Mode(asn1SccSystem_Mode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_System_Mode_ACN
int Decode_ACN_System_Mode(asn1SccSystem_Mode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_System_Mode_NATIVE
int Decode_NATIVE_System_Mode(asn1SccSystem_Mode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Subsystem_Address_UPER
int Encode_UPER_Subsystem_Address(void *pBuffer, size_t iMaxBufferSize, const asn1SccSubsystem_Address *pSrc);
#endif

#ifdef __NEED_Subsystem_Address_ACN
int Encode_ACN_Subsystem_Address(void *pBuffer, size_t iMaxBufferSize, asn1SccSubsystem_Address *pSrc);
#endif

#ifdef __NEED_Subsystem_Address_NATIVE
int Encode_NATIVE_Subsystem_Address(void *pBuffer, size_t iMaxBufferSize, const asn1SccSubsystem_Address *pSrc);
#endif

#ifdef __NEED_Subsystem_Address_UPER
int Decode_UPER_Subsystem_Address(asn1SccSubsystem_Address *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Subsystem_Address_ACN
int Decode_ACN_Subsystem_Address(asn1SccSubsystem_Address *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Subsystem_Address_NATIVE
int Decode_NATIVE_Subsystem_Address(asn1SccSubsystem_Address *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Mode_Change_Packet_UPER
int Encode_UPER_Mode_Change_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccMode_Change_Packet *pSrc);
#endif

#ifdef __NEED_Mode_Change_Packet_ACN
int Encode_ACN_Mode_Change_Packet(void *pBuffer, size_t iMaxBufferSize, asn1SccMode_Change_Packet *pSrc);
#endif

#ifdef __NEED_Mode_Change_Packet_NATIVE
int Encode_NATIVE_Mode_Change_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccMode_Change_Packet *pSrc);
#endif

#ifdef __NEED_Mode_Change_Packet_UPER
int Decode_UPER_Mode_Change_Packet(asn1SccMode_Change_Packet *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Mode_Change_Packet_ACN
int Decode_ACN_Mode_Change_Packet(asn1SccMode_Change_Packet *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Mode_Change_Packet_NATIVE
int Decode_NATIVE_Mode_Change_Packet(asn1SccMode_Change_Packet *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_UPER
int Encode_UPER_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc);
#endif

#ifdef __NEED_PID_ACN
int Encode_ACN_PID(void *pBuffer, size_t iMaxBufferSize, asn1SccPID *pSrc);
#endif

#ifdef __NEED_PID_NATIVE
int Encode_NATIVE_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc);
#endif

#ifdef __NEED_PID_UPER
int Decode_UPER_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_ACN
int Decode_ACN_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PID_NATIVE
int Decode_NATIVE_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize);
#endif


#endif
