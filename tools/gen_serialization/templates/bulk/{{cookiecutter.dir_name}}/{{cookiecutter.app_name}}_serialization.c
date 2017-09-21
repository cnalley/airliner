{% for proto_msg, proto_data in cookiecutter.proto_msgs.iteritems() %}
uint32 {{proto_data.airliner_type}}_Enc(const {{proto_data.airliner_type}} *inObject, char *inOutBuffer, uint32 inSize)
{
	bool status = false;
	{{proto_msg}} pbMsg;
	{% for pb_var, var_data in proto_data.fields.iteritems() %}{% if var_data.array_len| int > 0 %}
	pbMsg.{{pb_var}}_count = {{var_data.array_len}};{% for i in range(0, var_data.array_len | int) %}
	{% if var_data.type == "string" %}strcpy(pbMsg.{{pb_var}}[{{loop.index0}}], inObject->{{var_data.airliner_name}}[{{loop.index0}}]);{% else %}pbMsg.{{pb_var}}[{{loop.index0}}] = inObject->{{var_data.airliner_name}}[{{loop.index0}}];
	{%- endif -%}
	{%- endfor -%}
	{%- else %}
	{% if var_data.type == "string" %}strcpy(pbMsg.{{pb_var}}, inObject->{{var_data.airliner_name}});{% else %}pbMsg.{{pb_var}} = inObject->{{var_data.airliner_name}};
	{%- endif -%}
	{%- endif -%}
	{% endfor %}

	/* Create a stream that will write to our buffer. */
	pb_ostream_t stream = pb_ostream_from_buffer((pb_byte_t *)inOutBuffer, inSize);

	/* Now we are ready to encode the message. */
	status = pb_encode(&stream, {{proto_msg}}_fields, &pbMsg); 

	/* Check for errors... */
	if (!status)
	{
		return 0;
	}

	return stream.bytes_written;
}

uint32 {{proto_data.airliner_type}}_Dec(const char *inBuffer, uint32 inSize, {{proto_data.airliner_type}} *inOutObject)
{
	bool status = false;
	{{proto_msg}} pbMsg;

	/* Create a stream that reads from the buffer. */
	pb_istream_t stream = pb_istream_from_buffer((const pb_byte_t *)inBuffer, inSize);

	/* Now we are ready to decode the message. */
	status = pb_decode(&stream, {{proto_msg}}_fields, &pbMsg); 

	/* Check for errors... */
	if (!status)
	{
		return 0;
	}
	{% for pb_var, var_data in proto_data.fields.iteritems() %}{% if var_data.array_len| int > 0 %}{% for i in range(0, var_data.array_len | int) %}
	{% if var_data.type == "string" %}strcpy(inOutObject->{{var_data.airliner_name}}[{{loop.index0}}], pbMsg.{{pb_var}}[{{loop.index0}}]);{% else %}inOutObject->{{var_data.airliner_name}}[{{loop.index0}}] = pbMsg.{{pb_var}}[{{loop.index0}}];
	{%- endif -%}
	{%- endfor -%}
	{%- else %}
	{% if var_data.type == "string" %}strcpy(inOutObject->{{var_data.airliner_name}}, pbMsg.{{pb_var}});{% else %}inOutObject->{{var_data.airliner_name}} = pbMsg.{{pb_var}};
	{%- endif -%}
	{%- endif -%}
	{% endfor %}

	return sizeof({{proto_data.airliner_type}});
}
{% endfor %}
