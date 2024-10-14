#pragma once
#include "Core.h"

namespace Gratify {
	
	class GFAPI Application {
	public:
		Application();
		~Application();
		void Run();
	
	};

	Application* CreateApplication();

}

