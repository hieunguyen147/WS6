#ifndef SAIYAN_H
#define SAIYAN_H
#include"Saiyan.h"
#define MAX_NAME_CHARS 31
namespace sdds {

	class Saiyan {
		private:
			char m_name[MAX_NAME_CHARS + 1];
			int m_dob;
			int m_power;
			bool m_super = false;

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power, bool super = false);
		void set(const char* name, int dob, int power, bool super = false);
		void setEmpty();
		bool isValid() const;
		void display() const;
		bool fight(const Saiyan& other);
	};


}
#endif // !SAIYAN_H