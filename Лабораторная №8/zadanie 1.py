from math import exp, sqrt
from random import randint

##Начало функции поиска максимального значения
def findmax(A: list):
    mx = A[0]
    for i in range(1, len(A)):
        if A[i] > mx:
            mx = A[i]
    return mx
##Конец функции поиска максимального значения

##Функция ввода положительного числа с проверкой
def input_positive_digit(input_text: str):
    var = input(input_text)
    input_invalid = True
    while input_invalid:
        try:
            var = int(var)
            if var > 0:
                input_invalid = False
            else:
                print("Некорректный ввод! Попробуйте ещё раз!")
                var = input(input_text)
        except ValueError:
            print("Некорректный ввод! Попробуйте ещё раз!")
            var = input(input_text)
    return var

##main
##Входные данные
lenX = input_positive_digit("Введите длину списка X: ")
lenY = input_positive_digit("Введите длину списка Y: ")
X = [randint(-100, 100) for _ in range(lenX)] ##X = [randint(-20, 20) for _ in range(20)]
Y = [randint(-100, 100) for _ in range(lenY)] ##Y = [randint(-20, 20) for _ in range(15)]

##Вывод исходных списков
print("Список X:", *X)
print("Список Y:", *Y)

##Вычисление z и вывод
Xmax = findmax(X)
Ymax = findmax(Y)
try:
    z = (exp(abs(Xmax)) - exp(abs(Ymax))) / sqrt(abs(Xmax * Ymax))
    print("Значение z:", z)
except ZeroDivisionError:
    print("Упс! Кажется, произошло деление на 0 :)")
