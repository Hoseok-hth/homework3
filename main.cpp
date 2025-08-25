#include<iostream>
#include"inventory.h"



int main() {

	Inventory<int> i(3);

	i.AddItem(1);
	i.AddItem(1);
	i.AddItem(1);
	i.AddItem(1);
	i.PrintAllItems();
	i.RemoveLastItem();
	i.PrintAllItems();


	
	return 0;
}