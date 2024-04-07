#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Ship
{
private:
	/*unsigned int* m_ID;*/
	string m_Name;
	string m_Material;
	unsigned int m_Capacity = 0;
	unsigned int m_Price = 0;

public:
	// конструкторы 
	Ship() {}
	Ship(/*unsigned int* ID, */string Name, string Material, unsigned int Capacity, unsigned int Price)
	{
	
	}

	Ship(const Ship& ship)
	{

	}

	// деструктор
	~Ship()
	{
	}


	// set get
	/*unsigned int* getID() { return m_ID; }
	void setID(unsigned int* ID) { m_ID = ID; }*/

	string getName() { return m_Name; }
	void setName(string Name) { m_Name = Name; }

	string getMaterial() { return m_Material; }
	void setMaterial(string Material) { m_Material = Material; }

	unsigned int getCapacity() { return m_Capacity; }
	void setCapacity(unsigned int Capacity) { m_Capacity = Capacity; }

	unsigned int getPrice() { return m_Price; }
	void setPrice(unsigned int Price) { m_Price = Price; }
	// перегрузка сравнения по названию
	friend bool operator== (const Ship& s1, const Ship& s2);
	friend bool operator!= (const Ship& s1, const Ship& s2);

	friend bool operator> (const Ship& s1, const Ship& s2);
	friend bool operator>= (const Ship& s1, const Ship& s2);

	friend bool operator< (const Ship& s1, const Ship& s2);
	friend bool operator<= (const Ship& s1, const Ship& s2);

	// перегрузка + (прибавление к цене)
	friend Ship operator+(const Ship& s1, const unsigned int& price);

	// перегрузка оператора вывода
	friend std::ostream& operator<< (std::ostream& out, const Ship& s);






};

#endif
