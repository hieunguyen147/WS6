#define _CRT_SECURE_NO_WARNINGS

#include"Basket.h"
#include<cstring>
#include <iomanip>
#include<iostream>
#include<fstream>
using namespace std;

namespace sdds {

	Basket::Basket()
	{
		emptyBasket();
	}
	Basket::operator bool() const
	{
		return (this->m_cnt > 0);
	}
	Basket::Basket(Fruit* fruits, int cnt, double price)
	{
		//	this->m_fruits = nullptr; // error
		//	set(fruits, cnt, price);
			/*if (m_cnt < 0) {
				emptyBasket();
			}*//*
			else*/
		{
			/*if (this->m_fruits != nullptr) //error
			{
				delete[] this->m_fruits;
				this->m_fruits = nullptr;
			}*/
			this->m_cnt = cnt;
			this->m_fruits = new Fruit[this->m_cnt];
			for (int i = 0; i < this->m_cnt; i++) {
				this->m_fruits[i] = fruits[i];
			}
			setPrice(price);
		}
	}
	void Basket::emptyBasket()
	{
		this->m_fruits = nullptr;
		this->m_price = 0.0;
		this->m_cnt = 0;
	}
	void Basket::setPrice(double price)
	{
		if (price > 0.00)
			this->m_price = price;
	}
	bool Basket::check() const
	{
		return (this->m_fruits && this->m_cnt > 0);
	}


	Basket& Basket::operator +=(Fruit fruit) {
		if (fruit.m_name[0] == '\0')
			cout << "The object is not valid!" << endl;
		else {
			Fruit* tmp = new Fruit[this->m_cnt];
			for (int i = 0; i < this->m_cnt; i++)
			{
				tmp[i] = this->m_fruits[i];
			}
			delete[] this->m_fruits;
			this->m_fruits = nullptr;
			this->m_cnt += 1;
			this->m_fruits = new Fruit[this->m_cnt];
			for (int i = 0; i < this->m_cnt - 1; i++)
			{
				this->m_fruits[i] = tmp[i];
			}
			this->m_fruits[this->m_cnt - 1] = fruit;
			delete[] tmp;
			tmp = nullptr;
		}
		return *this;
	}
	Basket::Basket(const Basket& fruit) {
		if (fruit.check()) {
			this->m_cnt = fruit.m_cnt;
			this->m_price = fruit.m_price;
			if (fruit.m_fruits != nullptr) {
				this->m_fruits = new Fruit[this->m_cnt];
				for (int i = 0; i < this->m_cnt; i++)
				{
					this->m_fruits[i] = fruit.m_fruits[i];
				}
			}
			else this->m_fruits = nullptr;
		}
	}
	Basket& Basket::operator=(const Basket& b)
	{
		if (this != &b) {
			this->m_cnt = b.m_cnt;
			this->m_price = b.m_price;
			delete[] this->m_fruits;
			if (b.m_fruits != nullptr) {
				this->m_fruits = new Fruit[this->m_cnt];
				for (int i = 0; i < this->m_cnt; i++) {
					this->m_fruits[i] = b.m_fruits[i];
				}
			}
			else this->m_fruits = nullptr;
		}
		return *this;
	}

	void Basket::display()const
	{
		if (!*this) {
			cout << "The basket is empty!" << endl;
		}
		else {
			cout << "Basket Content:" << endl;
			for (int i = 0; i < this->m_cnt; i++) {
				cout << fixed << setprecision(2) << setw(10) << right << m_fruits[i].m_name << ": " << m_fruits[i].m_qty << "kg" << endl;
			}
			cout << "Price: " << this->m_price << endl;
		}
	}

	ostream& operator<<(ostream& cout, Basket& basket)
	{
		//if (!basket) {
		//	cout << "The basket is empty!" << endl;
		//}
		//else{
		//	cout << "Basket Content:" << endl;
		//	for (int i = 0; i < basket.m_cnt; i++) {
		//		cout << fixed << setprecision(2) << setw(10) << right << basket.m_fruits[i].m_name << ": " << basket.m_fruits[i].m_qty << "kg" << endl;
		//	}
		//	cout << "Price: " << basket.m_price << endl;}
		
		basket.display();
		return cout;
	}

	Basket::~Basket()
	{
			delete[] this->m_fruits;
			this->m_fruits = nullptr;
	}
}