user_input = input()
sum_a, sum_b = 0, 0
val_before = ""

for i in user_input:
    if i.isnumeric():
        if val_before == "A":
            sum_a += int(i)
        elif val_before == "B":
            sum_b += int(i)
    else:
        val_before = i

print("A") if sum_a > sum_b else print("B")
