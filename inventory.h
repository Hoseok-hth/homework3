#pragma once
#include<iostream>
using namespace std;

template <typename T>


class Inventory {
public:
	Inventory(int capacity = 10);
	
	
	~Inventory();
	void AddItem(const T& item);
	void RemoveLastItem();
	int GetSize() const;
	int GetCapacity() const;
	void PrintAllItems() const;

private:
	T* pItems_;
	int capacity_;
	int size_;
};


#include "inventory.tpp"