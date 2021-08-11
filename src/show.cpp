#include "show.h"

#include <iomanip>
#include <iostream>

namespace fk {
	void show_lines(gpiod::chip_iter &chips) {
		constexpr auto column_names = std::array<std::string_view, 6> {
			std::string_view("Offset"),
			std::string_view("Name"),
			std::string_view("Direction"),
			std::string_view("Requested?"),
			std::string_view("Used?"),
			std::string_view("Active State")
		};

		constexpr size_t pad_width = 4;

		for (auto col : column_names) {
			std::cout << std::setw(col.length() + pad_width) << col;
		}
		std::cout << std::endl;

		for (gpiod::line_iter lines = gpiod::line_iter(*chips); lines != gpiod::end(lines); ++lines) {
			size_t i = 0;
			std::cout << std::setw(column_names[i++].length() + pad_width) << lines->offset();
			std::cout << std::setw(column_names[i++].length() + pad_width) << lines->name();
			std::cout << std::setw(column_names[i++].length() + pad_width) << lines->direction();
			std::cout << std::setw(column_names[i++].length() + pad_width) << lines->is_requested();
			std::cout << std::setw(column_names[i++].length() + pad_width) << lines->is_used();
			std::cout << std::setw(column_names[i++].length() + pad_width) << lines->active_state() << std::endl;
		}

	}

	void show_chips() {
		constexpr auto column_names = std::array<std::string_view, 3> {
			std::string_view("Name"),
			std::string_view("Label"),
			std::string_view("Line Count"),
		};

		constexpr size_t pad_width = 20;

		for (auto col : column_names) {
			std::cout << std::setw(col.length() + pad_width) << col;
		}
		std::cout << std::endl;

		for (auto chips = gpiod::make_chip_iter(); chips != gpiod::end(chips); ++chips) {
			size_t i = 0;
			std::cout << std::setw(column_names[i++].length() + pad_width) << chips->name();
			std::cout << std::setw(column_names[i++].length() + pad_width) << chips->label();
			std::cout << std::setw(column_names[i++].length() + pad_width) << chips->num_lines() << std::endl;
		}
	}
}
