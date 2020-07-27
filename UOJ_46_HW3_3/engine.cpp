#include "engine.h"

Engine::Engine(string nam): name(nam) {
	cout << "Using "  << nam << " engine."<< endl;
}

string Engine::get_name() {
	return name;
}
