string = input()
print("pangram"if len(set(string.lower())) > 26 else "not pangram")
