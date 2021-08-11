#ifndef FK_SHOW_H
#define FK_SHOW_H

#include <gpiod.hpp>

namespace fk {
	void show_lines(gpiod::chip_iter &chips);
	void show_chips();
}
#endif
