#include <iostream>
#include <cmath>

class Activation
{
public:
	/* Sigmoid Function */
	// f(x) = 1 / (1 + e^(-x))
	float getSigmoid(const float& x) {
		return 1.0f / (1.0f + exp(-x));
	}

	float getGradSigmoid(const float& x) {
		const float f = getSigmoid(x);
		return f * (1.0 - f);
	}

	/* ReLU Function */
	// f(x) = 0 for x < 0, x for x >= 0

	float getReLU(const float& x) {
		return x >= 0.0f ? x : 0.0f;
	}
	float getGradReLU(const float& x) {
		return x >= 0.0f ? 1 : 0.0f;
	}
};

int main() {
	Activation acv;
	std::cout << "Sigmoid Function Val = 2.0 :: " << acv.getSigmoid(2.0) << std::endl;
	std::cout << "GradSigmoid Function Val = 2.0 :: " << acv.getGradSigmoid(2.0) << std::endl;

	std::cout << "ReLU Function Val = 2.0 :: " << acv.getReLU(2.0) << std::endl;
	std::cout << "GradReLU Function Val = 2.0 :: " << acv.getGradReLU(2.0) << std::endl;
}