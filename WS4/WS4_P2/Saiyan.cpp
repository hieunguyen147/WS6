// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"
#include<string.h>
#include<iostream>
using namespace std;
#define MAN_NAME 32

namespace sdds {
	Saiyan::Saiyan()
	{
		setEmpty();
	}
	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		this->m_name = nullptr;
		set(name, dob, power);
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if (this->m_name != nullptr) {
			delete[] this->m_name;
			this->m_name = nullptr;
		}

		if (name == nullptr || name[0] == '\0' || (dob < 0 || dob > 2020) || power < 0)
			setEmpty();
		else
		{

			this->m_name = new char[strlen(name) + 1];
			strncpy(this->m_name, name, strlen(name) + 1);
			this->m_dob = dob;
			this->m_power = power;
			this->m_super = super;
			this->m_level = level;
		}
	}

	void Saiyan::setEmpty()
	{
		this->m_name = nullptr;
		this->m_dob = 9999;
		this->m_power = -1;
		this->m_super = false;
		this->m_level = -1;
	}

	bool Saiyan::isValid() const
	{
		if (this->m_name == nullptr)
			return false;
		else return true;
	}

	void Saiyan::display() const
	{
		if (isValid()) {
			bool pow = false;
			cout << this->m_name << endl;
			cout << "     DOB: " << this->m_dob << endl;
			cout << "   Power: " << this->m_power << endl;
			if (this->m_super) {
				cout << "   Super: " << "yes" << endl;
				pow = true;
			}
			else cout << "   Super: " << "no" << endl;
			if (pow == true) {
				cout << "   Level: " << this->m_level << endl;
			}
		}
		else cout << "Invalid Saiyan!" << endl;
	}

	bool Saiyan::fight(Saiyan& other)
	{
		bool value = false;
		if (isValid()) {
			if (this->m_power)
				this->powUp();
			if (other.m_power)
				other.powUp();
			if (this->m_power < other.m_power)
				value = false;
			else value = true;
		}
		return value;
	}

	void Saiyan::powUp()
	{
		this->m_power += 0.1 * this->m_level * this->m_power;
	}

	Saiyan::~Saiyan() {
		if (this->m_name != nullptr)
		{
			delete[] this->m_name;
			this->m_name = nullptr;
		}
	}

}
