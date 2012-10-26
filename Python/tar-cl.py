#!/usr/bin/python
import subprocess
import sys
import os
p4home = "/home/john.liu/PERFORCE"

def check_output(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)
    output = process.communicate()
    retcode = process.poll()
    if retcode:
        raise subprocess.CalledProcessError(retcode, command, output=output[0])
    return output 

try:
    argc = len(sys.argv)
    if argc != 2:
        print ">>>> Please input a change list number!"
        sys.exit()

    clNum = sys.argv[1]
    targetDir = "CL" + clNum
    
    cmd = "p4 opened -c %s" % (clNum)
    #output = check_output(cmd)
    output = ["\\\\asdf#\n\\\\qwer#"]
    lines = output[0].split("\n")
    print ">>>> mkdir target folder ./%s" % (targetDir)
    os.system("mkdir ./" + targetDir);
    for line in lines:
        fname = p4home + "/" + line[2:].split("#")[0]
        print ">>>> copy %s into folder ./%s" % (fname, targetDir)
        os.system("cp %s ./%s" % (fname, targetDir))

    print ">>>> tar Changelist %s into %s.tar.gz ..." % (clNum, clNum)
    os.system("tar zcvf CL%s.tar.gz ./%s" % (clNum, targetDir))
except subprocess.CalledProcessError, e:
    print ">>>> native CalledProcessError.output = " + e.output
