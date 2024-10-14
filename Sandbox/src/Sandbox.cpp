#include "Gratify.h"

class Sandbox : public Gratify::Application {
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Gratify::Application* Gratify::CreateApplication()
{
	return new Sandbox();
}