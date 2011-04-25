'''
    transfer PCM file to WAVE file
'''

import array
from struct import *
import os
fname = './VOICE.pcm'
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
# which is big-endian, wave files use little-endian
data = open(fname, 'rb').read()
big_end = unpack('>%s' % ('H' * (pcmSize / 2)), data)
for b in big_end:
    f.write(pack('H', b))
f.close()

