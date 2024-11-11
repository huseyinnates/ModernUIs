// Main.cpp
#pragma once

#include "Walnut/Application.h"
#include "C:/Company/C++/UI/Walnut/Walnut/Source/Walnut/Engine/first_app.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

extern Walnut::Application* Walnut::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Walnut {

	int Main(int argc, char** argv) {
		
		Wallnut::FirstApp app{};
		Walnut::Application* appUI = Walnut::CreateApplication(argc, argv);
		appUI->Run();

		try {
			while (true) {
				app.run();
				appUI->Run();
			}
			delete appUI;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
			return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
		/*
		while (g_ApplicationRunning) {
			
			
		}
		return 0;
		*/
		
	}

}

#if defined(WL_PLATFORM_WINDOWS) && !defined(WL_HEADLESS) && defined(WL_DIST)

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
	return Walnut::Main(__argc, __argv);
}

#else

int main(int argc, char** argv) {
	return Walnut::Main(argc, argv);
}

#endif // defined(WL_PLATFORM_WINDOWS) && defined(WL_DIST)
