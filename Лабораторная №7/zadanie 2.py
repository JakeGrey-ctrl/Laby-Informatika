from random import randint
##Начало проверки ввода пользователя
n = input("Введите размерность списка: ")
input_invalid = True
while input_invalid:
    try:
        n = int(n)
        if n >= 1:
            input_invalid = False
        else:
            print("Вы должны ввести целое положительное число!")
            n = input("Попробуйте ввести размерность ещё раз: ")
    except ValueError:
        print("Вы должны ввести целое положительное число!")
        N = input("Попробуйте ввести размерность ещё раз: ")
##Конец проверки ввода пользователя

##Генерация списка
matrix = [[randint(-10, 10) for i in range(n)] for j in range(n)] ##версия с генератором
##matrix = []
##for i in range(n): ##версия без использования генератора
##    column = []
##    for j in range(n):
##        column.append(randint(-10, 10))
##    matrix.append(n)

##Вывод входного списка (начало)
print("Входной список: ")
for column in matrix:
    for i in column:
        if 0 <= i <= 9:
            print(" " + str(i), end = " ") ##сделано в целях грамотного отображения
        else:
            print(i, end = " ")
    print()
##Конец вывода входного списка

##Начало работы алгоритма
s = 0
for i in range(n):
    for j in range(n - i): ##j идёт от начала строки до побочной диагонали не включительно
        s += matrix[i][j]
print("Сумма элементов выше побочной диагонали равна", s)
