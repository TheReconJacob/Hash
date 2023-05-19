// Hash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable* table = new HashTable(17);
    table->Insert(new GameObject(10, "Bridge"));
    table->Insert(new GameObject(5, "Player"));
    table->Insert(new GameObject(30, "Tank"));
    table->Insert(new GameObject(16, "AI"));
    table->Insert(new GameObject(16, "AICollider"));
    //AICollider returns an index of 0 since the collision is resolved by linear probing. As it increments the index by one until it finds the next empty section. Since 16 was the last, it loops back to 0 as the next section.

    table->Display();

    GameObject* result = table->Find(30);
    if (result != NULL)
        std::cout << "Key: " << result->key << ", Name: " << result->name << std::endl;
    else
        std::cout << "GameObject not found." << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
