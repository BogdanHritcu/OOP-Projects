#pragma once

#include "../dosar.h"

class DosarID : virtual public Dosar
{
private:
	float m_NotaMate;

public:
	DosarID();
	~DosarID();

	std::string getFormaInvatamant() override;
	float getNota() const override;
};