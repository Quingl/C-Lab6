#pragma once
#include <string>

class Ship
{
private:
	/*unsigned int* m_ID;*/
	std::string m_Name;
	std::string m_Material;
	unsigned int m_Capacity = 0;
	unsigned int m_Price = 0;

public:
	// конструкторы 
	Ship();
	Ship(/*unsigned int* ID, */std::string Name, std::string Material, unsigned int Capacity, unsigned int Price);

	Ship(const Ship& ship);

	// деструктор
	~Ship();


	// set get
	/*unsigned int* getID() { return m_ID; }
	void setID(unsigned int* ID) { m_ID = ID; }*/

	std::string getName() { return m_Name; }
	void setName(std::string Name) { m_Name = Name; }

	std::string getMaterial() { return m_Material; }
	void setMaterial(std::string Material) { m_Material = Material; }

	unsigned int getCapacity() { return m_Capacity; }
	void setCapacity(unsigned int Capacity) { m_Capacity = Capacity; }

	unsigned int getPrice() { return m_Price; }
	void setPrice(unsigned int Price) { m_Price = Price; }
	// перегрузка сравнения по названию
	bool operator== (const Ship& s2) const noexcept;
	bool operator!= (const Ship& s2) const noexcept ;

	bool operator> (const Ship& s2) const noexcept;
	bool operator>= (const Ship& s2) const noexcept;

	bool operator< (const Ship& s2) const noexcept;
	bool operator<= (const Ship& s2) const noexcept;

	// перегрузка + (прибавление к цене)
	Ship operator+(int price) const noexcept;

	// перегрузка оператора вывода
	friend std::ostream& operator<< (std::ostream& out, const Ship& s);


};

