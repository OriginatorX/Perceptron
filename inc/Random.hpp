#pragma once

#include <random>

class Random {
public:
	using integer_rand	= std::uniform_int_distribution<int32_t>;
	using double_rand	= std::uniform_real_distribution<double_t>;
public:
	Random();
public:
	const int32_t	operator() ();

	const int32_t	operator() (int32_t lower, int32_t upper);

	const double_t	operator() (double_t lower, double_t upper);

	const int32_t   IntContent()	const;
	const double_t  DoubleContent()	const;
private: 
	int32_t randomINumber_;
	double	randomDNumber_;

	std::default_random_engine	engine_;
};
