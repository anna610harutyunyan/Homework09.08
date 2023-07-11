#include <iostream>
class Array
{
	int m_size;
	int* ptr = nullptr;
public:
	Array(int size) : m_size(size)
	{
		ptr = new int[size];
		std::cout << "Call parametrized constructor " << std::endl;
	}
	Array(Array&& obj)
	{
		this->m_size = obj.m_size;
		this->ptr = obj.ptr;
		obj.m_size = 0;
		obj.ptr = nullptr;
		std::cout << "Call move constructor " << std::endl;

	}
	Array& operator =(Array&& obj)
	{
		if (this != &obj)
		{
			delete [] this->ptr;
			this->m_size = obj.m_size;
			this->ptr = obj.ptr;
			obj.m_size = 0;
			obj.ptr = nullptr;
		}
		std::cout << "Call move operator assignment " << std::endl;
		return *this;

	}
	~Array()
	{
		std::cout << "Call destructor " << std::endl;
		delete[] ptr;
		ptr = nullptr;
	}
};

int main(int argc, char** argv)
{
	Array obj1(5);
	Array obj2(std::move(obj1));
	Array obj3(10);
	Array obj4(10);
	obj3 = std::move(obj4);

	return 0;
}