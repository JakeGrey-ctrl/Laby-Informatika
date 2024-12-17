from random import randint

##ввод M с проверкой
M = input("Введите количество строк: ")
input_invalid = True
while input_invalid:
    try:
        M = int(M)
        if M > 0:
            input_invalid = False
        else:
            print("Вам нужно ввести целое положительное число. Попробуйте ещё раз.")
            M = input("Введите количество строк: ")
    except ValueError:
        print("Вы ввели не целое число. Попробуйте ещё раз.")
        M = input("Введите количество строк: ")

##ввод N с проверкой
N = input("Введите количество столбцов: ")
input_invalid = True
while input_invalid:
    try:
        N = int(N)
        if N > 0:
            input_invalid = False
        else:
            print("Вам нужно ввести целое положительное число. Попробуйте ещё раз.")
            N = input("Введите количество столбцов: ")
    except ValueError:
        print("Вы ввели не целое число. Попробуйте ещё раз.")
        N = input("Введите количество столбцов: ")

##Формирование двумерного списка + попутный вывод элементов
A = []
print("Исходный список: ")
for _i in range(M):
    column = []
    for _j in range(N):
        val = randint(-50, 50)
        column.append(val)
        print(" " * (3 - len(str(val))) + str(val), end = " ") ##делаем так, дабы создать иллюзию ровных столбцов
    print()
    A.append(column)

##Поиск максимальных в строках и запоминание их индексов
max_elements = []
max_elements_indexes = [] ##В выводе нужно написать индекс минимального из максимальных.
##Список выше создан в целях запоминания, откуда мы берём максимальные
for i in range(M):
    mx = A[i][0] ##Предположим, что первый элемент строки - максимальный
    mx_ind = 0
    for j in range(1, N):
        if A[i][j] > mx:
            mx = A[i][j]
            mx_ind = j
    max_elements.append(mx)
    max_elements_indexes.append(mx_ind) ##длина списка индексов будет равен длине списка максимальных - числу M

##Поиск минимального из максимальных
mn = max_elements[0] ##Предположим, что первый элемент списка - минимальный
mn_pos = [1, max_elements_indexes[0] + 1] ##т. к. в реальной жизни мы считаем с единицы
for i in range(1, M):
    if max_elements[i] < mn:
        mn = max_elements[i]
        mn_pos = [i + 1, max_elements_indexes[i] + 1]

print("Минимальный элемент из максимальных в строках: ", mn)
print("Позиция, на которой находится этот элемент: ", *mn_pos)
