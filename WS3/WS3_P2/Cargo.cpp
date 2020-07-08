// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Cargo.h"

namespace sdds {

	void Cargo::initialize(const char* desc, double wei)
	{
		if (desc == nullptr || desc[0] == '\0')
		{
			this->description[0] = '\0';
			this->weight = 0;

		}
		else {
			this->setDesc(desc);
			this->setWeight(wei);
		}
	}

	void Cargo::setDesc(const char* desc)
	{
		strncpy(this->description, desc, MAX_DESC);
	}


	void Cargo::setWeight(double wei)
	{
		if (wei < MIN_WEIGHT || wei > MAX_WEIGHT)
			this->weight = MIN_WEIGHT;
		else this->weight = wei;
	}


	const char* Cargo::getDesc() const
	{
		return this->description;
	}


	double Cargo::getWeight() const
	{

		return this->weight;
	}
}