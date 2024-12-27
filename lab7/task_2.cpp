#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int main() {
    string name;
    cout << "Введите ваше имя: ";
    getline(cin, name);

    regex nameRegex("^[A-Z][a-zA-Z]{1,31}$"); 
    if (!regex_match(name, nameRegex)) {
        cout << "Некорректное имя. Имя должно начинаться с заглавной буквы и содержать только буквы, длина от 2 до 32 символов." << endl;
        return 1;
    }

    cout << "Здравствуйте, " << name << "!" << endl;

    string text = "Вот несколько e-mail адресов: example1@mail.com, test.email@domain.org, user_name@company.net. "
                  "А ещё один адрес: another.email@example.com";

    regex emailRegex(R"(([\w.-]+)@([\w.-]+\.[a-zA-Z]{2,}))"); 
    smatch match;

    cout << "Найдены следующие e-mail адреса:" << endl;
    string::const_iterator searchStart(text.cbegin());
    while (regex_search(searchStart, text.cend(), match, emailRegex)) {
        cout << match[0] << endl; 
        searchStart = match.suffix().first;
    }

    return 0;
}