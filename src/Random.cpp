#include "../inc/random.hpp"

Random::Random()
	: randomINumber_( 0 )
	, randomDNumber_( 0 )

	, engine_(std::random_device{}())
{}

const int32_t Random::operator() () {
	randomINumber_ = engine_();
	return randomINumber_;
}

const int32_t Random::operator() (int32_t lower, int32_t upper) {
	
	integer_rand	 dis{ lower, upper };
	randomINumber_ = dis(engine_);

	return	randomINumber_;
}

const double_t Random::operator() (double_t lower, double_t upper) {
	
	double_rand		  dis{ lower, upper };
	randomDNumber_	= dis(engine_);

	return randomDNumber_;
}

const int32_t Random::IntContent() const {
	return randomINumber_;
}

const double_t Random::DoubleContent() const {
	return randomDNumber_;
}
