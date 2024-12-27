#include <iostream>
#include <string>

using namespace std;

int main() {
    string userString;
    cout << "Введите строку: ";
    getline(cin, userString);

    if (userString.length() >= 4) {
        string substring = userString.substr(1, 3);
        cout << "Подстрока от 2-го до 4-го символа: " << substring << endl;
    } else {
        cout << "Строка слишком короткая для выполнения операции." << endl;
    }

    size_t index = userString.find('a');
    if (index != string::npos) {
        cout << "Индекс первого вхождения символа 'a': " << index << endl;
    } else {
        cout << "Символа 'a' не найдено." << endl;
    }

    return 0;
}