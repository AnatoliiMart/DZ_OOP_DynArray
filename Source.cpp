#include <iostream>
#include<ctime>

class Point
{
public:
	Point() :x(0), y(0) {};
	Point(int pX, int pY) :x(pX), y(pY) {};
	int getX() { return x; }
	int getY() { return y; }
	void setX(int pX) { x = pX; }
	void setY(int pY) { y = pY; }
	~Point(){}

private:
	int x;
	int y;
};

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
	int  getElem(size_t idx) { return arr[idx]; }
	void setElem(size_t idx, T val) { arr[idx] = val; }
	void print();
	void randomize();
	void Add(T);
	void Delete(size_t elemIndex);
	T sumElements();
	friend std::ostream& operator <<(std::ostream& os, Point& obj);
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
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = (T)(480 + rand() % 90) * 0.1;
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
 void DynArray<T>::Delete(size_t elemIndex)
 {
	 DynArray tmp(size - 1);
	 size_t j = 0;
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

 template<typename T>
 T DynArray<T>::sumElements()
 {
	 T tmp = 0;
	 for (size_t i = 0; i < size; i++)
	 {
		 tmp += arr[i];
	 }
	 return tmp;
 }
 template<>
 Point DynArray<Point>::sumElements()
 {
	 int sumX = 0;
	 int sumY = 0;
	 for (size_t i = 0; i < size; i++)
	 {
		 sumX += arr[i].getX();
		 sumY += arr[i].getY();
	 }
	 std::cout << "The sum of X coordinates: " << sumX << std::endl;
	 std::cout << "The sum of Y coordinates: " << sumY << std::endl;
	 return arr[size];
 }

 template<>
 void DynArray<Point>::randomize()
 {
	 for (size_t i = 0; i < size; i++)
	 {
		 arr[i].setX((int)(480 + rand() % 90) /10);
		 arr[i].setY((int)(480 + rand() % 90) /10);
	 }
 }
 std::ostream& operator <<(std::ostream& os,  Point& obj)
 {
	 os << "X: " << obj.getX() << std::endl;
	 os << "Y: " << obj.getY() << std::endl;
	 return os;
 }
int main()
{
	srand(static_cast<int>(time(NULL)));
	std::cout << "Array of int's" << std::endl;
	DynArray<int> arr(2);
	arr.randomize();
	arr.print();
	std::cout << arr.sumElements() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Array of doubles" << std::endl;
	DynArray<float> arr1(2);
	arr1.randomize();
	arr1.print();
	std::cout << arr1.sumElements() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Array of char's" << std::endl;
	DynArray<char> arr2(2);
	arr2.randomize();
	arr2.print();
	std::cout << arr2.sumElements() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Array of Points" << std::endl;
	DynArray<Point> arr3(2);
	arr3.randomize();
	arr3.print();
	arr3.sumElements();

	return 0;
}