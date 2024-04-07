// Laba6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Я очень новичок в мире обработки ошибок 
//Корабль(Название, Материал, Вместимость, Стоимость и т.п.)  
//Возможные операции для перегрузки : сравнение(Материал, Стоимость), +(увеличение Стоимости)

#include <fstream>
#include "windows.h"
#include "Ship.cpp"


using namespace std;




// Ввод 
void InputShipOnBase(istream& istr,Ship* MasShip, unsigned int* CountShip)
{
	for (int i = 0; i < *CountShip; i++)
	{
		try
		{			
			string Name;
			string Material;
			unsigned int Capacity;
			unsigned int Price;
			istr.get();
			getline(istr, Name);
			getline(istr, Material);
			istr >> Capacity;
			 istr.get();
			istr >> Price;
			MasShip[i] = Ship(Name, Material, Capacity, Price);
		}
		catch (std::ios_base::failure e)
		{
			cout << "Данные введены не корректно";
		}
		
	}
}
// сортировка

void sort(Ship* MasShip, unsigned int* CountShip)
{
	Ship temp; // временная переменная для обмена элементов местами

	// Сортировка массива пузырьком
	for (unsigned int i = 0; i < *CountShip - 1; i++) {
		for (unsigned int j = 0; j < *CountShip - i - 1; j++) {
			if (MasShip[j] > MasShip[j + 1]) {
				// меняем элементы местами
				temp = MasShip[j];
				MasShip[j] = MasShip[j + 1];
				MasShip[j + 1] = temp;
			}
		}
	}
}
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	
	unsigned int CountShip = 0;
	int Case;
	cout << "Введите кол-во кораблей которые вы хотите добавить" << endl;
	cin >> CountShip;
	Ship* MasShip = new Ship[CountShip];
	ifstream fin;
	cout << "Выберите способ ввода:" << endl
		<< "1 - с клавиатуры" << endl
		<< "2 - из файла" << endl;
	cin >> Case;
	switch (Case)
	{
	case 1:
		system("cls");
		cout << "Введите в последующих строках:" << endl
			<< "Название корабля" << endl
			<< "Материал из которого сделан корабль" << endl
			<< "Вместимость корабля" << endl
			<< "Цена корабля" << endl;
		
	
		InputShipOnBase(cin,MasShip, &CountShip);
		break;
	case 2:
		try
		{
			fin.open("input.txt");
			fin.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
		}
		catch (const ifstream::failure& e)
		{
			cout << "Exception opening/reading file";
			return 0;
		}	
			InputShipOnBase(fin, MasShip, &CountShip);
		fin.close();
		break;
	default:
		cout << "Введено не верное число.";
		break;

	}

	
	for (int i = 0; i < CountShip; i++)
	{
		cout << MasShip[i] << endl;
}	
	sort(MasShip, &CountShip);
	ofstream fout;
	fout.open("output.txt");

	for (int i = 0; i < CountShip; i++)
	{
		fout << MasShip[i] << endl;
	}
	fout.close();
	return 0;
}


