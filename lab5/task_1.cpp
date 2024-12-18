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

public:
    Weapon(const string &name, WeaponType type) : name(name), type(type) {}

    WeaponType getType() const {
        return type;
    }

    string getName() const {
        return name;
    }
};

class MagicWeapon : public Weapon {
private:
    int extraDamage;

public:
    MagicWeapon() : Weapon("Волшебная палочка", ONEHANDED), extraDamage(0) {}

    MagicWeapon(const string &name, WeaponType type, int extraDamage)
        : Weapon(name, type), extraDamage(extraDamage) {}

    int getExtraDamage() const {
        return extraDamage;
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
    Weapon sword("Gwynbleidd", ONEHANDED);
    
    if (sword.getType() == ONEHANDED) {
        cout << sword.getName() << " \"\u041e\u0434\u043d\u043e\u0440\u0443\u0447\u043d\u043e\u0435 \u043e\u0440\u0443\u0436\u0438\u0435\"." << std::endl;
    }

    Player player = {1, "Игрок 1", "qwerty639"};
    player.displayInfo();

    MagicWeapon fireSword("Меч Квилег", ONEHANDED, 50);
    cout << fireSword.getName() << " доп. урон: " << fireSword.getExtraDamage() << "\n";

    return 0;
}
