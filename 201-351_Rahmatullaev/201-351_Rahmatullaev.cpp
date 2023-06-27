// 201-351_Rahmatullaev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <random>


using namespace std;

vector<pair<string, string>> Accounts;

bool check_pin(string key)
{
    const string goodpass = "1234";
    return key == goodpass;
}


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


void generateAcc() {
    int randomNumlenght = rand() % 10 + 5;
    cout << "Всего аккаунтов: " << randomNumlenght -1 << "\n";
    for (int i = 0; i < randomNumlenght; i++) {

        string login = generateRandomCreds();
        string password = generateRandomCreds();

        Accounts.emplace_back(login, password);
    }
}
string enterpin() {
    cout << "Введите пинкод: \n";
    string key;
    int i = 0;
    char ch;

    while ((ch = _getch()) != '\r') { 
        if (ch == '\b') {  
            if (i > 0) {
                cout << "\b \b";  
                i--;
                key.pop_back();
            }
        }
        else {
            key += ch;
            cout << '*'; 
            i++;
        }
    }
    cout << "\n";
    return key;
}

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

