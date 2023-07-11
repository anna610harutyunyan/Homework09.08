#include <iostream>
class Matrix
{
	int m_columns;
	int m_rows;
	int** array=nullptr;
public:
	Matrix(int columns, int rows) :m_columns(columns), m_rows(rows)
	{
		array = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			array[i] = new int[columns];
		}
		std::cout << "Call parametrized constructor " << std::endl;
	}
	Matrix(Matrix&& obj)
	{
		this->m_columns = obj.m_columns;
		this->m_rows = obj.m_rows;
		this->array = obj.array;
		obj.m_columns = 0;
		obj.m_rows = 0;
		obj.array = nullptr;
		std::cout << "Call move constructor " << std::endl;

	}
	Matrix& operator =(Matrix&& obj)
	{
		if (this->array != obj.array)
		{
			for (int i = 0; i < m_rows; ++i)
			{
				delete[] array[i];
			}
			delete[] this-> array;
			this->m_columns = obj.m_columns;
			this->m_rows = obj.m_rows;
			this->array = obj.array;
			obj.m_columns = 0;
			obj.m_rows = 0;
			obj.array = nullptr;
			std::cout << "Call move operator assignment " << std::endl;

			return *this;
		}
		std::cout << "Call move operator assignment " << std::endl;
		return *this;
	}
	~Matrix()
	{
		std::cout << "Call destructor " << std::endl;
		for (int i = 0; i < m_rows; ++i)
		{
			delete [] array[i];
		}
		delete[] array;
		array = nullptr;

	}

};

int main(int argc, char** argv)
{
	Matrix obj1(4,5);
	Matrix obj2(std::move(obj1));
	Matrix obj3(6, 7);
	Matrix obj4(5,3);
	obj3 = std::move(obj4);

	return 0;
}