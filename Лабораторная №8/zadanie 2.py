##Функция поиска делителей числа
def dividers(n: int):
    s = set()
    for i in range(1, n//2 + 1):
        if n % i == 0:
            s.add(i)
    return s ##множество делителей

##Функция суммы элементов коллекции
def number_sum(collection):
    s = 0
    for i in collection:
        s += i
    return s

##Вариант 1: Функция сверки дружественных чисел
def amicable_numbers(a: int, b: int): ##дружественные числа
    ##Строка ниже возвращает True/False
    return number_sum(dividers(a)) == b and number_sum(dividers(b)) == a

##Вариант 2: Функция получения дружественного числа
def get_amicable_partner(a: int):
    b = number_sum(dividers(a))
    if number_sum(dividers(b)) == a:
        return b
    else:
        return -1

##main
##Ввод пользователя + проверка
n = input("Введите натуральное число: ")
input_invalid = True
while input_invalid:
    try:
        n = int(n)
        if n > 0:
            input_invalid = False
        else:
            print("Некорректный ввод! Попробуйте ещё раз!")
            n = input("Введите натуральное число: ")
    except ValueError:
        print("Некорректный ввод! Попробуйте ещё раз!")
        n = input("Введите натуральное число: ")
##Конец ввода

##Начало работы алгоритма
s = [] ##проблема множества - оно сортируется как попало
##for i in range(n):
##    for j in range(i + 1, n):
##        if amicable_numbers(i, j):
##            s.add((i, j))
for i in range(n):
    j = get_amicable_partner(i)
    if j != -1 and j > i: ##знак строгий, т. к. одинаковые числа не считаются дружественными
        s.append((i, j))
##Конец работы алгоритма


##Вывод
if len(s) > 0:
    print("Пары дружественных чисел до числа " + str(n) + ":", *s)
else:
    print("До числа", n, "нет пар дружественных чисел.")
