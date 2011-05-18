''' 
    operating system
    os
    commands
    operations
'''

import shutil

shutil.rmtree('./folder_name')

#-------------------------------------------------------------------------------
# execute system commands
os.system('ifconfig e1000g0 plumb')
# chmod
os.chmod('my.o', 0755)
# check file exist
os.path.exists('salary.txt')
