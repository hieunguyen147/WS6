// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include "Cargo.h"
#include <iomanip>
#include <iostream>
#pragma once

using namespace std;

namespace sdds{
	 const int MAX_NAME = 30;
	class Train{
	private:
		char t_name[MAX_NAME + 1];
		int t_id;
		Cargo* cargo;
	public:
		void initialize(const char* name, int id);
		bool isValid();
		void loadCargo(Cargo car);
		void unloadCargo();
		void display();

		bool swapCargo(Train& t);
		bool increaseCargo(double weight);
		bool decreaseCargo(double weight);
	
	};
}