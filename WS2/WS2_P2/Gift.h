#ifndef GIFT_H
#define GIFT_H
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {


	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;
	
	struct Wrapping {
		char* m_pattern;
	};
	
	struct Gift {
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		Wrapping* m_wrap;
		int m_wrapLayers;
	};
	void gifting(Gift&);
	void gifting(char* descr);
	void gifting(double& price);
	void gifting(int& units);

	void display(Gift& gift);
	void oldDisplay(Gift& gift);

	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);

	int minimum();
	double getMinMax(double min, double max);
}
#endif