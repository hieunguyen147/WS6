#ifndef GIFT_H
#define GIFT_H

namespace sdds {

	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	
	struct Gift {
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
	};
	void gifting(char* descr);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& gift);
	double getMinMax(double min, double max);
}
#endif