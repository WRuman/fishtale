#include <gpiod.hpp>

#include <sysexits.h>

#include <cstdlib>
#include <iostream>
#include <string>


int main(int argc, char **argv) {
	if (argc < 2 ) {
		std::cout << "Required input: GPIO pin number" << std::endl;
		return EX_USAGE;
	}
	long pin = std::strtol(argv[1], nullptr, 10);
	if (pin > 40 || pin < 0) {
		std::cerr << "GPIO pin number out of range" << std::endl;
		return EX_USAGE;
	}
	std::cout << "Using pin " << pin << std::endl;

	gpiod::chip_iter chips = gpiod::make_chip_iter();

	for (; chips != gpiod::end(chips); ++chips) {
		std::cout << "Found chip '" << chips->name() << "'" << std::endl;
	}

	return 0;
}

