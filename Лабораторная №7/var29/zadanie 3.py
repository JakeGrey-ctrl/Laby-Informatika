d = {"white" : "белый", "black" : "чёрный", "blue" : "синий", "red" : "красный", "yellow" : "жёлтый", "green" : "зелёный", "brown" : "коричневый", "pink" : "розовый"}

##Вывод словаря
for i in d.keys():
    print(i, "-", d[i])

##Перевод последнего слова
keys = list(d.keys()) ##нужно перевести в список, т. к. d.keys возвращает тип 'method_descriptor'
print("\nПеревод последнего слова:")
print(keys[-1], "переводится как", d[keys[-1]])
