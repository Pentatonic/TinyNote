'''
	Python call C library
'''


from ctypes import *

'''
struct DogObject
{
    char dog_name[256];
    uint64_t size;
    uint32_t blocksize;
    int in_use;
};
'''
class DogObject(Structure):
	_fields_ = [("dog_name", c_char*256),
				("size", c_uint64),
				("blocksize", c_uint32),
				("in_use", c_int)
				]


	

libzfs = CDLL(g_nas_lib_path + "libDog.so")
null_ptr = POINTER(c_int)()
size=c_int(0)
noFilter = c_byte(0)	# char
libzfs.getAllDogs(null_ptr, byref(size), noFilter, noFilter, noFilter, noFilter, noFilter)
dogObjs = (DogObject * size.value)()
ret = libzfs.getAllDogs(dogObjs, byref(size), noFilter, noFilter, noFilter, noFilter, noFilter)

#	for d in dogObjs:
#		print "[debug] dog_name:" + str(d.dog_name) + ", size:" + str(d.size) + ", blocksize:" + str(d.blocksize) + ", in_use:" + str(d.in_use)
#	print "[debug] size.value:" + str(size.value)
#	print str(dogObjs[0:size.value])

if ret == 0 and size.value > 0:
	return dogObjs[0:size.value]
else:
	return []

	

	
# -------------------------------------------------------


POINTER(type)	# reuturn a pointer-type
pointer(obj)	# return the address of obj
byref(obj)		# return the address of obj with less overhead


# -------------------------------------------------------


# pass pointer to pointer to c functions
libcups = CDLL("/usr/lib/libcups.so")
#cupsGetDests.argtypes = [POINTER(POINTER(cups_dest_s))]
cups_dests = POINTER(cups_dest_s)()	# a pointer to cups_dest_s object
#cups_dests = POINTER(POINTER(c_char_p))()
numDests = libcups.cupsGetDests(pointer(cups_dests))	# pass the address of pointer cups_dests
print str(cups_dests[0].name)
print 'num of dest:' + str(numDests)
