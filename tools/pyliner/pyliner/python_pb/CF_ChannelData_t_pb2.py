# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CF_ChannelData_t.proto

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
  name='_py_CF_ChannelData_t.proto',
  package='',
  serialized_pb=_b('\n\x1a_py_CF_ChannelData_t.proto\"C\n\rCF_Queue_t_pb\x12\x0f\n\x07HeadPtr\x18\x01 \x02(\r\x12\x0f\n\x07TailPtr\x18\x02 \x02(\r\x12\x10\n\x08\x45ntryCnt\x18\x03 \x02(\r\"\xcf\x01\n\x13\x43\x46_ChannelData_t_pb\x12\x14\n\x0cPollDirTimer\x18\x01 \x02(\r\x12\x1b\n\x03PbQ\x18\x02 \x03(\x0b\x32\x0e.CF_Queue_t_pb\x12\x12\n\nPendQTimer\x18\x03 \x02(\r\x12\x18\n\x10TransNumBlasting\x18\x04 \x02(\r\x12\x15\n\rZeroCpyHandle\x18\x05 \x02(\r\x12\x16\n\x0eHandshakeSemId\x18\x06 \x02(\r\x12\x15\n\rZeroCpyMsgPtr\x18\x07 \x02(\r\x12\x11\n\tDataBlast\x18\x08 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CF_QUEUE_T_PB = _descriptor.Descriptor(
  name='CF_Queue_t_pb',
  full_name='CF_Queue_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='HeadPtr', full_name='CF_Queue_t_pb.HeadPtr', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TailPtr', full_name='CF_Queue_t_pb.TailPtr', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='EntryCnt', full_name='CF_Queue_t_pb.EntryCnt', index=2,
      number=3, type=13, cpp_type=3, label=2,
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
  serialized_start=30,
  serialized_end=97,
)


_CF_CHANNELDATA_T_PB = _descriptor.Descriptor(
  name='CF_ChannelData_t_pb',
  full_name='CF_ChannelData_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='PollDirTimer', full_name='CF_ChannelData_t_pb.PollDirTimer', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='PbQ', full_name='CF_ChannelData_t_pb.PbQ', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='PendQTimer', full_name='CF_ChannelData_t_pb.PendQTimer', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TransNumBlasting', full_name='CF_ChannelData_t_pb.TransNumBlasting', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ZeroCpyHandle', full_name='CF_ChannelData_t_pb.ZeroCpyHandle', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='HandshakeSemId', full_name='CF_ChannelData_t_pb.HandshakeSemId', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ZeroCpyMsgPtr', full_name='CF_ChannelData_t_pb.ZeroCpyMsgPtr', index=6,
      number=7, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DataBlast', full_name='CF_ChannelData_t_pb.DataBlast', index=7,
      number=8, type=13, cpp_type=3, label=2,
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
  serialized_start=100,
  serialized_end=307,
)

_CF_CHANNELDATA_T_PB.fields_by_name['PbQ'].message_type = _CF_QUEUE_T_PB
DESCRIPTOR.message_types_by_name['CF_Queue_t_pb'] = _CF_QUEUE_T_PB
DESCRIPTOR.message_types_by_name['CF_ChannelData_t_pb'] = _CF_CHANNELDATA_T_PB

CF_Queue_t_pb = _reflection.GeneratedProtocolMessageType('CF_Queue_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CF_QUEUE_T_PB,
  __module__ = '_py_CF_ChannelData_t_pb2'
  # @@protoc_insertion_point(class_scope:CF_Queue_t_pb)
  ))
_sym_db.RegisterMessage(CF_Queue_t_pb)

CF_ChannelData_t_pb = _reflection.GeneratedProtocolMessageType('CF_ChannelData_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CF_CHANNELDATA_T_PB,
  __module__ = '_py_CF_ChannelData_t_pb2'
  # @@protoc_insertion_point(class_scope:CF_ChannelData_t_pb)
  ))
_sym_db.RegisterMessage(CF_ChannelData_t_pb)


# @@protoc_insertion_point(module_scope)
