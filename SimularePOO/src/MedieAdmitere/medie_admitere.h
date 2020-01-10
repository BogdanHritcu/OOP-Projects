#pragma once

#include "../Dosar/dosar.h"
#include "../ProbaConcurs/proba_concurs.h"

class MedieAdmitere
{
private:
	Dosar* m_Dosar;
	ProbaConcurs* m_ProbaConcurs;

public:

	MedieAdmitere();
	~MedieAdmitere();

	float getNota() const;
};