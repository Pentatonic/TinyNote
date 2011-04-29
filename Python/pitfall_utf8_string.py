#-*- coding:utf-8 -*-
'''
    issue, problem, error ?
    when using __str__
    to string
    
    a convenient way to ouput json object
'''

# in the __str__ function, it actually calls __repr__
# the __repr__ will chnage utf-8 characters to their unicode representation
a = {}
a['a'] = 'C:\Documents and Settings\john.liu\My Documents\FinePrint ÀÉ®×'
print a
#output: {'a': 'C:\\Documents and Settings\\john.liu\\My Documents\\FinePrint \xc0\xc9\xae\xd7'}



# ---------------------- work around ------------------------

class utf8Str(object):
    '''
    super real string
    '''
    ss = ""
    def __init__(self, s):
        #super(object, self).__init__()
        self.ss = s
    def __repr__(self):
        return "'" + self.ss.replace('\\', '/').replace("'", "\\'") + "'"

b = {}
b['a'] = utf8Str("C:\Documents and Settings\john.liu\My Documents\FinePrint ÀÉ®×")
print b
#output: {'a': 'C:/Documents and Settings/john.liu/My Documents/FinePrint ÀÉ®×'}
