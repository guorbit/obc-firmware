#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dataview-uniq_getset.h"

size_t GetStreamCurrentLength(BitStream *pBitStrm) {
    return pBitStrm->currentByte + ((pBitStrm->currentBit+7)/8);
}

byte *GetBitstreamBuffer(BitStream *pBitStrm) {
    return pBitStrm->buf;
}

byte GetBufferByte(byte *p, size_t off) {
    assert(p);
    return p[off];
}

void SetBufferByte(byte *p, size_t off, byte b) {
    assert(p);
    p[off] = b;
}

void ResetStream(BitStream *pStrm) {
    assert(pStrm);
    assert(pStrm->count >= 0);
    pStrm->currentByte = 0;
    pStrm->currentBit = 0;
}

BitStream *CreateStream(size_t bufferSize) {
    BitStream *pBitStrm = malloc(sizeof(BitStream));
    assert(pBitStrm);
    unsigned char* buf = malloc(bufferSize);
    assert(buf);
    memset(buf, 0x0, bufferSize);
    BitStream_Init(pBitStrm, buf, bufferSize);
    return pBitStrm;
}

void DestroyStream(BitStream *pBitStrm) {
    assert(pBitStrm);
    assert(pBitStrm->buf);
    free(pBitStrm->buf);
    free(pBitStrm);
}


/* INTEGER */
asn1SccUint CounterK__Get(CounterK* root)
{
    return (*root);
}

