# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_GPS_NAV_PVT_t.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='_py_GPS_NAV_PVT_t.proto',
  package='',
  serialized_pb=_b('\n\x17_py_GPS_NAV_PVT_t.proto\"\xff\x03\n\x10GPS_NAV_PVT_t_pb\x12\x0c\n\x04hMSL\x18\x01 \x02(\x05\x12\x0e\n\x06height\x18\x02 \x02(\x05\x12\x0b\n\x03sec\x18\x03 \x02(\r\x12\x0c\n\x04year\x18\x04 \x02(\r\x12\x0e\n\x06magDec\x18\x05 \x02(\x05\x12\x11\n\treserved3\x18\x06 \x02(\r\x12\x11\n\treserved2\x18\x07 \x02(\r\x12\x0c\n\x04velN\x18\x08 \x02(\x05\x12\x0f\n\x07headMot\x18\t \x02(\x05\x12\x0c\n\x04nano\x18\n \x02(\x05\x12\x0b\n\x03min\x18\x0b \x02(\r\x12\x0f\n\x07headAcc\x18\x0c \x02(\r\x12\x0c\n\x04velD\x18\r \x02(\x05\x12\x0b\n\x03lon\x18\x0e \x02(\x05\x12\r\n\x05valid\x18\x0f \x02(\r\x12\x0c\n\x04vAcc\x18\x10 \x02(\r\x12\r\n\x05numSV\x18\x11 \x02(\r\x12\x0c\n\x04tAcc\x18\x12 \x02(\r\x12\x0c\n\x04hAcc\x18\x13 \x02(\r\x12\x0e\n\x06gSpeed\x18\x14 \x02(\x05\x12\x0c\n\x04pDOP\x18\x15 \x02(\r\x12\x0c\n\x04iTOW\x18\x16 \x02(\r\x12\x0b\n\x03lat\x18\x17 \x02(\x05\x12\r\n\x05month\x18\x18 \x02(\r\x12\x0b\n\x03\x64\x61y\x18\x19 \x02(\r\x12\x0c\n\x04sAcc\x18\x1a \x02(\r\x12\x0f\n\x07\x66ixType\x18\x1b \x02(\r\x12\x0c\n\x04hour\x18\x1c \x02(\r\x12\x0e\n\x06\x66lags2\x18\x1d \x02(\r\x12\x0e\n\x06magAcc\x18\x1e \x02(\r\x12\r\n\x05\x66lags\x18\x1f \x02(\r\x12\x0f\n\x07headVeh\x18  \x02(\x05\x12\x0c\n\x04velE\x18! \x02(\x05')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_GPS_NAV_PVT_T_PB = _descriptor.Descriptor(
  name='GPS_NAV_PVT_t_pb',
  full_name='GPS_NAV_PVT_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='hMSL', full_name='GPS_NAV_PVT_t_pb.hMSL', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='height', full_name='GPS_NAV_PVT_t_pb.height', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sec', full_name='GPS_NAV_PVT_t_pb.sec', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='year', full_name='GPS_NAV_PVT_t_pb.year', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='magDec', full_name='GPS_NAV_PVT_t_pb.magDec', index=4,
      number=5, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='reserved3', full_name='GPS_NAV_PVT_t_pb.reserved3', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='reserved2', full_name='GPS_NAV_PVT_t_pb.reserved2', index=6,
      number=7, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='velN', full_name='GPS_NAV_PVT_t_pb.velN', index=7,
      number=8, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='headMot', full_name='GPS_NAV_PVT_t_pb.headMot', index=8,
      number=9, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='nano', full_name='GPS_NAV_PVT_t_pb.nano', index=9,
      number=10, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='min', full_name='GPS_NAV_PVT_t_pb.min', index=10,
      number=11, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='headAcc', full_name='GPS_NAV_PVT_t_pb.headAcc', index=11,
      number=12, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='velD', full_name='GPS_NAV_PVT_t_pb.velD', index=12,
      number=13, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='lon', full_name='GPS_NAV_PVT_t_pb.lon', index=13,
      number=14, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='valid', full_name='GPS_NAV_PVT_t_pb.valid', index=14,
      number=15, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='vAcc', full_name='GPS_NAV_PVT_t_pb.vAcc', index=15,
      number=16, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='numSV', full_name='GPS_NAV_PVT_t_pb.numSV', index=16,
      number=17, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='tAcc', full_name='GPS_NAV_PVT_t_pb.tAcc', index=17,
      number=18, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='hAcc', full_name='GPS_NAV_PVT_t_pb.hAcc', index=18,
      number=19, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='gSpeed', full_name='GPS_NAV_PVT_t_pb.gSpeed', index=19,
      number=20, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pDOP', full_name='GPS_NAV_PVT_t_pb.pDOP', index=20,
      number=21, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='iTOW', full_name='GPS_NAV_PVT_t_pb.iTOW', index=21,
      number=22, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='lat', full_name='GPS_NAV_PVT_t_pb.lat', index=22,
      number=23, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='month', full_name='GPS_NAV_PVT_t_pb.month', index=23,
      number=24, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='day', full_name='GPS_NAV_PVT_t_pb.day', index=24,
      number=25, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sAcc', full_name='GPS_NAV_PVT_t_pb.sAcc', index=25,
      number=26, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='fixType', full_name='GPS_NAV_PVT_t_pb.fixType', index=26,
      number=27, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='hour', full_name='GPS_NAV_PVT_t_pb.hour', index=27,
      number=28, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='flags2', full_name='GPS_NAV_PVT_t_pb.flags2', index=28,
      number=29, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='magAcc', full_name='GPS_NAV_PVT_t_pb.magAcc', index=29,
      number=30, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='flags', full_name='GPS_NAV_PVT_t_pb.flags', index=30,
      number=31, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='headVeh', full_name='GPS_NAV_PVT_t_pb.headVeh', index=31,
      number=32, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='velE', full_name='GPS_NAV_PVT_t_pb.velE', index=32,
      number=33, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=28,
  serialized_end=539,
)

DESCRIPTOR.message_types_by_name['GPS_NAV_PVT_t_pb'] = _GPS_NAV_PVT_T_PB

GPS_NAV_PVT_t_pb = _reflection.GeneratedProtocolMessageType('GPS_NAV_PVT_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _GPS_NAV_PVT_T_PB,
  __module__ = '_py_GPS_NAV_PVT_t_pb2'
  # @@protoc_insertion_point(class_scope:GPS_NAV_PVT_t_pb)
  ))
_sym_db.RegisterMessage(GPS_NAV_PVT_t_pb)


# @@protoc_insertion_point(module_scope)
