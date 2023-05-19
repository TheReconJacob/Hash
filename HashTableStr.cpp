#include "HashTableStr.h"
#include <iostream>

HashTableStr::HashTableStr(int size)
{
    this->size = size;
    data = new GameObjectStr * [size];
    for (int i = 0; i < size; i++)
        data[i] = NULL;
}

void HashTableStr::Display()
{
    for (int i = 0; i < size; i++)
        if (data[i] != NULL)
            std::cout << "Index: " << i << ", Key: " << data[i]->key << ", Name: " << data[i]->name << std::endl;
}

void HashTableStr::Insert(GameObjectStr* item) {
    int hash = HashFunction(item->key);
    while (data[hash] != NULL) {
        ++hash;
        hash %= size;
    }
    data[hash] = item;
}

int HashTableStr::HashFunction(std::string key) {
    int sum = 0;
    for (char c : key)
        sum += c;
    return sum % size;
}

GameObjectStr* HashTableStr::Find(std::string key)
{
    int hash = HashFunction(key);
    while (data[hash] != NULL) {
        if (data[hash]->key == key)
            return data[hash];
        ++hash;
        hash %= size;
    }
    return NULL;
}

GameObjectStr* HashTableStr::Delete(std::string key)
{
    int hash = HashFunction(key);
    while (data[hash] != NULL) {
        if (data[hash]->key == key) {
            GameObjectStr* temp = data[hash];
            data[hash] = NULL;
            return temp;
        }
        ++hash;
        hash %= size;
    }
    return NULL;
}