input_String = "MWALOLIAIWWTGBHJ"
# input_String = "CODEISREADY"


def f(char):
    return ord(char)-65

new = ''
for x in input_String:
    new += str(f(x))
    new += ' '
print(new)
