'''
    write byte value to file
'''

import array
from struct import *
import os

pcmSize = os.path.getsize('./VOICE.pcm')
print 'pcm size:%s' % pcmSize

f = open('123', 'wb')
f.write('RIFF')
f.write(pack('I', pcmSize + 36)) # file size
f.write('WAVE')
f.write('fmt ')
f.write(pack('I', 16)) # wave section chunk size
f.write(pack('H', 0x10)) # wave type format
f.write(pack('H', 1)) # mono/stereo
f.write(pack('I', 1)) # sample rate
f.write(pack('I', 1)) # bytes/sec
f.write(pack('H', 1)) # block alignment
f.write(pack('H', 16)) # bits/sample
f.write('data')
f.write(pack('I', pcmSize)) # size of data chunk

f.close()

