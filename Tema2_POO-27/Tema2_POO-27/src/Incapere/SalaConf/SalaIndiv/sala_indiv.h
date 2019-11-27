#pragma once

#include "../sala_conf.h"

namespace oop
{
	class SalaIndiv : public SalaConf
	{
	private:
		int m_NrMese;
		int m_LocuriMasa;

	public:
		SalaIndiv(int locuri, int mese, int locuri_masa);
		~SalaIndiv();

		int getNrMese() const; //returneaza cate mese sunt in sala
		int getLocuriMasa() const; //returneaza cate locuri sunt la o masa
		void afiseaza() const override;
	};
}