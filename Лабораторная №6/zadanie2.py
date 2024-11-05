text = input("Введите текст: ")
bracket_balance = 0
for i in text:
    if i == "(":
        bracket_balance += 1
    elif i == ")":
        bracket_balance -= 1
    if bracket_balance < 0:
        break
if bracket_balance == 0:
    print("Сбалансированность скобок в тексте соблюдается.")
else:
    print("Сбалансированность скобок в тексте не соблюдается.")
