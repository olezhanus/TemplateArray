#pragma once
#include <exception>
class bad_length :
	public std::exception
{
public:
	bad_length() noexcept;
	~bad_length() noexcept;
};

