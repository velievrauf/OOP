#pragma once

#include <memory>
#include <string>

struct Position {
    double x;
    double y;
};

class Character {
public:
    Character(const std::string& name, double x, double y)
        : name(name), pos({ x, y }) {}

    const std::string& GetName() const noexcept { return name; }
    double GetPosX() const noexcept { return pos.x; }
    double GetPosY() const noexcept { return pos.y; }
    virtual std::string GetType() const = 0;
    bool IsAlive() const { return isAlive; }
    void Kill() { isAlive = false; }
    virtual bool Beats(const Character& other) const = 0;
    virtual ~Character() = default;

protected:
    std::string name;
    Position pos;
    bool isAlive = true;
};

class Dragon : public Character {
public:
    Dragon(const std::string& name, double x, double y)
        : Character(name, x, y) {}

    virtual std::string GetType() const override {
        return "Dragon";
    }

    virtual bool Beats(const Character& other) const override {
        return other.GetType() == "Pegasus"; // Дракон ест пегаса
    }
};

class Pegasus : public Character {
public:
    Pegasus(const std::string& name, double x, double y)
        : Character(name, x, y) {}

    virtual std::string GetType() const override {
        return "Pegasus";
    }

    virtual bool Beats(const Character&) const override {
        return false; // Пегас никого не трогает
    }
};

class Knight : public Character {
public:
    Knight(const std::string& name, double x, double y)
        : Character(name, x, y) {}

    virtual std::string GetType() const override {
        return "Knight";
    }

    virtual bool Beats(const Character& other) const override {
        return other.GetType() == "Dragon"; // Рыцарь убивает дракона
    }
};
