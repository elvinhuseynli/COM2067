import random

lower = "abcdefghijklmnopqrstuvwxyz"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
num = "0123456789"
symbol = "{}[]()*&^%$#@!~|/.<>?!"

all = lower + upper + num +symbol

length = 15

pasw = "".join(random.sample(all, length))
print("Your generated Password:\n", pasw)
print("\n")