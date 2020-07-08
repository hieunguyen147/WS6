// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"Train.h"

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
			this->cargo = nullptr;
		}
	}

	bool Train::isValid() {
		bool value;
		if (t_id <= 0) value = false;
		else if (t_id > 0) value = true;
		return value;
	}

	void Train::loadCargo(Cargo car) {
		if (this->cargo != nullptr) {
			unloadCargo();
		}
		this->cargo = new Cargo;
		this->cargo->setDesc(car.getDesc());
		this->cargo->setWeight(car.getWeight());
	}

	void Train::unloadCargo() {
		if (this->cargo) {
			delete cargo;
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
			cout << "    Name: " << t_name << endl;
			cout << "      ID: " << t_id << endl;
			if (cargo == nullptr)
			{
				cout << "No cargo on this train." << endl;
			}
			else
			{
				cout << "   Cargo: " << cargo->getDesc() << endl;
				cout << "  Weight: " << fixed << setprecision(2) << this->cargo->getWeight() << endl;
				cout.unsetf(ios::fixed);
				cout.precision(6);
			}
		}
	}

	bool Train::swapCargo(Train& t){
		bool result = false;
		if (t.cargo && this->cargo) {
			char temp_1[MAX_DESC], temp_2[MAX_DESC];
			double temp_3, temp_4;

			strcpy(temp_1, t.cargo->getDesc());			// get t2 set to temp
			temp_3 = t.cargo->getWeight();



			strcpy(temp_2, this->cargo->getDesc());		// get t1 set to temp
			temp_4 = this->cargo->getWeight();			

			
			this->cargo->setDesc(temp_1);				// temp set to t1
			this->cargo->setWeight(temp_3);

			t.cargo->setDesc(temp_2);					// temp set to t2
			t.cargo->setWeight(temp_4);

			result = true;
		}
			return result;	
	}

	bool Train::increaseCargo(double weight)
	{
		if ((this->isValid() && this->cargo != nullptr) || (this->cargo->getWeight() < MAX_WEIGHT)) {
			bool result = false;
			double oldWeight;
			oldWeight = this->cargo->getWeight();
			double newWeight;
			newWeight = oldWeight + weight;

			if (this->isValid() && this->cargo != nullptr && (this->cargo->getWeight() < MAX_WEIGHT))
			{
				if (newWeight < MAX_WEIGHT)
					this->cargo->setWeight(newWeight);
				else this->cargo->setWeight(MAX_WEIGHT);
				result = true;
			}
			return result;
		}
		else return false;
	}

	bool Train::decreaseCargo(double weight)
	{
		bool result = false;
		if ((this->isValid() && this->cargo != nullptr) && (this->cargo->getWeight() > MIN_WEIGHT))
		{
			double oldWeight;
			oldWeight = this->cargo->getWeight();
			double newWeight;
			newWeight = oldWeight - weight;

			if (newWeight > MIN_WEIGHT)
				this->cargo->setWeight(newWeight);
			else this->cargo->setWeight(MIN_WEIGHT);
			result = true;
		}
		return result;
	}
}