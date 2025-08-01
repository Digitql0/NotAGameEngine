#include "MiniGL.hpp"
#include "MostlyForces.hpp"
#include <iostream>

int main() {

	std::cout << "Making Window..." << std::endl;
	MakeWindow(800, 600, "Lol how did i do this");
	std::cout << "This is not real" << std::endl;

	Rectangle a = {250, 0, 100, 100};
	Rectangle b = {500, 0, 100, 100};
	Rectangle c = {0, 0, 100, 100};

	Vec2 a_velocity = {1, 0};

	while(!WindowShouldClose()) {
		//std::cout << "Beginning Drawing..." << std::endl;
		BeginDrawing();

		//std::cout << "Clearing Background..." << std::endl;
		ClearBackground(255, 255, 255);

		//std::cout << "Drawing Rectangle..." << std::endl;
		drawRectangle(a.x, a.y, a.w, a.h, 255, 0, 0);
		drawRectangle(b.x, b.y, b.w, b.h, 0, 255, 255);
		drawRectangle(c.x, c.y, c.w, c.h, 0, 0, 255);
		a.x += a_velocity.x;
		a.y += a_velocity.y;

		if (CheckCollisionRectangles(a, b) || CheckCollisionRectangles(a, c)) {
			a_velocity = getScaledVec(a_velocity, -1);
		}

		//std::cout << "Ending Drawing..." << std::endl;
		EndDrawing();
	}

	std::cout << "Closing Window..." << std::endl;
	CloseWindow();

	return 0;
}
