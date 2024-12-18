#include <iostream>
#include <string>
using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon {
private:
    string name;
    WeaponType type;
    int baseDamage;

public:
    Weapon(const string &name, WeaponType type, int baseDamage) : name(name), type(type), baseDamage(baseDamage) {}

    WeaponType getType() const {
        return type;
    }

    string getName() const {
        return name;
    }

    virtual int getDamage() const {
        return baseDamage;
    }

    bool operator>(const Weapon &other) const {
        return this->getDamage() > other.getDamage();
    }

    bool operator<(const Weapon &other) const {
        return this->getDamage() < other.getDamage();
    }
};

class MagicWeapon : public Weapon {
private:
    int extraDamage;

public:
    MagicWeapon() : Weapon("Волшебная палочка", ONEHANDED, 0), extraDamage(0) {}

    MagicWeapon(const string &name, WeaponType type, int baseDamage, int extraDamage)
        : Weapon(name, type, baseDamage), extraDamage(extraDamage) {}

    int getExtraDamage() const {
        return extraDamage;
    }

    int getDamage() const override {
        return Weapon::getDamage() + extraDamage;
    }
};

struct Player {
    int id;
    string login;
    string password;

    void displayInfo() const {
        cout << "ID: " << id << "\n"
             << "Login: " << login << "\n"
             << "Password: " << password << "\n";
    }
};

int main() {
    Weapon sword("Gwynbleidd", ONEHANDED, 30);
    
    if (sword.getType() == ONEHANDED) {
        cout << sword.getName() << " \"\u041e\u0434\u043d\u043e\u0440\u0443\u0447\u043d\u043e\u0435 \u043e\u0440\u0443\u0436\u0438\u0435\"." << endl;
    }

    Player player = {1, "Игрок 1", "qwerty639"};
    player.displayInfo();

    MagicWeapon fireSword("Меч квилег", ONEHANDED, 30, 50);
    cout << fireSword.getName() << " имеет урон: " << fireSword.getDamage() << "\n";

    MagicWeapon iceSword("Меч льда", TWOHANDED, 40, 20);

    if (fireSword > iceSword) {
        cout << fireSword.getName() << " сильнее чем " << iceSword.getName() << "\n";
    } else {
        cout << iceSword.getName() << " сильнее чем " << fireSword.getName() << "\n";
    }

    return 0;
}
