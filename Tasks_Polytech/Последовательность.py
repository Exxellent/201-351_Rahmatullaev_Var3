### 14.1-14.3
def write_numbers_to_file(filename):
    """Ввести числа от пользователя и записать их в файл."""
    with open(filename, 'w') as file:
        while True:
            number = input("Введите число (или 'стоп' для завершения ввода): ")
            if number.lower() == 'стоп':
                break
            try:
                file.write(f"{float(number)}\n")
            except ValueError:
                print("Пожалуйста, введите корректное число.")

def read_numbers_from_file(filename):
    """Прочитать все числа из файла и вывести их."""
    try:
        with open(filename, 'r') as file:
            numbers = file.readlines()
        numbers = [float(number.strip()) for number in numbers]
        print("Числа из файла:")
        print(numbers)
    except FileNotFoundError:
        print("Файл не найден.")
    except ValueError:
        print("Ошибка чтения чисел из файла.")

def perform_operations_on_numbers(filename):
    """Выполнить заданные действия над числами из файла и вывести результат."""
    try:
        with open(filename, 'r') as file:
            numbers = file.readlines()
        numbers = [float(number.strip()) for number in numbers]

        if numbers:
            total_sum = sum(numbers)
            max_number = max(numbers)
            min_number = min(numbers)


            print(f"Сумма всех чисел: {total_sum}")
            print(f"Наибольшее число: {max_number}")
            print(f"Наименьшее число: {min_number}")

        else:
            print("Файл пуст.")
    except FileNotFoundError:
        print("Файл не найден.")
    except ValueError:
        print("Ошибка чтения чисел из файла.")

def main():
    filename = 'numbers.txt'
    while True:
        print("\nВыберите режим работы:")
        print("1. Ввести числа и записать их в файл.")
        print("2. Прочитать все числа из файла и вывести их.")
        print("3. Выполнить над числами из файла заданные действия и вывести результат.")
        print("0. Выход.")

        choice = input("Введите номер режима: ")

        if choice == '1':
            write_numbers_to_file(filename)
        elif choice == '2':
            read_numbers_from_file(filename)
        elif choice == '3':
            perform_operations_on_numbers(filename)
        elif choice == '0':
            print("Выход из программы.")
            break
        else:
            print("Неверный ввод, попробуйте снова.")

if __name__ == "__main__":
    main()
