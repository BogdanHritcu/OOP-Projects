#pragma once

#include "../sala_conf.h"

namespace oop
{
	class SalaScena : public SalaConf
	{
	public:
		SalaScena(int locuri);
		~SalaScena();

		void afiseaza() const override;
	};
}