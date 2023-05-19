#pragma once
#include "GameObject.h"
class HashTable
{
private:
	GameObject** data;
	int size;

	int HashFunction(int key);
	
public:
	void Display();
	HashTable(int size);
	void Insert(GameObject* item);
	GameObject* Find(int key);
	GameObject* Delete(int key);
};