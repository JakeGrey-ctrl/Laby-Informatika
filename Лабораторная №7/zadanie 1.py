from random import randint
columns_count = input("Введите количество строк: ")
##Начало проверки ввода пользователя
input_invalid = True
while input_invalid:
    try:
        columns_count = int(columns_count)
        if columns_count >= 1:
            input_invalid = False
        else:
            print("Вы должны ввести целое положительное число!")
            columns_count = input("Попробуйте ввести количество строк ещё раз: ")
    except ValueError:
        print("Вы должны ввести целое положительное число!")
        columns_count = input("Попробуйте ввести количество строк ещё раз: ")

rows_count = input("Введите количество столбцов: ")
input_invalid = True
while input_invalid:
    try:
        rows_count = int(rows_count)
        if rows_count >= 1:
            input_invalid = False
        else:
            print("Вы должны ввести целое положительное число!")
            rows_count = input("Попробуйте ввести количество столбцов ещё раз: ")
    except ValueError:
        print("Вы должны ввести целое положительное число!")
        rows_count = input("Попробуйте ввести количество столбцов ещё раз: ")

matrix = [[randint(-10, 10) for i in range(rows_count)] for j in range(columns_count)] ##версия с генератором
##Конец проверки ввода пользователя
##matrix = []
##for i in range(columns_count): ##версия без использования генератора
##    row = []
##    for j in range(rows_count):
##        row.append(randint(-10, 10))
##    matrix.append(row)

##Вывод входного массива (начало)
print("Входной массив: ")
for row in matrix:
    for i in row:
        if 0 <= i <= 9:
            print(" " + str(i), end = " ") ##сделано в целях грамотного отображения
        else:
            print(i, end = " ")
    print()
##Конец вывода входного массива
