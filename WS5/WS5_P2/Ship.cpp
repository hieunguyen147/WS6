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
		this->m_type = nullptr;
		this->m_engines = nullptr;
		this->m_engCnt = 0;
	}
	Ship::Ship(const char* type, Engine* engines, int cnt)
	{
		setShip(type, engines, cnt);
	}

	void Ship::setShip(const char* type, Engine* engine, int size)
	{
		if (type == nullptr || size < 0)
		{
			setEmpty();
		}
		else
		{
			int a = strlen(type) + 1;
			this->m_type = new char[a];
			strncpy(m_type, type, a);
			this->m_engCnt = size;
			this->m_engines = new Engine[this->m_engCnt];
			for (int i = 0; i < size; i++)
			{
				this->m_engines[i] = engine[i];
			}
		}
	}

	Ship::operator bool() const
	{
		bool result = false;
		if (m_type != nullptr)
		{
			result = true;
		}
		return result;
	}

	Ship& Ship::operator+=(Engine a) {
		if (!*this)
		{
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			Engine* r = nullptr;
			r = new Engine[this->m_engCnt];
			for (int i = 0; i < this->m_engCnt; i++) {
				r[i] = this->m_engines[i];
			}
			delete[] this->m_engines;
			this->m_engines = nullptr;
			this->m_engCnt += 1;
			this->m_engines = new Engine[this->m_engCnt];
			for (int i = 0; i < m_engCnt - 1; i++) {
				this->m_engines[i] = r[i];
			}
			this->m_engines[m_engCnt - 1] = a;
			delete[] r;
			r = nullptr;
		}
		return *this;
	}


	bool Ship::operator<(double power) const
	{
		return calculatePower() < power;
	}

	double Ship::calculatePower() const
	{
		double total = 0;
		for (int i = 0; i < m_engCnt;
			i++) {
			total += this->m_engines[i].get() * 5;
		}
		return total;
	}

	Ship::~Ship()
	{
		if (this->m_type != nullptr) {
			delete[] this->m_type;
			this->m_type = nullptr;
		}
		if (this->m_engines != nullptr) {
			delete[] this->m_engines;
			this->m_engines = nullptr;
		}
	}

	void Ship::display() const
	{
		if (!*this)
		{
			cout << "No available data" << endl;
		}
		else {
			double sum = 0.0;
			sum = this->calculatePower();
			cout << fixed << setprecision(2) << this->m_type << " - " << setw(6) << right << sum << endl;

			for (int i = 0; i < m_engCnt; i++)
			{
				m_engines[i].display();
			}
			cout.unsetf(ios::fixed);
			cout.precision(5);
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