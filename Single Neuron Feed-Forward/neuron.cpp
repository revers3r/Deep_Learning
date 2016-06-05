#include <iostream>

#define MAX2(a, b) (a) > (b) ? a:b;

class Neuron
{
public:
	double _weight;
	double _bias;

	double GetActivation(const double& x) {
		return MAX2(0.0, x);
	}

	double feedfoward(const double& w) {
		const double sigma = _weight * w + _bias;
		return GetActivation(sigma);
	}
};

int main() {
	Neuron my_neuron;
	my_neuron._bias = 1.0;
	my_neuron._weight = 2.0;

	std::cout << "Input = 2.0 : " << my_neuron.feedfoward(2.0) << std::endl;
}