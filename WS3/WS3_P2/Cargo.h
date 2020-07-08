// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#pragma once

namespace sdds {
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;

	class Cargo
	{
	public:
		void initialize(const char* desc, double wei);
		void setDesc(const char* desc);
		const char* getDesc() const;
		void setWeight(double wei);
		double getWeight() const;
	
	private:
		char description[MAX_DESC + 1];
		double weight;
	};
}