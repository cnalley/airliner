# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_AMC_HkTlm_t.proto

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
  name='_py_AMC_HkTlm_t.proto',
  package='',
  serialized_pb=_b('\n\x15_py_AMC_HkTlm_t.proto\"|\n\x0e\x41MC_HkTlm_t_pb\x12\r\n\x05\x43ount\x18\x01 \x02(\r\x12\x11\n\tTimestamp\x18\x02 \x02(\x04\x12\x10\n\x08usCmdCnt\x18\x03 \x02(\r\x12\x11\n\tTlmHeader\x18\x04 \x03(\r\x12\x13\n\x0busCmdErrCnt\x18\x05 \x02(\r\x12\x0e\n\x06Output\x18\x06 \x03(\x02')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_AMC_HKTLM_T_PB = _descriptor.Descriptor(
  name='AMC_HkTlm_t_pb',
  full_name='AMC_HkTlm_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Count', full_name='AMC_HkTlm_t_pb.Count', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Timestamp', full_name='AMC_HkTlm_t_pb.Timestamp', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='usCmdCnt', full_name='AMC_HkTlm_t_pb.usCmdCnt', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TlmHeader', full_name='AMC_HkTlm_t_pb.TlmHeader', index=3,
      number=4, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='usCmdErrCnt', full_name='AMC_HkTlm_t_pb.usCmdErrCnt', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Output', full_name='AMC_HkTlm_t_pb.Output', index=5,
      number=6, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=25,
  serialized_end=149,
)

DESCRIPTOR.message_types_by_name['AMC_HkTlm_t_pb'] = _AMC_HKTLM_T_PB

AMC_HkTlm_t_pb = _reflection.GeneratedProtocolMessageType('AMC_HkTlm_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _AMC_HKTLM_T_PB,
  __module__ = '_py_AMC_HkTlm_t_pb2'
  # @@protoc_insertion_point(class_scope:AMC_HkTlm_t_pb)
  ))
_sym_db.RegisterMessage(AMC_HkTlm_t_pb)


# @@protoc_insertion_point(module_scope)
