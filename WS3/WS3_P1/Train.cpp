// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I did this workshop by myself


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Train.h"
#include"Cargo.h"
#include<cstring>
using namespace std;

namespace sdds {
	void Train::initialize(const char* name, int id) {
		if (name == nullptr || name[0] == '\0' || id <= 0) {
			this->t_id = -1; 
			t_name[0] = '\0';
			this->cargo = nullptr;
		}
		else 
		{
				strncpy(this->t_name, name, MAX_NAME + 1);
				this->t_id = id;
		}
	}

	bool Train::isValid(){
		bool value;
		if (t_id <= 0) value = false;
		else if (t_id > 0) value = true;
		return value;
	}

	void Train::loadCargo(Cargo car){
		if (this->cargo == nullptr) {

			this->cargo = new Cargo[30];
			strncpy(cargo->description, car.description, MAX_NAME + 1);
			this->cargo->weight = car.weight;
		}
	}

	void Train::unloadCargo() {
		if (this->t_name != nullptr && this->t_id > 0 && this->cargo != nullptr) {
			delete[] cargo;
			cargo = nullptr;
		}
	}

	void Train::display() {
		cout << "***Train Summary***" << endl;
		if (t_name == nullptr || t_name[0] == '\0' || t_id <= 0)
		{
			cout << "This is an invalid train." << endl;
		}
		else
		{
			cout << "Name: " << t_name << endl;
			cout << "ID: " << t_id << endl;
			if (cargo == nullptr)
			{
				cout << "No cargo on this train." << endl;
			}
			else
			{
				cout << "Cargo: " << cargo->description << endl;
				cout << "Weight: " << cargo->weight << endl;
			}
		}
	}
}

