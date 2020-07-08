// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include"Ship.h"
#include<iostream>
using namespace std;
namespace sdds {
	Ship::Ship()
	{
		setEmpty();
	}
	void Ship::setEmpty() {
		this->m_type[0] = '\0';
		this->m_engCnt = 0;
	}
	Ship::Ship(const char* type, Engine* engines, int cnt)
	{
		setShip(type,engines,cnt);
	}

	void Ship::setShip(const char* type, Engine* engine, int size)
	{
		if (type == nullptr || type[0] == '\0' || size < 0)
		{
			Ship();
		}
		else
		{
			strncpy(m_type, type, TYPE_MAX_SIZE);
			m_engCnt = size;
			for (int i = 0; i < size; i++)
			{
				m_engines[i].setEngine(engine[i].getType(), engine[i].get());
			}
		}
	}

	Ship::operator bool() const
	{
		bool result = false;
		if (m_type != nullptr && m_type[0] != '\0')
		{
			result = true;
		}
		return result;
	}

	Ship& Ship::operator+=(Engine r)
	{
		if (m_type != nullptr && m_type[0] != '\0' && m_engCnt < NUM_OF_ENGINES)
		{
			m_engines[m_engCnt++].setEngine(r.getType(), r.get());
		}
		else
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		return *this;
	}

	bool Ship::operator<(double power) const
	{
		double sum = calculatePower();
		bool result = (sum < power);
		return result;
	}

	double Ship::calculatePower() const
	{
		double total = 0;
		for (int i = 0; i < 10; i++) {
			total += this->m_engines[i].get() * 5;
		}
		return total;
	}

	void Ship::display() const
	{
		if (m_type == nullptr || m_type[0] == '\0')
		{
			cout << "No available data" << endl;
		}
		else
		{
			double sum = 0.0;
			sum = this->calculatePower();
			cout << m_type << " - " << sum << endl;
			for (int i = 0; i < m_engCnt; i++)
			{
				m_engines[i].display();
			}
		}
	}
bool operator<(double power, const Ship& theShip)
{
	double sum = 0.0;
	sum = theShip.calculatePower();
	bool result(power < sum);
	return result;
}

}