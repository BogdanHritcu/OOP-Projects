#include "camera.h"

namespace oop
{
	Camera::Camera(int locuri) : Incapere(locuri)
	{
		m_Tip = TipIncapere::camera;
	}

	Camera::~Camera()
	{

	}

	void Camera::afiseaza() const
	{
		std::cout << "Camera" << std::endl;
		Incapere::afiseaza();
	}
}