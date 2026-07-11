#pragma once

#include "Number.h"
#include "Result.h"

class Judge
{
	public:
		Result compare(const Number& rand, const Number& input);

private:
	int count;
};

