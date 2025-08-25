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
Inventory<T>::~Inventory()
{
	delete []pItems_;
	pItems_ = nullptr;
}

template<typename T>
void Inventory<T>::AddItem(const T& item) {
	if (size_ < capacity_) {
		pItems_[size_] = item;
		size_++;
	}
	else {
		cout << "인벤토리가 꽉 찼습니다." << endl;
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
void Inventory<T>::PrintAllItems() const{
	if (size_ > 0) {
		for (int i = 0; i < size_; i++) {
			cout << pItems_[i] << " ";
		}
	}
	else {
		cout << "(비어있음)";
	}
	cout <<endl;
}