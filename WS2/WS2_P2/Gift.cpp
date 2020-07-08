#include"Gift.h"
#include <iostream>
#include<string.h>
namespace sdds {

	using namespace std;
	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);
	}

	void gifting(char* descr) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> descr;
	}
	void gifting(double& price) {
		cout << "Enter gift price: ";
		price = getMinMax(0.0, MAX_PRICE);
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

	void display(Gift& gift) {
		
		if (gift.m_wrapLayers == 0) {
			cout << "Gift Details:" << endl;
			oldDisplay(gift);
			cout << "Unwrapped!" << endl;
		}
		else {
			cout << "Gift Details:" << endl;
			oldDisplay(gift);
			cout << "Wrap Layers: " << gift.m_wrapLayers << endl;
			for (int i = 0; i < gift.m_wrapLayers; i++) {
				cout << "Wrap #" << i + 1 << " -> " << gift.m_wrap[i].m_pattern << endl;
			}
		}
	}

	void oldDisplay(Gift& gift)
	{
		cout << " Description: " << gift.m_description << endl;
		cout << "       Price: " << gift.m_price << endl;
		cout << "       Units: " << gift.m_units << endl;
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
			else done = 0;
		} while (done);
		return value;
	}

	bool wrap(Gift& theGift) {
		bool check;

		if (theGift.m_wrap != NULL)
		{
			cout << "Gift is already wrapped!" << endl;;
			check = false;
		}
		else {
			int value = 0;
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			value = minimum();

			theGift.m_wrapLayers = value;
			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];

			char buffer[20];
			int LONG = 0;
			for (int i = 0; i < value; i++) {
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> buffer;
				LONG = strlen(buffer);

				theGift.m_wrap[i].m_pattern = new char[LONG + 1];
				strcpy(theGift.m_wrap[i].m_pattern, buffer);
			}
			check = true;
		}
		return check;
	}

	bool unwrap(Gift& theGift) {
		bool check;
		if (theGift.m_wrap == NULL)
		{
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			check = false;
		}
		else {
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				delete[] theGift.m_wrap[i].m_pattern;
				theGift.m_wrap[i].m_pattern = nullptr;
			}
			delete[] theGift.m_wrap;
			theGift.m_wrap = nullptr;

			cout << "Gift being unwrapped." << endl;
			check = true;
		}return check;

	}

	int minimum() {
		int done;
		int min;
		do {
			cin >> min;
			if (min < 1)
			{
				done = 1;
				cin.ignore(2000, '\n');
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
			}
			else done = 0;
		} while (done);
		return min;
	}
}