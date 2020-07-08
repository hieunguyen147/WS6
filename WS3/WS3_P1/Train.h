// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I did this workshop by myself

#pragma once
#include "Cargo.h"
using namespace std;
#define MAX_NAME 30
namespace sdds{
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
	};
}