#pragma once

#include "Character.h"
#include <memory>
#include <stdexcept>

class Factory {
public:
    static std::shared_ptr<Character> CreateCharacter(const std::string& type, const std::string& name, double x, double y) {
        if (type == "Dragon") {
            return std::make_shared<Dragon>(name, x, y);
        }
        else if (type == "Pegasus") {
            return std::make_shared<Pegasus>(name, x, y);
        }
        else if (type == "Knight") {
            return std::make_shared<Knight>(name, x, y);
        }
        else {
            throw std::invalid_argument("Unknown NPC type: " + type);
        }
    }
};
