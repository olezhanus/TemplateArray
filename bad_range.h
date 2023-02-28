#pragma once
#include <exception>
class bad_range :
	public std::exception
{
public:
	bad_range() noexcept;
	~bad_range() noexcept;
};

