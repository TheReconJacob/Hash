#pragma once
#include "GameObjectStr.h"

class HashTableStr
{
private:
    GameObjectStr** data;
    int size;

    int HashFunction(std::string key);

public:
    void Display();
    HashTableStr(int size);
    void Insert(GameObjectStr* item);
    int HashFunction(int key);
    GameObjectStr* Find(std::string key);
    GameObjectStr* Delete(std::string key);

};