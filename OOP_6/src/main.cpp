#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>

// Базовый класс Fighter
class Fighter {
public:
    virtual ~Fighter() = default;
    virtual void Print() const = 0;
    virtual bool Beats(const Fighter& other) const = 0;
    virtual std::string GetType() const = 0;
    virtual std::string GetName() const = 0;
    virtual float GetX() const = 0;
    virtual float GetY() const = 0;
};

// Класс Pegasus
class Pegasus : public Fighter {
private:
    std::string name;
    float x, y;
public:
    Pegasus(const std::string& name, float x, float y)
        : name(name), x(x), y(y) {}

    void Print() const override {
        std::cout << "Pegasus '" << name << "' (" << x << ", " << y << ")\n";
    }

    bool Beats(const Fighter& other) const override {
        // Пегас не побеждает никого
        return false;
    }

    std::string GetType() const override {
        return "Pegasus";
    }

    std::string GetName() const override {
        return name;
    }

    float GetX() const override {
        return x;
    }

    float GetY() const override {
        return y;
    }
};

// Класс Dragon
class Dragon : public Fighter {
private:
    std::string name;
    float x, y;
public:
    Dragon(const std::string& name, float x, float y)
        : name(name), x(x), y(y) {}

    void Print() const override {
        std::cout << "Dragon '" << name << "' (" << x << ", " << y << ")\n";
    }

    bool Beats(const Fighter& other) const override {
        // Дракон побеждает пегаса
        if (other.GetType() == "Pegasus") {
            return true;
        }
        return false;
    }

    std::string GetType() const override {
        return "Dragon";
    }

    std::string GetName() const override {
        return name;
    }

    float GetX() const override {
        return x;
    }

    float GetY() const override {
        return y;
    }
};

// Класс Knight
class Knight : public Fighter {
private:
    std::string name;
    float x, y;
public:
    Knight(const std::string& name, float x, float y)
        : name(name), x(x), y(y) {}

    void Print() const override {
        std::cout << "Knight '" << name << "' (" << x << ", " << y << ")\n";
    }

    bool Beats(const Fighter& other) const override {
        // Рыцарь побеждает только дракона
        if (other.GetType() == "Dragon") {
            return true;
        }
        return false;
    }

    std::string GetType() const override {
        return "Knight";
    }

    std::string GetName() const override {
        return name;
    }

    float GetX() const override {
        return x;
    }

    float GetY() const override {
        return y;
    }
};

int main() {
    // Создаем бойцов
    std::vector<std::shared_ptr<Fighter>> fighters;
    fighters.push_back(std::make_shared<Pegasus>("Pegasus 0", 70.3446, 288.352));
    fighters.push_back(std::make_shared<Pegasus>("Pegasus 1", 183.604, 78.6679));
    fighters.push_back(std::make_shared<Dragon>("Dragon 2", 477.024, 444.76));
    fighters.push_back(std::make_shared<Dragon>("Dragon 3", 157.113, 146.669));
    fighters.push_back(std::make_shared<Knight>("Knight 6", 117.329, 244.419));

    // Выводим информацию о бойцах
    std::cout << "Fighters in dungeon:\n";
    std::cout << "------------------------------------------------------------------\n";
    for (const auto& fighter : fighters) {
        fighter->Print();
    }

    // Проведение боев
    std::cout << "\nBattles:\n";
    std::cout << "------------------------------------------------------------------\n";
    for (size_t i = 0; i < fighters.size(); ++i) {
        for (size_t j = i + 1; j < fighters.size(); ++j) {
            const auto& fighter1 = fighters[i];
            const auto& fighter2 = fighters[j];
            if (fighter1->Beats(*fighter2)) {
                std::cout << fighter1->GetName() << " beats " << fighter2->GetName() << "\n";
            }
            else if (fighter2->Beats(*fighter1)) {
                std::cout << fighter2->GetName() << " beats " << fighter1->GetName() << "\n";
            }
        }
    }

    return 0;
}
