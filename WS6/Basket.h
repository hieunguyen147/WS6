// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191

#define _CRT_SECURE_NO_WARNINGS
#ifndef BASHKET_H
#define BASHKET_H
#include"Basket.h"
#include<fstream>
namespace sdds {
	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};
	class Basket {
	private:
		Fruit* m_fruits;
		int m_cnt;
		double m_price;

	public:
		Basket();
		Basket(const Basket&);
		Basket(Fruit* fruit, int cnt, double price);
		void set(Fruit* fruit, int cnt, double price);
		void emptyBasket();
		void setPrice(double price);
		bool check() const;
		explicit operator bool() const;
		Basket& operator+= (Fruit a);
		Basket& operator=(const Basket& b);
		friend std::ostream& operator<<(std::ostream& out, Basket& bk);
		~Basket();
	};
}
#endif // BASHKET_H