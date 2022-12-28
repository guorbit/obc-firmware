
#  SQLAlchemy models for types used in "obc_model.asn"

from sqlalchemy.ext.declarative import declarative_base
Base = declarative_base()

from sqlalchemy import (Column, Integer, String, Boolean, Float,
                        ForeignKey, CheckConstraint, UniqueConstraint)
from sqlalchemy.orm import relationship

from obc_model_asn import (
    CounterK, Deployment_Analogue, Deployment_Digital, Latitude_WGS84, Location, Location_Fix_Packet, Longitude_WGS84, Mode_Change_Packet, PID, Subsystem_Address, System_Mode, T_Boolean, T_Int32, T_Int8, T_Null_Record, T_UInt32, T_UInt8, Temperature_Generic, Time_UNIX
)

import DV


class CounterK_SQL(Base):
    __tablename__ = 'CounterK'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=1000'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            CounterK_SQL).filter(CounterK_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = CounterK()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Deployment_Analogue_SQL(Base):
    __tablename__ = 'Deployment_Analogue'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Float, CheckConstraint('data>=0.0 and data<=100.0'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Deployment_Analogue_SQL).filter(Deployment_Analogue_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Deployment_Analogue()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Deployment_Digital_SQL(Base):
    __tablename__ = 'Deployment_Digital'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Boolean, nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Deployment_Digital_SQL).filter(Deployment_Digital_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Deployment_Digital()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Latitude_WGS84_SQL(Base):
    __tablename__ = 'Latitude_WGS84'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Float, CheckConstraint('data>=-90.0 and data<=90.0'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Latitude_WGS84_SQL).filter(Latitude_WGS84_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Latitude_WGS84()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Longitude_WGS84_SQL(Base):
    __tablename__ = 'Longitude_WGS84'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Float, CheckConstraint('data>=-180.0 and data<=180.0'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Longitude_WGS84_SQL).filter(Longitude_WGS84_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Longitude_WGS84()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Mode_Change_Packet_ttl_ms_SQL(Base):
    __tablename__ = 'Mode_Change_Packet_ttl_ms'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=10000'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Mode_Change_Packet_ttl_ms_SQL).filter(Mode_Change_Packet_ttl_ms_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Mode_Change_Packet_ttl_ms()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class PID_SQL(Base):
    __tablename__ = 'PID'
    __table_args__ = (UniqueConstraint('iid'),)
    loc_provider = 0
    state_handler_entrypoint = 1
    tc_provider = 2
    tc_validation = 3
    tm_collection = 4
    tm_provider = 5
    env = 6
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data=0 OR data=1 OR data=2 OR data=3 OR data=4 OR data=5 OR data=6'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PID_SQL).filter(PID_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PID()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Subsystem_Address_SQL(Base):
    __tablename__ = 'Subsystem_Address'
    __table_args__ = (UniqueConstraint('iid'),)
    obc = 0
    comms = 1
    electrical = 2
    mechanical = 3
    control = 4
    software = 5
    payload = 6
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data=0 OR data=1 OR data=2 OR data=3 OR data=4 OR data=5 OR data=6'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Subsystem_Address_SQL).filter(Subsystem_Address_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Subsystem_Address()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class System_Mode_SQL(Base):
    __tablename__ = 'System_Mode'
    __table_args__ = (UniqueConstraint('iid'),)
    idle = 0
    uplink = 1
    downlink = 2
    imaging = 3
    processing = 4
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data=0 OR data=1 OR data=2 OR data=3 OR data=4'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            System_Mode_SQL).filter(System_Mode_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = System_Mode()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Boolean_SQL(Base):
    __tablename__ = 'T_Boolean'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Boolean, nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Boolean_SQL).filter(T_Boolean_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Boolean()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Int32_SQL(Base):
    __tablename__ = 'T_Int32'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=-2147483648 and data<=2147483647'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Int32_SQL).filter(T_Int32_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Int32()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Int8_SQL(Base):
    __tablename__ = 'T_Int8'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=-128 and data<=127'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Int8_SQL).filter(T_Int8_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Int8()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Null_Record_SQL(Base):
    __tablename__ = 'T_Null_Record'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Null_Record_SQL).filter(T_Null_Record_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Null_Record()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


    def __init__(self, pyObj):
        state = pyObj.GetState()


class T_UInt32_SQL(Base):
    __tablename__ = 'T_UInt32'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=4294967295'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_UInt32_SQL).filter(T_UInt32_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_UInt32()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_UInt8_SQL(Base):
    __tablename__ = 'T_UInt8'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=255'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_UInt8_SQL).filter(T_UInt8_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_UInt8()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Temperature_Generic_SQL(Base):
    __tablename__ = 'Temperature_Generic'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Float, CheckConstraint('data>=-200.0 and data<=200.0'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Temperature_Generic_SQL).filter(Temperature_Generic_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Temperature_Generic()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Time_UNIX_SQL(Base):
    __tablename__ = 'Time_UNIX'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=4294967294'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Time_UNIX_SQL).filter(Time_UNIX_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Time_UNIX()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class Location_SQL(Base):
    __tablename__ = 'Location'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Location_SQL).filter(Location_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Location()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.lat.assignToASN1object(pyObj.lat)
        pyObj.Reset(state)
        self.lon.assignToASN1object(pyObj.lon)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_lat_iid = Column(Integer, ForeignKey('Latitude_WGS84.iid'), nullable=False)
    lat = relationship(
        "Latitude_WGS84_SQL",
        foreign_keys=[fk_lat_iid])
    fk_lon_iid = Column(Integer, ForeignKey('Longitude_WGS84.iid'), nullable=False)
    lon = relationship(
        "Longitude_WGS84_SQL",
        foreign_keys=[fk_lon_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.lat = Latitude_WGS84_SQL(pyObj.lat)
        pyObj.Reset(state)
        self.lon = Longitude_WGS84_SQL(pyObj.lon)
        pyObj.Reset(state)


class Location_Fix_Packet_SQL(Base):
    __tablename__ = 'Location_Fix_Packet'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Location_Fix_Packet_SQL).filter(Location_Fix_Packet_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Location_Fix_Packet()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.t.assignToASN1object(pyObj.t)
        pyObj.Reset(state)
        self.lat.assignToASN1object(pyObj.lat)
        pyObj.Reset(state)
        self.lon.assignToASN1object(pyObj.lon)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_t_iid = Column(Integer, ForeignKey('Time_UNIX.iid'), nullable=False)
    t = relationship(
        "Time_UNIX_SQL",
        foreign_keys=[fk_t_iid])
    fk_lat_iid = Column(Integer, ForeignKey('Latitude_WGS84.iid'), nullable=False)
    lat = relationship(
        "Latitude_WGS84_SQL",
        foreign_keys=[fk_lat_iid])
    fk_lon_iid = Column(Integer, ForeignKey('Longitude_WGS84.iid'), nullable=False)
    lon = relationship(
        "Longitude_WGS84_SQL",
        foreign_keys=[fk_lon_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.t = Time_UNIX_SQL(pyObj.t)
        pyObj.Reset(state)
        self.lat = Latitude_WGS84_SQL(pyObj.lat)
        pyObj.Reset(state)
        self.lon = Longitude_WGS84_SQL(pyObj.lon)
        pyObj.Reset(state)


class Mode_Change_Packet_SQL(Base):
    __tablename__ = 'Mode_Change_Packet'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Mode_Change_Packet_SQL).filter(Mode_Change_Packet_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Mode_Change_Packet()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.target_addr.assignToASN1object(pyObj.target_addr)
        pyObj.Reset(state)
        self.target_mode.assignToASN1object(pyObj.target_mode)
        pyObj.Reset(state)
        self.ttl_ms.assignToASN1object(pyObj.ttl_ms)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_target_addr_iid = Column(Integer, ForeignKey('Subsystem_Address.iid'), nullable=False)
    target_addr = relationship(
        "Subsystem_Address_SQL",
        foreign_keys=[fk_target_addr_iid])
    fk_target_mode_iid = Column(Integer, ForeignKey('System_Mode.iid'), nullable=False)
    target_mode = relationship(
        "System_Mode_SQL",
        foreign_keys=[fk_target_mode_iid])
    fk_ttl_ms_iid = Column(Integer, ForeignKey('Mode_Change_Packet_ttl_ms.iid'), nullable=False)
    ttl_ms = relationship(
        "Mode_Change_Packet_ttl_ms_SQL",
        foreign_keys=[fk_ttl_ms_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.target_addr = Subsystem_Address_SQL(pyObj.target_addr)
        pyObj.Reset(state)
        self.target_mode = System_Mode_SQL(pyObj.target_mode)
        pyObj.Reset(state)
        self.ttl_ms = Mode_Change_Packet_ttl_ms_SQL(pyObj.ttl_ms)
        pyObj.Reset(state)

