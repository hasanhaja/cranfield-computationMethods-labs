#include <iostream>
#include <vector>
#include <string>

double f(double x) {
	return 3.0*(x*x*x) + 2.0*x + 1.0;
}

double fPrime(double x) {
	return 9.0*(x*x) + 2.0;
}

double forwardDifference(double x, double deltax) {
	return (f(x + deltax) - f(x)) / deltax;
}

double backwardDifference(double x, double deltax) {
	return (f(x) - f(x - deltax)) / deltax;
}

double centralDifference(double x, double deltax) {
	return (f(x + deltax) - f(x - deltax)) / (2.0*deltax);
}

double measureAccuracy(double calculated, double analytical) {
	return analytical - calculated;
}

// TODO try to add lambda to specify actual function.
std::vector<double> analyticalSolution(double start, double end, double deltax) {
	
	std::vector<double>	results;	

	for (double x = start; x <= end; ) {
		double result = fPrime(x);
		results.push_back(result);
		x += deltax;
	} 

	return results;
}

std::vector<double> forwardSolution(double start, double end, double deltax) {
	
	std::vector<double>	results;	

	for (double x = start; x <= end; ) {
		double result = forwardDifference(x, deltax);
		results.push_back(result);
		x += deltax;
	} 

	return results;
}

std::vector<double> backwardSolution(double start, double end, double deltax) {
	
	std::vector<double>	results;	

	for (double x = start; x <= end; ) {
		double result = backwardDifference(x, deltax);
		results.push_back(result);
		x += deltax;
	} 

	return results;
}

std::vector<double> centralSolution(double start, double end, double deltax) {
	
	std::vector<double>	results;	

	for (double x = start; x <= end; ) {
		double result = centralDifference(x, deltax);
		results.push_back(result);
		x += deltax;
	} 

	return results;
}

void display(double in, double result) {
	std::cout << "f(" << in << ") = " << result << std::endl;
}

void show(std::string msg) {
	std::cout << msg << std::endl;
}

int main() {
	

	double start = 0.0;
	double end = 1.0;
	double deltax = 0.1;	

	std::vector<double> actualResults = analyticalSolution(start, end, deltax);
	std::vector<double> forwardResults = forwardSolution(start, end, deltax);
	std::vector<double> backwardResults = backwardSolution(start, end, deltax);
	std::vector<double> centralResults = centralSolution(start, end, deltax);
 
	
	show("Actual results:");
	for (auto result : actualResults) {
		std::cout << result << std::endl;
	}
	
	show("Forward results:");
	for (auto result : forwardResults) {
		std::cout << result << std::endl;
	}

	show("Backward results:");
	for (auto result : backwardResults) {
		std::cout << result << std::endl;
	}

	show("Central results:");
	for (auto result : centralResults) {
		std::cout << result << std::endl;
	}
	
	return 0;
}
