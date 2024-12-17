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

##Фильтрация двумерного списка A в целях оставить только эл-ты с нечётными столбцами
##В выводе также строки будут соответствовать столбцам, столбцы - строкам (как требуется в условии задачи)
ind_st = 1
print("Получившийся список: ")
for j in range(0, N, 2):
    print(str(ind_st) + "-й столбец: ", end = "")
    for i in range(M):
        el = A[i][j]
        print(" " * (3 - len(str(el))) + str(el), end = " ")
    ind_st += 2
    print()
