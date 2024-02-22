#include <iostream>
#include <string>
#include "App.hpp"

using namespace std;

int main() {
	App app;

	app.build(600, 600);
	app.start();
	return 0;
}