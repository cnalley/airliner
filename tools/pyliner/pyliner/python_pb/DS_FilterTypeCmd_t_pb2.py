# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_DS_FilterTypeCmd_t.proto

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
  name='_py_DS_FilterTypeCmd_t.proto',
  package='',
  serialized_pb=_b('\n\x1c_py_DS_FilterTypeCmd_t.proto\"|\n\x15\x44S_FilterTypeCmd_t_pb\x12\x0f\n\x07Padding\x18\x01 \x02(\r\x12\x12\n\nFilterType\x18\x02 \x02(\r\x12\x18\n\x10\x46ilterParmsIndex\x18\x03 \x02(\r\x12\x11\n\tCmdHeader\x18\x04 \x03(\r\x12\x11\n\tMessageID\x18\x05 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_DS_FILTERTYPECMD_T_PB = _descriptor.Descriptor(
  name='DS_FilterTypeCmd_t_pb',
  full_name='DS_FilterTypeCmd_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Padding', full_name='DS_FilterTypeCmd_t_pb.Padding', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FilterType', full_name='DS_FilterTypeCmd_t_pb.FilterType', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FilterParmsIndex', full_name='DS_FilterTypeCmd_t_pb.FilterParmsIndex', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CmdHeader', full_name='DS_FilterTypeCmd_t_pb.CmdHeader', index=3,
      number=4, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MessageID', full_name='DS_FilterTypeCmd_t_pb.MessageID', index=4,
      number=5, type=13, cpp_type=3, label=2,
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
  serialized_start=32,
  serialized_end=156,
)

DESCRIPTOR.message_types_by_name['DS_FilterTypeCmd_t_pb'] = _DS_FILTERTYPECMD_T_PB

DS_FilterTypeCmd_t_pb = _reflection.GeneratedProtocolMessageType('DS_FilterTypeCmd_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _DS_FILTERTYPECMD_T_PB,
  __module__ = '_py_DS_FilterTypeCmd_t_pb2'
  # @@protoc_insertion_point(class_scope:DS_FilterTypeCmd_t_pb)
  ))
_sym_db.RegisterMessage(DS_FilterTypeCmd_t_pb)


# @@protoc_insertion_point(module_scope)
