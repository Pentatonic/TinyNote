'''
    python ssh client
    Install Pramiko python library
    (it needs pycypto library, see detail in readme)
'''


client = paramiko.SSHClient()
client.load_system_host_keys()
client.set_missing_host_key_policy(paramiko.WarningPolicy())
client.connect(ip, 22, user, pw)
chan = client.invoke_shell()
chan.settimeout(10.0)
chan.send('ls')
data = chan.recv(1024)
print data
time.sleep(1)
chan.close()
client.close()


