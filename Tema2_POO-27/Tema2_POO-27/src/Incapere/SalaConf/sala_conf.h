#pragma once

#include "../incapere.h"

namespace oop
{
	class SalaConf : public Incapere
	{
	protected:
		bool m_Proiector;

	public:
		SalaConf(int locuri);
		~SalaConf();

		bool getProiector() const;

		void setProiector(bool valoare);

		void afiseaza() const override;
	};
}