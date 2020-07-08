#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
using namespace std;

#include <string>

namespace sdds {




	Engine::Engine()
	{
		m_type[0] = '\0';
		m_size = 0.0;
	}

	Engine::Engine(const char* type, double size)
	{
		setEngine(type,size);
	}
	void Engine::setEngine(const char* type, double size) {
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