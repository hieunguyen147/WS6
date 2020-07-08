// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SAIYAN_H
#define SAIYAN_H
#include"Saiyan.h"

namespace sdds {

	class Saiyan {
		private:
			char* m_name;
			int m_dob;
			int m_power;
			bool m_super = false;
			int m_level;

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		void set(const char* name, int dob, int power, int level = 0 ,bool super = false);
		void setEmpty();
		bool isValid() const;
		void display() const;
		bool fight( Saiyan& other);
		void powUp();
		~Saiyan();
	};


}
#endif // !SAIYAN_H