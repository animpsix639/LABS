#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void PrintVector(const vector<float>& vec) {
    for (float val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

class Settings {
private:
    static map<string, string> settingsMap;

public:
    static void Add(const string& key, const string& value) {
        settingsMap[key] = value;
    }

    static string Get(const string& key) {
        if (settingsMap.find(key) != settingsMap.end()) {
            return settingsMap[key];
        } else {
            return "Ключ не найден";
        }
    }

    static void Print() {
        for (const auto& pair : settingsMap) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

map<string, string> Settings::settingsMap;

int main() {
    vector<float> vec;

    vec.push_back(1.1f);
    vec.push_back(2.2f);
    vec.push_back(3.3f);
    vec.push_back(4.4f);
    vec.push_back(5.5f);

    cout << "Вектор после добавления 5 элементов:" << endl;
    PrintVector(vec);

    vec.insert(vec.begin() + 3, 3.9f);

    cout << "Вектор после вставки элемента между 3 и 4 элементами:" << endl;
    PrintVector(vec);

    vec.pop_back();

    cout << "Вектор после удаления последнего элемента:" << endl;
    PrintVector(vec);

    /*
    Settings settings;

    settings.Add("username", "admin");
    settings.Add("password", "12345");
    settings.Add("theme", "dark");

    cout << "Содержимое Map:" << endl;
    settings.Print();

    cout << "Значение по ключу 'username': " << settings.Get("username") << endl;
    cout << "Значение по ключу 'not_exist': " << settings.Get("not_exist") << endl;
    */

    // 14-15. Работа со статическим классом Settings
    Settings::Add("username", "admin");
    Settings::Add("password", "12345");
    Settings::Add("theme", "dark");

    cout << "Содержимое Map (статические методы):" << endl;
    Settings::Print();

    cout << "Значение по ключу 'username': " << Settings::Get("username") << endl;
    cout << "Значение по ключу 'not_exist': " << Settings::Get("not_exist") << endl;

    return 0;
}