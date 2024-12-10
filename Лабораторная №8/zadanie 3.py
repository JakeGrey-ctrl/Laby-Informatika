def input_string_index(s_len: int, input_text: str):
    var = input(input_text)
    input_invalid = True
    while input_invalid:
        try:
            var = int(var)
            if 0 <= var < s_len:
                input_invalid = False
            else:
                print("Вы должны ввести целое число в диапазоне [0; " + str(s_len - 1) + "]. Попробуйте ещё раз.")
                var = input(input_text)
        except ValueError:
            print("Вы ввели не число. Попробуйте ещё раз.")
            var = input(input_text)
    return var
    
def round_down(n: float):
    return int(n // 1)

def round_up(n: float):
    if n % 1 == 0:
        return int(n)
    else:
        return int((n + 1) // 1)

def is_palyndrome(s: str, inc = 0):
    pivot = (len(s) - 1) / 2
    if round_down(pivot) - inc == 0: ##условие продолжения
        return s[round_down(pivot) - inc] == s[round_up(pivot) + inc]
    elif s[round_down(pivot) - inc] == s[round_up(pivot) + inc]: ##в случае, если буквы по равные стороны от центра равны -
        ##... продолжаем проверку на палиндром:
        return is_palyndrome(s, inc + 1)
    else:
        ##в противном случае это делать нет смысла
        return False

##main
##Ввод + проверка
st = input("Введите строку: ")
while st == "":
    print("Пустая строка. Попробуйте ещё раз.")
    st = input("Введите строку: ")

i = input_string_index(len(st), "Введите номер символа (от 0 до " + str(len(st) - 1) + " включительно), с которого будет начинаться подстрока: ")
j = input_string_index(len(st), "Введите номер символа (от 0 до " + str(len(st) - 1) + " включительно), на котором будет заканчиваться подстрока: ")

##Срез подстроки
cut_st = "" ##нельзя использовать срезы (?)
for ind in range(i, j + 1): ##последний не учитывается
    cut_st += st[ind]

##Вывод
if is_palyndrome(cut_st):
    print("Подстрока", cut_st, "является палиндромом")
else:
    print("Подстрока", cut_st, "не является палиндромом")
