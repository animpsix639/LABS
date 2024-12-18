#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>

using namespace std;

class BirthYearException : public exception {
public:
    enum ErrorCode {
        TOO_OLD,
        NOT_BORN_YET,
        NEGATIVE_YEAR
    };

    explicit BirthYearException(ErrorCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
            case TOO_OLD:
                return "Что-то не верится...";
            case NOT_BORN_YET:
                return "Вы ещё не родились";
            case NEGATIVE_YEAR:
                return "Вы ввели отрицательное число!";
            default:
                return "Неизвестная ошибка";
        }
    }

private:
    ErrorCode code;
};

int main() {
    try {
        int number;
        cout << "Введите число (1, 2 или 3): ";
        cin >> number;

        switch (number) {
            case 1:
                cout << "Один" << endl;
                break;
            case 2:
                cout << "Два" << endl;
                break;
            case 3:
                cout << "Три" << endl;
                break;
            default:
                throw invalid_argument("Некорректное значение");
        }

        int birthYear;
        cout << "Введите год вашего рождения: ";
        cin >> birthYear;

        time_t t = time(nullptr);
        tm* currentTime = localtime(&t);
        int currentYear = currentTime->tm_year + 1900;

        if (birthYear < 1850) {
            throw BirthYearException(BirthYearException::TOO_OLD);
        } else if (birthYear > currentYear) {
            throw BirthYearException(BirthYearException::NOT_BORN_YET);
        } else if (birthYear < 0) {
            throw BirthYearException(BirthYearException::NEGATIVE_YEAR);
        }

        cout << "Спасибо!" << endl;

    } catch (const BirthYearException& e) {
        cout << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "Произошла неизвестная ошибка." << endl;
    }

    return 0;
}
