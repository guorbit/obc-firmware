#ifdef __unix__
#include <stdio.h>
#include <assert.h>
#endif

#include <string.h>

#include "C_ASN1_Types.h"

#ifdef __NEED_DmtNull_UPER
int Encode_UPER_DmtNull(void *pBuffer, size_t iMaxBufferSize, const asn1SccDmtNull *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDmtNull_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DmtNull (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DmtNull_ACN
int Encode_ACN_DmtNull(void *pBuffer, size_t iMaxBufferSize, asn1SccDmtNull *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDmtNull_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DmtNull (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DmtNull_NATIVE
int Encode_NATIVE_DmtNull(void *pBuffer, size_t iMaxBufferSize, const asn1SccDmtNull *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccDmtNull) );
    return sizeof(asn1SccDmtNull);
}
#endif

#ifdef __NEED_DmtNull_UPER
int Decode_UPER_DmtNull(asn1SccDmtNull *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDmtNull_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DmtNull (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DmtNull_ACN
int Decode_ACN_DmtNull(asn1SccDmtNull *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDmtNull_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DmtNull (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DmtNull_NATIVE
int Decode_NATIVE_DmtNull(asn1SccDmtNull *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccDmtNull *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Headerless_Telemetries_UPER
int Encode_UPER_Headerless_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeaderless_Telemetries *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHeaderless_Telemetries_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Headerless-Telemetries (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Headerless_Telemetries_ACN
int Encode_ACN_Headerless_Telemetries(void *pBuffer, size_t iMaxBufferSize, asn1SccHeaderless_Telemetries *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHeaderless_Telemetries_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Headerless-Telemetries (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Headerless_Telemetries_NATIVE
int Encode_NATIVE_Headerless_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeaderless_Telemetries *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHeaderless_Telemetries) );
    return sizeof(asn1SccHeaderless_Telemetries);
}
#endif

#ifdef __NEED_Headerless_Telemetries_UPER
int Decode_UPER_Headerless_Telemetries(asn1SccHeaderless_Telemetries *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHeaderless_Telemetries_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Headerless-Telemetries (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Headerless_Telemetries_ACN
int Decode_ACN_Headerless_Telemetries(asn1SccHeaderless_Telemetries *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHeaderless_Telemetries_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Headerless-Telemetries (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Headerless_Telemetries_NATIVE
int Decode_NATIVE_Headerless_Telemetries(asn1SccHeaderless_Telemetries *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHeaderless_Telemetries *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TYPE_ID_UPER
int Encode_UPER_TYPE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccTYPE_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTYPE_ID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TYPE-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TYPE_ID_ACN
int Encode_ACN_TYPE_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccTYPE_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTYPE_ID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TYPE-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TYPE_ID_NATIVE
int Encode_NATIVE_TYPE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccTYPE_ID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTYPE_ID) );
    return sizeof(asn1SccTYPE_ID);
}
#endif

#ifdef __NEED_TYPE_ID_UPER
int Decode_UPER_TYPE_ID(asn1SccTYPE_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTYPE_ID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TYPE-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TYPE_ID_ACN
int Decode_ACN_TYPE_ID(asn1SccTYPE_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTYPE_ID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TYPE-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TYPE_ID_NATIVE
int Decode_NATIVE_TYPE_ID(asn1SccTYPE_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTYPE_ID *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_REQUEST_ID_UPER
int Encode_UPER_REQUEST_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccREQUEST_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccREQUEST_ID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode REQUEST-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_REQUEST_ID_ACN
int Encode_ACN_REQUEST_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccREQUEST_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccREQUEST_ID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode REQUEST-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_REQUEST_ID_NATIVE
int Encode_NATIVE_REQUEST_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccREQUEST_ID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccREQUEST_ID) );
    return sizeof(asn1SccREQUEST_ID);
}
#endif

#ifdef __NEED_REQUEST_ID_UPER
int Decode_UPER_REQUEST_ID(asn1SccREQUEST_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccREQUEST_ID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode REQUEST-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_REQUEST_ID_ACN
int Decode_ACN_REQUEST_ID(asn1SccREQUEST_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccREQUEST_ID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode REQUEST-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_REQUEST_ID_NATIVE
int Decode_NATIVE_REQUEST_ID(asn1SccREQUEST_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccREQUEST_ID *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_UPER
int Encode_UPER_SuccessfulStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSuccessfulStartOfExecutionNotificationNotification_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SuccessfulStartOfExecutionNotificationNotification-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_ACN
int Encode_ACN_SuccessfulStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSuccessfulStartOfExecutionNotificationNotification_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SuccessfulStartOfExecutionNotificationNotification-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_NATIVE
int Encode_NATIVE_SuccessfulStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type) );
    return sizeof(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type);
}
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_UPER
int Decode_UPER_SuccessfulStartOfExecutionNotificationNotification_Type(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSuccessfulStartOfExecutionNotificationNotification_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SuccessfulStartOfExecutionNotificationNotification-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_ACN
int Decode_ACN_SuccessfulStartOfExecutionNotificationNotification_Type(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSuccessfulStartOfExecutionNotificationNotification_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SuccessfulStartOfExecutionNotificationNotification-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SuccessfulStartOfExecutionNotificationNotification_Type_NATIVE
int Decode_NATIVE_SuccessfulStartOfExecutionNotificationNotification_Type(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSuccessfulStartOfExecutionNotificationNotification_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_UPER
int Encode_UPER_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TM-1-3-SuccessfulStartOfExecutionVerificationReport-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_ACN
int Encode_ACN_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TM-1-3-SuccessfulStartOfExecutionVerificationReport-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_NATIVE
int Encode_NATIVE_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type) );
    return sizeof(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type);
}
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_UPER
int Decode_UPER_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TM-1-3-SuccessfulStartOfExecutionVerificationReport-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_ACN
int Decode_ACN_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TM-1-3-SuccessfulStartOfExecutionVerificationReport-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type_NATIVE
int Decode_NATIVE_TM_1_3_SuccessfulStartOfExecutionVerificationReport_Type(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTM_1_3_SuccessfulStartOfExecutionVerificationReport_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_UPER
int Encode_UPER_FAILURE_NOTICE_CODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_CODE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFAILURE_NOTICE_CODE_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FAILURE-NOTICE-CODE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_ACN
int Encode_ACN_FAILURE_NOTICE_CODE(void *pBuffer, size_t iMaxBufferSize, asn1SccFAILURE_NOTICE_CODE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFAILURE_NOTICE_CODE_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FAILURE-NOTICE-CODE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_NATIVE
int Encode_NATIVE_FAILURE_NOTICE_CODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_CODE *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccFAILURE_NOTICE_CODE) );
    return sizeof(asn1SccFAILURE_NOTICE_CODE);
}
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_UPER
int Decode_UPER_FAILURE_NOTICE_CODE(asn1SccFAILURE_NOTICE_CODE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFAILURE_NOTICE_CODE_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FAILURE-NOTICE-CODE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_ACN
int Decode_ACN_FAILURE_NOTICE_CODE(asn1SccFAILURE_NOTICE_CODE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFAILURE_NOTICE_CODE_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FAILURE-NOTICE-CODE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_CODE_NATIVE
int Decode_NATIVE_FAILURE_NOTICE_CODE(asn1SccFAILURE_NOTICE_CODE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccFAILURE_NOTICE_CODE *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_UPER
int Encode_UPER_ON_OFF_DEVICE_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccON_OFF_DEVICE_ADDRESS *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccON_OFF_DEVICE_ADDRESS_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ON-OFF-DEVICE-ADDRESS (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_ACN
int Encode_ACN_ON_OFF_DEVICE_ADDRESS(void *pBuffer, size_t iMaxBufferSize, asn1SccON_OFF_DEVICE_ADDRESS *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccON_OFF_DEVICE_ADDRESS_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ON-OFF-DEVICE-ADDRESS (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_NATIVE
int Encode_NATIVE_ON_OFF_DEVICE_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccON_OFF_DEVICE_ADDRESS *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccON_OFF_DEVICE_ADDRESS) );
    return sizeof(asn1SccON_OFF_DEVICE_ADDRESS);
}
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_UPER
int Decode_UPER_ON_OFF_DEVICE_ADDRESS(asn1SccON_OFF_DEVICE_ADDRESS *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccON_OFF_DEVICE_ADDRESS_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ON-OFF-DEVICE-ADDRESS (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_ACN
int Decode_ACN_ON_OFF_DEVICE_ADDRESS(asn1SccON_OFF_DEVICE_ADDRESS *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccON_OFF_DEVICE_ADDRESS_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ON-OFF-DEVICE-ADDRESS (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ON_OFF_DEVICE_ADDRESS_NATIVE
int Decode_NATIVE_ON_OFF_DEVICE_ADDRESS(asn1SccON_OFF_DEVICE_ADDRESS *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccON_OFF_DEVICE_ADDRESS *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_UPER
int Encode_UPER_DistributeAnOnoffDeviceCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeAnOnoffDeviceCommand_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDistributeAnOnoffDeviceCommand_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DistributeAnOnoffDeviceCommand-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_ACN
int Encode_ACN_DistributeAnOnoffDeviceCommand_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccDistributeAnOnoffDeviceCommand_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDistributeAnOnoffDeviceCommand_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DistributeAnOnoffDeviceCommand-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_NATIVE
int Encode_NATIVE_DistributeAnOnoffDeviceCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeAnOnoffDeviceCommand_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccDistributeAnOnoffDeviceCommand_Type) );
    return sizeof(asn1SccDistributeAnOnoffDeviceCommand_Type);
}
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_UPER
int Decode_UPER_DistributeAnOnoffDeviceCommand_Type(asn1SccDistributeAnOnoffDeviceCommand_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDistributeAnOnoffDeviceCommand_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DistributeAnOnoffDeviceCommand-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_ACN
int Decode_ACN_DistributeAnOnoffDeviceCommand_Type(asn1SccDistributeAnOnoffDeviceCommand_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDistributeAnOnoffDeviceCommand_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DistributeAnOnoffDeviceCommand-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DistributeAnOnoffDeviceCommand_Type_NATIVE
int Decode_NATIVE_DistributeAnOnoffDeviceCommand_Type(asn1SccDistributeAnOnoffDeviceCommand_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccDistributeAnOnoffDeviceCommand_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_UPER
int Encode_UPER_TC_2_1_DistributeOnoffDeviceCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-1-DistributeOnoffDeviceCommands-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_ACN
int Encode_ACN_TC_2_1_DistributeOnoffDeviceCommands_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-1-DistributeOnoffDeviceCommands-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_NATIVE
int Encode_NATIVE_TC_2_1_DistributeOnoffDeviceCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type) );
    return sizeof(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type);
}
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_UPER
int Decode_UPER_TC_2_1_DistributeOnoffDeviceCommands_Type(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-1-DistributeOnoffDeviceCommands-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_ACN
int Decode_ACN_TC_2_1_DistributeOnoffDeviceCommands_Type(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-1-DistributeOnoffDeviceCommands-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_1_DistributeOnoffDeviceCommands_Type_NATIVE
int Decode_NATIVE_TC_2_1_DistributeOnoffDeviceCommands_Type(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_2_1_DistributeOnoffDeviceCommands_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_REGISTER_ADDRESS_UPER
int Encode_UPER_REGISTER_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_ADDRESS *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccREGISTER_ADDRESS_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode REGISTER-ADDRESS (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_REGISTER_ADDRESS_ACN
int Encode_ACN_REGISTER_ADDRESS(void *pBuffer, size_t iMaxBufferSize, asn1SccREGISTER_ADDRESS *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccREGISTER_ADDRESS_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode REGISTER-ADDRESS (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_REGISTER_ADDRESS_NATIVE
int Encode_NATIVE_REGISTER_ADDRESS(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_ADDRESS *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccREGISTER_ADDRESS) );
    return sizeof(asn1SccREGISTER_ADDRESS);
}
#endif

#ifdef __NEED_REGISTER_ADDRESS_UPER
int Decode_UPER_REGISTER_ADDRESS(asn1SccREGISTER_ADDRESS *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccREGISTER_ADDRESS_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode REGISTER-ADDRESS (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_REGISTER_ADDRESS_ACN
int Decode_ACN_REGISTER_ADDRESS(asn1SccREGISTER_ADDRESS *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccREGISTER_ADDRESS_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode REGISTER-ADDRESS (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_REGISTER_ADDRESS_NATIVE
int Decode_NATIVE_REGISTER_ADDRESS(asn1SccREGISTER_ADDRESS *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccREGISTER_ADDRESS *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_UPER
int Encode_UPER_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HOUSEKEEPING-PARAMETER-REPORT-STRUCTURE-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_ACN
int Encode_ACN_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HOUSEKEEPING-PARAMETER-REPORT-STRUCTURE-ID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_NATIVE
int Encode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID) );
    return sizeof(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID);
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_UPER
int Decode_UPER_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HOUSEKEEPING-PARAMETER-REPORT-STRUCTURE-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_ACN
int Decode_ACN_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HOUSEKEEPING-PARAMETER-REPORT-STRUCTURE-ID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID_NATIVE
int Decode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHOUSEKEEPING_PARAMETER_REPORT_STRUCTURE_ID *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PI_COEFFICIENT_UPER
int Encode_UPER_PI_COEFFICIENT(void *pBuffer, size_t iMaxBufferSize, const asn1SccPI_COEFFICIENT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPI_COEFFICIENT_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PI-COEFFICIENT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PI_COEFFICIENT_ACN
int Encode_ACN_PI_COEFFICIENT(void *pBuffer, size_t iMaxBufferSize, asn1SccPI_COEFFICIENT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPI_COEFFICIENT_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PI-COEFFICIENT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PI_COEFFICIENT_NATIVE
int Encode_NATIVE_PI_COEFFICIENT(void *pBuffer, size_t iMaxBufferSize, const asn1SccPI_COEFFICIENT *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPI_COEFFICIENT) );
    return sizeof(asn1SccPI_COEFFICIENT);
}
#endif

#ifdef __NEED_PI_COEFFICIENT_UPER
int Decode_UPER_PI_COEFFICIENT(asn1SccPI_COEFFICIENT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPI_COEFFICIENT_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PI-COEFFICIENT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PI_COEFFICIENT_ACN
int Decode_ACN_PI_COEFFICIENT(asn1SccPI_COEFFICIENT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPI_COEFFICIENT_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PI-COEFFICIENT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PI_COEFFICIENT_NATIVE
int Decode_NATIVE_PI_COEFFICIENT(asn1SccPI_COEFFICIENT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPI_COEFFICIENT *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_UINT8T_UPER
int Encode_UPER_UINT8T(void *pBuffer, size_t iMaxBufferSize, const asn1SccUINT8T *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccUINT8T_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode UINT8T (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_UINT8T_ACN
int Encode_ACN_UINT8T(void *pBuffer, size_t iMaxBufferSize, asn1SccUINT8T *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccUINT8T_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode UINT8T (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_UINT8T_NATIVE
int Encode_NATIVE_UINT8T(void *pBuffer, size_t iMaxBufferSize, const asn1SccUINT8T *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccUINT8T) );
    return sizeof(asn1SccUINT8T);
}
#endif

#ifdef __NEED_UINT8T_UPER
int Decode_UPER_UINT8T(asn1SccUINT8T *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccUINT8T_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode UINT8T (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_UINT8T_ACN
int Decode_ACN_UINT8T(asn1SccUINT8T *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccUINT8T_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode UINT8T (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_UINT8T_NATIVE
int Decode_NATIVE_UINT8T(asn1SccUINT8T *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccUINT8T *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_REGISTER_DATA_UPER
int Encode_UPER_REGISTER_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccREGISTER_DATA_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode REGISTER-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_REGISTER_DATA_ACN
int Encode_ACN_REGISTER_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccREGISTER_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccREGISTER_DATA_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode REGISTER-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_REGISTER_DATA_NATIVE
int Encode_NATIVE_REGISTER_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccREGISTER_DATA *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccREGISTER_DATA) );
    return sizeof(asn1SccREGISTER_DATA);
}
#endif

#ifdef __NEED_REGISTER_DATA_UPER
int Decode_UPER_REGISTER_DATA(asn1SccREGISTER_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccREGISTER_DATA_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode REGISTER-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_REGISTER_DATA_ACN
int Decode_ACN_REGISTER_DATA(asn1SccREGISTER_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccREGISTER_DATA_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode REGISTER-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_REGISTER_DATA_NATIVE
int Decode_NATIVE_REGISTER_DATA(asn1SccREGISTER_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccREGISTER_DATA *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_UPER
int Encode_UPER_DistributeARegisterLoadCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeARegisterLoadCommand_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDistributeARegisterLoadCommand_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DistributeARegisterLoadCommand-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_ACN
int Encode_ACN_DistributeARegisterLoadCommand_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccDistributeARegisterLoadCommand_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDistributeARegisterLoadCommand_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DistributeARegisterLoadCommand-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_NATIVE
int Encode_NATIVE_DistributeARegisterLoadCommand_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccDistributeARegisterLoadCommand_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccDistributeARegisterLoadCommand_Type) );
    return sizeof(asn1SccDistributeARegisterLoadCommand_Type);
}
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_UPER
int Decode_UPER_DistributeARegisterLoadCommand_Type(asn1SccDistributeARegisterLoadCommand_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDistributeARegisterLoadCommand_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DistributeARegisterLoadCommand-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_ACN
int Decode_ACN_DistributeARegisterLoadCommand_Type(asn1SccDistributeARegisterLoadCommand_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDistributeARegisterLoadCommand_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DistributeARegisterLoadCommand-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DistributeARegisterLoadCommand_Type_NATIVE
int Decode_NATIVE_DistributeARegisterLoadCommand_Type(asn1SccDistributeARegisterLoadCommand_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccDistributeARegisterLoadCommand_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_UPER
int Encode_UPER_TC_2_2_DistributeRegisterLoadCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_2_DistributeRegisterLoadCommands_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-2-DistributeRegisterLoadCommands-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_ACN
int Encode_ACN_TC_2_2_DistributeRegisterLoadCommands_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_2_DistributeRegisterLoadCommands_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-2-DistributeRegisterLoadCommands-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_NATIVE
int Encode_NATIVE_TC_2_2_DistributeRegisterLoadCommands_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type) );
    return sizeof(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type);
}
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_UPER
int Decode_UPER_TC_2_2_DistributeRegisterLoadCommands_Type(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_2_DistributeRegisterLoadCommands_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-2-DistributeRegisterLoadCommands-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_ACN
int Decode_ACN_TC_2_2_DistributeRegisterLoadCommands_Type(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_2_DistributeRegisterLoadCommands_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-2-DistributeRegisterLoadCommands-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_2_DistributeRegisterLoadCommands_Type_NATIVE
int Decode_NATIVE_TC_2_2_DistributeRegisterLoadCommands_Type(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_2_2_DistributeRegisterLoadCommands_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_DUTY_CYCLE_UPER
int Encode_UPER_DUTY_CYCLE(void *pBuffer, size_t iMaxBufferSize, const asn1SccDUTY_CYCLE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDUTY_CYCLE_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DUTY-CYCLE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DUTY_CYCLE_ACN
int Encode_ACN_DUTY_CYCLE(void *pBuffer, size_t iMaxBufferSize, asn1SccDUTY_CYCLE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccDUTY_CYCLE_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode DUTY-CYCLE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_DUTY_CYCLE_NATIVE
int Encode_NATIVE_DUTY_CYCLE(void *pBuffer, size_t iMaxBufferSize, const asn1SccDUTY_CYCLE *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccDUTY_CYCLE) );
    return sizeof(asn1SccDUTY_CYCLE);
}
#endif

#ifdef __NEED_DUTY_CYCLE_UPER
int Decode_UPER_DUTY_CYCLE(asn1SccDUTY_CYCLE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDUTY_CYCLE_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DUTY-CYCLE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DUTY_CYCLE_ACN
int Decode_ACN_DUTY_CYCLE(asn1SccDUTY_CYCLE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccDUTY_CYCLE_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode DUTY-CYCLE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_DUTY_CYCLE_NATIVE
int Decode_NATIVE_DUTY_CYCLE(asn1SccDUTY_CYCLE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccDUTY_CYCLE *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_SATELLITE_MODE_UPER
int Encode_UPER_SATELLITE_MODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccSATELLITE_MODE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSATELLITE_MODE_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SATELLITE-MODE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SATELLITE_MODE_ACN
int Encode_ACN_SATELLITE_MODE(void *pBuffer, size_t iMaxBufferSize, asn1SccSATELLITE_MODE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSATELLITE_MODE_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SATELLITE-MODE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SATELLITE_MODE_NATIVE
int Encode_NATIVE_SATELLITE_MODE(void *pBuffer, size_t iMaxBufferSize, const asn1SccSATELLITE_MODE *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSATELLITE_MODE) );
    return sizeof(asn1SccSATELLITE_MODE);
}
#endif

#ifdef __NEED_SATELLITE_MODE_UPER
int Decode_UPER_SATELLITE_MODE(asn1SccSATELLITE_MODE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSATELLITE_MODE_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SATELLITE-MODE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SATELLITE_MODE_ACN
int Decode_ACN_SATELLITE_MODE(asn1SccSATELLITE_MODE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSATELLITE_MODE_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SATELLITE-MODE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SATELLITE_MODE_NATIVE
int Decode_NATIVE_SATELLITE_MODE(asn1SccSATELLITE_MODE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSATELLITE_MODE *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_SwitchMode_Type_UPER
int Encode_UPER_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSwitchMode_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSwitchMode_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SwitchMode-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SwitchMode_Type_ACN
int Encode_ACN_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSwitchMode_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSwitchMode_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SwitchMode-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SwitchMode_Type_NATIVE
int Encode_NATIVE_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSwitchMode_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSwitchMode_Type) );
    return sizeof(asn1SccSwitchMode_Type);
}
#endif

#ifdef __NEED_SwitchMode_Type_UPER
int Decode_UPER_SwitchMode_Type(asn1SccSwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSwitchMode_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SwitchMode-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SwitchMode_Type_ACN
int Decode_ACN_SwitchMode_Type(asn1SccSwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSwitchMode_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SwitchMode-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SwitchMode_Type_NATIVE
int Decode_NATIVE_SwitchMode_Type(asn1SccSwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSwitchMode_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_UPER
int Encode_UPER_TC_222_1_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_1_SwitchMode_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_222_1_SwitchMode_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-222-1-SwitchMode-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_ACN
int Encode_ACN_TC_222_1_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_222_1_SwitchMode_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_222_1_SwitchMode_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-222-1-SwitchMode-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_NATIVE
int Encode_NATIVE_TC_222_1_SwitchMode_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_1_SwitchMode_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_222_1_SwitchMode_Type) );
    return sizeof(asn1SccTC_222_1_SwitchMode_Type);
}
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_UPER
int Decode_UPER_TC_222_1_SwitchMode_Type(asn1SccTC_222_1_SwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_222_1_SwitchMode_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-222-1-SwitchMode-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_ACN
int Decode_ACN_TC_222_1_SwitchMode_Type(asn1SccTC_222_1_SwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_222_1_SwitchMode_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-222-1-SwitchMode-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_222_1_SwitchMode_Type_NATIVE
int Decode_NATIVE_TC_222_1_SwitchMode_Type(asn1SccTC_222_1_SwitchMode_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_222_1_SwitchMode_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_VOLTAGE_UPER
int Encode_UPER_VOLTAGE(void *pBuffer, size_t iMaxBufferSize, const asn1SccVOLTAGE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccVOLTAGE_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode VOLTAGE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_VOLTAGE_ACN
int Encode_ACN_VOLTAGE(void *pBuffer, size_t iMaxBufferSize, asn1SccVOLTAGE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccVOLTAGE_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode VOLTAGE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_VOLTAGE_NATIVE
int Encode_NATIVE_VOLTAGE(void *pBuffer, size_t iMaxBufferSize, const asn1SccVOLTAGE *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccVOLTAGE) );
    return sizeof(asn1SccVOLTAGE);
}
#endif

#ifdef __NEED_VOLTAGE_UPER
int Decode_UPER_VOLTAGE(asn1SccVOLTAGE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccVOLTAGE_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode VOLTAGE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_VOLTAGE_ACN
int Decode_ACN_VOLTAGE(asn1SccVOLTAGE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccVOLTAGE_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode VOLTAGE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_VOLTAGE_NATIVE
int Decode_NATIVE_VOLTAGE(asn1SccVOLTAGE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccVOLTAGE *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_UPER
int Encode_UPER_FAILURE_NOTICE_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFAILURE_NOTICE_DATA_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FAILURE-NOTICE-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_ACN
int Encode_ACN_FAILURE_NOTICE_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccFAILURE_NOTICE_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFAILURE_NOTICE_DATA_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FAILURE-NOTICE-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_NATIVE
int Encode_NATIVE_FAILURE_NOTICE_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccFAILURE_NOTICE_DATA *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccFAILURE_NOTICE_DATA) );
    return sizeof(asn1SccFAILURE_NOTICE_DATA);
}
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_UPER
int Decode_UPER_FAILURE_NOTICE_DATA(asn1SccFAILURE_NOTICE_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFAILURE_NOTICE_DATA_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FAILURE-NOTICE-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_ACN
int Decode_ACN_FAILURE_NOTICE_DATA(asn1SccFAILURE_NOTICE_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFAILURE_NOTICE_DATA_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FAILURE-NOTICE-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FAILURE_NOTICE_DATA_NATIVE
int Decode_NATIVE_FAILURE_NOTICE_DATA(asn1SccFAILURE_NOTICE_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccFAILURE_NOTICE_DATA *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_UPER
int Encode_UPER_FailedStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccFailedStartOfExecutionNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFailedStartOfExecutionNotificationNotification_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FailedStartOfExecutionNotificationNotification-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_ACN
int Encode_ACN_FailedStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccFailedStartOfExecutionNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFailedStartOfExecutionNotificationNotification_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FailedStartOfExecutionNotificationNotification-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_NATIVE
int Encode_NATIVE_FailedStartOfExecutionNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccFailedStartOfExecutionNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccFailedStartOfExecutionNotificationNotification_Type) );
    return sizeof(asn1SccFailedStartOfExecutionNotificationNotification_Type);
}
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_UPER
int Decode_UPER_FailedStartOfExecutionNotificationNotification_Type(asn1SccFailedStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFailedStartOfExecutionNotificationNotification_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FailedStartOfExecutionNotificationNotification-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_ACN
int Decode_ACN_FailedStartOfExecutionNotificationNotification_Type(asn1SccFailedStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFailedStartOfExecutionNotificationNotification_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FailedStartOfExecutionNotificationNotification-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FailedStartOfExecutionNotificationNotification_Type_NATIVE
int Decode_NATIVE_FailedStartOfExecutionNotificationNotification_Type(asn1SccFailedStartOfExecutionNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccFailedStartOfExecutionNotificationNotification_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_UPER
int Encode_UPER_TM_1_4_FailedStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TM-1-4-FailedStartOfExecutionVerificationReport-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_ACN
int Encode_ACN_TM_1_4_FailedStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TM-1-4-FailedStartOfExecutionVerificationReport-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_NATIVE
int Encode_NATIVE_TM_1_4_FailedStartOfExecutionVerificationReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type) );
    return sizeof(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type);
}
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_UPER
int Decode_UPER_TM_1_4_FailedStartOfExecutionVerificationReport_Type(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TM-1-4-FailedStartOfExecutionVerificationReport-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_ACN
int Decode_ACN_TM_1_4_FailedStartOfExecutionVerificationReport_Type(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TM-1-4-FailedStartOfExecutionVerificationReport-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TM_1_4_FailedStartOfExecutionVerificationReport_Type_NATIVE
int Decode_NATIVE_TM_1_4_FailedStartOfExecutionVerificationReport_Type(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTM_1_4_FailedStartOfExecutionVerificationReport_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_UPER
int Encode_UPER_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetSafeThresholdVoltage_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSetSafeThresholdVoltage_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SetSafeThresholdVoltage-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_ACN
int Encode_ACN_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSetSafeThresholdVoltage_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSetSafeThresholdVoltage_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SetSafeThresholdVoltage-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_NATIVE
int Encode_NATIVE_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetSafeThresholdVoltage_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSetSafeThresholdVoltage_Type) );
    return sizeof(asn1SccSetSafeThresholdVoltage_Type);
}
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_UPER
int Decode_UPER_SetSafeThresholdVoltage_Type(asn1SccSetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSetSafeThresholdVoltage_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SetSafeThresholdVoltage-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_ACN
int Decode_ACN_SetSafeThresholdVoltage_Type(asn1SccSetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSetSafeThresholdVoltage_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SetSafeThresholdVoltage-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SetSafeThresholdVoltage_Type_NATIVE
int Decode_NATIVE_SetSafeThresholdVoltage_Type(asn1SccSetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSetSafeThresholdVoltage_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_UPER
int Encode_UPER_TC_222_11_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_222_11_SetSafeThresholdVoltage_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-222-11-SetSafeThresholdVoltage-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_ACN
int Encode_ACN_TC_222_11_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_222_11_SetSafeThresholdVoltage_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-222-11-SetSafeThresholdVoltage-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_NATIVE
int Encode_NATIVE_TC_222_11_SetSafeThresholdVoltage_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_222_11_SetSafeThresholdVoltage_Type) );
    return sizeof(asn1SccTC_222_11_SetSafeThresholdVoltage_Type);
}
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_UPER
int Decode_UPER_TC_222_11_SetSafeThresholdVoltage_Type(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_222_11_SetSafeThresholdVoltage_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-222-11-SetSafeThresholdVoltage-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_ACN
int Decode_ACN_TC_222_11_SetSafeThresholdVoltage_Type(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_222_11_SetSafeThresholdVoltage_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-222-11-SetSafeThresholdVoltage-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_222_11_SetSafeThresholdVoltage_Type_NATIVE
int Decode_NATIVE_TC_222_11_SetSafeThresholdVoltage_Type(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_222_11_SetSafeThresholdVoltage_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TEMPERATURE_UPER
int Encode_UPER_TEMPERATURE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTEMPERATURE_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TEMPERATURE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TEMPERATURE_ACN
int Encode_ACN_TEMPERATURE(void *pBuffer, size_t iMaxBufferSize, asn1SccTEMPERATURE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTEMPERATURE_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TEMPERATURE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TEMPERATURE_NATIVE
int Encode_NATIVE_TEMPERATURE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTEMPERATURE) );
    return sizeof(asn1SccTEMPERATURE);
}
#endif

#ifdef __NEED_TEMPERATURE_UPER
int Decode_UPER_TEMPERATURE(asn1SccTEMPERATURE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTEMPERATURE_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TEMPERATURE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TEMPERATURE_ACN
int Decode_ACN_TEMPERATURE(asn1SccTEMPERATURE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTEMPERATURE_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TEMPERATURE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TEMPERATURE_NATIVE
int Decode_NATIVE_TEMPERATURE(asn1SccTEMPERATURE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTEMPERATURE *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_UPER
int Encode_UPER_HOUSEKEEPING_PARAMETER_REPORT_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HOUSEKEEPING-PARAMETER-REPORT-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_ACN
int Encode_ACN_HOUSEKEEPING_PARAMETER_REPORT_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HOUSEKEEPING-PARAMETER-REPORT-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_NATIVE
int Encode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA) );
    return sizeof(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA);
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_UPER
int Decode_UPER_HOUSEKEEPING_PARAMETER_REPORT_DATA(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HOUSEKEEPING-PARAMETER-REPORT-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_ACN
int Decode_ACN_HOUSEKEEPING_PARAMETER_REPORT_DATA(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HOUSEKEEPING-PARAMETER-REPORT-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HOUSEKEEPING_PARAMETER_REPORT_DATA_NATIVE
int Decode_NATIVE_HOUSEKEEPING_PARAMETER_REPORT_DATA(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHOUSEKEEPING_PARAMETER_REPORT_DATA *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_UPER
int Encode_UPER_HousekeepingParameterNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccHousekeepingParameterNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHousekeepingParameterNotificationNotification_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HousekeepingParameterNotificationNotification-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_ACN
int Encode_ACN_HousekeepingParameterNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccHousekeepingParameterNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHousekeepingParameterNotificationNotification_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HousekeepingParameterNotificationNotification-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_NATIVE
int Encode_NATIVE_HousekeepingParameterNotificationNotification_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccHousekeepingParameterNotificationNotification_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHousekeepingParameterNotificationNotification_Type) );
    return sizeof(asn1SccHousekeepingParameterNotificationNotification_Type);
}
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_UPER
int Decode_UPER_HousekeepingParameterNotificationNotification_Type(asn1SccHousekeepingParameterNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHousekeepingParameterNotificationNotification_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HousekeepingParameterNotificationNotification-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_ACN
int Decode_ACN_HousekeepingParameterNotificationNotification_Type(asn1SccHousekeepingParameterNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHousekeepingParameterNotificationNotification_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HousekeepingParameterNotificationNotification-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HousekeepingParameterNotificationNotification_Type_NATIVE
int Decode_NATIVE_HousekeepingParameterNotificationNotification_Type(asn1SccHousekeepingParameterNotificationNotification_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHousekeepingParameterNotificationNotification_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_UPER
int Encode_UPER_TM_3_25_HousekeepingParameterReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_3_25_HousekeepingParameterReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTM_3_25_HousekeepingParameterReport_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TM-3-25-HousekeepingParameterReport-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_ACN
int Encode_ACN_TM_3_25_HousekeepingParameterReport_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTM_3_25_HousekeepingParameterReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTM_3_25_HousekeepingParameterReport_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TM-3-25-HousekeepingParameterReport-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_NATIVE
int Encode_NATIVE_TM_3_25_HousekeepingParameterReport_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM_3_25_HousekeepingParameterReport_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTM_3_25_HousekeepingParameterReport_Type) );
    return sizeof(asn1SccTM_3_25_HousekeepingParameterReport_Type);
}
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_UPER
int Decode_UPER_TM_3_25_HousekeepingParameterReport_Type(asn1SccTM_3_25_HousekeepingParameterReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTM_3_25_HousekeepingParameterReport_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TM-3-25-HousekeepingParameterReport-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_ACN
int Decode_ACN_TM_3_25_HousekeepingParameterReport_Type(asn1SccTM_3_25_HousekeepingParameterReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTM_3_25_HousekeepingParameterReport_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TM-3-25-HousekeepingParameterReport-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TM_3_25_HousekeepingParameterReport_Type_NATIVE
int Decode_NATIVE_TM_3_25_HousekeepingParameterReport_Type(asn1SccTM_3_25_HousekeepingParameterReport_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTM_3_25_HousekeepingParameterReport_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Regular_Telemetries_UPER
int Encode_UPER_Regular_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccRegular_Telemetries *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccRegular_Telemetries_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Regular-Telemetries (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Regular_Telemetries_ACN
int Encode_ACN_Regular_Telemetries(void *pBuffer, size_t iMaxBufferSize, asn1SccRegular_Telemetries *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccRegular_Telemetries_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Regular-Telemetries (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Regular_Telemetries_NATIVE
int Encode_NATIVE_Regular_Telemetries(void *pBuffer, size_t iMaxBufferSize, const asn1SccRegular_Telemetries *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccRegular_Telemetries) );
    return sizeof(asn1SccRegular_Telemetries);
}
#endif

#ifdef __NEED_Regular_Telemetries_UPER
int Decode_UPER_Regular_Telemetries(asn1SccRegular_Telemetries *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccRegular_Telemetries_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Regular-Telemetries (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Regular_Telemetries_ACN
int Decode_ACN_Regular_Telemetries(asn1SccRegular_Telemetries *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccRegular_Telemetries_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Regular-Telemetries (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Regular_Telemetries_NATIVE
int Decode_NATIVE_Regular_Telemetries(asn1SccRegular_Telemetries *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccRegular_Telemetries *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Telemetry_UPER
int Encode_UPER_Telemetry(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelemetry *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTelemetry_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Telemetry (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Telemetry_ACN
int Encode_ACN_Telemetry(void *pBuffer, size_t iMaxBufferSize, asn1SccTelemetry *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTelemetry_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Telemetry (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Telemetry_NATIVE
int Encode_NATIVE_Telemetry(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelemetry *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTelemetry) );
    return sizeof(asn1SccTelemetry);
}
#endif

#ifdef __NEED_Telemetry_UPER
int Decode_UPER_Telemetry(asn1SccTelemetry *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTelemetry_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Telemetry (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Telemetry_ACN
int Decode_ACN_Telemetry(asn1SccTelemetry *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTelemetry_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Telemetry (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Telemetry_NATIVE
int Decode_NATIVE_Telemetry(asn1SccTelemetry *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTelemetry *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_SetThermalControlParameters_Type_UPER
int Encode_UPER_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetThermalControlParameters_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSetThermalControlParameters_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SetThermalControlParameters-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SetThermalControlParameters_Type_ACN
int Encode_ACN_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccSetThermalControlParameters_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSetThermalControlParameters_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode SetThermalControlParameters-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_SetThermalControlParameters_Type_NATIVE
int Encode_NATIVE_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccSetThermalControlParameters_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSetThermalControlParameters_Type) );
    return sizeof(asn1SccSetThermalControlParameters_Type);
}
#endif

#ifdef __NEED_SetThermalControlParameters_Type_UPER
int Decode_UPER_SetThermalControlParameters_Type(asn1SccSetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSetThermalControlParameters_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SetThermalControlParameters-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SetThermalControlParameters_Type_ACN
int Decode_ACN_SetThermalControlParameters_Type(asn1SccSetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSetThermalControlParameters_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode SetThermalControlParameters-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_SetThermalControlParameters_Type_NATIVE
int Decode_NATIVE_SetThermalControlParameters_Type(asn1SccSetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSetThermalControlParameters_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_UPER
int Encode_UPER_TC_222_21_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_21_SetThermalControlParameters_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_222_21_SetThermalControlParameters_Type_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-222-21-SetThermalControlParameters-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_ACN
int Encode_ACN_TC_222_21_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_222_21_SetThermalControlParameters_Type *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_222_21_SetThermalControlParameters_Type_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-222-21-SetThermalControlParameters-Type (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_NATIVE
int Encode_NATIVE_TC_222_21_SetThermalControlParameters_Type(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_222_21_SetThermalControlParameters_Type *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_222_21_SetThermalControlParameters_Type) );
    return sizeof(asn1SccTC_222_21_SetThermalControlParameters_Type);
}
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_UPER
int Decode_UPER_TC_222_21_SetThermalControlParameters_Type(asn1SccTC_222_21_SetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_222_21_SetThermalControlParameters_Type_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-222-21-SetThermalControlParameters-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_ACN
int Decode_ACN_TC_222_21_SetThermalControlParameters_Type(asn1SccTC_222_21_SetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_222_21_SetThermalControlParameters_Type_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-222-21-SetThermalControlParameters-Type (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_222_21_SetThermalControlParameters_Type_NATIVE
int Decode_NATIVE_TC_222_21_SetThermalControlParameters_Type(asn1SccTC_222_21_SetThermalControlParameters_Type *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_222_21_SetThermalControlParameters_Type *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Telecommands_UPER
int Encode_UPER_Telecommands(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommands *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTelecommands_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Telecommands (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Telecommands_ACN
int Encode_ACN_Telecommands(void *pBuffer, size_t iMaxBufferSize, asn1SccTelecommands *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTelecommands_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Telecommands (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Telecommands_NATIVE
int Encode_NATIVE_Telecommands(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommands *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTelecommands) );
    return sizeof(asn1SccTelecommands);
}
#endif

#ifdef __NEED_Telecommands_UPER
int Decode_UPER_Telecommands(asn1SccTelecommands *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTelecommands_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Telecommands (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Telecommands_ACN
int Decode_ACN_Telecommands(asn1SccTelecommands *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTelecommands_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Telecommands (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Telecommands_NATIVE
int Decode_NATIVE_Telecommands(asn1SccTelecommands *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTelecommands *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Telecommand_UPER
int Encode_UPER_Telecommand(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommand *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTelecommand_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Telecommand (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Telecommand_ACN
int Encode_ACN_Telecommand(void *pBuffer, size_t iMaxBufferSize, asn1SccTelecommand *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTelecommand_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Telecommand (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Telecommand_NATIVE
int Encode_NATIVE_Telecommand(void *pBuffer, size_t iMaxBufferSize, const asn1SccTelecommand *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTelecommand) );
    return sizeof(asn1SccTelecommand);
}
#endif

#ifdef __NEED_Telecommand_UPER
int Decode_UPER_Telecommand(asn1SccTelecommand *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTelecommand_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Telecommand (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Telecommand_ACN
int Decode_ACN_Telecommand(asn1SccTelecommand *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTelecommand_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Telecommand (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Telecommand_NATIVE
int Decode_NATIVE_Telecommand(asn1SccTelecommand *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTelecommand *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_2_1_COUNT_UPER
int Encode_UPER_TC_2_1_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_COUNT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_1_COUNT_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-1-COUNT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_1_COUNT_ACN
int Encode_ACN_TC_2_1_COUNT(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_1_COUNT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_1_COUNT_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-1-COUNT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_1_COUNT_NATIVE
int Encode_NATIVE_TC_2_1_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_1_COUNT *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_2_1_COUNT) );
    return sizeof(asn1SccTC_2_1_COUNT);
}
#endif

#ifdef __NEED_TC_2_1_COUNT_UPER
int Decode_UPER_TC_2_1_COUNT(asn1SccTC_2_1_COUNT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_1_COUNT_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-1-COUNT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_1_COUNT_ACN
int Decode_ACN_TC_2_1_COUNT(asn1SccTC_2_1_COUNT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_1_COUNT_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-1-COUNT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_1_COUNT_NATIVE
int Decode_NATIVE_TC_2_1_COUNT(asn1SccTC_2_1_COUNT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_2_1_COUNT *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TC_2_2_COUNT_UPER
int Encode_UPER_TC_2_2_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_COUNT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_2_COUNT_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-2-COUNT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_2_COUNT_ACN
int Encode_ACN_TC_2_2_COUNT(void *pBuffer, size_t iMaxBufferSize, asn1SccTC_2_2_COUNT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTC_2_2_COUNT_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TC-2-2-COUNT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TC_2_2_COUNT_NATIVE
int Encode_NATIVE_TC_2_2_COUNT(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC_2_2_COUNT *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTC_2_2_COUNT) );
    return sizeof(asn1SccTC_2_2_COUNT);
}
#endif

#ifdef __NEED_TC_2_2_COUNT_UPER
int Decode_UPER_TC_2_2_COUNT(asn1SccTC_2_2_COUNT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_2_COUNT_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-2-COUNT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_2_COUNT_ACN
int Decode_ACN_TC_2_2_COUNT(asn1SccTC_2_2_COUNT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTC_2_2_COUNT_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TC-2-2-COUNT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TC_2_2_COUNT_NATIVE
int Decode_NATIVE_TC_2_2_COUNT(asn1SccTC_2_2_COUNT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTC_2_2_COUNT *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int32) );
    return sizeof(asn1SccT_Int32);
}
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt32) );
    return sizeof(asn1SccT_UInt32);
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int8) );
    return sizeof(asn1SccT_Int8);
}
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt8) );
    return sizeof(asn1SccT_UInt8);
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Boolean) );
    return sizeof(asn1SccT_Boolean);
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Boolean *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Null_Record) );
    return sizeof(asn1SccT_Null_Record);
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Null_Record *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_UPER
int Encode_UPER_PAYLOAD_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccPAYLOAD_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPAYLOAD_HK_DATA_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PAYLOAD-HK-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_ACN
int Encode_ACN_PAYLOAD_HK_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccPAYLOAD_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPAYLOAD_HK_DATA_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PAYLOAD-HK-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_NATIVE
int Encode_NATIVE_PAYLOAD_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccPAYLOAD_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPAYLOAD_HK_DATA) );
    return sizeof(asn1SccPAYLOAD_HK_DATA);
}
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_UPER
int Decode_UPER_PAYLOAD_HK_DATA(asn1SccPAYLOAD_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPAYLOAD_HK_DATA_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PAYLOAD-HK-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_ACN
int Decode_ACN_PAYLOAD_HK_DATA(asn1SccPAYLOAD_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPAYLOAD_HK_DATA_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PAYLOAD-HK-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PAYLOAD_HK_DATA_NATIVE
int Decode_NATIVE_PAYLOAD_HK_DATA(asn1SccPAYLOAD_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPAYLOAD_HK_DATA *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_MODE_HK_DATA_UPER
int Encode_UPER_MODE_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccMODE_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMODE_HK_DATA_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MODE-HK-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MODE_HK_DATA_ACN
int Encode_ACN_MODE_HK_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccMODE_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMODE_HK_DATA_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MODE-HK-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MODE_HK_DATA_NATIVE
int Encode_NATIVE_MODE_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccMODE_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMODE_HK_DATA) );
    return sizeof(asn1SccMODE_HK_DATA);
}
#endif

#ifdef __NEED_MODE_HK_DATA_UPER
int Decode_UPER_MODE_HK_DATA(asn1SccMODE_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMODE_HK_DATA_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MODE-HK-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MODE_HK_DATA_ACN
int Decode_ACN_MODE_HK_DATA(asn1SccMODE_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMODE_HK_DATA_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MODE-HK-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MODE_HK_DATA_NATIVE
int Decode_NATIVE_MODE_HK_DATA(asn1SccMODE_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMODE_HK_DATA *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_THERMAL_HK_DATA_UPER
int Encode_UPER_THERMAL_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccTHERMAL_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTHERMAL_HK_DATA_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode THERMAL-HK-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_THERMAL_HK_DATA_ACN
int Encode_ACN_THERMAL_HK_DATA(void *pBuffer, size_t iMaxBufferSize, asn1SccTHERMAL_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTHERMAL_HK_DATA_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode THERMAL-HK-DATA (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_THERMAL_HK_DATA_NATIVE
int Encode_NATIVE_THERMAL_HK_DATA(void *pBuffer, size_t iMaxBufferSize, const asn1SccTHERMAL_HK_DATA *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTHERMAL_HK_DATA) );
    return sizeof(asn1SccTHERMAL_HK_DATA);
}
#endif

#ifdef __NEED_THERMAL_HK_DATA_UPER
int Decode_UPER_THERMAL_HK_DATA(asn1SccTHERMAL_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTHERMAL_HK_DATA_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode THERMAL-HK-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_THERMAL_HK_DATA_ACN
int Decode_ACN_THERMAL_HK_DATA(asn1SccTHERMAL_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTHERMAL_HK_DATA_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode THERMAL-HK-DATA (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_THERMAL_HK_DATA_NATIVE
int Decode_NATIVE_THERMAL_HK_DATA(asn1SccTHERMAL_HK_DATA *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTHERMAL_HK_DATA *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_EXECUTION_REPORT_UPER
int Encode_UPER_EXECUTION_REPORT(void *pBuffer, size_t iMaxBufferSize, const asn1SccEXECUTION_REPORT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEXECUTION_REPORT_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EXECUTION-REPORT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EXECUTION_REPORT_ACN
int Encode_ACN_EXECUTION_REPORT(void *pBuffer, size_t iMaxBufferSize, asn1SccEXECUTION_REPORT *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEXECUTION_REPORT_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EXECUTION-REPORT (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EXECUTION_REPORT_NATIVE
int Encode_NATIVE_EXECUTION_REPORT(void *pBuffer, size_t iMaxBufferSize, const asn1SccEXECUTION_REPORT *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccEXECUTION_REPORT) );
    return sizeof(asn1SccEXECUTION_REPORT);
}
#endif

#ifdef __NEED_EXECUTION_REPORT_UPER
int Decode_UPER_EXECUTION_REPORT(asn1SccEXECUTION_REPORT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEXECUTION_REPORT_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EXECUTION-REPORT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EXECUTION_REPORT_ACN
int Decode_ACN_EXECUTION_REPORT(asn1SccEXECUTION_REPORT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEXECUTION_REPORT_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EXECUTION-REPORT (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EXECUTION_REPORT_NATIVE
int Decode_NATIVE_EXECUTION_REPORT(asn1SccEXECUTION_REPORT *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccEXECUTION_REPORT *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_REAL_UPER
int Encode_UPER_T_REAL(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_REAL *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_REAL_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-REAL (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_REAL_ACN
int Encode_ACN_T_REAL(void *pBuffer, size_t iMaxBufferSize, asn1SccT_REAL *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_REAL_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-REAL (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_REAL_NATIVE
int Encode_NATIVE_T_REAL(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_REAL *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_REAL) );
    return sizeof(asn1SccT_REAL);
}
#endif

#ifdef __NEED_T_REAL_UPER
int Decode_UPER_T_REAL(asn1SccT_REAL *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_REAL_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-REAL (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_REAL_ACN
int Decode_ACN_T_REAL(asn1SccT_REAL *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_REAL_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-REAL (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_REAL_NATIVE
int Decode_NATIVE_T_REAL(asn1SccT_REAL *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_REAL *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_UPER
int Encode_UPER_TEMPERATURE_DIFFERENCE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE_DIFFERENCE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTEMPERATURE_DIFFERENCE_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TEMPERATURE-DIFFERENCE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_ACN
int Encode_ACN_TEMPERATURE_DIFFERENCE(void *pBuffer, size_t iMaxBufferSize, asn1SccTEMPERATURE_DIFFERENCE *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTEMPERATURE_DIFFERENCE_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode TEMPERATURE-DIFFERENCE (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_NATIVE
int Encode_NATIVE_TEMPERATURE_DIFFERENCE(void *pBuffer, size_t iMaxBufferSize, const asn1SccTEMPERATURE_DIFFERENCE *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTEMPERATURE_DIFFERENCE) );
    return sizeof(asn1SccTEMPERATURE_DIFFERENCE);
}
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_UPER
int Decode_UPER_TEMPERATURE_DIFFERENCE(asn1SccTEMPERATURE_DIFFERENCE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTEMPERATURE_DIFFERENCE_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TEMPERATURE-DIFFERENCE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_ACN
int Decode_ACN_TEMPERATURE_DIFFERENCE(asn1SccTEMPERATURE_DIFFERENCE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTEMPERATURE_DIFFERENCE_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode TEMPERATURE-DIFFERENCE (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_TEMPERATURE_DIFFERENCE_NATIVE
int Decode_NATIVE_TEMPERATURE_DIFFERENCE(asn1SccTEMPERATURE_DIFFERENCE *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTEMPERATURE_DIFFERENCE *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PID_UPER
int Encode_UPER_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPID_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PID_ACN
int Encode_ACN_PID(void *pBuffer, size_t iMaxBufferSize, asn1SccPID *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPID_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PID (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PID_NATIVE
int Encode_NATIVE_PID(void *pBuffer, size_t iMaxBufferSize, const asn1SccPID *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPID) );
    return sizeof(asn1SccPID);
}
#endif

#ifdef __NEED_PID_UPER
int Decode_UPER_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPID_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PID_ACN
int Decode_ACN_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPID_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PID (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PID_NATIVE
int Decode_NATIVE_PID(asn1SccPID *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPID *) pBuffer;
    {
        return 0;
    }
}
#endif

