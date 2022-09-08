#include<iostream>
using namespace std;

// Статические члены класса (поля и методы). Проблема -> решение
class Point
{
	int x;
	int y;
	static int count;
public:
	Point();
	Point(int, int);
	void Print();
	Point& GetObj(int, int);
	~Point()
	{
		count--;
	}
	static int GetCount()  // static метод класса, для работы со static полем класса
	{
		return count;
	}
};
int Point::count = 0;   // тип статич._переменной имя_класса::имя_переменной = значение;

Point::Point()
{
	x = y = 0;
	count++;
}
Point::Point(int a, int b)
{
	x = a;
	y = b;
	count++;
}
void Point::Print()
{
	cout << this->x << "\t" << this->y << endl;
}
Point& Point::GetObj(int a, int b)
{
	x += a;
	y += b;
	return *this;
}
int main()
{

	cout << Point::GetCount() << endl;

	Point a(5, 10);
	a.Print();
	cout << a.GetCount() << endl;
	// Point b(1, 3);





}