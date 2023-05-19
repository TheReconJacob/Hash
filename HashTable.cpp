#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int size)
{
    this->size = size;
    data = new GameObject * [size];
    for (int i = 0; i < size; i++)
        data[i] = NULL;
}

void HashTable::Display()
{
    for (int i = 0; i < size; i++)
        if (data[i] != NULL)
            std::cout << "Index: " << i << ", Key: " << data[i]->key << ", Name: " << data[i]->name << std::endl;
}

void HashTable::Insert(GameObject* item)
{
    int key = item->key;
    int hash = HashFunction(key);
    while (data[hash] != NULL) {
        ++hash;
        hash %= size;
    }
    data[hash] = item;
}

int HashTable::HashFunction(int key)
{
    return key % size;
}

GameObject* HashTable::Find(int key)
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

GameObject* HashTable::Delete(int key)
{
    int hash = HashFunction(key);
    while (data[hash] != NULL) {
        if (data[hash]->key == key) {
            GameObject* temp = data[hash];
            data[hash] = NULL;
            return temp;
        }
        ++hash;
        hash %= size;
    }
    return NULL;
}