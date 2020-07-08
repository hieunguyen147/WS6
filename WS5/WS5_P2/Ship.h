// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SHIP_H
#define SHIP_H
#include"Engine.h"
#include <iomanip>
namespace sdds {
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;
	const int NUM_OF_ENGINES = 10;

	class Ship {
	private:
		Engine* m_engines;
		int m_engCnt;
		char* m_type;
	public:
		Ship();
		Ship(const char* type, Engine* engine, int size);
		void setShip(const char* type, Engine* engine, int size);
		void setEmpty();
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		double calculatePower() const;
		~Ship();
	};
	bool operator<(double power, const Ship& theShip);
}
#endif // !SHIP_H

