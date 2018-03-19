'''
    sort list
'''
from operator import itemgetter, attrgetter

ips = [{'status': 'unplumb', 'ip': '000.000.000.000',
        'mask': '000.000.000.000', 'name': 'yge1', 'braod': '000.000.000.000'},
       {'ip': '172.018.008.208', 'stats': 'plumb',
        'mask': '255.255.254.000', 'name': 'yge0', 'broad': '172.018.009.255'}]

# sort list according to the key - 'name' - of each item
out = sorted(ips, key=itemgetter('name'))
print str(out)


# ------------------------------------------------------------------------------
