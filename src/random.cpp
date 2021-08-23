#include "../inc/random.hpp"

Random::Random()
	: randomINumber_( 0 )
	, randomDNumber_( 0 )

	, engine_(std::random_device{}())
{}

const int Random::operator() () {
	randomINumber_ = engine_();
	return randomINumber_;
}

const int Random::operator() (int lower, int upper) {
	
	integer_rand dis{ lower, upper };
	randomINumber_ = dis(engine_);

	return randomINumber_;
}

const double Random::operator() (double lower, double upper) {
	
	double_rand dis{ lower, upper };
	randomDNumber_	= dis(engine_);

	return randomDNumber_;
}

const int Random::IntContent() const {
	return randomINumber_;
}

const double Random::DoubleContent() const {
	return randomDNumber_;
}
