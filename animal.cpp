#include <iostream>
#include <string>

class Animal {
private:
	int age;
	int weight;
public:
	int* ptr;
public:
	Animal(int weight) :age(0), weight(weight), ptr(nullptr)
	{
		std::cout << "Call parametrized constructor " << std::endl;
	}
	~Animal()
	
	{
		std::cout << "Call destructor " << std::endl;
		
	}
	Animal(Animal&& obj)
	{
		if(this!=&obj)
		this->age = obj.age;
		this->weight = obj.weight;
		this->ptr = obj.ptr;
		obj.age = 0;
		obj.weight = 0;
		obj.ptr = nullptr;
		std::cout << "Call move constructor " << std::endl;
	}
	Animal& operator = (Animal&& obj)
	{
		if (this != &obj)
		{
			this->age = obj.age;
			this->weight = obj.weight;
			delete this->ptr;
			this->ptr = obj.ptr;
			obj.age = 0;
			obj.weight = 0;
			obj.ptr = nullptr;
		}
		std::cout << "Call move assignment operator " << std::endl;

		return *this;
	}
};

int main(int argc, char** argv)
{
	Animal obj1(25);
	Animal obj2(std::move(obj1));
	Animal obj3(30);
	Animal obj4(15);
	obj3 = std::move(obj4);

	return 0;
}