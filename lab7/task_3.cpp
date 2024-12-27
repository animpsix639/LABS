#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double radius;
    cout << "Введите радиус окружности: ";
    cin >> radius;

    const double PI = 3.141592653589793;
    double circumference = 2 * PI * radius;

    cout << fixed << setprecision(3); 
    cout << "Длина окружности: " << circumference << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    const string filename = "output.txt";

    while (true) {
        cout << "Введите строку (или команды read, erase, exit): ";
        getline(cin, input);

        if (input == "read") {
            ifstream file(filename);
            if (file.is_open()) {
                cout << "Содержимое файла:" << endl;
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "Файл ещё не создан." << endl;
            }
        } else if (input == "erase") {
            ofstream file(filename, ios::trunc);
            if (file.is_open()) {
                cout << "Файл очищен." << endl;
                file.close();
            } else {
                cout << "Не удалось открыть файл для очистки." << endl;
            }
        } else if (input == "exit") {
            cout << "Программа завершена." << endl;
            break;
        } else {
            ofstream file(filename, ios::app);
            if (file.is_open()) {
                file << input << endl;
                file.close();
                cout << "Строка добавлена в файл." << endl;
            } else {
                cout << "Не удалось открыть файл для записи." << endl;
            }
        }
    }

    return 0;
}