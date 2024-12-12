#include "Character.h"
#include "Visitor.h"
#include "Observer.h"
#include "Factory.h"
#include "World.h"
#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <sstream>

TEST(NPCTest, CreateAndAccess) {
    Position coords = { 10.0f, 20.0f };

    // Создаем персонажей: Рыцарь и Пегас
    Knight knight("Knight1", coords.x, coords.y);
    Pegasus pegasus("Pegasus1", coords.x + 5.0, coords.y + 5.0);

    // Проверяем характеристики Рыцаря
    EXPECT_EQ(knight.GetType(), "Knight");
    EXPECT_EQ(knight.GetName(), "Knight1");
    EXPECT_EQ((double)knight.GetPosX(), 10.0);
    EXPECT_EQ((double)knight.GetPosY(), 20.0);

    // Проверяем характеристики Пегаса
    EXPECT_EQ(pegasus.GetType(), "Pegasus");
    EXPECT_EQ(pegasus.GetName(), "Pegasus1");
    EXPECT_EQ(pegasus.GetPosX(), 15.0f);
    EXPECT_EQ(pegasus.GetPosY(), 25.0f);
}

TEST(WorldTest, World) {
    World w;
    Visitor v(15.0);  // Увеличили силу посетителя
    ConsoleObserver ob;

    // Добавляем персонажей в мир
    EXPECT_NO_THROW(w.AddCharacter("Dragon", "Dragon1", 0.0, 0.0));
    EXPECT_NO_THROW(w.AddCharacter("Pegasus", "Pegasus1", 10.0, 10.0));
    EXPECT_NO_THROW(w.AddCharacter("Knight", "Knight1", 5.0, 5.0));

    // Добавляем наблюдателя
    EXPECT_NO_THROW(v.AddObserver(&ob));

    // Взаимодействие между персонажами
    EXPECT_NO_THROW(w.Engage(v));
}

TEST(FileOperationsTest, SaveAndLoadNPCs) {
    World w;

    // Добавляем персонажей в мир
    w.AddCharacter("Pegasus", "Pegasus1", 10.0, 10.0);
    w.AddCharacter("Dragon", "Dragon1", 30.0, 40.0);
    w.AddCharacter("Knight", "Knight1", 50.0, 60.0);

    const std::string filename = "npcs.txt";  // Новый файл

    // Сохраняем мир в файл
    w.Serialize(filename);

    World w2;

    // Загружаем мир из файла
    w2.Deserialize(filename);
    auto loaded_npcs = w2.GetCharacters();

    // Проверяем, что загруженные персонажи соответствуют ожидаемым
    ASSERT_EQ(loaded_npcs.size(), 3);  // 3 персонажа
    EXPECT_EQ(loaded_npcs[0]->GetType(), "Pegasus");
    EXPECT_EQ(loaded_npcs[0]->GetName(), "Pegasus1");
    EXPECT_EQ(loaded_npcs[1]->GetType(), "Dragon");
    EXPECT_EQ(loaded_npcs[1]->GetName(), "Dragon1");
    EXPECT_EQ(loaded_npcs[2]->GetType(), "Knight");
    EXPECT_EQ(loaded_npcs[2]->GetName(), "Knight1");
}
