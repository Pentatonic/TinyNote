'''
    Linux
    Move cursor posisition on the screen
'''

import sys

def gotoxy(x, y):
    essq = "\033[" + str(x) + "d" + "\033[" + str(y) + "G"
    sys.stdout.write(essq)
    