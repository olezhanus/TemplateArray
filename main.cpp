#include <iostream>
#include <ctime>
#include "Array.h"
#include "Vector3d.h"


using namespace std;

template<typename T>
void PrintArr(const Array<T> &);


int main()
{
	srand(time(0));
	cout << "////Testing Array<int>:////\n\n";
	{
		Array<int> a1(10, 1), a2;
		a2 = a1;
		for (size_t i = 0; i < a1.size(); ++i)
		{
			a1[i] = rand() % 5;
		}
		cout << "a1:\t"; PrintArr(a1);
		cout << "a2:\t"; PrintArr(a2);

		cout << "a1.find(3):\t" << a1.find(3) << '\n';

		a2.push_front(8);
		cout << "a2.push_front(8):\t"; PrintArr(a2);

		a2.push_back(8);
		cout << "a2.push_back(8):\t"; PrintArr(a2);

		a2.pop_back();
		cout << "a2.pop_back():\t\t"; PrintArr(a2);

		a2.pop_front();
		cout << "a2.pop_front():\t\t"; PrintArr(a2);

		a2.resize(15);
		cout << "a2.resize(15):\t\t"; PrintArr(a2);

		a2.resize(7);
		cout << "a2.resize(7):\t\t"; PrintArr(a2);

		a2.insert(3, a1);
		cout << "a2.insert(3, a1):\t"; PrintArr(a2);

		a2.insert(1, 30);
		cout << "a2.insert(1, 30):\t"; PrintArr(a2);

		a2.insert(16, 20, 0);
		cout << "a2.insert(16, 20, 0):\t"; PrintArr(a2);

		a2.erase(0);
		cout << "a2.erase(0):\t\t"; PrintArr(a2);

		a2.erase(1, 14);
		cout << "a2.erase(1, 14):\t"; PrintArr(a2);

		cout << "a2.empty():\t" << a2.empty() << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		a2.clear();
		cout << "a2.clear()" << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		cout << "a2.empty():\t" << a2.empty() << '\n';
	}






	cout << "\n\n////Testing Array<double>:////\n\n";
	{
		Array<double> a1(10, 1), a2;
		a2 = a1;
		for (size_t i = 0; i < a1.size(); ++i)
		{
			a1[i] = rand() / 100.;
		}
		cout << "a1:\t"; PrintArr(a1);
		cout << "a2:\t"; PrintArr(a2);

		cout << "a1.find([](const double &el)->bool { return (el > 50 && el < 100); }):\t" <<
			a1.find([](const double &el)->bool
					{
						return (el > 50 && el < 100);
					}) << '\n';

		a2.push_front(7.5);
		cout << "a2.push_front(7.5):\t"; PrintArr(a2);

		a2.push_back(7.5);
		cout << "a2.push_back(7.5):\t"; PrintArr(a2);

		a2.pop_back();
		cout << "a2.pop_back():\t\t"; PrintArr(a2);

		a2.pop_front();
		cout << "a2.pop_front():\t\t"; PrintArr(a2);

		a2.resize(15);
		cout << "a2.resize(15):\t\t"; PrintArr(a2);

		a2.resize(7);
		cout << "a2.resize(7):\t\t"; PrintArr(a2);

		a2.insert(3, a1);
		cout << "a2.insert(3, a1):\t"; PrintArr(a2);

		a2.insert(1, 30);
		cout << "a2.insert(1, 30):\t"; PrintArr(a2);

		a2.insert(16, 20, 0);
		cout << "a2.insert(16, 20, 0):\t"; PrintArr(a2);

		a2.erase(0);
		cout << "a2.erase(0):\t\t"; PrintArr(a2);

		a2.erase(1, 14);
		cout << "a2.erase(1, 14):\t"; PrintArr(a2);

		cout << "a2.empty():\t" << a2.empty() << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		a2.clear();
		cout << "a2.clear()" << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		cout << "a2.empty():\t" << a2.empty() << '\n';
	}






	cout << "\n\n////Testing Array<Vector3d>:////\n\n";
	{
		Array<Vector3d> a1(10, 1), a2;
		a2 = a1;
		for (size_t i = 0; i < a1.size(); ++i)
		{
			a1[i] = { rand() % 10, rand() % 10, rand() % 10 };
		}
		cout << "a1:\t"; PrintArr(a1);
		cout << "a2:\t"; PrintArr(a2);

		cout << "a1.find([](const Vector3d &el)->bool { return (el.X == 5 || el.Y == 5 || el.Z == 5); }):\t" <<
			a1.find([](const Vector3d &el)->bool
					{
						return (el.X == 5 || el.Y == 5 || el.Z == 5);
					}) << '\n';

		a2.push_front({ 7,7,7 });
		cout << "a2.push_front({ 7,7,7 }):\t"; PrintArr(a2);

		a2.push_back({ 7,7,7 });
		cout << "a2.push_back({ 7,7,7 }):\t"; PrintArr(a2);

		a2.pop_back();
		cout << "a2.pop_back():\t\t"; PrintArr(a2);

		a2.pop_front();
		cout << "a2.pop_front():\t\t"; PrintArr(a2);

		a2.resize(15);
		cout << "a2.resize(15):\t\t"; PrintArr(a2);

		a2.resize(7);
		cout << "a2.resize(7):\t\t"; PrintArr(a2);

		a2.insert(3, a1);
		cout << "a2.insert(3, a1):\t"; PrintArr(a2);

		a2.insert(1, { 1,2,3 });
		cout << "a2.insert(1, { 1,2,3 }):\t"; PrintArr(a2);

		a2.insert(16, 20, { 16,32,64 });
		cout << "a2.insert(16, 20, { 16,32,64 }):\t"; PrintArr(a2);

		a2.erase(0);
		cout << "a2.erase(0):\t\t"; PrintArr(a2);

		a2.erase(1, 14);
		cout << "a2.erase(1, 14):\t"; PrintArr(a2);

		cout << "a2.empty():\t" << a2.empty() << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		a2.clear();
		cout << "a2.clear()" << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		cout << "a2.empty():\t" << a2.empty() << '\n';
	}

	return 0;
}



template<typename T>
void PrintArr(const Array<T> &arr)
{
	if (arr.empty())
	{
		cout << "Array is empty";
	}
	else
	{
		for (size_t i = 0; i < arr.size(); ++i)
		{
			cout << arr[i] << ' ';
		}
	}
	cout << '\n';
}