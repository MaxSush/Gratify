#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace Gratify {
	
	class GFAPI Application {
	public:
		Application();
		~Application();
		void Run();
	
	};

	Application* CreateApplication();

}

