#pragma once

#include <random>

class Random {
public:
	using integer_rand  = std::uniform_int_distribution<int32_t>;
	using double_rand   = std::uniform_real_distribution<double_t>;
public:
	Random();
public:
	const int     operator() ();

	const int     operator() (int lower, int upper);

	const double  operator() (double lower, double upper);

	const int     IntContent()	const;
	const double  DoubleContent()	const;
private: 
	int 	randomINumber_;
	double	randomDNumber_;

	std::default_random_engine engine_;
};