/* INTEGER */
void CounterK__Set(CounterK* root, asn1SccUint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccUint Time_UNIX__Get(Time_UNIX* root)
{
    return (*root);
}

/* INTEGER */
void Time_UNIX__Set(Time_UNIX* root, asn1SccUint value)
{
    (*root) = value;
}

/* REAL */
double Latitude_WGS84__Get(Latitude_WGS84* root)
{
    return (*root);
}

/* REAL */
void Latitude_WGS84__Set(Latitude_WGS84* root, double value)
{
    (*root) = value;
}

/* REAL */
double Longitude_WGS84__Get(Longitude_WGS84* root)
{
    return (*root);
}

/* REAL */
void Longitude_WGS84__Set(Longitude_WGS84* root, double value)
{
    (*root) = value;
}

/* REAL */
double Location__lat_Get(Location* root)
{
    return (*root).lat;
}

/* REAL */
void Location__lat_Set(Location* root, double value)
{
    (*root).lat = value;
}

/* REAL */
double Location__lon_Get(Location* root)
{
    return (*root).lon;
}

/* REAL */
void Location__lon_Set(Location* root, double value)
{
    (*root).lon = value;
}

/* INTEGER */
asn1SccUint Location_Fix_Packet__t_Get(Location_Fix_Packet* root)
{
    return (*root).t;
}

/* INTEGER */
void Location_Fix_Packet__t_Set(Location_Fix_Packet* root, asn1SccUint value)
{
    (*root).t = value;
}

/* REAL */
double Location_Fix_Packet__lat_Get(Location_Fix_Packet* root)
{
    return (*root).lat;
}

/* REAL */
void Location_Fix_Packet__lat_Set(Location_Fix_Packet* root, double value)
{
    (*root).lat = value;
}

/* REAL */
double Location_Fix_Packet__lon_Get(Location_Fix_Packet* root)
{
    return (*root).lon;
}

/* REAL */
void Location_Fix_Packet__lon_Set(Location_Fix_Packet* root, double value)
{
    (*root).lon = value;
}

/* REAL */
double Temperature_Generic__Get(Temperature_Generic* root)
{
    return (*root);
}

/* REAL */
void Temperature_Generic__Set(Temperature_Generic* root, double value)
{
    (*root) = value;
}

/* BOOLEAN */
flag Deployment_Digital__Get(Deployment_Digital* root)
{
    return (*root);
}

/* BOOLEAN */
void Deployment_Digital__Set(Deployment_Digital* root, flag value)
{
    (*root) = value;
}

/* REAL */
double Deployment_Analogue__Get(Deployment_Analogue* root)
{
    return (*root);
}

/* REAL */
void Deployment_Analogue__Set(Deployment_Analogue* root, double value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccUint System_Mode__Get(System_Mode* root)
{
    return (*root);
}

/* INTEGER */
void System_Mode__Set(System_Mode* root, asn1SccUint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccUint Subsystem_Address__Get(Subsystem_Address* root)
{
    return (*root);
}

/* INTEGER */
void Subsystem_Address__Set(Subsystem_Address* root, asn1SccUint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccUint Mode_Change_Packet__target_addr_Get(Mode_Change_Packet* root)
{
    return (*root).target_addr;
}

/* INTEGER */
void Mode_Change_Packet__target_addr_Set(Mode_Change_Packet* root, asn1SccUint value)
{
    (*root).target_addr = value;
}

/* INTEGER */
asn1SccUint Mode_Change_Packet__target_mode_Get(Mode_Change_Packet* root)
{
    return (*root).target_mode;
}

/* INTEGER */
void Mode_Change_Packet__target_mode_Set(Mode_Change_Packet* root, asn1SccUint value)
{
    (*root).target_mode = value;
}

/* INTEGER */
asn1SccUint Mode_Change_Packet__ttl_ms_Get(Mode_Change_Packet* root)
{
    return (*root).ttl_ms;
}

/* INTEGER */
void Mode_Change_Packet__ttl_ms_Set(Mode_Change_Packet* root, asn1SccUint value)
{
    (*root).ttl_ms = value;
}

/* INTEGER */
asn1SccSint T_Int32__Get(T_Int32* root)
{
    return (*root);
}

/* INTEGER */
void T_Int32__Set(T_Int32* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccUint T_UInt32__Get(T_UInt32* root)
{
    return (*root);
}

/* INTEGER */
void T_UInt32__Set(T_UInt32* root, asn1SccUint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint T_Int8__Get(T_Int8* root)
{
    return (*root);
}

/* INTEGER */
void T_Int8__Set(T_Int8* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccUint T_UInt8__Get(T_UInt8* root)
{
    return (*root);
}

/* INTEGER */
void T_UInt8__Set(T_UInt8* root, asn1SccUint value)
{
    (*root) = value;
}

/* BOOLEAN */
flag T_Boolean__Get(T_Boolean* root)
{
    return (*root);
}

/* BOOLEAN */
void T_Boolean__Set(T_Boolean* root, flag value)
{
    (*root) = value;
}

/* ENUMERATED */
int PID__Get(PID* root)
{
    return (*root);
}

/* ENUMERATED */
void PID__Set(PID* root, int value)
{
    (*root) = value;
}

/* Helper functions for NATIVE encodings */

void SetDataFor_CounterK(void *dest, void *src)
{
    memcpy(dest, src, sizeof(CounterK));
}

byte* MovePtrBySizeOf_CounterK(byte *pData)
{
    return pData + sizeof(CounterK);
}

byte* CreateInstanceOf_CounterK() {
    CounterK *p = (CounterK*)malloc(sizeof(CounterK));
    CounterK_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_CounterK(byte *pData) {
    free(pData);
}

void SetDataFor_Time_UNIX(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Time_UNIX));
}

byte* MovePtrBySizeOf_Time_UNIX(byte *pData)
{
    return pData + sizeof(Time_UNIX);
}

byte* CreateInstanceOf_Time_UNIX() {
    Time_UNIX *p = (Time_UNIX*)malloc(sizeof(Time_UNIX));
    Time_UNIX_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Time_UNIX(byte *pData) {
    free(pData);
}

void SetDataFor_Latitude_WGS84(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Latitude_WGS84));
}

byte* MovePtrBySizeOf_Latitude_WGS84(byte *pData)
{
    return pData + sizeof(Latitude_WGS84);
}

byte* CreateInstanceOf_Latitude_WGS84() {
    Latitude_WGS84 *p = (Latitude_WGS84*)malloc(sizeof(Latitude_WGS84));
    Latitude_WGS84_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Latitude_WGS84(byte *pData) {
    free(pData);
}

void SetDataFor_Longitude_WGS84(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Longitude_WGS84));
}

byte* MovePtrBySizeOf_Longitude_WGS84(byte *pData)
{
    return pData + sizeof(Longitude_WGS84);
}

byte* CreateInstanceOf_Longitude_WGS84() {
    Longitude_WGS84 *p = (Longitude_WGS84*)malloc(sizeof(Longitude_WGS84));
    Longitude_WGS84_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Longitude_WGS84(byte *pData) {
    free(pData);
}

void SetDataFor_Location(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Location));
}

byte* MovePtrBySizeOf_Location(byte *pData)
{
    return pData + sizeof(Location);
}

byte* CreateInstanceOf_Location() {
    Location *p = (Location*)malloc(sizeof(Location));
    Location_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Location(byte *pData) {
    free(pData);
}

void SetDataFor_Location_Fix_Packet(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Location_Fix_Packet));
}

byte* MovePtrBySizeOf_Location_Fix_Packet(byte *pData)
{
    return pData + sizeof(Location_Fix_Packet);
}

byte* CreateInstanceOf_Location_Fix_Packet() {
    Location_Fix_Packet *p = (Location_Fix_Packet*)malloc(sizeof(Location_Fix_Packet));
    Location_Fix_Packet_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Location_Fix_Packet(byte *pData) {
    free(pData);
}

void SetDataFor_Temperature_Generic(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Temperature_Generic));
}

byte* MovePtrBySizeOf_Temperature_Generic(byte *pData)
{
    return pData + sizeof(Temperature_Generic);
}

byte* CreateInstanceOf_Temperature_Generic() {
    Temperature_Generic *p = (Temperature_Generic*)malloc(sizeof(Temperature_Generic));
    Temperature_Generic_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Temperature_Generic(byte *pData) {
    free(pData);
}

void SetDataFor_Deployment_Digital(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Deployment_Digital));
}

