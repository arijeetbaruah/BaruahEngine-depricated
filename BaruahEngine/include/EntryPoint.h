#pragma once

#ifdef BE_PLATFORM_WINDOW

	extern Baruah::Application* Baruah::CreateApplication();

	int main(int argc, char** argv) {
		auto app = Baruah::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Baruah Engine is only supported in Windows!
#endif

