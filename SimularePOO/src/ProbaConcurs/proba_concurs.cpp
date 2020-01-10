#include "proba_concurs.h"

ProbaConcurs::ProbaConcurs()
{
	m_Nota = 1.0f;
}

ProbaConcurs::~ProbaConcurs()
{

}

float ProbaConcurs::getNota() const
{
	return m_Nota;
}