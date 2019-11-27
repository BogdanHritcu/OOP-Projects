#include "cerere.h"

namespace oop
{
	Cerere::Cerere()
	{
		m_Tip = TipCerere::rezervare;
		m_TipSala = TipIncapere::invalid;
		m_Grup = nullptr;
	}

	Cerere::Cerere(const Cerere& cerere)
	{
		m_Tip = cerere.m_Tip;
		m_Grup = cerere.m_Grup;
		m_Proiector = m_Proiector;
		m_TipSala = cerere.m_TipSala;
	}

	Cerere& Cerere::operator=(const Cerere& cerere)
	{
		m_Tip = cerere.m_Tip;
		m_Grup = cerere.m_Grup;
		m_Proiector = m_Proiector;
		m_TipSala = cerere.m_TipSala;

		return *this;
	}

	Cerere::~Cerere()
	{

	}

	TipCerere Cerere::getTip() const
	{
		return m_Tip;
	}
	
	Grup* Cerere::getGrup() const
	{
		return m_Grup;
	}

	TipIncapere Cerere::getTipSala() const
	{
		return m_TipSala;
	}

	bool Cerere::getProiector() const
	{
		return m_Proiector;
	}

	void Cerere::setTipCerere(const TipCerere tip)
	{
		m_Tip = tip;
	}

	void Cerere::setGrup(const Grup& grup)
	{
		m_Grup = const_cast<Grup*>(&grup);
	}

	void Cerere::setTipSala(TipIncapere tip)
	{
		m_TipSala = tip;
	}

	void Cerere::setProiector(bool valoare)
	{
		m_Proiector = valoare;
	}
}
