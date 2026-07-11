#pragma once
class Result
{
	public:
		int hit;
		int blow;
		bool isClear_;
		Result() {};
		void set(int hit, int blow, bool isClear);
};

