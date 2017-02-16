#include <iostream>
using namespace std;

int main() {

	//ONE.
	for (int i = 0; i < 6; i = i++) {
		for (int i = 0; i < 3; i = i++)
			cout << "*";
		cout << endl;
	}
	cout << endl;
	//TWO.
	for (int i = 0; i < 6; i = i + 4) {
		cout << i ;
		cout << endl;
	}
	cout << endl;
	//THREE.
	for (int i = 50; i < 62; i=i++) {
		cout << i ;
		cout << endl;
	}
	cout << endl;
}