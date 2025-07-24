#include <iostream>
#include "MiniGL.hpp"

int main() {

	MakeWindow(500, 500, "LOL");

	while (!WindowShouldClose()) {
		BeginDrawing();
		drawRectangle(200, 200, 200, 200, 255, 0, 255/2);
		EndDrawing();
	}

	CloseWindow();

	std::cout << "Hello World" << std::endl;
	return 0;
}