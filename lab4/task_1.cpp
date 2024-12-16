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

        void show() const {
            cout << "Имя: " << name << endl << "Урон: " << damage << endl << "Вес: " << weight << " кг \n";
        }
};  

int main() {
    Weapon gwynbleidd("Gwynbleidd", 70, 2.8f);
    Weapon defaultWeapon;

    cout << "Меч:\n";
    gwynbleidd.show();
    cout << "Обычное оружие:\n";
    defaultWeapon.show();

    return 0;
}