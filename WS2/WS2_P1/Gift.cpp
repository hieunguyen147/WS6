#include"Gift.h"
#include <iostream>
namespace sdds {

	using namespace std;
	using namespace sdds;

	void gifting(char* descr) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> descr;
	}
	void gifting(double& price) {
		cout << "Enter gift price: ";
		price = getMinMax(0.0,MAX_PRICE);
	}
	void gifting(int& units) {
		cout << "Enter gift units: ";
		int flag = 0;
		do {
			cin >> units;
			if (units <= 0) {
				cin.ignore(2000, '\n');
				cout << "Gift units must be at least 1" << endl;
				cout << "Enter gift units: ";
				flag = 1;
			}
			else break;
				
		} while (flag);
	}
	
	void display(const Gift& gift) {
		cout << " Description: " << gift.m_description << endl;
		cout << "       Price: " << gift.m_price << endl;
		cout << "       Units: " << gift.m_units << "\n" << endl;
	}


	double getMinMax(double min, double max) //Check value Min max
	{
		int done;
		double value;
		do
		{
			cin >> value;
			if (value < min || value > max)
			{
				done = 1;
				cout << "Gift price must be between " << min << " and " << max << endl;
				cout << "Enter gift price: ";
			}
			else
				done = 0;

		} while (done);
		return value;
	}
}