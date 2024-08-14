### 6.1-6.2
def find_shortest_word(sentence):
    # Разделяем строку на слова
    words = sentence.split()
    # Находим самое короткое слово
    shortest_word = min(words, key=len)
    maximus_word = max(words, key=len)

    return shortest_word, maximus_word

# Пример использования
sentence = "Ехал грека через реку, видит грека вв реке рак"
shortest_word, maximus_word = find_shortest_word(sentence)
print(f"Самое короткое слово: {shortest_word} \nСамое длинное слово: {maximus_word}")
