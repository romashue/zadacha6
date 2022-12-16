#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct T
{
	int a;
	double b;
	string c;
	T(int a, double b, string&& c)
		: a(a)
		, b(b)
		, c(std::move(c))
	{}
};

vector<T> V;


int main() 
{
	setlocale(LC_ALL, "ru");

	vector<int> myVector;
	myVector.push_back(2);//добавляет элемент справа
	myVector.push_back(44);
	myVector.push_back(77);
	myVector.push_back(10);
	myVector.push_back(925);

	cout << "Наш вектор, образованный push_back(ами)" << endl;

	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	vector<int>::iterator it = myVector.begin();

	cout << "Применили erase()" << endl;

	myVector.erase(it + 2);//убирает элемент под индексом 2

	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	cout << "Применили insert()" << endl;

	myVector.insert(it+1,999);//добавляет элемент под индексом 1

	
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	V.emplace_back(42, 3.14, "foo"); //конструирует элемент прямо на месте, где его и предполагалось разместить
	//При этом не вызывается ни копирующий конструктор, ни перемещающий, в отличии от push_back.
	
	cout << endl << endl;

	cout << "количество элементов в векторе = " << myVector.size() << endl;
	cout << "capacity вектора = " << myVector.capacity() << endl; //capacity показывает,
	//сколько зарезервированно ячеек под вектор


	myVector.shrink_to_fit();//уменьшает количество ячеек под вектор до размера вектора
	cout << "shrink_to_fit()" << endl;
	cout << "количество элементов в векторе = " << myVector.size() << endl;
	cout << "capacity вектора = " << myVector.capacity() << endl;

	myVector.resize(20,448);//изменяет размер вектора и соответсвенно количество ячеек под вектор
	//и заполняет вектор параметром, указанным 2 после запятой
	cout << "resize(100,448)" << endl;
	cout << "количество элементов в векторе = " << myVector.size() << endl;
	cout << "capacity вектора = " << myVector.capacity() << endl;
	cout << "как выглядит вектор после resize(20,448)" << endl;
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << " ";
	}

	myVector.clear();//опустошает вектор

	//ничего не выведет, так как элементов в векторе нет
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	cout << endl << endl;

	vector<int> myvector1{ 1, 2, 3 };
	vector<int> myvector2{ 3, 2, 1, 4 };
	myvector1 = myvector2;
	cout << "myvector1 = ";
	for (auto it = myvector1.begin(); it != myvector1.end(); ++it)
		cout << ' ' << *it;

	cout << endl;

	cout << "Второй элемент myvector1 = " << myvector1[1] << endl;

	cout << endl;

	return 0;
}