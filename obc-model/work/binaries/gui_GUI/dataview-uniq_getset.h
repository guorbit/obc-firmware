#ifndef __GETSET_H__
#define __GETSET_H__

#include "dataview-uniq.h"

size_t GetStreamCurrentLength(BitStream *pBitStrm);
byte *GetBitstreamBuffer(BitStream *pBitStrm);
byte GetBufferByte(byte *p, size_t off);
void SetBufferByte(byte *p, size_t off, byte b);
void ResetStream(BitStream *pStrm);
BitStream *CreateStream(size_t bufferSize);
void DestroyStream(BitStream *pBitStrm);


/* INTEGER */
asn1SccUint CounterK__Get(CounterK* root);

/* INTEGER */
void CounterK__Set(CounterK* root, asn1SccUint value);

/* INTEGER */
asn1SccUint Time_UNIX__Get(Time_UNIX* root);

/* INTEGER */
void Time_UNIX__Set(Time_UNIX* root, asn1SccUint value);

/* REAL */
double Latitude_WGS84__Get(Latitude_WGS84* root);

/* REAL */
void Latitude_WGS84__Set(Latitude_WGS84* root, double value);

/* REAL */
double Longitude_WGS84__Get(Longitude_WGS84* root);

/* REAL */
void Longitude_WGS84__Set(Longitude_WGS84* root, double value);

/* REAL */
double Location__lat_Get(Location* root);

/* REAL */
void Location__lat_Set(Location* root, double value);

/* REAL */
double Location__lon_Get(Location* root);

/* REAL */
void Location__lon_Set(Location* root, double value);

/* INTEGER */
asn1SccUint Location_Fix_Packet__t_Get(Location_Fix_Packet* root);

/* INTEGER */
void Location_Fix_Packet__t_Set(Location_Fix_Packet* root, asn1SccUint value);

/* REAL */
double Location_Fix_Packet__lat_Get(Location_Fix_Packet* root);

/* REAL */
void Location_Fix_Packet__lat_Set(Location_Fix_Packet* root, double value);

/* REAL */
double Location_Fix_Packet__lon_Get(Location_Fix_Packet* root);

/* REAL */
void Location_Fix_Packet__lon_Set(Location_Fix_Packet* root, double value);

/* REAL */
double Temperature_Generic__Get(Temperature_Generic* root);

/* REAL */
void Temperature_Generic__Set(Temperature_Generic* root, double value);

/* BOOLEAN */
flag Deployment_Digital__Get(Deployment_Digital* root);

/* BOOLEAN */
void Deployment_Digital__Set(Deployment_Digital* root, flag value);

/* REAL */
double Deployment_Analogue__Get(Deployment_Analogue* root);

/* REAL */
void Deployment_Analogue__Set(Deployment_Analogue* root, double value);

/* INTEGER */
asn1SccUint System_Mode__Get(System_Mode* root);

/* INTEGER */
void System_Mode__Set(System_Mode* root, asn1SccUint value);

/* INTEGER */
asn1SccUint Subsystem_Address__Get(Subsystem_Address* root);

/* INTEGER */
void Subsystem_Address__Set(Subsystem_Address* root, asn1SccUint value);

/* INTEGER */
asn1SccUint Mode_Change_Packet__target_addr_Get(Mode_Change_Packet* root);

/* INTEGER */
void Mode_Change_Packet__target_addr_Set(Mode_Change_Packet* root, asn1SccUint value);

/* INTEGER */
asn1SccUint Mode_Change_Packet__target_mode_Get(Mode_Change_Packet* root);

/* INTEGER */
void Mode_Change_Packet__target_mode_Set(Mode_Change_Packet* root, asn1SccUint value);

/* INTEGER */
asn1SccUint Mode_Change_Packet__ttl_ms_Get(Mode_Change_Packet* root);

/* INTEGER */
void Mode_Change_Packet__ttl_ms_Set(Mode_Change_Packet* root, asn1SccUint value);

/* INTEGER */
asn1SccSint T_Int32__Get(T_Int32* root);

/* INTEGER */
void T_Int32__Set(T_Int32* root, asn1SccSint value);

/* INTEGER */
asn1SccUint T_UInt32__Get(T_UInt32* root);

/* INTEGER */
void T_UInt32__Set(T_UInt32* root, asn1SccUint value);

/* INTEGER */
asn1SccSint T_Int8__Get(T_Int8* root);

/* INTEGER */
void T_Int8__Set(T_Int8* root, asn1SccSint value);

/* INTEGER */
asn1SccUint T_UInt8__Get(T_UInt8* root);

/* INTEGER */
void T_UInt8__Set(T_UInt8* root, asn1SccUint value);

/* BOOLEAN */
flag T_Boolean__Get(T_Boolean* root);

/* BOOLEAN */
void T_Boolean__Set(T_Boolean* root, flag value);

/* ENUMERATED */
int PID__Get(PID* root);

/* ENUMERATED */
void PID__Set(PID* root, int value);

/* Helper functions for NATIVE encodings */

