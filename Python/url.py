'''
    open url
    send data
    submit form
'''

import urllib


params = urllib.urlencode({'op':'add-printer'})
f = urllib.urlopen('http://127.0.0.1/admin', params)
lines = f.readlines()

for line in lines:
    pass
    
# ------------------------------------------------------------------------------------
'''
    submit form
    multipart
    multi part post
'''

# test_client.py
from poster.encode import multipart_encode
from poster.streaminghttp import register_openers
import urllib2

# Register the streaming http handlers with urllib2
register_openers()

# Start the multipart/form-data encoding of the file "DSC0001.jpg"
# "image1" is the name of the parameter, which is normally set
# via the "name" parameter of the HTML <input> tag.

# headers contains the necessary Content-Type and Content-Length
# datagen is a generator object that yields the encoded parameters
datagen, headers = multipart_encode({"image1": open("DSC0001.jpg")})

# Create the Request object
request = urllib2.Request("http://localhost:5000/upload_image", datagen, headers)
# Actually do the request, and get the response
print urllib2.urlopen(request).read()
