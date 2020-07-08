//#define _CRT_SECURE_NO_WARNINGS
//#pragma once
//#include"Basket.h"
//#include<cstring>
//#include <iomanip>
//#include<iostream>
//#include<fstream>
//using namespace std;
//
//namespace sdds {
//
//
//	Basket::Basket()
//	{
//		emptyBasket();
//	}
//	void Basket::setBasket(double price, Fruit* _fruit, int cnt)
//	{
//		if (m_fruits == nullptr || m_price < 0 || m_cnt < 0) {
//			emptyBasket();
//		}
//		else
//		{
//			this->m_cnt = m_cnt;
//			setPrice(price);
//			this->m_cnt = cnt;
//			this->m_fruits = new Fruit[this->m_cnt];
//			for (int i = 0; i < cnt; i++) {
//				this->m_fruits[i] = _fruit[i];
//			}
//		}
//	}
//	void Basket::emptyBasket()
//	{
//		this->m_fruits = nullptr;
//		this->m_price = 0.0;
//		this->m_cnt = 0;
//	}
//	void Basket::setPrice(double& price)
//	{
//		this->m_price = price;
//	}
//	bool Basket::check()
//	{
//		return (this->m_fruits != nullptr && this->m_cnt > 0);
//	}
//
//
//
//
//	Basket& Basket::operator+=(Fruit a)
//	{
//		if (a.m_name[0] == 0 || a.m_qty < 0) {
//			cout << "The object is not valid!" << endl;
//		}
//		else {
//			Fruit* r = nullptr;
//			r = new Fruit[this->m_cnt];
//			for (int i = 0; i < this->m_cnt; i++) {
//				r[i] = this->m_fruits[i];
//			}
//			delete[] this->m_fruits;
//			this->m_fruits = nullptr;
//			this->m_cnt += 1;
//			this->m_fruits = new Fruit[this->m_cnt];
//			for (int i = 0; i < m_cnt - 1; i++) {
//				this->m_fruits[i] = r[i];
//			}
//			delete[] r;
//			r = nullptr;
//		}
//		return *this;
//	}
//	Basket& Basket::operator=(const Basket& b)
//	{
//		if (this->m_fruits != b.m_fruits) {
//			this->m_fruits = b.m_fruits;
//			this->m_cnt = b.m_cnt;
//			this->m_price = b.m_price;
//			delete[] this->m_fruits;
//			if (b.m_fruits != nullptr) {
//				this->m_fruits = new Fruit[this->m_cnt];
//				for (int i = 0; i < this->m_cnt; i++) {
//					this->m_fruits[i] = b.m_fruits[i];
//				}
//			}
//		}
//		return *this;
//	}
//	Basket::~Basket()
//	{
//		delete[] this->m_fruits;
//		this->m_fruits = nullptr;
//	}
//
//	void Basket::display( ostream& out) const
//	{
//		if (this->m_cnt > 0) {
//			cout << "Basket Content:" << endl;
//			for (int i = 0; i < this->m_cnt; i++) {
//				cout << this->m_fruits->m_name << ": " << this->m_fruits->m_qty << endl;
//			}
//		}
//		else cout << "The basket is empty!" << endl;
//	}
//
//	std::ostream& operator<< (std::ostream& out, const Basket& bk)
//	{
//			bk.display(out);
//		return out;
//	}
//}

#define _CRT_SECURE_NO_WARNINGS
#pragma once
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
	Basket::Basket(Fruit* fruit, int cnt, double price)
	{
		set(fruit,cnt,price);
	}
	void Basket::set(Fruit* fruit, int cnt, double price)
	{
		if (m_fruits == nullptr || m_cnt < 0) {
			emptyBasket();
		}
		else
		{
			this->m_cnt = m_cnt;
			setPrice(price);
			this->m_cnt = cnt;
			this->m_fruits = new Fruit[this->m_cnt];
			for (int i = 0; i < cnt; i++) {
				this->m_fruits[i] = fruit[i];
			}
			delete[] this->m_fruits;
			this->m_fruits = nullptr;
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
		this->m_price = price;
	}
	bool Basket::check()
	{
		return (this->m_fruits != nullptr && this->m_cnt > 0);
	}




	Basket& Basket::operator+=(Fruit a)
	{
		if (a.m_name[0] == 0 || a.m_qty < 0) {
			cout << "The object is not valid!" << endl;
		}
		else {
			Fruit* r = nullptr;
			r = new Fruit[this->m_cnt];
			for (int i = 0; i < this->m_cnt; i++) {
				r[i] = this->m_fruits[i];
			}
			delete[] this->m_fruits;
			this->m_fruits = nullptr;
			this->m_cnt += 1;
			this->m_fruits = new Fruit[this->m_cnt];
			for (int i = 0; i < m_cnt - 1; i++) {
				this->m_fruits[i] = r[i];
			}
			delete[] r;
			r = nullptr;
		}
		return *this;
	}
	Basket& Basket::operator=(const Basket& b)
	{
		if (this->m_fruits != b.m_fruits) {
			this->m_fruits = b.m_fruits;
			this->m_cnt = b.m_cnt;
			this->m_price = b.m_price;
			delete[] this->m_fruits;
			if (b.m_fruits != nullptr) {
				this->m_fruits = new Fruit[this->m_cnt];
				for (int i = 0; i < this->m_cnt; i++) {
					this->m_fruits[i] = b.m_fruits[i];
				}
			}
		}
		return *this;
	}
	Basket::~Basket()
	{
		delete[] this->m_fruits;
		this->m_fruits = nullptr;
	}

	void Basket::display( ostream& out) const
	{
		if (this->m_cnt > 0) {
			cout << "Basket Content:" << endl;
			for (int i = 0; i < this->m_cnt; i++) {
				cout << this->m_fruits->m_name << ": " << this->m_fruits->m_qty << endl;
			}
		}
		else cout << "The basket is empty!" << endl;
	}

	std::ostream& operator<< (std::ostream& out, const Basket& bk)
	{
		bk.display(out);
		return out;
	}
}

