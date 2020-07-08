// Student name: Nguyen Hoang Trung Hieu
// Student ID:   142914191
// Section:      NBB
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
using namespace std;
#include <cstring>
using namespace std;
namespace sdds {
	Engine::Engine()
	{
		setEmpty();
	}

	void Engine::setEmpty()
	{
		m_type[0] = '\0';
		m_size = 0.0;
	}

	Engine::Engine(const char* type, double size)
	{
		setEngine(type, size);
	}

	void Engine::setEngine(const char* type, double size)
	{
		if (type == nullptr || type[0] == '\0' || size < 0)
		{
			Engine();
		}
		else
		{
			strncpy(m_type, type, TYPE_MAX_SIZE);
			m_size = size;
		}
	}

	double Engine::get() const
	{
		return this->m_size;
	}

	char* Engine::getType()
	{
		return m_type;
	}

	void Engine::display() const
	{
		cout << this->m_size << " liters - " << this->m_type << endl;
	}

}