'''
    transfer PCM file to WAVE file
'''

import array
from struct import *
import os
import math

fname = './VOICE1.pcm'
pcmSize = os.path.getsize(fname)
print 'pcm size:%s' % pcmSize

f = open('VOICE.wav', 'wb')
f.write('RIFF')
f.write(pack('I', pcmSize + 36)) # file size
f.write('WAVE')
f.write('fmt ')
f.write(pack('I', 16)) # wave section chunk size
f.write(pack('H', 1)) # wave type format
f.write(pack('H', 1)) # mono/stereo
f.write(pack('I', 44100)) # sample rate
f.write(pack('I', 88200)) # bytes/sec, == SampleRate * NumChannels * BitsPerSample/8
f.write(pack('H', 2)) # block alignment
f.write(pack('H', 16)) # bits/sample
f.write('data')
f.write(pack('I', pcmSize)) # size of data chunk

# The 16-bit PCM file is in Motorolla PCM format
# which is big-endian, wave file's data use little-endian
data = open(fname, 'rb').read()
big_end = unpack('>%s' % ('h' * (pcmSize / 2)), data)
for i in xrange(len(big_end)):
    b_loud = big_end[i]# * 8
    if b_loud > 32767:
        b_loud = 32767
    elif b_loud < -32768:
        b_loud = -32768
    #if math.fabs(b_loud) < 3000 and i > 0:
    #if i > 0 and i < len(big_end) - 1:
    #    b_loud = (big_end[i-1] + b_loud + big_end[i+1]) / 3
    f.write(pack('h', b_loud))
f.close()

