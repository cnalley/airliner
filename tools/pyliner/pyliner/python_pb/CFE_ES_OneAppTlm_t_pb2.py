# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CFE_ES_OneAppTlm_t.proto

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
  name='_py_CFE_ES_OneAppTlm_t.proto',
  package='',
  serialized_pb=_b('\n\x1c_py_CFE_ES_OneAppTlm_t.proto\"9\n\x10\x43\x46\x45_ES_AppInfo_t\x12%\n\x07\x41ppInfo\x18\x01 \x02(\x0b\x32\x14.CFE_ES_AppInfo_t_pb\"\xb7\x03\n\x13\x43\x46\x45_ES_AppInfo_t_pb\x12\x0c\n\x04Type\x18\x01 \x02(\r\x12\x18\n\x10\x45xecutionCounter\x18\x02 \x02(\r\x12\x0c\n\x04Name\x18\x03 \x02(\t\x12\x14\n\x0cMainTaskName\x18\x04 \x02(\t\x12\x13\n\x0b\x43odeAddress\x18\x05 \x02(\r\x12\x10\n\x08\x43odeSize\x18\x06 \x02(\r\x12\x10\n\x08\x46ileName\x18\x07 \x02(\t\x12\x10\n\x08Priority\x18\x08 \x02(\r\x12\x0f\n\x07\x42SSSize\x18\t \x02(\r\x12\x13\n\x0b\x44\x61taAddress\x18\n \x02(\r\x12\x12\n\nMainTaskId\x18\x0b \x02(\r\x12\x12\n\nBSSAddress\x18\x0c \x02(\r\x12\r\n\x05\x41ppId\x18\r \x02(\r\x12\x14\n\x0cStartAddress\x18\x0e \x02(\r\x12\x19\n\x11\x41\x64\x64ressesAreValid\x18\x0f \x02(\r\x12\x11\n\tStackSize\x18\x10 \x02(\r\x12\x10\n\x08\x44\x61taSize\x18\x11 \x02(\r\x12\x17\n\x0fNumOfChildTasks\x18\x12 \x02(\r\x12\x12\n\nEntryPoint\x18\x13 \x02(\t\x12\x17\n\x0f\x45xceptionAction\x18\x14 \x02(\r\x12\x10\n\x08ModuleId\x18\x15 \x02(\r\"N\n\x15\x43\x46\x45_ES_OneAppTlm_t_pb\x12\x11\n\tTlmHeader\x18\x01 \x03(\r\x12\"\n\x07Payload\x18\x02 \x02(\x0b\x32\x11.CFE_ES_AppInfo_t')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CFE_ES_APPINFO_T = _descriptor.Descriptor(
  name='CFE_ES_AppInfo_t',
  full_name='CFE_ES_AppInfo_t',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='AppInfo', full_name='CFE_ES_AppInfo_t.AppInfo', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
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
  serialized_end=89,
)


