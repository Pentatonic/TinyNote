'''
    write byte value to file
'''

import array
from struct import *

# Approach 1
data = array.array('B')
data.append(0xff)
data.append(0x11)
data.append(0x22)
f = file('qqq', 'wb')
data.tofile(f)
f.close()


f = open('123', 'wb')
# Approach 2
f.write('\xff')
# Approach 3
f.write(pack('BB', 0x01, 0xff))
f.close()

