from random import randint
##Начало проверки ввода пользователя
columns_count = input("Введите количество строк: ") ##строки
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

rows_count = input("Введите количество столбцов: ")  ##столбцы
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
##Конец проверки ввода пользователя

##Генерация списка
matrix = [[randint(-10, 10) for i in range(rows_count)] for j in range(columns_count)] ##версия с генератором
##matrix = []
##for i in range(columns_count): ##версия без использования генератора
##    column = []
##    for j in range(rows_count):
##        column.append(randint(-10, 10))
##    matrix.append(column)

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

##Пользователь вводит режим и шаг сдвига
mode = input("Введите режим сдвига (вниз или вправо): ")
while mode != "вниз" and mode != "вправо":
    print("Выберите один режим сдвига из предложенных!")
    mode = input("Попробуйте выбрать режим сдвига ещё раз (вниз или вправо): ")
n = input("Введите шаг сдвига: ")
input_invalid = True
while input_invalid:
    try:
        n = int(n)
        if n != 0:
            input_invalid = False
        else:
            print("Вы должны ввести целое ненулевое число!")
            n = input("Попробуйте выбрать шаг сдвига ещё раз: ")
    except ValueError:
        print("Вы должны ввести целое ненулевое число!")
        n = input("Попробуйте выбрать шаг сдвига ещё раз: ")

##Начало работы алгоритма
matrix1 = []
if mode == "вниз":
    for i in range(columns_count):
        matrix1.append(matrix[(i - n) % columns_count]) ##%columns_count, чтобы работало зацикливание.
        ##Знак "-", так как мы движем матрицу визуально вниз
        ##При отрицательном шаге зацикливание также работает, но в обратную сторону (вверх)
else:
    for i in range(columns_count):
        column = []
        for j in range(rows_count):
            column.append(matrix[i][(j - n) % rows_count]) 
        matrix1.append(column)
matrix = matrix1
##Конец работы алгоритма

##Вывод получившегося списка (начало)
print("Получившийся список: ")
for column in matrix:
    for i in column:
        if 0 <= i <= 9:
            print(" " + str(i), end = " ") ##сделано в целях грамотного отображения
        else:
            print(i, end = " ")
    print()
##Конец вывода получившегося списка
