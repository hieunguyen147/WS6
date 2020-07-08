// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

namespace sdds{
	const int TYPE_MAX_SIZE = 30;
	class Engine {
	private:
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];
	public:

		Engine();
		Engine(const char* type, double size);
		void setEmpty();
		void setEngine(const char* type, double size);
		double get() const;
		char* getType();
		void display() const;

	};
}
#endif // !ENGINE_H


