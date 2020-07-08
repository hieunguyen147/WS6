#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>
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
		void setEngine(const char* type, double size);
		double get() const;
		char* getType();
		void display() const;

	};
}
#endif // !ENGINE_H


