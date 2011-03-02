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