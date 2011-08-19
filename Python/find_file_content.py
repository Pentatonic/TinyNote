'''
Find file contents
Search file contents
Walk files
'''
import os
import fnmatch

target_folder = 'D:\\FWx86\\'
lines =  open('gcc-output').readlines()

out = open('find-func.output', 'w+')

for line in lines:
    if line.find("x86_64-unknown-elf-gcc.exe") >= 0:
        #print '>>>> %s' % line
        out.write('>>>> %s\n' % line)
    elif line.find("[-Werror=implicit-function-declaration]") >= 0:
        #print '[???] %s' % line.strip()
        out.write('[???] %s\n' % line.strip())
        a = line.find("'")
        b = line.find("'", a+1)
        func_name = line[a+1:b]
        for root, dirnames, filenames in os.walk(target_folder):
            # find content of header files
            for filename in fnmatch.filter(filenames, '*.h'):
                file_path = os.path.join(root, filename)
                for target_line in open(file_path):
                    if target_line.find(func_name) >= 0:
                        #print '[!!!] (%s) %s'% (file_path, target_line.strip())
                        out.write('[!!!] (%s) %s\n'% (file_path, target_line.strip()))
                        
            # find content of c source files
            for filename in fnmatch.filter(filenames, '*.c'):
                file_path = os.path.join(root, filename)
                for target_line in open(file_path):
                    if target_line.find(func_name) >= 0:
                        #print '[!!!] (%s) %s'% (file_path, target_line.strip())
                        out.write('[!!!] (%s) %s\n'% (file_path, target_line.strip()))
    #print '\n' 
    out.write('\n')
    
out.close()
