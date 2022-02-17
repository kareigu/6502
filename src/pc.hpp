#pragma once
#include <thread>
#include "cpu.hpp"
#include "ftxui/component/screen_interactive.hpp"

#define WAIT_TIME 2500

struct PC {
	CPU cpu;
	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
	std::thread worker;

	bool running = false;
	bool screen_on = false;

	void run();

	PC();
	~PC();
};