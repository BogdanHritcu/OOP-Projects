#pragma once

class ProbaConcurs
{
protected:
	float m_Nota;

public:
	ProbaConcurs();
	~ProbaConcurs();

	virtual float getNota() const;
};