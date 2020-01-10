#pragma once

#include "../DosarIF/dosar_if.h"
#include "../DosarID/dosar_id.h"

class Dosar2 : public DosarIF, public DosarID
{
private:
	float m_NotaFacultate;
	std::string m_FormaInvatamant;


public:
	Dosar2(std::string forma_invatamant);
	~Dosar2();

	std::string getFormaInvatamant() override;
	float getNota() const override;
};