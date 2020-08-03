#include <iostream>
#include <cmath>

using namespace std;

#define M_PI 3.14159265358979323846

int main(void) {

	double r;

	cin >> r;

	printf("%.6lf\n%.6lf", r * r * M_PI, 2 * r * r);
	return 0;
}