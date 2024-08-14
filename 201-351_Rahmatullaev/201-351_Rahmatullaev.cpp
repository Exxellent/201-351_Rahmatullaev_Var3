#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <random>

using namespace std;

// Вектор для хранения пар логин-пароль
vector<pair<string, string>> Accounts;

// Функция проверки введенного пин-кода
bool check_pin(string key)
{
    const string goodpass = "1234";
    return key == goodpass;
}

// Функция генерации случайной строки, используемой для логинов и паролей
string generateRandomCreds()
{
    string randomString;
    int randomNumlenght = rand() % 5 + 4;

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;

    for (int i = 0; i < randomNumlenght; ++i) {
        int randomIndex = rand() % alphabet.length();
        result += alphabet[randomIndex];
    }

    return result;
}

// Функция генерации аккаунтов со случайными логинами и паролями
void generateAcc() {
    int randomNumlenght = rand() % 10 + 5;
    cout << "Всего аккаунтов: " << randomNumlenght -1 << "\n";
    for (int i = 0; i < randomNumlenght; i++) {
        string login = generateRandomCreds();
        string password = generateRandomCreds();
        Accounts.emplace_back(login, password);
    }
}

// Функция для чтения символа с клавиатуры без ожидания Enter
char getch() {
    char buf = 0;
    struct termios old = {0};
    // Получение текущих настроек терминала
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    // Отключение канонического режима и эхо-режима
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    // Применение новых настроек
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    // Чтение одного символа
    if (read(0, &buf, 1) < 0)
        perror("read()");
    // Возврат настроек терминала в исходное состояние
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

// Функция для ввода пин-кода с использованием функции getch
string enterpin() {
    cout << "Введите пинкод: \n";
    string key;
    char ch;

    while ((ch = getch()) != '\n') {
        if (ch == '\b' || ch == 127) {  // Обработка клавиши Backspace
            if (!key.empty()) {
                cout << "\b \b";  // Удаление символа на экране
                key.pop_back();   // Удаление символа из строки
                cout.flush();        // Принудительное обновление экрана

            }
        } else {
            key += ch;            // Добавление символа в строку
            cout << '*';          // Отображение звездочки вместо символа
            cout.flush();        // Принудительное обновление экрана

        }
    }
    cout << "\n";
    return key;
}

// Основная функция программы
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    while (true)
    {
        string key = enterpin();
        if (check_pin(key))
        {
            generateAcc();
            while (true)
            {
                int NumAcc;
                cout << "Введите номер аккаунта (для выхода из программы введите -1): ";
                cin >> NumAcc;
                if (NumAcc == -1) {
                    cout << "Выход\n";
                    return 0;
                }
                if (NumAcc < -1 || NumAcc >= Accounts.size()) { cout << "Аккаунт не найден!\n"; }
                else
                {
                    cout << "Логин: " << Accounts[NumAcc].first << "\n" << "Пароль: " << Accounts[NumAcc].second << "\n";
                }
            } 
        }
        else
        {
            cout << "Введен неверный пин-код" << "\n";
        }
    }  
}
