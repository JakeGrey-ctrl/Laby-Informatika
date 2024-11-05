text = input("Введите текст: ").strip()
while "  " in text:
    text = text.replace("  ", " ")
text += " " ##добавляем пробел в конце, чтобы алгоритм учёл последнее слово
c = text.count(" ")
print("В тексте", c, end = " ")
if c % 10 == 1: ##далее определение окончания в зависимости от 
    print("слово")
elif c % 10 != 0 and c % 10 <= 4:
    print("слова")
else:
    print("слов")
