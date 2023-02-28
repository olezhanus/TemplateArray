#include "bad_length.h"

bad_length::bad_length() noexcept :
	exception("Bad length exception")
{
}

bad_length::~bad_length() noexcept = default;
