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
	myVector.push_back(2);//��������� ������� ������
	myVector.push_back(44);
	myVector.push_back(77);
	myVector.push_back(10);
	myVector.push_back(925);

	cout << "��� ������, ������������ push_back(���)" << endl;

	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	vector<int>::iterator it = myVector.begin();

	cout << "��������� erase()" << endl;

	myVector.erase(it + 2);//������� ������� ��� �������� 2

	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	cout << "��������� insert()" << endl;

	myVector.insert(it+1,999);//��������� ������� ��� �������� 1

	
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << endl;
	}

	V.emplace_back(42, 3.14, "foo"); //������������ ������� ����� �� �����, ��� ��� � �������������� ����������
	//��� ���� �� ���������� �� ���������� �����������, �� ������������, � ������� �� push_back.
	
	cout << endl << endl;

	cout << "���������� ��������� � ������� = " << myVector.size() << endl;
	cout << "capacity ������� = " << myVector.capacity() << endl; //capacity ����������,
	//������� ���������������� ����� ��� ������


	myVector.shrink_to_fit();//��������� ���������� ����� ��� ������ �� ������� �������
	cout << "shrink_to_fit()" << endl;
	cout << "���������� ��������� � ������� = " << myVector.size() << endl;
	cout << "capacity ������� = " << myVector.capacity() << endl;

	myVector.resize(20,448);//�������� ������ ������� � ������������� ���������� ����� ��� ������
	//� ��������� ������ ����������, ��������� 2 ����� �������
	cout << "resize(100,448)" << endl;
	cout << "���������� ��������� � ������� = " << myVector.size() << endl;
	cout << "capacity ������� = " << myVector.capacity() << endl;
	cout << "��� �������� ������ ����� resize(20,448)" << endl;
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << " ";
	}

	myVector.clear();//���������� ������

	//������ �� �������, ��� ��� ��������� � ������� ���
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

	cout << "������ ������� myvector1 = " << myvector1[1] << endl;

	cout << endl;

	return 0;
}