#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

void getLevel(char* filename, vector<int>* map, int* width) {
	string str;
	int x;
	bool exist;
	vector<int>::iterator it;
	int iterator = 0;

	ifstream in;
	in.open(filename);

	in >> str;
	in >> *width;
	while(in >> x) {
		//cout << iterator << "-" << x << endl;

		if (iterator == 2) {
			exist = false;
			for (it = (*map).begin()+2; it <= (*map).end(); it += 3) {
				if (*it == x)
					exist = true;
				//cout << "ada" << endl;
			}

			if (!exist) {
				(*map).push_back(x);
			} else {
				(*map).pop_back();
				(*map).pop_back();
			}


			iterator = 0 ;			
		} else {
			(*map).push_back(x);
			iterator ++;
		}
	}

	in.close();
}

int main() {
	long double mass, volume, inertia, dx, dm, height, length, pheight, plength, rho, fx;
	//Insert parameters
	cout << "Insert object's mass : ";
	cin >> mass;
	cout << "Insert object's cyclindrical height : ";
	cin >> length;
	cout << "Insert object's maximum radius : ";
	cin >> height;

	//Open file
	char file[] = "level";
	int width;
	vector<int> map;

	getLevel(file, &map, &width);
	
	//Search the farthest point
	vector<int>::iterator it = map.begin();
	int pixelheight = 0;
	for (it = map.begin(); it <= map.end(); it += 3) {
		if (*it > pixelheight)
			pixelheight = *it;
	}

	//Create proportional constants
	plength = length / width;
	pheight = height / pixelheight;
	dx = plength;

	//VOLUME CALCULATION
	volume = 0;
	for (it = map.begin(); it <= map.end(); it += 3) {
		fx = (*it) * pheight;

		volume += M_PI * fx * fx * dx;
	}

	rho = mass / volume;
	
	//INERTIA CALCULATION
	inertia = 0;
	for (it = map.begin(); it <= map.end(); it += 3) {
		fx = (*it) * pheight;
		dm = M_PI * fx * fx * dx * rho;

		inertia += (0.5) * dm * fx * fx;
	}

	cout << endl << "CALCULATION RESULTS :" << endl;
	cout << "Inertia : " << inertia << endl;
	cout << "Volume : " << volume << endl;

	cout << "Insert any key to close" << endl;
	char x;
	cin >> x;

	return 0;
}
