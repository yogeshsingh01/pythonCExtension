python-ymath
=============

This is a python module for showing Example to use python Extension

## Requirements
  For Windows, python3.5 or greater required.<br>
  For Linux and MacOS, python2.7 or python3.4 or greater required.

## Installing the latest release:
    $ python setup.py install
    Make sure to have [Visual Studio 2015](https://visualstudio.microsoft.com/visual-cpp-build-tools/).

## Module Documentation

ymath.factorial(number)
> Return factorial of a number using c function

## Usage Example

```python
import bchlib
import hashlib
import os
import random

# create a bch object
BCH_POLYNOMIAL = 8219
BCH_BITS = 16
bch = bchlib.BCH(BCH_POLYNOMIAL, BCH_BITS)

# random data
data = bytearray(os.urandom(512))

# encode and make a "packet"
ecc = bch.encode(data)
packet = data + ecc

# print hash of packet
sha1_initial = hashlib.sha1(packet)
print('sha1: %s' % (sha1_initial.hexdigest(),))

def bitflip(packet):
    byte_num = random.randint(0, len(packet) - 1)
    bit_num = random.randint(0, 7)
    packet[byte_num] ^= (1 << bit_num)

# make BCH_BITS errors
for _ in range(BCH_BITS):
    bitflip(packet)

# print hash of packet
sha1_corrupt = hashlib.sha1(packet)
print('sha1: %s' % (sha1_corrupt.hexdigest(),))

# de-packetize
data, ecc = packet[:-bch.ecc_bytes], packet[-bch.ecc_bytes:]

# correct
bitflips = bch.decode_inplace(data, ecc)
print('bitflips: %d' % (bitflips))

# packetize
packet = data + ecc

# print hash of packet
sha1_corrected = hashlib.sha1(packet)
print('sha1: %s' % (sha1_corrected.hexdigest(),))

if sha1_initial.digest() == sha1_corrected.digest():
    print('Corrected!')
else:
    print('Failed')
```
