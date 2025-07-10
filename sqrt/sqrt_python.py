import math

def sqrt(l) -> int:

    x = l
    
    while True:

        y = int((x + l / x) / 2)

        if y == x:

            break

        x = y

    return y

a = 5

print(int(math.sqrt(a)))
print(sqrt(a))