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

#ifdef __NEED_DmtNull_UPER
int Encode_UPER_DmtNull(void *pBuffer, size_t iMaxBufferSize, const asn1SccDmtNull *pSrc);
#endif

#ifdef __NEED_DmtNull_ACN
int Encode_ACN_DmtNull(void *pBuffer, size_t iMaxBufferSize, asn1SccDmtNull *pSrc);
#endif

#ifdef __NEED_DmtNull_NATIVE
int Encode_NATIVE_DmtNull(void *pBuffer, size_t iMaxBufferSize, const asn1SccDmtNull *pSrc);
#endif

#ifdef __NEED_DmtNull_UPER
int Decode_UPER_DmtNull(asn1SccDmtNull *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DmtNull_ACN
int Decode_ACN_DmtNull(asn1SccDmtNull *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DmtNull_NATIVE
int Decode_NATIVE_DmtNull(asn1SccDmtNull *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Headerless_Telemetries_UPER
int Encode_UPER_Headerless_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeaderless_Telemetries *pSrc);
#endif

#ifdef __NEED_Headerless_Telemetries_ACN
int Encode_ACN_Headerless_Telemetries(void *pBuffer, size_t iMaxBufferSize, asn1SccHeaderless_Telemetries *pSrc);
#endif

#ifdef __NEED_Headerless_Telemetries_NATIVE
int Encode_NATIVE_Headerless_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeaderless_Telemetries *pSrc);
#endif

#ifdef __NEED_Headerless_Telemetries_UPER
int Decode_UPER_Headerless_Telemetries(asn1SccHeaderless_Telemetries *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Headerless_Telemetries_ACN
int Decode_ACN_Headerless_Telemetries(asn1SccHeaderless_Telemetries *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Headerless_Telemetries_NATIVE
int Decode_NATIVE_Headerless_Telemetries(asn1SccHeaderless_Telemetries *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TYPE_ID_UPER
int Encode_UPER_TYPE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccTYPE_ID *pSrc);
#endif

#ifdef __NEED_TYPE_ID_ACN
int Encode_ACN_TYPE_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccTYPE_ID *pSrc);
#endif

#ifdef __NEED_TYPE_ID_NATIVE
int Encode_NATIVE_TYPE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccTYPE_ID *pSrc);
#endif

#ifdef __NEED_TYPE_ID_UPER
int Decode_UPER_TYPE_ID(asn1SccTYPE_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TYPE_ID_ACN
int Decode_ACN_TYPE_ID(asn1SccTYPE_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TYPE_ID_NATIVE
int Decode_NATIVE_TYPE_ID(asn1SccTYPE_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REQUEST_ID_UPER
int Encode_UPER_REQUEST_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccREQUEST_ID *pSrc);
#endif

#ifdef __NEED_REQUEST_ID_ACN
int Encode_ACN_REQUEST_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccREQUEST_ID *pSrc);
#endif

#ifdef __NEED_REQUEST_ID_NATIVE
int Encode_NATIVE_REQUEST_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccREQUEST_ID *pSrc);
#endif

#ifdef __NEED_REQUEST_ID_UPER
int Decode_UPER_REQUEST_ID(asn1SccREQUEST_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REQUEST_ID_ACN
int Decode_ACN_REQUEST_ID(asn1SccREQUEST_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REQUEST_ID_NATIVE
int Decode_NATIVE_REQUEST_ID(asn1SccREQUEST_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_UPER
int Encode_UPER_SuccessfulStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_ACN
int Encode_ACN_SuccessfulStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_NATIVE
int Encode_NATIVE_SuccessfulStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_UPER
int Decode_UPER_SuccessfulStartOfExecutionNotificationNotification_Type(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_ACN
int Decode_ACN_SuccessfulStartOfExecutionNotificationNotification_Type(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_NATIVE
int Decode_NATIVE_SuccessfulStartOfExecutionNotificationNotification_Type(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_UPER
int Encode_UPER_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pSrc);
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_ACN
int Encode_ACN_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pSrc);
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_NATIVE
int Encode_NATIVE_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pSrc);
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_UPER
int Decode_UPER_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_ACN
int Decode_ACN_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_NATIVE
int Decode_NATIVE_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_UPER
int Encode_UPER_FAILURE_NOTICE_CODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_CODE *pSrc);
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_ACN
int Encode_ACN_FAILURE_NOTICE_CODE(void *pBuffer, size_t iMaxBufferSize, asn1SccFAILURE_NOTICE_CODE *pSrc);
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_NATIVE
int Encode_NATIVE_FAILURE_NOTICE_CODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_CODE *pSrc);
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_UPER
int Decode_UPER_FAILURE_NOTICE_CODE(asn1SccFAILURE_NOTICE_CODE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_ACN
int Decode_ACN_FAILURE_NOTICE_CODE(asn1SccFAILURE_NOTICE_CODE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_NATIVE
int Decode_NATIVE_FAILURE_NOTICE_CODE(asn1SccFAILURE_NOTICE_CODE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_UPER
int Encode_UPER_ON_OFF_DEVICE_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccON_OFF_DEVICE_ADDRESS *pSrc);
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_ACN
int Encode_ACN_ON_OFF_DEVICE_ADDRESS(void *pBuffer, size_t iMaxBufferSize, asn1SccON_OFF_DEVICE_ADDRESS *pSrc);
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_NATIVE
int Encode_NATIVE_ON_OFF_DEVICE_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccON_OFF_DEVICE_ADDRESS *pSrc);
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_UPER
int Decode_UPER_ON_OFF_DEVICE_ADDRESS(asn1SccON_OFF_DEVICE_ADDRESS *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_ACN
int Decode_ACN_ON_OFF_DEVICE_ADDRESS(asn1SccON_OFF_DEVICE_ADDRESS *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_NATIVE
int Decode_NATIVE_ON_OFF_DEVICE_ADDRESS(asn1SccON_OFF_DEVICE_ADDRESS *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_UPER
int Encode_UPER_DistributeAnOnoffDeviceCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeAnOnoffDeviceCommand_Type *pSrc);
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_ACN
int Encode_ACN_DistributeAnOnoffDeviceCommand_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccDistributeAnOnoffDeviceCommand_Type *pSrc);
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_NATIVE
int Encode_NATIVE_DistributeAnOnoffDeviceCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeAnOnoffDeviceCommand_Type *pSrc);
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_UPER
int Decode_UPER_DistributeAnOnoffDeviceCommand_Type(asn1SccDistributeAnOnoffDeviceCommand_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_ACN
int Decode_ACN_DistributeAnOnoffDeviceCommand_Type(asn1SccDistributeAnOnoffDeviceCommand_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_NATIVE
int Decode_NATIVE_DistributeAnOnoffDeviceCommand_Type(asn1SccDistributeAnOnoffDeviceCommand_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_UPER
int Encode_UPER_TC_2_1_DistributeOnoffDeviceCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pSrc);
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_ACN
int Encode_ACN_TC_2_1_DistributeOnoffDeviceCommands_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pSrc);
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_NATIVE
int Encode_NATIVE_TC_2_1_DistributeOnoffDeviceCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pSrc);
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_UPER
int Decode_UPER_TC_2_1_DistributeOnoffDeviceCommands_Type(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_ACN
int Decode_ACN_TC_2_1_DistributeOnoffDeviceCommands_Type(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_NATIVE
int Decode_NATIVE_TC_2_1_DistributeOnoffDeviceCommands_Type(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REGISTER_ADDRESS_UPER
int Encode_UPER_REGISTER_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_ADDRESS *pSrc);
#endif

#ifdef __NEED_REGISTER_ADDRESS_ACN
int Encode_ACN_REGISTER_ADDRESS(void *pBuffer, size_t iMaxBufferSize, asn1SccREGISTER_ADDRESS *pSrc);
#endif

#ifdef __NEED_REGISTER_ADDRESS_NATIVE
int Encode_NATIVE_REGISTER_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_ADDRESS *pSrc);
#endif

#ifdef __NEED_REGISTER_ADDRESS_UPER
int Decode_UPER_REGISTER_ADDRESS(asn1SccREGISTER_ADDRESS *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REGISTER_ADDRESS_ACN
int Decode_ACN_REGISTER_ADDRESS(asn1SccREGISTER_ADDRESS *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REGISTER_ADDRESS_NATIVE
int Decode_NATIVE_REGISTER_ADDRESS(asn1SccREGISTER_ADDRESS *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_UPER
int Encode_UPER_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pSrc);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_ACN
int Encode_ACN_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pSrc);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_NATIVE
int Encode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pSrc);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_UPER
int Decode_UPER_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_ACN
int Decode_ACN_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_NATIVE
int Decode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PI_COEFFICIENT_UPER
int Encode_UPER_PI_COEFFICIENT(void *pBuffer, size_t iMaxBufferSize, const asn1SccPI_COEFFICIENT *pSrc);
#endif

#ifdef __NEED_PI_COEFFICIENT_ACN
int Encode_ACN_PI_COEFFICIENT(void *pBuffer, size_t iMaxBufferSize, asn1SccPI_COEFFICIENT *pSrc);
#endif

#ifdef __NEED_PI_COEFFICIENT_NATIVE
int Encode_NATIVE_PI_COEFFICIENT(void *pBuffer, size_t iMaxBufferSize, const asn1SccPI_COEFFICIENT *pSrc);
#endif

#ifdef __NEED_PI_COEFFICIENT_UPER
int Decode_UPER_PI_COEFFICIENT(asn1SccPI_COEFFICIENT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PI_COEFFICIENT_ACN
int Decode_ACN_PI_COEFFICIENT(asn1SccPI_COEFFICIENT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PI_COEFFICIENT_NATIVE
int Decode_NATIVE_PI_COEFFICIENT(asn1SccPI_COEFFICIENT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UINT8T_UPER
int Encode_UPER_UINT8T(void *pBuffer, size_t iMaxBufferSize, const asn1SccUINT8T *pSrc);
#endif

#ifdef __NEED_UINT8T_ACN
int Encode_ACN_UINT8T(void *pBuffer, size_t iMaxBufferSize, asn1SccUINT8T *pSrc);
#endif

#ifdef __NEED_UINT8T_NATIVE
int Encode_NATIVE_UINT8T(void *pBuffer, size_t iMaxBufferSize, const asn1SccUINT8T *pSrc);
#endif

#ifdef __NEED_UINT8T_UPER
int Decode_UPER_UINT8T(asn1SccUINT8T *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UINT8T_ACN
int Decode_ACN_UINT8T(asn1SccUINT8T *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UINT8T_NATIVE
int Decode_NATIVE_UINT8T(asn1SccUINT8T *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REGISTER_DATA_UPER
int Encode_UPER_REGISTER_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_DATA *pSrc);
#endif

#ifdef __NEED_REGISTER_DATA_ACN
int Encode_ACN_REGISTER_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccREGISTER_DATA *pSrc);
#endif

#ifdef __NEED_REGISTER_DATA_NATIVE
int Encode_NATIVE_REGISTER_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_DATA *pSrc);
#endif

#ifdef __NEED_REGISTER_DATA_UPER
int Decode_UPER_REGISTER_DATA(asn1SccREGISTER_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REGISTER_DATA_ACN
int Decode_ACN_REGISTER_DATA(asn1SccREGISTER_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_REGISTER_DATA_NATIVE
int Decode_NATIVE_REGISTER_DATA(asn1SccREGISTER_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_UPER
int Encode_UPER_DistributeARegisterLoadCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeARegisterLoadCommand_Type *pSrc);
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_ACN
int Encode_ACN_DistributeARegisterLoadCommand_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccDistributeARegisterLoadCommand_Type *pSrc);
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_NATIVE
int Encode_NATIVE_DistributeARegisterLoadCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeARegisterLoadCommand_Type *pSrc);
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_UPER
int Decode_UPER_DistributeARegisterLoadCommand_Type(asn1SccDistributeARegisterLoadCommand_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_ACN
int Decode_ACN_DistributeARegisterLoadCommand_Type(asn1SccDistributeARegisterLoadCommand_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_NATIVE
int Decode_NATIVE_DistributeARegisterLoadCommand_Type(asn1SccDistributeARegisterLoadCommand_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_UPER
int Encode_UPER_TC_2_2_DistributeRegisterLoadCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pSrc);
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_ACN
int Encode_ACN_TC_2_2_DistributeRegisterLoadCommands_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pSrc);
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_NATIVE
int Encode_NATIVE_TC_2_2_DistributeRegisterLoadCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pSrc);
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_UPER
int Decode_UPER_TC_2_2_DistributeRegisterLoadCommands_Type(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_ACN
int Decode_ACN_TC_2_2_DistributeRegisterLoadCommands_Type(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_NATIVE
int Decode_NATIVE_TC_2_2_DistributeRegisterLoadCommands_Type(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DUTY_CYCLE_UPER
int Encode_UPER_DUTY_CYCLE(void *pBuffer, size_t iMaxBufferSize, const asn1SccDUTY_CYCLE *pSrc);
#endif

#ifdef __NEED_DUTY_CYCLE_ACN
int Encode_ACN_DUTY_CYCLE(void *pBuffer, size_t iMaxBufferSize, asn1SccDUTY_CYCLE *pSrc);
#endif

#ifdef __NEED_DUTY_CYCLE_NATIVE
int Encode_NATIVE_DUTY_CYCLE(void *pBuffer, size_t iMaxBufferSize, const asn1SccDUTY_CYCLE *pSrc);
#endif

#ifdef __NEED_DUTY_CYCLE_UPER
int Decode_UPER_DUTY_CYCLE(asn1SccDUTY_CYCLE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DUTY_CYCLE_ACN
int Decode_ACN_DUTY_CYCLE(asn1SccDUTY_CYCLE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_DUTY_CYCLE_NATIVE
int Decode_NATIVE_DUTY_CYCLE(asn1SccDUTY_CYCLE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SATELLITE_MODE_UPER
int Encode_UPER_SATELLITE_MODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccSATELLITE_MODE *pSrc);
#endif

#ifdef __NEED_SATELLITE_MODE_ACN
int Encode_ACN_SATELLITE_MODE(void *pBuffer, size_t iMaxBufferSize, asn1SccSATELLITE_MODE *pSrc);
#endif

#ifdef __NEED_SATELLITE_MODE_NATIVE
int Encode_NATIVE_SATELLITE_MODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccSATELLITE_MODE *pSrc);
#endif

#ifdef __NEED_SATELLITE_MODE_UPER
int Decode_UPER_SATELLITE_MODE(asn1SccSATELLITE_MODE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SATELLITE_MODE_ACN
int Decode_ACN_SATELLITE_MODE(asn1SccSATELLITE_MODE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SATELLITE_MODE_NATIVE
int Decode_NATIVE_SATELLITE_MODE(asn1SccSATELLITE_MODE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SwitchMode_Type_UPER
int Encode_UPER_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSwitchMode_Type *pSrc);
#endif

#ifdef __NEED_SwitchMode_Type_ACN
int Encode_ACN_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSwitchMode_Type *pSrc);
#endif

#ifdef __NEED_SwitchMode_Type_NATIVE
int Encode_NATIVE_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSwitchMode_Type *pSrc);
#endif

#ifdef __NEED_SwitchMode_Type_UPER
int Decode_UPER_SwitchMode_Type(asn1SccSwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SwitchMode_Type_ACN
int Decode_ACN_SwitchMode_Type(asn1SccSwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SwitchMode_Type_NATIVE
int Decode_NATIVE_SwitchMode_Type(asn1SccSwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_UPER
int Encode_UPER_TC_222_1_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_1_SwitchMode_Type *pSrc);
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_ACN
int Encode_ACN_TC_222_1_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_222_1_SwitchMode_Type *pSrc);
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_NATIVE
int Encode_NATIVE_TC_222_1_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_1_SwitchMode_Type *pSrc);
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_UPER
int Decode_UPER_TC_222_1_SwitchMode_Type(asn1SccTC_222_1_SwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_ACN
int Decode_ACN_TC_222_1_SwitchMode_Type(asn1SccTC_222_1_SwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_NATIVE
int Decode_NATIVE_TC_222_1_SwitchMode_Type(asn1SccTC_222_1_SwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_VOLTAGE_UPER
int Encode_UPER_VOLTAGE(void *pBuffer, size_t iMaxBufferSize, const asn1SccVOLTAGE *pSrc);
#endif

#ifdef __NEED_VOLTAGE_ACN
int Encode_ACN_VOLTAGE(void *pBuffer, size_t iMaxBufferSize, asn1SccVOLTAGE *pSrc);
#endif

#ifdef __NEED_VOLTAGE_NATIVE
int Encode_NATIVE_VOLTAGE(void *pBuffer, size_t iMaxBufferSize, const asn1SccVOLTAGE *pSrc);
#endif

#ifdef __NEED_VOLTAGE_UPER
int Decode_UPER_VOLTAGE(asn1SccVOLTAGE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_VOLTAGE_ACN
int Decode_ACN_VOLTAGE(asn1SccVOLTAGE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_VOLTAGE_NATIVE
int Decode_NATIVE_VOLTAGE(asn1SccVOLTAGE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_UPER
int Encode_UPER_FAILURE_NOTICE_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_DATA *pSrc);
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_ACN
int Encode_ACN_FAILURE_NOTICE_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccFAILURE_NOTICE_DATA *pSrc);
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_NATIVE
int Encode_NATIVE_FAILURE_NOTICE_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_DATA *pSrc);
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_UPER
int Decode_UPER_FAILURE_NOTICE_DATA(asn1SccFAILURE_NOTICE_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_ACN
int Decode_ACN_FAILURE_NOTICE_DATA(asn1SccFAILURE_NOTICE_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_NATIVE
int Decode_NATIVE_FAILURE_NOTICE_DATA(asn1SccFAILURE_NOTICE_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_UPER
int Encode_UPER_FailedStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccFailedStartOfExecutionNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_ACN
int Encode_ACN_FailedStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccFailedStartOfExecutionNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_NATIVE
int Encode_NATIVE_FailedStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccFailedStartOfExecutionNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_UPER
int Decode_UPER_FailedStartOfExecutionNotificationNotification_Type(asn1SccFailedStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_ACN
int Decode_ACN_FailedStartOfExecutionNotificationNotification_Type(asn1SccFailedStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_NATIVE
int Decode_NATIVE_FailedStartOfExecutionNotificationNotification_Type(asn1SccFailedStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_UPER
int Encode_UPER_TM_1_4_FailedStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pSrc);
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_ACN
int Encode_ACN_TM_1_4_FailedStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pSrc);
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_NATIVE
int Encode_NATIVE_TM_1_4_FailedStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pSrc);
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_UPER
int Decode_UPER_TM_1_4_FailedStartOfExecutionVerificationReport_Type(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_ACN
int Decode_ACN_TM_1_4_FailedStartOfExecutionVerificationReport_Type(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_NATIVE
int Decode_NATIVE_TM_1_4_FailedStartOfExecutionVerificationReport_Type(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_UPER
int Encode_UPER_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetSafeThresholdVoltage_Type *pSrc);
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_ACN
int Encode_ACN_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSetSafeThresholdVoltage_Type *pSrc);
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_NATIVE
int Encode_NATIVE_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetSafeThresholdVoltage_Type *pSrc);
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_UPER
int Decode_UPER_SetSafeThresholdVoltage_Type(asn1SccSetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_ACN
int Decode_ACN_SetSafeThresholdVoltage_Type(asn1SccSetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_NATIVE
int Decode_NATIVE_SetSafeThresholdVoltage_Type(asn1SccSetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_UPER
int Encode_UPER_TC_222_11_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pSrc);
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_ACN
int Encode_ACN_TC_222_11_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pSrc);
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_NATIVE
int Encode_NATIVE_TC_222_11_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pSrc);
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_UPER
int Decode_UPER_TC_222_11_SetSafeThresholdVoltage_Type(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_ACN
int Decode_ACN_TC_222_11_SetSafeThresholdVoltage_Type(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_NATIVE
int Decode_NATIVE_TC_222_11_SetSafeThresholdVoltage_Type(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TEMPERATURE_UPER
int Encode_UPER_TEMPERATURE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE *pSrc);
#endif

#ifdef __NEED_TEMPERATURE_ACN
int Encode_ACN_TEMPERATURE(void *pBuffer, size_t iMaxBufferSize, asn1SccTEMPERATURE *pSrc);
#endif

#ifdef __NEED_TEMPERATURE_NATIVE
int Encode_NATIVE_TEMPERATURE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE *pSrc);
#endif

#ifdef __NEED_TEMPERATURE_UPER
int Decode_UPER_TEMPERATURE(asn1SccTEMPERATURE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TEMPERATURE_ACN
int Decode_ACN_TEMPERATURE(asn1SccTEMPERATURE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TEMPERATURE_NATIVE
int Decode_NATIVE_TEMPERATURE(asn1SccTEMPERATURE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_UPER
int Encode_UPER_HOUSEKEEPING_PARAMETER_REPORT_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pSrc);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_ACN
int Encode_ACN_HOUSEKEEPING_PARAMETER_REPORT_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pSrc);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_NATIVE
int Encode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pSrc);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_UPER
int Decode_UPER_HOUSEKEEPING_PARAMETER_REPORT_DATA(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_ACN
int Decode_ACN_HOUSEKEEPING_PARAMETER_REPORT_DATA(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_NATIVE
int Decode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_DATA(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_UPER
int Encode_UPER_HousekeepingParameterNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccHousekeepingParameterNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_ACN
int Encode_ACN_HousekeepingParameterNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccHousekeepingParameterNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_NATIVE
int Encode_NATIVE_HousekeepingParameterNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccHousekeepingParameterNotificationNotification_Type *pSrc);
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_UPER
int Decode_UPER_HousekeepingParameterNotificationNotification_Type(asn1SccHousekeepingParameterNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_ACN
int Decode_ACN_HousekeepingParameterNotificationNotification_Type(asn1SccHousekeepingParameterNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_NATIVE
int Decode_NATIVE_HousekeepingParameterNotificationNotification_Type(asn1SccHousekeepingParameterNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_UPER
int Encode_UPER_TM_3_25_HousekeepingParameterReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_3_25_HousekeepingParameterReport_Type *pSrc);
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_ACN
int Encode_ACN_TM_3_25_HousekeepingParameterReport_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTM_3_25_HousekeepingParameterReport_Type *pSrc);
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_NATIVE
int Encode_NATIVE_TM_3_25_HousekeepingParameterReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_3_25_HousekeepingParameterReport_Type *pSrc);
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_UPER
int Decode_UPER_TM_3_25_HousekeepingParameterReport_Type(asn1SccTM_3_25_HousekeepingParameterReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_ACN
int Decode_ACN_TM_3_25_HousekeepingParameterReport_Type(asn1SccTM_3_25_HousekeepingParameterReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_NATIVE
int Decode_NATIVE_TM_3_25_HousekeepingParameterReport_Type(asn1SccTM_3_25_HousekeepingParameterReport_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Regular_Telemetries_UPER
int Encode_UPER_Regular_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccRegular_Telemetries *pSrc);
#endif

#ifdef __NEED_Regular_Telemetries_ACN
int Encode_ACN_Regular_Telemetries(void *pBuffer, size_t iMaxBufferSize, asn1SccRegular_Telemetries *pSrc);
#endif

#ifdef __NEED_Regular_Telemetries_NATIVE
int Encode_NATIVE_Regular_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccRegular_Telemetries *pSrc);
#endif

#ifdef __NEED_Regular_Telemetries_UPER
int Decode_UPER_Regular_Telemetries(asn1SccRegular_Telemetries *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Regular_Telemetries_ACN
int Decode_ACN_Regular_Telemetries(asn1SccRegular_Telemetries *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Regular_Telemetries_NATIVE
int Decode_NATIVE_Regular_Telemetries(asn1SccRegular_Telemetries *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telemetry_UPER
int Encode_UPER_Telemetry(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelemetry *pSrc);
#endif

#ifdef __NEED_Telemetry_ACN
int Encode_ACN_Telemetry(void *pBuffer, size_t iMaxBufferSize, asn1SccTelemetry *pSrc);
#endif

#ifdef __NEED_Telemetry_NATIVE
int Encode_NATIVE_Telemetry(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelemetry *pSrc);
#endif

#ifdef __NEED_Telemetry_UPER
int Decode_UPER_Telemetry(asn1SccTelemetry *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telemetry_ACN
int Decode_ACN_Telemetry(asn1SccTelemetry *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telemetry_NATIVE
int Decode_NATIVE_Telemetry(asn1SccTelemetry *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SetThermalControlParameters_Type_UPER
int Encode_UPER_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetThermalControlParameters_Type *pSrc);
#endif

#ifdef __NEED_SetThermalControlParameters_Type_ACN
int Encode_ACN_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSetThermalControlParameters_Type *pSrc);
#endif

#ifdef __NEED_SetThermalControlParameters_Type_NATIVE
int Encode_NATIVE_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetThermalControlParameters_Type *pSrc);
#endif

#ifdef __NEED_SetThermalControlParameters_Type_UPER
int Decode_UPER_SetThermalControlParameters_Type(asn1SccSetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SetThermalControlParameters_Type_ACN
int Decode_ACN_SetThermalControlParameters_Type(asn1SccSetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SetThermalControlParameters_Type_NATIVE
int Decode_NATIVE_SetThermalControlParameters_Type(asn1SccSetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_UPER
int Encode_UPER_TC_222_21_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_21_SetThermalControlParameters_Type *pSrc);
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_ACN
int Encode_ACN_TC_222_21_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_222_21_SetThermalControlParameters_Type *pSrc);
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_NATIVE
int Encode_NATIVE_TC_222_21_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_21_SetThermalControlParameters_Type *pSrc);
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_UPER
int Decode_UPER_TC_222_21_SetThermalControlParameters_Type(asn1SccTC_222_21_SetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_ACN
int Decode_ACN_TC_222_21_SetThermalControlParameters_Type(asn1SccTC_222_21_SetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_NATIVE
int Decode_NATIVE_TC_222_21_SetThermalControlParameters_Type(asn1SccTC_222_21_SetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telecommands_UPER
int Encode_UPER_Telecommands(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommands *pSrc);
#endif

#ifdef __NEED_Telecommands_ACN
int Encode_ACN_Telecommands(void *pBuffer, size_t iMaxBufferSize, asn1SccTelecommands *pSrc);
#endif

#ifdef __NEED_Telecommands_NATIVE
int Encode_NATIVE_Telecommands(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommands *pSrc);
#endif

#ifdef __NEED_Telecommands_UPER
int Decode_UPER_Telecommands(asn1SccTelecommands *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telecommands_ACN
int Decode_ACN_Telecommands(asn1SccTelecommands *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telecommands_NATIVE
int Decode_NATIVE_Telecommands(asn1SccTelecommands *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telecommand_UPER
int Encode_UPER_Telecommand(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommand *pSrc);
#endif

#ifdef __NEED_Telecommand_ACN
int Encode_ACN_Telecommand(void *pBuffer, size_t iMaxBufferSize, asn1SccTelecommand *pSrc);
#endif

#ifdef __NEED_Telecommand_NATIVE
int Encode_NATIVE_Telecommand(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommand *pSrc);
#endif

#ifdef __NEED_Telecommand_UPER
int Decode_UPER_Telecommand(asn1SccTelecommand *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telecommand_ACN
int Decode_ACN_Telecommand(asn1SccTelecommand *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Telecommand_NATIVE
int Decode_NATIVE_Telecommand(asn1SccTelecommand *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_1_COUNT_UPER
int Encode_UPER_TC_2_1_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_COUNT *pSrc);
#endif

#ifdef __NEED_TC_2_1_COUNT_ACN
int Encode_ACN_TC_2_1_COUNT(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_1_COUNT *pSrc);
#endif

#ifdef __NEED_TC_2_1_COUNT_NATIVE
int Encode_NATIVE_TC_2_1_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_COUNT *pSrc);
#endif

#ifdef __NEED_TC_2_1_COUNT_UPER
int Decode_UPER_TC_2_1_COUNT(asn1SccTC_2_1_COUNT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_1_COUNT_ACN
int Decode_ACN_TC_2_1_COUNT(asn1SccTC_2_1_COUNT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_1_COUNT_NATIVE
int Decode_NATIVE_TC_2_1_COUNT(asn1SccTC_2_1_COUNT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_2_COUNT_UPER
int Encode_UPER_TC_2_2_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_COUNT *pSrc);
#endif

#ifdef __NEED_TC_2_2_COUNT_ACN
int Encode_ACN_TC_2_2_COUNT(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_2_COUNT *pSrc);
#endif

#ifdef __NEED_TC_2_2_COUNT_NATIVE
int Encode_NATIVE_TC_2_2_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_COUNT *pSrc);
#endif

#ifdef __NEED_TC_2_2_COUNT_UPER
int Decode_UPER_TC_2_2_COUNT(asn1SccTC_2_2_COUNT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_2_COUNT_ACN
int Decode_ACN_TC_2_2_COUNT(asn1SccTC_2_2_COUNT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_2_2_COUNT_NATIVE
int Decode_NATIVE_TC_2_2_COUNT(asn1SccTC_2_2_COUNT *pDst, void *pBuffer, size_t iBufferSize);
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

#ifdef __NEED_PAYLOAD_HK_DATA_UPER
int Encode_UPER_PAYLOAD_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccPAYLOAD_HK_DATA *pSrc);
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_ACN
int Encode_ACN_PAYLOAD_HK_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccPAYLOAD_HK_DATA *pSrc);
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_NATIVE
int Encode_NATIVE_PAYLOAD_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccPAYLOAD_HK_DATA *pSrc);
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_UPER
int Decode_UPER_PAYLOAD_HK_DATA(asn1SccPAYLOAD_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_ACN
int Decode_ACN_PAYLOAD_HK_DATA(asn1SccPAYLOAD_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_NATIVE
int Decode_NATIVE_PAYLOAD_HK_DATA(asn1SccPAYLOAD_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MODE_HK_DATA_UPER
int Encode_UPER_MODE_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccMODE_HK_DATA *pSrc);
#endif

#ifdef __NEED_MODE_HK_DATA_ACN
int Encode_ACN_MODE_HK_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccMODE_HK_DATA *pSrc);
#endif

#ifdef __NEED_MODE_HK_DATA_NATIVE
int Encode_NATIVE_MODE_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccMODE_HK_DATA *pSrc);
#endif

#ifdef __NEED_MODE_HK_DATA_UPER
int Decode_UPER_MODE_HK_DATA(asn1SccMODE_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MODE_HK_DATA_ACN
int Decode_ACN_MODE_HK_DATA(asn1SccMODE_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MODE_HK_DATA_NATIVE
int Decode_NATIVE_MODE_HK_DATA(asn1SccMODE_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_THERMAL_HK_DATA_UPER
int Encode_UPER_THERMAL_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccTHERMAL_HK_DATA *pSrc);
#endif

#ifdef __NEED_THERMAL_HK_DATA_ACN
int Encode_ACN_THERMAL_HK_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccTHERMAL_HK_DATA *pSrc);
#endif

#ifdef __NEED_THERMAL_HK_DATA_NATIVE
int Encode_NATIVE_THERMAL_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccTHERMAL_HK_DATA *pSrc);
#endif

#ifdef __NEED_THERMAL_HK_DATA_UPER
int Decode_UPER_THERMAL_HK_DATA(asn1SccTHERMAL_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_THERMAL_HK_DATA_ACN
int Decode_ACN_THERMAL_HK_DATA(asn1SccTHERMAL_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_THERMAL_HK_DATA_NATIVE
int Decode_NATIVE_THERMAL_HK_DATA(asn1SccTHERMAL_HK_DATA *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EXECUTION_REPORT_UPER
int Encode_UPER_EXECUTION_REPORT(void *pBuffer, size_t iMaxBufferSize, const asn1SccEXECUTION_REPORT *pSrc);
#endif

#ifdef __NEED_EXECUTION_REPORT_ACN
int Encode_ACN_EXECUTION_REPORT(void *pBuffer, size_t iMaxBufferSize, asn1SccEXECUTION_REPORT *pSrc);
#endif

#ifdef __NEED_EXECUTION_REPORT_NATIVE
int Encode_NATIVE_EXECUTION_REPORT(void *pBuffer, size_t iMaxBufferSize, const asn1SccEXECUTION_REPORT *pSrc);
#endif

#ifdef __NEED_EXECUTION_REPORT_UPER
int Decode_UPER_EXECUTION_REPORT(asn1SccEXECUTION_REPORT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EXECUTION_REPORT_ACN
int Decode_ACN_EXECUTION_REPORT(asn1SccEXECUTION_REPORT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EXECUTION_REPORT_NATIVE
int Decode_NATIVE_EXECUTION_REPORT(asn1SccEXECUTION_REPORT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_REAL_UPER
int Encode_UPER_T_REAL(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_REAL *pSrc);
#endif

#ifdef __NEED_T_REAL_ACN
int Encode_ACN_T_REAL(void *pBuffer, size_t iMaxBufferSize, asn1SccT_REAL *pSrc);
#endif

#ifdef __NEED_T_REAL_NATIVE
int Encode_NATIVE_T_REAL(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_REAL *pSrc);
#endif

#ifdef __NEED_T_REAL_UPER
int Decode_UPER_T_REAL(asn1SccT_REAL *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_REAL_ACN
int Decode_ACN_T_REAL(asn1SccT_REAL *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_REAL_NATIVE
int Decode_NATIVE_T_REAL(asn1SccT_REAL *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_UPER
int Encode_UPER_TEMPERATURE_DIFFERENCE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE_DIFFERENCE *pSrc);
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_ACN
int Encode_ACN_TEMPERATURE_DIFFERENCE(void *pBuffer, size_t iMaxBufferSize, asn1SccTEMPERATURE_DIFFERENCE *pSrc);
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_NATIVE
int Encode_NATIVE_TEMPERATURE_DIFFERENCE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE_DIFFERENCE *pSrc);
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_UPER
int Decode_UPER_TEMPERATURE_DIFFERENCE(asn1SccTEMPERATURE_DIFFERENCE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_ACN
int Decode_ACN_TEMPERATURE_DIFFERENCE(asn1SccTEMPERATURE_DIFFERENCE *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_NATIVE
int Decode_NATIVE_TEMPERATURE_DIFFERENCE(asn1SccTEMPERATURE_DIFFERENCE *pDst, void *pBuffer, size_t iBufferSize);
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
