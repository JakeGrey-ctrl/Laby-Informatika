text = input("Введите текст: ").strip()
while "  " in text:
    text = text.replace("  ", " ")
print("В тексте", text.count(" ") + 1, "слов")
