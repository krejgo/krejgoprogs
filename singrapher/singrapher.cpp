#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <cmath>
using namespace std;

void print(int size, int val) {
	int ls;
	if (val==0){
		cout << string(size, ' ') << '*' << endl;
		return;
	} else if (val > 0) {
		ls = size;
	} else if (val < 0) {
		ls = size + val;
		val *= -1;
	}
	cout << string(ls,' ') << '*' << string(val-1,' ') << '*' << endl;
}

int fSin(float num, int amp) {
	float x = (amp*sin(num));
	return x+0.5;
}

int main() {
	int size, time, period;

	size = 39; //max supaya muat di cmd 39
	time = 1000;
	period = 500;

	cout << string(size*2+1, '*') << endl;
	
	for (int i = 0; i < period; ++i) {
		float phase = (float) i/period * (2*M_PI);
		int value = fSin(phase, size);
		print(size, value);
		if (i == period-1){
			i = 0;
		}
		usleep(time);
	}
}