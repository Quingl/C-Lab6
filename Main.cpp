// Laba6.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//�������(��������, ��������, �����������, ��������� � �.�.)  
//��������� �������� ��� ���������� : ���������(��������, ���������), +(���������� ���������)

#include <fstream>
#include <string>
#include <iostream>
#include "windows.h"
#include "Ship.h"

// ���� 
void InputShipOnBase(std::istream& istr, Ship* MasShip, unsigned int* CountShip)
{
	for (int i = 0; i < *CountShip; i++)
	{
		try
		{
			std::string Name;
			std::string Material;
			unsigned int Capacity;
			unsigned int Price;
			getline(istr, Name);
			getline(istr, Material);
			istr >> Capacity;
			istr.get();
			istr >> Price;
			istr.get();
			MasShip[i] = Ship(Name, Material, Capacity, Price);
		}
		catch (std::ios_base::failure e)
		{
			std::cout << "������ ������� �� ���������";
		}

	}
}
// ����������

void sort(Ship* MasShip, unsigned int* CountShip)
{
	Ship temp; // ��������� ���������� ��� ������ ��������� �������

	// ���������� ������� ���������
	for (unsigned int i = 0; i < *CountShip - 1; i++) {
		for (unsigned int j = 0; j < *CountShip - i - 1; j++) {
			if (MasShip[j] > MasShip[j + 1]) {
				// ������ �������� �������
				temp = MasShip[j];
				MasShip[j] = MasShip[j + 1];
				MasShip[j + 1] = temp;
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int CountShip = 0;
	int Case;
	std::string filename;
	std::cout << "������� ���-�� �������� ������� �� ������ ��������" << std::endl;
	std::cin >> CountShip;
	Ship* MasShip = new Ship[CountShip];
	std::ifstream fin;
	std::cout << "�������� ������ �����:" << std::endl
		<< "1 - � ����������" << std::endl
		<< "2 - �� �����" << std::endl;
	std::cin >> Case;
	switch (Case)
	{
	case 1:
		system("cls");
		std::cout << "������� � ����������� �������:" << std::endl
			<< "�������� �������" << std::endl
			<< "�������� �� �������� ������ �������" << std::endl
			<< "����������� �������" << std::endl
			<< "���� �������" << std::endl;


		InputShipOnBase(std::cin, MasShip, &CountShip);
		break;
	case 2:
	{
		std::cout << "������� ��� �����:" << std::endl;
		std::cin >> filename;
	}
		try
		{
			fin.open(filename);
			fin.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);
		}
		
		catch (const std::ifstream::failure& e)
		{
			std::cout << "Exception opening/reading file";
			return 0;
		}
		InputShipOnBase(fin, MasShip, &CountShip);
		fin.close();
		break;
	default:
		std::cout << "������� �� ������ �����.";
		break;

	}

	std::cout << "********* ����� �� ���������������� �������" << std::endl;
	for (int i = 0; i < CountShip; i++)
	{
		std::cout << MasShip[i] << std::endl;
	}
	std::cout << "********* ����� �� ���������������� ������� ��������" << std::endl;
	
	
	std::cout << "********* �������� �������������� ��������� �����" << std::endl;
	std::cout << MasShip[0] << std::endl;
	std::cout << "********* ������� ����� ������� ����� ��������� � ����" << std::endl;
	unsigned int addprice = 0;
	std::cin >> addprice;
	MasShip[0] = MasShip[0] + addprice;
	std::cout << "********* ������� � ����� ������" << std::endl;
	std::cout << MasShip[0] << std::endl;


	sort(MasShip, &CountShip);
	std::ofstream fout;
	fout.open("output.txt");

	for (int i = 0; i < CountShip; i++)
	{
		fout << MasShip[i] << std::endl;
	}
	fout.close();
	return 0;
}