byte* MovePtrBySizeOf_Deployment_Digital(byte *pData)
{
    return pData + sizeof(Deployment_Digital);
}

byte* CreateInstanceOf_Deployment_Digital() {
    Deployment_Digital *p = (Deployment_Digital*)malloc(sizeof(Deployment_Digital));
    Deployment_Digital_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Deployment_Digital(byte *pData) {
    free(pData);
}

void SetDataFor_Deployment_Analogue(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Deployment_Analogue));
}

byte* MovePtrBySizeOf_Deployment_Analogue(byte *pData)
{
    return pData + sizeof(Deployment_Analogue);
}

byte* CreateInstanceOf_Deployment_Analogue() {
    Deployment_Analogue *p = (Deployment_Analogue*)malloc(sizeof(Deployment_Analogue));
    Deployment_Analogue_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Deployment_Analogue(byte *pData) {
    free(pData);
}

void SetDataFor_System_Mode(void *dest, void *src)
{
    memcpy(dest, src, sizeof(System_Mode));
}

byte* MovePtrBySizeOf_System_Mode(byte *pData)
{
    return pData + sizeof(System_Mode);
}

byte* CreateInstanceOf_System_Mode() {
    System_Mode *p = (System_Mode*)malloc(sizeof(System_Mode));
    System_Mode_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_System_Mode(byte *pData) {
    free(pData);
}

void SetDataFor_Subsystem_Address(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Subsystem_Address));
}

byte* MovePtrBySizeOf_Subsystem_Address(byte *pData)
{
    return pData + sizeof(Subsystem_Address);
}

