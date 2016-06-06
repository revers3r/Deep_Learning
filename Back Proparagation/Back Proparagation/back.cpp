#include <iostream>

#define MAX2(a, b) (a) > (b) ? a:b;

class Neuron
{
public:
	Neuron()
		: _weight(2.0), _bias(2.0)
	{}
	Neuron(const double& w_input, const double& b_input)
		: _weight(w_input), _bias(b_input)
	{}

	double _weight;
	double _bias;
	double output, input;

	double GetActivation(const double& x) {
		return x;
	}

	double GetActivationGrad(const double& x) {
		return 1.0;
	}

	double feedfoward(const double& w) {
		input = w;
		const double sigma = _weight * input + _bias;
		output = GetActivation(sigma);

		return output;
	}

	void propBackward(const double& target) {
		const double grad = (output - target) * GetActivationGrad(output);
		const double alpha = 0.1;

		_weight = _weight - alpha * grad * input; // d(wx+b)/dw = x
		_bias = _bias - alpha * grad * 1.0; // d(wx+b)/db = 1
	}

	void FeedForwardAndPrint(const double& _input) {
		printf("%f %f \n", _input, feedfoward(_input));
	}
};

int main() {
	Neuron my_neuron(2.0, 1.0);

	for(int i = 0; i < 100; i++) {
		my_neuron.FeedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		my_neuron.FeedForwardAndPrint(1.0);
	}
}