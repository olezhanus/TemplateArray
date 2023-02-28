#include "bad_range.h"

bad_range::bad_range() noexcept :
	exception("Bad range exception")
{
}

bad_range::~bad_range() noexcept = default;