void SetDataFor_CounterK(void *dest, void *src);
byte* MovePtrBySizeOf_CounterK(byte *pData);
byte* CreateInstanceOf_CounterK(void);
void DestroyInstanceOf_CounterK(byte *pData);

void SetDataFor_Time_UNIX(void *dest, void *src);
byte* MovePtrBySizeOf_Time_UNIX(byte *pData);
byte* CreateInstanceOf_Time_UNIX(void);
void DestroyInstanceOf_Time_UNIX(byte *pData);

void SetDataFor_Latitude_WGS84(void *dest, void *src);
byte* MovePtrBySizeOf_Latitude_WGS84(byte *pData);
byte* CreateInstanceOf_Latitude_WGS84(void);
void DestroyInstanceOf_Latitude_WGS84(byte *pData);

void SetDataFor_Longitude_WGS84(void *dest, void *src);
byte* MovePtrBySizeOf_Longitude_WGS84(byte *pData);
byte* CreateInstanceOf_Longitude_WGS84(void);
void DestroyInstanceOf_Longitude_WGS84(byte *pData);

void SetDataFor_Location(void *dest, void *src);
byte* MovePtrBySizeOf_Location(byte *pData);
byte* CreateInstanceOf_Location(void);
void DestroyInstanceOf_Location(byte *pData);

void SetDataFor_Location_Fix_Packet(void *dest, void *src);
byte* MovePtrBySizeOf_Location_Fix_Packet(byte *pData);
byte* CreateInstanceOf_Location_Fix_Packet(void);
void DestroyInstanceOf_Location_Fix_Packet(byte *pData);

void SetDataFor_Temperature_Generic(void *dest, void *src);
byte* MovePtrBySizeOf_Temperature_Generic(byte *pData);
byte* CreateInstanceOf_Temperature_Generic(void);
void DestroyInstanceOf_Temperature_Generic(byte *pData);

void SetDataFor_Deployment_Digital(void *dest, void *src);
byte* MovePtrBySizeOf_Deployment_Digital(byte *pData);
byte* CreateInstanceOf_Deployment_Digital(void);
void DestroyInstanceOf_Deployment_Digital(byte *pData);

void SetDataFor_Deployment_Analogue(void *dest, void *src);
byte* MovePtrBySizeOf_Deployment_Analogue(byte *pData);
byte* CreateInstanceOf_Deployment_Analogue(void);
void DestroyInstanceOf_Deployment_Analogue(byte *pData);

void SetDataFor_System_Mode(void *dest, void *src);
byte* MovePtrBySizeOf_System_Mode(byte *pData);
byte* CreateInstanceOf_System_Mode(void);
void DestroyInstanceOf_System_Mode(byte *pData);

void SetDataFor_Subsystem_Address(void *dest, void *src);
byte* MovePtrBySizeOf_Subsystem_Address(byte *pData);
byte* CreateInstanceOf_Subsystem_Address(void);
void DestroyInstanceOf_Subsystem_Address(byte *pData);

void SetDataFor_Mode_Change_Packet(void *dest, void *src);
byte* MovePtrBySizeOf_Mode_Change_Packet(byte *pData);
byte* CreateInstanceOf_Mode_Change_Packet(void);
void DestroyInstanceOf_Mode_Change_Packet(byte *pData);

void SetDataFor_T_Int32(void *dest, void *src);
byte* MovePtrBySizeOf_T_Int32(byte *pData);
byte* CreateInstanceOf_T_Int32(void);
void DestroyInstanceOf_T_Int32(byte *pData);

void SetDataFor_T_UInt32(void *dest, void *src);
byte* MovePtrBySizeOf_T_UInt32(byte *pData);
byte* CreateInstanceOf_T_UInt32(void);
void DestroyInstanceOf_T_UInt32(byte *pData);

void SetDataFor_T_Int8(void *dest, void *src);
byte* MovePtrBySizeOf_T_Int8(byte *pData);
byte* CreateInstanceOf_T_Int8(void);
void DestroyInstanceOf_T_Int8(byte *pData);

void SetDataFor_T_UInt8(void *dest, void *src);
byte* MovePtrBySizeOf_T_UInt8(byte *pData);
byte* CreateInstanceOf_T_UInt8(void);
void DestroyInstanceOf_T_UInt8(byte *pData);

void SetDataFor_T_Boolean(void *dest, void *src);
byte* MovePtrBySizeOf_T_Boolean(byte *pData);
byte* CreateInstanceOf_T_Boolean(void);
void DestroyInstanceOf_T_Boolean(byte *pData);

void SetDataFor_T_Null_Record(void *dest, void *src);
byte* MovePtrBySizeOf_T_Null_Record(byte *pData);
byte* CreateInstanceOf_T_Null_Record(void);
void DestroyInstanceOf_T_Null_Record(byte *pData);

void SetDataFor_PID(void *dest, void *src);
byte* MovePtrBySizeOf_PID(byte *pData);
byte* CreateInstanceOf_PID(void);
void DestroyInstanceOf_PID(byte *pData);

void SetDataFor_int(void *dest, void *src);
byte* MovePtrBySizeOf_int(byte *pData);
byte* CreateInstanceOf_int(void);
void DestroyInstanceOf_int(byte *pData);


#endif
