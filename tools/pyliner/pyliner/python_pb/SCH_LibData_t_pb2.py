# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_SCH_LibData_t.proto

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
  name='_py_SCH_LibData_t.proto',
  package='',
  serialized_pb=_b('\n\x17_py_SCH_LibData_t.proto\"1\n\x10SCH_LibData_t_pb\x12\x1d\n\x15ProcessingDisabledCtr\x18\x01 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_SCH_LIBDATA_T_PB = _descriptor.Descriptor(
  name='SCH_LibData_t_pb',
  full_name='SCH_LibData_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ProcessingDisabledCtr', full_name='SCH_LibData_t_pb.ProcessingDisabledCtr', index=0,
      number=1, type=13, cpp_type=3, label=2,
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
  serialized_start=27,
  serialized_end=76,
)

DESCRIPTOR.message_types_by_name['SCH_LibData_t_pb'] = _SCH_LIBDATA_T_PB

SCH_LibData_t_pb = _reflection.GeneratedProtocolMessageType('SCH_LibData_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _SCH_LIBDATA_T_PB,
  __module__ = '_py_SCH_LibData_t_pb2'
  # @@protoc_insertion_point(class_scope:SCH_LibData_t_pb)
  ))
_sym_db.RegisterMessage(SCH_LibData_t_pb)


# @@protoc_insertion_point(module_scope)