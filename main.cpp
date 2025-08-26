#include<iostream>
#include"inventory.h"



int main() {
	
	Inventory<Item> i(1);
	Inventory<Item> i2(1);
	
	Item tem1("Į", 9);
	Item tem2("����", 2);
	Item tem3("����", 4);
	Item tem4("�Ź�", 3);

	
	i.AddItem(tem1);
	i.AddItem(tem2);
	i.PrintAllItems();

	i.Resize(10);
	i.AddItem(tem3);
	i.AddItem(tem4);
	i.PrintAllItems();

	i2.Assign(i);
	i2.PrintAllItems();

	i.SortItems();
	i.PrintAllItems();

	i.RemoveLastItem();
	i.PrintAllItems();

	Inventory<Item> i3(i);

	i3.PrintAllItems();
	

	
	

	
	return 0;
}