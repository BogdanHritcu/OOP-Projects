#pragma once

#include <string>
#include <vector>

#include "../ProgramInvatamant/program_invatamant.h"

class Dosar
{
protected:
	std::string m_Nume;
	std::string m_Prenume;

	float m_MedieBac;

public:
	Dosar();
	~Dosar();

	virtual std::string getFormaInvatamant() = 0;
	virtual float getNota() const = 0;
};