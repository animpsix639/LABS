#include <iostream>
#include <string>

using namespace std;

class Weapon {
    private:
        string name;
        int damage;
        float weight;

    public:
        Weapon(const string& weaponName, int weaponDamage, float weaponWeight)
            : name(weaponName), damage(weaponDamage), weight(weaponWeight) {}

        Weapon() : Weapon("Glock", 7, 0.7f) {}
    
        ~Weapon() {
            cout << "Удаление оружия" << endl;
            cout << "Имя: " << name << endl 
                 << "Урон: " << damage << endl 
                 << "Вес: " << weight << " кг \n"
                 << "Оружие удалено." << "\n\n"; 

        }
        void show() const {
            cout << "Имя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << " кг \n\n";
        }

        bool isHeavy(float maxWeight) const {
            return weight > maxWeight;
        }

        float totalWeight(const Weapon& otherWeapon) const {
            return totalWeight(otherWeapon.weight); 
        }

        float totalWeight(float plusWeight) const {
            return weight + plusWeight;
        }
};  

int main() {
    Weapon gwynbleidd("Gwynbleidd", 70, 2.8f);
    Weapon defaultWeapon;

    cout << "Меч:\n";
    gwynbleidd.show();

    cout << "Обычное оружие:\n";
    defaultWeapon.show();

    Weapon* newWeapon = new Weapon("Rocket Launcher", 500, 6.7f);
    cout << "Новое оружие:\n";
    newWeapon->show();

    float maxWeight = 4.5f;
    cout << "Новое оружие слишком тяжелое?\n"
         << (newWeapon->isHeavy(maxWeight) ? "Да\n" : "Нет\n")
         << endl;

    cout << "Общий вес оружия: " << newWeapon->totalWeight(*newWeapon) << " кг\n\n";

    cout << "Общий вес оружия + 4.2 кг: " << newWeapon->totalWeight(4.2f) << "кг\n\n";

    delete newWeapon;

    return 0;
}