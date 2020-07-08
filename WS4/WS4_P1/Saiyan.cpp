// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"
#include<string.h>
#include<iostream>
using namespace std;


namespace sdds {
	Saiyan::Saiyan()
	{
		setEmpty();
	}
	Saiyan::Saiyan(const char* name, int dob, int power, bool super)
	{
		set(name, dob, power);
	}

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		if (name == nullptr || name[0] == '\0' || (dob < 0 || dob > 2020) || power < 0)
			setEmpty();
		else
		{
			strcpy(this->m_name, name);
			this->m_dob = dob;
			this->m_power = power;
		}
	}

	void Saiyan::setEmpty()
	{
		this->m_name[0] = '\0';
		this->m_dob = 9999;
		this->m_power = -1;
	}

	bool Saiyan::isValid() const
	{
		if ( this->m_name[0] == '\0' || this->m_dob< 0 || this->m_dob > 2020 || this->m_power < 0)
			return false;
		else return true;
	}

	void Saiyan::display() const
	{
		if (isValid()) {
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << endl;
			cout << "Power: " << this->m_power << endl;
			if(this->m_super)
				cout << "Super: " << "yes" << endl;
			else cout << "Super: " << "no" << endl;
		}
		else cout << "Invalid Saiyan!" << endl;
	}

	bool Saiyan::fight(const Saiyan& other)
	{
		bool value = false;
		if (isValid()) {
			if (this->m_power < other.m_power)
				value = false;
			else value = true;
		}
		return value;
	}

}