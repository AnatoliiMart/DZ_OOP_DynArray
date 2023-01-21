#include <iostream>
template<typename T>
class DynArray
{
	T* arr;
	size_t size;
public:
	DynArray(size_t sizeP)
		: arr{ new T[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object): arr{ new T[object.size] }, size{ object.size }
	{
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = object.arr[i];
		};
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	int getElem(size_t idx) { return arr[idx]; }
	void setElem(size_t idx, T val) { arr[idx] = val; }
	void print();
	void randomize();
	void Add(T);
	void Delete(int elemIndex);
	~DynArray()
	{
		delete[] arr;
	}
};

template<typename T>
void DynArray<T>::print()
{
	for (size_t i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

template<typename T>
void DynArray<T>::randomize()
{
		for (size_t i{ 0 }; i < size; ++i)
		{
			arr[i] = rand() % 10;
		}
}

template<typename T>
 void DynArray<T>::Add(T newElem)
{
	DynArray tmp(size + 1);

	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp.arr[i] = this->arr[i];
		if (i == (tmp.size - 1))
		{
			tmp.arr[i] = newElem;
		}
	}

	size = tmp.size;
	arr  = new T[size];
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = tmp.arr[i];
	}
}

 template<typename T>
 void DynArray<T>::Delete(int elemIndex)
 {
	 DynArray tmp(size - 1);
	 int j = 0;
	 for (size_t i = 0; i < tmp.size; i++)
	 {
		 if (i == elemIndex - 1)
		 {
			 continue;
		 }
		 else
		 {
			 tmp.arr[j] = arr[i];
			 j++;
		 }
	 }
	 this->~DynArray();

	 size = size - 1;
	 arr = new T[size];

	 for (size_t i = 0; i < size; i++)
	 {
		 arr[i] = tmp.arr[i];
	 }
 }


int main()
{
	DynArray<int> ar1{ 10 };
	ar1.randomize();
	std::cout << "ar1 elements: ";
	ar1.print();
	DynArray<int> ar2{ ar1 };
	std::cout << "ar2 elements: ";
	ar2.print();
	ar2.Add(0);
	ar2.print();
	ar2.Delete(3);
	ar2.print();
	return 0;
}