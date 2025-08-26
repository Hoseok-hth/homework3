#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;


class Item {
public:
	Item() {
		temName_ = "empty";
		price_ = 0;
	};
	Item(string temName, int price);
	
	void Assign(Item& other);
	void PrintInfo();
	void SetPrice(int price);
	void SetName(string name);
	int GetPrice() const;
	string GetName() const;

private:
	string temName_;
	int price_;
};




//두 Item 객체를 받아 가격을 기준으로 어떤 것이 먼저 와야 하는지 판단
bool compareItemsByPrice(const Item& a, const Item& b) {
	return a.GetPrice() < b.GetPrice();
}


template <typename T>


class Inventory {
public:
	Inventory(int capacity = 10);
	// 복사 생성자
	Inventory(const Inventory<T>& other);
	~Inventory();

	void Assign(const Inventory<T>& other);
	void AddItem(const T& item);
	void RemoveLastItem();
	void Resize(int newCapacity);
	void SortItems();
	int GetSize() const;
	int GetCapacity() const;
	void PrintAllItems() const;
	
	

private:
	T* pItems_;
	int capacity_;
	int size_;
};


//#include "inventory.tpp"

using namespace std;

template<typename T>
Inventory<T>::Inventory(int capacity)
{
	if (capacity <= 0) {
		this->capacity_ = 1;
	}
	else {
		this->capacity_ = capacity;
	}
	pItems_ = new T[this->capacity_];
	this->size_ = 0;

}
template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other) {
	capacity_ = other.capacity_;
	size_ = other.size_;
	pItems_ = new T[capacity_];
	for (int i = 0; i < size_; i++) {
		pItems_[i].Assign(other.pItems_[i]);
	}
	cout << "인벤토리 복사 완료" << endl;
}

template<typename T>
Inventory<T>::~Inventory()
{
	delete[]pItems_;
	pItems_ = nullptr;
}

template<typename T>
void Inventory<T>::AddItem(const T& item) {
	int price = item.GetPrice();
	string temName = item.GetName();
	if (size_ < capacity_) {
		pItems_[size_].SetPrice(price);
		pItems_[size_].SetName(temName);
		size_++;
	}
	else {
		cout << "double inven" << endl;
		int t_price = 0;
		string t_name = "empty";
		T* temp = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			t_price = pItems_[i].GetPrice();
			t_name = pItems_[i].GetName();
			temp[i].SetPrice(t_price);
			temp[i].SetName(t_name);
		}
		delete[] pItems_;
		capacity_ *= 2;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			t_price = temp[i].GetPrice();
			t_name = temp[i].GetName();
			pItems_[i].SetPrice(t_price);
			pItems_[i].SetName(t_name);
		}
		delete[]temp;
		temp = nullptr;
		pItems_[size_].SetPrice(price);
		pItems_[size_].SetName(temName);
		size_++;
		
		
	}
}

template<typename T>
void Inventory<T>::RemoveLastItem() {
	if (size_ > 0) {
		size_--;
	}
	else {
		cout << "인벤토리가 비어있습니다." << endl;
	}
}

template<typename T>
int Inventory<T>::GetCapacity() const {
	return capacity_;
}

template<typename T>
int Inventory<T>::GetSize() const {
	return size_;
}

template<typename T>
void Inventory<T>::PrintAllItems() const {
	if (size_ > 0) {
		for (int i = 0; i < size_; i++) {
			pItems_[i].PrintInfo();
		}
	}
	else {
		cout << "(비어있음)";
	}
	cout << endl;
}

template<typename T>
void Inventory<T>::Resize(int newCapacity) 
{
	if (newCapacity > capacity_) {
		T* temp = new T[capacity_];
		int t_price = 0;
		string t_name = "empty";
		for (int i = 0; i < size_; i++) {
			//temp[i] = pItems_[i];
			t_price = pItems_[i].GetPrice();
			t_name = pItems_[i].GetName();
			temp[i].SetPrice(t_price);
			temp[i].SetName(t_name);
		}
		delete[] pItems_;
		capacity_ = newCapacity;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			t_price = temp[i].GetPrice();
			t_name = temp[i].GetName();
			pItems_[i].SetPrice(t_price);
			pItems_[i].SetName(t_name);
		}
	}
	else {
		cout << "기존 용량보다 작습니다." << endl;
	}

}

template<typename T>
void Inventory<T>::SortItems()
{
	sort(pItems_, pItems_ + GetSize(), compareItemsByPrice);
}

template<typename T>
void Inventory<T>::Assign(const Inventory<T>& other) {
	delete[] pItems_;
	this->capacity_ = other.GetCapacity();
	pItems_ = new T[this->capacity_];
	int t_price = 0;
	string t_name = "empty";
	int i = 0;
	for ( i = 0; i < other.size_; i++) {
		t_price = other.pItems_[i].GetPrice();
		t_name = other.pItems_[i].GetName();
		pItems_[i].SetPrice(t_price);
		pItems_[i].SetName(t_name);
	}
	size_ = i;
}




Item::Item(string temName, int price)
{
	temName_ = temName;
	price_ = price;
}

void Item::Assign(Item& other)
{
	temName_ = other.GetName();
	price_ = other.GetPrice();
}

void Item::PrintInfo()
{
	cout << "아이템 이름: " << GetName() <<endl;
	cout << "아이템 가격: " << GetPrice() <<endl;
}

void Item::SetPrice(int price)
{
	price_ = price;
}

 void Item::SetName(string name)
{
	 temName_ = name;
}

int Item::GetPrice() const
{
	return price_;
}

string Item::GetName() const
{
	return temName_;
}
