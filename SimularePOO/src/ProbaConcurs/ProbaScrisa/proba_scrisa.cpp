#include "proba_scrisa.h"

ProbaScrisa::ProbaScrisa()
{
	m_Nota2 = 1.0f;
}

ProbaScrisa::~ProbaScrisa()
{

}

float ProbaScrisa::getNota() const
{
	return (m_Nota + m_Nota2) / 2;
}