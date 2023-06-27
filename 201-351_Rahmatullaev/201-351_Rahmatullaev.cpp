// 201-351_Rahmatullaev.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include <random>


using namespace std;



vector<pair<string, string>> UserAccounts;

bool check_pin(string key)
{
    const string goodpass = "1234";
    return key == goodpass;
}


string generateRandomCreds()
{
    string randomString;

    int randomNumlenght = rand() % 5 + 4;

    static const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;

    for (int i = 0; i < randomNumlenght; ++i) {
        int randomIndex = rand() % alphabet.length();
        result += alphabet[randomIndex];
    }

    return result;
}


void generateAcc() {
    int randomNumlenght = rand() % 10 + 5;
    cout << "Всего аккаунтов: " << randomNumlenght << "\n";
    for (int i = 0; i < randomNumlenght; i++) {
        string login = generateRandomCreds();
        string password = generateRandomCreds();

        UserAccounts.emplace_back(login, password);
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
            cout << '*';  // Выводим звездочку вместо введенного символа
            i++;
        }
    }
    cout << "\n";
    return key;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string key = enterpin();

    srand(time(0));

    

    if (check_pin(key))
    {
        generateAcc();
        int NumAcc;
        while (true)
        {
            cout << "Введите номер аккаунта (или -1 для выхода): ";
            cin >> NumAcc;
            if (NumAcc == -1) {
                cout << "Выход\n";
                break;
                
            }
            if (NumAcc < 0 || NumAcc >= UserAccounts.size()) { cout << "Аккаунт не найден!\n";}
            else
            {
                cout << "Логин: " << UserAccounts[NumAcc].first << "\n";
                cout << "Пароль: " << UserAccounts[NumAcc].second << "\n";
            }
        }
    }
    else
    {
        cout << "Введен неверный пин-код" << "\n";
        return -1;
    }

}

