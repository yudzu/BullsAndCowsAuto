#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int arr[4], hod[4];
string a[5040];
bool b[5040];

void rndm() {
    int i = 0;
    bool f = 0;
    srand(time(0));
    while (i < 4) {
        arr[i] = rand() % 10;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j] && j != i) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            i++;
        }
        f = 0;
    }
    cout << "Задуманное число: ";
    for (int k = 0; k < 4; k++) {
        cout << arr[k];
    }
    cout << endl << endl;
}

void initialization() {
    int t = 0;
    string s;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        s = to_string(i) + to_string(j) + to_string(k) + to_string(l);
                        a[t] = s;
                        t++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5040; i++) {
        b[i] = true;
    }
}

void variant() {
    string s;
    int x;
    for (int i = 0; i < 5040; i++) {
        if (b[i]) {
            s = a[i];
            for (int j = 0; j < 4; j++) {
                auto c = s[j];
                x = atoi(&c);
                hod[j] = x;
                cout << hod[j];
            }
            break;
        }
    }
    cout << endl;
}

int bulls() {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == hod[i]) {
            res++;
        }
    }
    return res;
}

int cows() {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i] == hod[j] && i != j) {
                res++;
            }
        }
    }
    return res;
}

bool resheto(string s) {
    int t = 0;
    int x, mass[4];
    for (int i = 0; i < 4; i++) {
        auto c = s[i];
        x = atoi(&c);
        mass[i] = x;
    }
    for (int j = 0; j < 4; j++) {
        if (mass[j] == hod[j]) {
            t++;
        }
    }
    if (t != bulls()) {
        return false;
    }
    t = 0;
    for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
            if (mass[k] != hod[k] && hod[k] == mass[l]) {
                t++;
            }
        }
    }
    if (t < cows()) {
        return false;
    }
    return true;
}

void game() {
    rndm();
    int k = 1;
    while (true) {
        cout << "Попытка " << k++ << ": ";
        variant();
        for (int i = 0; i < 5040; i++) {
            string s = a[i];
            if (b[i] && !resheto(s)) {
                b[i] = false;
            }
        }
        cout << "Быков: " << bulls() << " Коров: " << cows() << endl << endl;
        if (bulls() == 4) {
            cout << "Победа! Всего потребовалось " << --k << " попыток для угадывания задуманного числа." << endl;
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Здравствуйте, это игра 'Быки и коровы', но с одной особенностью." << endl;
    cout << "Компьютер загадал 4-хзначное число, а данная программа будет его угадывать по правилам вышеупомянутой игры." << endl;
    cout << "Если цифра совпадает, но стоит на другом месте - это корова, если стоит на том же месте - бык." << endl << endl;
    initialization();
    game();
    return 0;
}