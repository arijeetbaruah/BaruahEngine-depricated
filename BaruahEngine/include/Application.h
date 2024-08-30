#pragma once

#include "Core.h"

namespace Baruah {
	class BARUAH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}

