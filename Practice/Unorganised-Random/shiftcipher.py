# checking shift cipher
text = "Gjy ictw wvrwswm riw aksfr licquws ja riw lctwf."

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

ciphertext = "Gjy ictw wvrwswm riw aksfr licquws ja riw lctwf. Cf gjy lcv fww riwsw kf vjrikvz ja kvrwswfr kv riw licquws. Fjqw ja riw hcrws licquwsf nkhh uw qjsw kvrwswfrkvz ricv rikf jvw, k cq fwskjyf. Riw ljmw yfwm ajs rikf qwffczw kf c fkqohw fyufrkryrkjv lkoiws kv nikli mkzkrf ictw uwwv fikarwm ug 6 ohclwf. Ajs rikf sjyvm ocffnjsm kf zktwv uwhjn, nkrijyr riw dyjrwf. vvUc56Nrmz"

freq = {}
for x in ciphertext:
    if x.isalpha():
        x = x.lower()
        if x not in freq:
            freq[x] = 1
        else:
            freq[x] = freq[x] + 1

print("frequency of characters in cipher : ", freq)

print(sorted(freq.items(), key=lambda x: x[1], reverse=True))

print("="*136)

# english frequency

eng_freq = ["E", "T", "A", "O", "I", "N", "S", "R", "H", "D", "L", "U",
            "C", "M", "F", "Y", "W", "G", "P", "B", "V", "K", "X", "Q", "J", "Z", ]

mapping = {}
index = 0
for alpha in sorted(freq.items(), key=lambda x: x[1], reverse=True):
    mapping[alpha[0]] = eng_freq[index].lower()
    index += 1

print("mapping : ", mapping)


mapping = {'w': 'e', 'f': 't', 'r': 'a', 'k': 'o', 'i': 'i', 'j': 'n', 's': 's', 'c': 'r', 'v': 'h', 'y': 'd',
            'l': 'l', 'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" swap b/w r and f (almost similar freq)")
mapping = {'w': 'e', 'r': 't', 'f': 'a', 'k': 'o', 'i': 'i', 'j': 'n', 's': 's', 'c': 'r', 'v': 'h', 'y': 'd',
            'l': 'l', 'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" lot of occurences of 'tie', chances of being it 'the'. So swapping i and h")
mapping = {'w': 'e', 'r': 't', 'f': 'a', 'k': 'o', 'i': 'h', 'j': 'n', 's': 's', 'c': 'r', 'v': 'i', 'y': 'd', 'l': 'l',
           'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" o and a swap")
mapping = {'w': 'e', 'r': 't', 'f': 'o', 'k': 'a', 'i': 'h', 'j': 'n', 's': 's', 'c': 'r', 'v': 'i', 'y': 'd', 'l': 'l',
           'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" n and s swap -> nee = see")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'a', 'i': 'h', 'j': 'o', 's': 'n', 'c': 'r', 'v': 'i', 'y': 'd', 'l': 'l',
           'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" a,i swap for is")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'n', 'c': 'a', 'v': 'r', 'y': 'd', 'l': 'l',
           'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" r and n swap,  ir in text -> in")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'd', 'l': 'l',
           'q': 'u', 'u': 'c', 'm': 'm', 'a': 'f', 'h': 'y', 'z': 'w', 'n': 'g', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" enterem -> entered, nothinw -> nothing,")
print(" seriods -> serious")

mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'm', 'l': 'l',
           'q': 'u', 'u': 'c', 'm': 'd', 'a': 'f', 'h': 'y', 'z': 'g', 'n': 'w', 't': 'p', 'o': 'b', 'g': 'v', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" i au serioms -> i am serious")
print(" bassword -> password")
print(" gipen -> given")

mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'u', 'l': 'l',
           'q': 'm', 'u': 'c', 'm': 'd', 'a': 'f', 'h': 'y', 'z': 'g', 'n': 'w', 't': 'v', 'o': 'p', 'g': 'b', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" lhamcer of the laves -> chamler of the caves")

mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'u', 'l': 'c',
           'q': 'm', 'u': 'l', 'm': 'd', 'a': 'f', 'h': 'y', 'z': 'g', 'n': 'w', 't': 'v', 'o': 'p', 'g': 'b', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" chamler of the caves -> chamber of the caves")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'u', 'l': 'c',
           'q': 'm', 'u': 'b', 'm': 'd', 'a': 'f', 'h': 'y', 'z': 'g', 'n': 'w', 't': 'v', 'o': 'p', 'g': 'l', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" lou have entered the first cham -> You have entered the first cham")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'u', 'l': 'c',
           'q': 'm', 'u': 'b', 'm': 'd', 'a': 'f', 'h': 'l', 'z': 'g', 'n': 'w', 't': 'v', 'o': 'p', 'g': 'y', 'd': 'k'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" missing mappings added randomly")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'u', 'l': 'c',
           'q': 'm', 'u': 'b', 'm': 'd', 'a': 'f', 'h': 'l', 'z': 'g', 'n': 'w', 't': 'v', 'o': 'p', 'g': 'y', 'd': 'k',
           'b': 'j', 'p': 'q', 'e': 'x', 'x': 'z'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)
print(" without the kuotes - without the quotes")
mapping = {'w': 'e', 'r': 't', 'f': 's', 'k': 'i', 'i': 'h', 'j': 'o', 's': 'r', 'c': 'a', 'v': 'n', 'y': 'u', 'l': 'c',
           'q': 'm', 'u': 'b', 'm': 'd', 'a': 'f', 'h': 'l', 'z': 'g', 'n': 'w', 't': 'v', 'o': 'p', 'g': 'y', 'd': 'q',
           'b': 'j', 'p': 'k', 'e': 'x', 'x': 'z'}

plaintext_ = ''

for alpha in ciphertext:
    if alpha.isalpha():
        plaintext_ += mapping[alpha.lower()]
    else:
        plaintext_ += alpha
print("Mapping : ",mapping)
print()
print("ciphertext : ", ciphertext)
print()
print("New plain text : ", plaintext_)
print("="*136)
print("="*136)

# print(sorted(mapping.items(), key=lambda x: x[0]))
# print()
# print(sorted(mapping.items(), key=lambda x: x[1]))