_CFE_ES_APPINFO_T_PB = _descriptor.Descriptor(
  name='CFE_ES_AppInfo_t_pb',
  full_name='CFE_ES_AppInfo_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Type', full_name='CFE_ES_AppInfo_t_pb.Type', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ExecutionCounter', full_name='CFE_ES_AppInfo_t_pb.ExecutionCounter', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Name', full_name='CFE_ES_AppInfo_t_pb.Name', index=2,
      number=3, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MainTaskName', full_name='CFE_ES_AppInfo_t_pb.MainTaskName', index=3,
      number=4, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CodeAddress', full_name='CFE_ES_AppInfo_t_pb.CodeAddress', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CodeSize', full_name='CFE_ES_AppInfo_t_pb.CodeSize', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileName', full_name='CFE_ES_AppInfo_t_pb.FileName', index=6,
      number=7, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Priority', full_name='CFE_ES_AppInfo_t_pb.Priority', index=7,
      number=8, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='BSSSize', full_name='CFE_ES_AppInfo_t_pb.BSSSize', index=8,
      number=9, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DataAddress', full_name='CFE_ES_AppInfo_t_pb.DataAddress', index=9,
      number=10, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MainTaskId', full_name='CFE_ES_AppInfo_t_pb.MainTaskId', index=10,
      number=11, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='BSSAddress', full_name='CFE_ES_AppInfo_t_pb.BSSAddress', index=11,
      number=12, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AppId', full_name='CFE_ES_AppInfo_t_pb.AppId', index=12,
      number=13, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='StartAddress', full_name='CFE_ES_AppInfo_t_pb.StartAddress', index=13,
      number=14, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AddressesAreValid', full_name='CFE_ES_AppInfo_t_pb.AddressesAreValid', index=14,
      number=15, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='StackSize', full_name='CFE_ES_AppInfo_t_pb.StackSize', index=15,
      number=16, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DataSize', full_name='CFE_ES_AppInfo_t_pb.DataSize', index=16,
      number=17, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='NumOfChildTasks', full_name='CFE_ES_AppInfo_t_pb.NumOfChildTasks', index=17,
      number=18, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='EntryPoint', full_name='CFE_ES_AppInfo_t_pb.EntryPoint', index=18,
      number=19, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ExceptionAction', full_name='CFE_ES_AppInfo_t_pb.ExceptionAction', index=19,
      number=20, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ModuleId', full_name='CFE_ES_AppInfo_t_pb.ModuleId', index=20,
      number=21, type=13, cpp_type=3, label=2,
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
  serialized_start=92,
  serialized_end=531,
)


_CFE_ES_ONEAPPTLM_T_PB = _descriptor.Descriptor(
  name='CFE_ES_OneAppTlm_t_pb',
  full_name='CFE_ES_OneAppTlm_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='TlmHeader', full_name='CFE_ES_OneAppTlm_t_pb.TlmHeader', index=0,
      number=1, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Payload', full_name='CFE_ES_OneAppTlm_t_pb.Payload', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
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
  serialized_start=533,
  serialized_end=611,
)

_CFE_ES_APPINFO_T.fields_by_name['AppInfo'].message_type = _CFE_ES_APPINFO_T_PB
_CFE_ES_ONEAPPTLM_T_PB.fields_by_name['Payload'].message_type = _CFE_ES_APPINFO_T
DESCRIPTOR.message_types_by_name['CFE_ES_AppInfo_t'] = _CFE_ES_APPINFO_T
DESCRIPTOR.message_types_by_name['CFE_ES_AppInfo_t_pb'] = _CFE_ES_APPINFO_T_PB
DESCRIPTOR.message_types_by_name['CFE_ES_OneAppTlm_t_pb'] = _CFE_ES_ONEAPPTLM_T_PB

CFE_ES_AppInfo_t = _reflection.GeneratedProtocolMessageType('CFE_ES_AppInfo_t', (_message.Message,), dict(
  DESCRIPTOR = _CFE_ES_APPINFO_T,
  __module__ = '_py_CFE_ES_OneAppTlm_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_ES_AppInfo_t)
  ))
_sym_db.RegisterMessage(CFE_ES_AppInfo_t)

CFE_ES_AppInfo_t_pb = _reflection.GeneratedProtocolMessageType('CFE_ES_AppInfo_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_ES_APPINFO_T_PB,
  __module__ = '_py_CFE_ES_OneAppTlm_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_ES_AppInfo_t_pb)
  ))
_sym_db.RegisterMessage(CFE_ES_AppInfo_t_pb)

CFE_ES_OneAppTlm_t_pb = _reflection.GeneratedProtocolMessageType('CFE_ES_OneAppTlm_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_ES_ONEAPPTLM_T_PB,
  __module__ = '_py_CFE_ES_OneAppTlm_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_ES_OneAppTlm_t_pb)
  ))
_sym_db.RegisterMessage(CFE_ES_OneAppTlm_t_pb)


# @@protoc_insertion_point(module_scope)
