#include "Application.h"
#include "Gratify/Event/ApplicationEvent.h"
#include "Gratify/Log.h"

namespace Gratify {
	Application::Application() 
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1000, 200);

		GF_INFO(e.ToString());


		while (true);
	}
}
