#pragma once

#include "../dosar.h"

class DosarIF : virtual public Dosar
{
private:
	float m_NotaMate;

public:
	DosarIF();
	~DosarIF();

	std::string getFormaInvatamant() override;
	float getNota() const override;
};