#include <gpiod.hpp>

#include <sysexits.h>

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

#include "show.h"

enum UsageMode {
	GENERAL,
	SHOW
};


void show_usage(UsageMode m) {
	switch (m) {
		case SHOW:
			std::cout << "Usage: fishkeeper show {chips, lines}" << std::endl;
			break;
		case GENERAL:
		default:
			std::cout << "Usage: fishkeeper {show, run}" << std::endl;
			break;
	}
}

int check_pin(char *arg) {
	auto pin = std::strtol(arg, nullptr, 10);
	if (pin > 40 || pin < 0) {
		std::cerr << "GPIO pin number out of range" << std::endl;
		return EX_USAGE;
	}
	return 0;
}


int main(int argc, char **argv) {
	constexpr auto DIAG_MODE = std::string_view{"show"};
	constexpr auto DIAG_LINES_MODE = std::string_view{"lines"};
	constexpr auto DIAG_CHIPS_MODE = std::string_view{"chips"};

	if (argc < 2 ) {
		show_usage(UsageMode::GENERAL);
		return EX_USAGE;
	}

	if (DIAG_MODE == argv[1]) {
		if (argc == 3 && DIAG_LINES_MODE == argv[2]) {
			for (auto chips = gpiod::make_chip_iter(); chips != gpiod::end(chips); ++chips) {
				fk::show_lines(chips);
			}
		} else if (argc == 3 && DIAG_CHIPS_MODE == argv[2]) {
			fk::show_chips();
		} else {
			show_usage(UsageMode::SHOW);
			return EX_USAGE;
		}
	}

	return 0;
}

