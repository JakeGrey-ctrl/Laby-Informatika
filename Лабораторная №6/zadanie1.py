text = input("Введите текст: ")
counter = 0
text += " " ##это лучше, чем counter = 1, т. к. нет обхода проверки на фальш. пробел
n = len(text)
for i in range(n):
    if text[i] == " " and i != 0 and text[i - 1] != " ": ##условия 2 и 3 - проверка на лишние пробелы
        counter += 1
##Вывод
print("В тексте", counter, end = " ")
if counter % 10 == 1: ##далее определение окончания слова в зависимости от последней цифры
    print("слово")
elif counter % 10 != 0 and counter % 10 <= 4:
    print("слова")
else:
    print("слов")
