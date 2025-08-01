#include "MiniGL.hpp"
#include "MostlyForces.hpp"
#include <iostream>

int main() {

	std::cout << "Making Window..." << std::endl;
	MakeWindow(800, 600, "Lol how did i do this");

	while(!WindowShouldClose()) {
		//std::cout << "Beginning Drawing..." << std::endl;
		BeginDrawing();

		//std::cout << "Clearing Background..." << std::endl;
		ClearBackground(255, 255, 255);

		//std::cout << "Drawing Rectangle..." << std::endl;
		drawRectangle(10, 10, 100, 100, 255, 0, 0);

		//std::cout << "Ending Drawing..." << std::endl;
		EndDrawing();
	}

	std::cout << "Closing Window..." << std::endl;
	CloseWindow();

	return 0;
}
