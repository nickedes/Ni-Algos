# trying shift cipher
text = 'Lg ccud qh urg tgay ejbwdkt, wmgtf su bgud nkudnk lrd vjfbg.'

for key in range(26):
    cipher = ''
    for alpha in text:
        if alpha.islower():
            cipher += chr((ord(alpha) - ord('a') + key) % 26 + ord('a'))
        elif alpha.isupper():
            cipher += chr((ord(alpha) - ord('A') + key) % 26 + ord('A'))
        else:
            cipher += alpha
    print(cipher)

print("="*80)


ciphertext_ = 'Lg ccud qh urg tgay ejbwdkt, wmgtf su bgud nkudnk lrd vjfbg. Yrhfm qvd vng sfuuxytj "vkj_ecwo_ogp_ej_rnfkukf" wt iq urtuwjm. Ocz iqa jdag vio uzthsivi pqx vkj pgyd encpggt. Uy hopg yjg fhkz arz hkscv ckoq pgfn vu wwygt nkioe zttft djkth.'

newcipher = ''
for alpha in ciphertext_:
    if alpha.isalpha():
        newcipher += alpha.lower()
    elif alpha == '.':
        pass
    else:
        newcipher += alpha

ciphertext = newcipher

keylen = 9

words = ciphertext.split(' ')

# print(words)
quadgram = [x for x in words if len(x) == 4]
bigram = [x for x in words if len(x) == 2]
trigram = [x for x in words if len(x) == 3]

print(quadgram)
print(bigram)
print(trigram)

print(set(words) - (set(quadgram) | set(trigram) | set(bigram)))

freq = {}
for x in ciphertext:
    if x.isalpha():
        x = x.lower()
        if x not in freq:
            freq[x] = 1
        else:
            freq[x] = freq[x] + 1

print("frequency of characters in cipher : ", freq)

level2Key = 'kcgcdfccb'

newcipher = ''
for alpha in ciphertext_:
    if alpha.isalpha():
        newcipher += alpha.lower()

ciphertext_ = 'Lg ccud qh urg tgay ejbwdkt, wmgtf su bgud nkudnk lrd vjfbg. Yrhfm qvd vng sfuuxytj "vkj_ecwo_ogp_ej_rnfkukf" wt iq urtuwjm. Ocz iqa jdag vio uzthsivi pqx vkj pgyd encpggt. Uy hopg yjg fhkz arz hkscv ckoq pgfn vu wwygt nkioe zttft djkth.'

plaintext = ''
j = 0
for alpha in ciphertext_:
    if alpha.isalpha():
        character = chr(
            (ord(alpha.lower()) - ord(level2Key[j])) % 26 + ord('a'))
        plaintext += character.upper() if alpha.isupper() else character
        # chr((ord(alpha) - ord('a') + key) % 26 + ord('a'))
        j = (j + 1) % len(level2Key)
    else:
        plaintext += alpha

print(plaintext)
