#pragma once

#ifdef PLATFORM_WINDOWS

extern Gratify::Application* Gratify::CreateApplication();

int main(int argc, char** argv) {
	
	Gratify::Log::Init();

	GF_CORE_CRITICAL("critical error");
	GF_CORE_ERROR("Error error");
	GF_CORE_INFO("Info error");
	GF_CORE_TRACE("Trace error");
	GF_CORE_WARN("Warning Error");

	GF_TRACE("Application error");
	GF_INFO("Applicati<on error");
	GF_WARN("Application error");
	GF_CRITICAL("Application error");
	GF_ERROR("Application error"); 

	auto app = Gratify::CreateApplication();
	app->Run();
	delete app;
}

#endif // PLATFORM_WINDOWS