byte* CreateInstanceOf_Subsystem_Address() {
    Subsystem_Address *p = (Subsystem_Address*)malloc(sizeof(Subsystem_Address));
    Subsystem_Address_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Subsystem_Address(byte *pData) {
    free(pData);
}

void SetDataFor_Mode_Change_Packet(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Mode_Change_Packet));
}

byte* MovePtrBySizeOf_Mode_Change_Packet(byte *pData)
{
    return pData + sizeof(Mode_Change_Packet);
}

byte* CreateInstanceOf_Mode_Change_Packet() {
    Mode_Change_Packet *p = (Mode_Change_Packet*)malloc(sizeof(Mode_Change_Packet));
    Mode_Change_Packet_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Mode_Change_Packet(byte *pData) {
    free(pData);
}

void SetDataFor_T_Int32(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Int32));
}

byte* MovePtrBySizeOf_T_Int32(byte *pData)
{
    return pData + sizeof(T_Int32);
}

byte* CreateInstanceOf_T_Int32() {
    T_Int32 *p = (T_Int32*)malloc(sizeof(T_Int32));
    T_Int32_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Int32(byte *pData) {
    free(pData);
}

void SetDataFor_T_UInt32(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_UInt32));
}

byte* MovePtrBySizeOf_T_UInt32(byte *pData)
{
    return pData + sizeof(T_UInt32);
}

byte* CreateInstanceOf_T_UInt32() {
    T_UInt32 *p = (T_UInt32*)malloc(sizeof(T_UInt32));
    T_UInt32_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_UInt32(byte *pData) {
    free(pData);
}

void SetDataFor_T_Int8(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Int8));
}

byte* MovePtrBySizeOf_T_Int8(byte *pData)
{
    return pData + sizeof(T_Int8);
}

byte* CreateInstanceOf_T_Int8() {
    T_Int8 *p = (T_Int8*)malloc(sizeof(T_Int8));
    T_Int8_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Int8(byte *pData) {
    free(pData);
}

void SetDataFor_T_UInt8(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_UInt8));
}

byte* MovePtrBySizeOf_T_UInt8(byte *pData)
{
    return pData + sizeof(T_UInt8);
}

byte* CreateInstanceOf_T_UInt8() {
    T_UInt8 *p = (T_UInt8*)malloc(sizeof(T_UInt8));
    T_UInt8_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_UInt8(byte *pData) {
    free(pData);
}

void SetDataFor_T_Boolean(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Boolean));
}

byte* MovePtrBySizeOf_T_Boolean(byte *pData)
{
    return pData + sizeof(T_Boolean);
}

byte* CreateInstanceOf_T_Boolean() {
    T_Boolean *p = (T_Boolean*)malloc(sizeof(T_Boolean));
    T_Boolean_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Boolean(byte *pData) {
    free(pData);
}

void SetDataFor_T_Null_Record(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Null_Record));
}

byte* MovePtrBySizeOf_T_Null_Record(byte *pData)
{
    return pData + sizeof(T_Null_Record);
}

byte* CreateInstanceOf_T_Null_Record() {
    T_Null_Record *p = (T_Null_Record*)malloc(sizeof(T_Null_Record));
    T_Null_Record_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Null_Record(byte *pData) {
    free(pData);
}

void SetDataFor_PID(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PID));
}

byte* MovePtrBySizeOf_PID(byte *pData)
{
    return pData + sizeof(PID);
}

byte* CreateInstanceOf_PID() {
    PID *p = (PID*)malloc(sizeof(PID));
    PID_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PID(byte *pData) {
    free(pData);
}

void SetDataFor_int(void *dest, void *src)
{
    memcpy(dest, src, sizeof(int));
}

byte* MovePtrBySizeOf_int(byte *pData)
{
    return pData + sizeof(int);
}

byte* CreateInstanceOf_int() {
    int *p = (int*)malloc(sizeof(int));
    *p = 0;
    return (byte*)p;
}

void DestroyInstanceOf_int(byte *pData) {
    free(pData);
}

