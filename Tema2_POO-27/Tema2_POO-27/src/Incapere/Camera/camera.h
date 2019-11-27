#pragma once

#include "../incapere.h"

namespace oop
{
	class Camera : public Incapere
	{
	public:
		Camera(int locuri);
		~Camera();

		void afiseaza() const override;
	};
}