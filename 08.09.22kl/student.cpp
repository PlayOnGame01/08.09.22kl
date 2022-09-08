#include<iostream>
using namespace std;

//class Car
//{
//	char* model;
//	char* country;
//	double price;
//	static int count;
//public:
//	Car();
//	Car(const char* m, const char* c, double p);
//	~Car();
//	void Input();
//	void Print();
//	const char* GetModel();
//	void SetModel(const char* m)
//
//		///  static method
//		static int GetCount();
//		static void SetCount(const char* n);
//		static const char* GetCount();
//		static void DelCount();
//
//};
//
//char* Car::Count = nullptr;
//Car::Car()
//{
//	country = nullptr;
//	price = 0;
//}
//
//Car::Car(const char* m,const char* c, double p)
//{
//	country = new char[strlen(c) + 1];
//	strcpy_s(country, strlen(c) + 1, c);
//	price = p;
//}
//
//
//int main()
//{
//	int count;
//	cin >> count;
//	Car* shop = new Car[count];
//	// ввод, вывод, вывод кол-во автомобилей!
//
//}


class Car
{
	char* model;
	int price;
	static char* GroupModel;
	int coll_car;
public:
	Car();
	Car(const char* m, int p, int coll);
	~Car();
	void Input();
	void Print();
	///----------------------
	static void SetGroupModel(const char* m);
	static const char* GetGroupModel();
	static void DelGroupModel();
};
char* Car::GroupModel = nullptr;
Car::Car()
{
	model = nullptr;
	price = 0;
	coll_car = 0;
}
Car::Car(const char* m, int p, int coll)
{
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
	price = p;
	coll_car = coll;
}

Car::~Car()
{
	delete[] model;
}

void Car::Input()
{
	char buff[20];
	cout << "Enter model -> ";
	cin.getline(buff, 20);
	if (model != nullptr)
	{
		delete[]model;
	}
	model = new char[strlen(buff) + 1];
	strcpy_s(model, strlen(buff) + 1, buff);
	cout << "Enter price-> ";
	cin >> price;
	cin.ignore();

}

void Car::Print()
{
	cout << "Model: " << model << "\t Price: " << price << endl;
	cout << "Coll_car: " << coll_car << "\t Price: " << price << endl;
}

void Car::SetGroupModel(const char* n) // static
{
	if (GroupModel != nullptr)
	{
		delete[] GroupModel;
	}
	GroupModel = new char[strlen(n) + 1];
	strcpy_s(GroupModel, strlen(n) + 1, n);
}

const char* Car::GetGroupModel() // static
{
	return GroupModel;
}

void Car::DelGroupModel() // static
{
	delete[] GroupModel;
}

int main()
{
	Car::SetGroupModel("Infernus");
	cout << Car::GetGroupModel() << endl;

	Car group[3]{};
	for (int i = 0; i < 3; i++)
	{
		group[i].Input();
	}
	for (int i = 0; i < 3; i++)
	{
		group[i].Print();
	}
	
	//////////////

	int count;
	cout << "Enter count -> ";
	cin >> count;	
	int mod;
	cout << "Enter count model -> ";
	cin >> mod;

	Car* Group = new Car[count];
	Car* Versian = new Car[mod];

	for (int i = 0; i < count; i++)
	{
		Group[i].Input();
	}
	for (int i = 0; i < count; i++)
	{
		Group[i].Print();
	}

	delete[]Group;
	for (int i = 0; i < mod; i++)
	{
		Versian[i].Input();
	}	
	for (int i = 0; i < mod; i++)
	{
		Versian[i].Print();
	}
	delete[]Versian;

	Car::DelGroupModel();
}

