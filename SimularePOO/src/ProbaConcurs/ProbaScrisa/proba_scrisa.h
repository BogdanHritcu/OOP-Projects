#pragma once

#include "../proba_concurs.h"

class ProbaScrisa : public ProbaConcurs
{
private:
	float m_Nota2;

public:
	ProbaScrisa();
	~ProbaScrisa();

	float getNota() const override;
};