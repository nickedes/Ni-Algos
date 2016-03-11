# this seems to be easy. But sadly this is very slow.
# Problem : https://www.hackerrank.com/challenges/string-function-calculation


def get_all_substrings(input_string):
    length = len(input_string)
    return [input_string[i:j+1] for i in range(length) for j in range(i, length)]


string = input()
substrings = get_all_substrings(string)
set_subs = set(substrings)
val = 0
for x in set_subs:
    str_val = len(x)*substrings.count(x)
    if str_val > val:
        val = str_val
print(val)
