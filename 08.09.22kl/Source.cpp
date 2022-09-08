#include<iostream>
using namespace std;

// ����������� ����� ������ (���� � ������). �������� -> �������
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
	static int GetCount()  // static ����� ������, ��� ������ �� static ����� ������
	{
		return count;
	}
};
int Point::count = 0;   // ��� ������._���������� ���_������::���_���������� = ��������;

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