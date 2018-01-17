import sys
sys.setrecursionlimit(99999)


def f(n):
    fibs = [0, 1]
    for i in range(2, n+1):
        fibs.append(fibs[i-1] + fibs[i-2])
    return fibs[n]

# print(f(1024))
print "flag{" + str(f(25)) + "}"

#!/usr/bin/python -u
# qgsn{aqZ_QNztqzmf@_&^$_#*@_fnp_ixfhuJbay}
# flag{aqZ_QNztqzmf@_&^$_#*@_fnp_ixfhuJbay}
# import random
# import string
# import time
# import os

# plaintext_file = "plain.text.enc"
# encrypted_file = "plain.text"


# def main():
#     flag = ""
#     with open(plaintext_file, 'r') as f:
#         flag = f.read()
#     # x = 1514399399
#     # x = 1514485799
#     x = 1514532599

#     while x > 0:
#         random.seed(int(time.time()))
#         ciphertext = ""
#         for c in flag:
#             if c.islower():
#                 # rotate number around alphabet a random amount
#                 ciphertext += chr((ord(c)-ord('a') -
#                                    random.randrange(0, 26)) % 26 + ord('a'))
#             elif c.isupper():
#                 ciphertext += chr((ord(c)-ord('A') -
#                                    random.randrange(0, 26)) % 26 + ord('A'))
#             elif c.isdigit():
#                 ciphertext += chr((ord(c)-ord('0') -
#                                    random.randrange(0, 10)) % 10 + ord('0'))
#             else:
#                 ciphertext += c
#         if 'flag{' in ciphertext:
#             print("flag found")
#             with open(encrypted_file, 'a') as f:
#                 f.write(ciphertext)
#         x -= 1

#     # print(x)
#     print("stop")


# if __name__ == "__main__":
#     main()
