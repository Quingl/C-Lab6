#include "Ship.h"
#include <iostream>
	// ������������ 
Ship::Ship() {}
	Ship::Ship(/*unsigned int* ID, */std::string Name, std::string Material, unsigned int Capacity, unsigned int Price)
	{
		m_Name = Name;
		m_Material = Material;
		m_Capacity = Capacity;
		m_Price = Price;
	}

	Ship::Ship(const Ship& ship) :m_Name(ship.m_Name), m_Material(ship.m_Material), m_Capacity(ship.m_Capacity), m_Price(ship.m_Price)
	{
	}

	Ship::~Ship() {}

// ��������� ����� �������� ���� ��� � ������ ����� b ����� ����� � ����� ����� ��� b � ��������
bool Ship::operator== (const Ship& s2)const noexcept
{
	return this->m_Name == s2.m_Name;
}
bool Ship::operator!= (const Ship& s2)const noexcept
{
	return !(this->m_Name == s2.m_Name);
}

bool Ship::operator> (const Ship& s2)const noexcept
{
	return this->m_Name > s2.m_Name;
}
bool Ship::operator>= (const Ship& s2)const noexcept
{
	return this->m_Name >= s2.m_Name;
}


bool Ship::operator< (const Ship& s2)const noexcept
{
	return this->m_Name < s2.m_Name;
}

bool Ship::operator<= (const Ship& s2)const noexcept
{
	return this->m_Name <= s2.m_Name;
}
// ����������� � ���� 



Ship Ship::operator+(int price)const noexcept
{

	return Ship(m_Name,m_Material,m_Capacity, m_Price + price);
}
// ���������� ������
std::ostream& operator<< (std::ostream& out, const Ship& s)
{
	
	out <<s.m_Name << std::endl << s.m_Material << std::endl << s.m_Capacity << std::endl << s.m_Price;

	return out;
}

