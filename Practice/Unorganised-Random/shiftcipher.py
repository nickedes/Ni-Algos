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


ciphertext = "Gjy ictw wvrwswm riw aksfr licquws ja riw lctwf. Cf gjy lcv fww riwsw kf vjrikvz ja kvrwswfr kv riw licquws. Fjqw ja riw hcrws licquwsf nkhh uw qjsw kvrwswfrkvz ricv rikf jvw, k cq fwskjyf. Riw ljmw yfwm ajs rikf qwffczw kf c fkqohw fyufrkryrkjv lkoiws kv nikli mkzkrf ictw uwwv fikarwm ug 6 ohclwf. Ajs rikf sjyvm ocffnjsm kf zktwv uwhjn, nkrijyr riw dyjrwf."

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

# english frequency

eng_freq = ["E", "T", "A", "O", "I", "N", "S", "R", "H", "D", "L", "U",
            "C", "M", "F", "Y", "W", "G", "P", "B", "V", "K", "X", "Q", "J", "Z", ]

mapping = {}
index = 0
for alpha in sorted(freq.items(), key=lambda x: x[1], reverse=True):
    mapping[alpha] = eng_freq[index]
    index += 1

print(mapping)
