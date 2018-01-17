ciphertext = 'Lg ccud qh urg tgay ejbwdkt, wmgtf su bgud nkudnk lrd vjfbg. Yrhfm qvd vng sfuuxytj "vkj_ecwo_ogp_ej_rnfkukf" wt iq urtuwjm. Ocz iqa jdag vio uzthsivi pqx vkj pgyd encpggt. Uy hopg yjg fhkz arz hkscv ckoq pgfn vu wwygt nkioe zttft djkth.'

# ciphertext = 'CHREEVOAHMAERATBIAXXWTNXBEEOPHBSBQMQEQERBWRVXUOAKXAOSXXWEAHBWGJMMQMNKGRFVGXWTRZXWIAKLXFPSKAUTEMNDCMGTSXMXBTUIADNGMGPSRELXNJELXVRVPRTULHDNQWTWDTYGBPHXTFALJHASVBFXNGLLCHRZBWELEKMSJIKNBHWRJGNMGJSGLXFEYPHAGNRBIEQJTAMRVLCRREMNDGLXRRIMGNSNRWCHRQHAEYEVTAQEBBIPEEWEVKAKOEWADREMXMTBHHCHRTKDNVRZCHRCLQOHPWQAIIWXNRMGWOIIFKEE'

# ciphertext = 'abcde'
newcipher = ''
for alpha in ciphertext:
    if alpha.isalpha():
        newcipher += alpha.lower()
    # else:
        # newcipher += alpha

print(newcipher)
ciphertext = newcipher

gap_len = 2

repeats = set()

while gap_len < len(ciphertext):
    for i in range(len(ciphertext)):
        text = ciphertext[i:i+gap_len]
        if ciphertext.count(text) > 1 and len(text) == gap_len:
            print(text, ciphertext.count(text))
            repeats.add(text)
    gap_len += 1

print(repeats)

for x in repeats:
    id1 = ciphertext.index(x)
    print()
    id2 = ciphertext.find(x, id1+1)
    print(id1, id2, id2 - id1, x)


# keylen = 9
# print()

# shiftkey = "123456789"

# for i in range(len(ciphertext)):
#     cipher = ciphertext[i:i+keylen]
#     # print(cipher)
#     plain = ''
#     for c in range(len(cipher)):
#         if cipher[c].islower():
#             # rotate number around alphabet a random amount
#             plain += chr((ord(cipher[c])-ord('a') +
#                           int(shiftkey[c])) % 26 + ord('a'))
#         else:
#             plain += cipher[c]
#     # print(cipher, plain)

# lengths = [2, 3, 18, 9, 6, 15, 1, 5, 20]

# for keylen in lengths:
#     sum_freqs = 0
#     print("="*100)
#     print(" KEY LEN = ", keylen)
#     plain = ['']*keylen

#     for i in range(len(ciphertext)):
#         cipher = ciphertext[i*keylen: (i+1)*keylen]
#         # if len(cipher) == keylen:
#         for c in range(len(cipher)):
#             plain[c] += cipher[c]

#     for random in plain:
#         freq = {}
#         for x in random:
#             if x.isalpha():
#                 x = x.lower()
#                 if x not in freq:
#                     freq[x] = 1
#                 else:
#                     freq[x] = freq[x] + 1

#         # print(freq)
#         sum_f = 0
#         for x in freq:
#             sum_f += freq[x]**2

#         print(sum_f/len(random)**2)
#         sum_freqs += sum_f/(len(random)**2)
#     # print(sum_freqs/keylen)
