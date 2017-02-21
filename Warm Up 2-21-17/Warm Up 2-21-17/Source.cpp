#include <iostream>
using namespace std;

int main() {
	int cookie = 0;

	do {
		cout << "What type of cookie would you like? 1. Chocolate Fudge. 2. Chocolate Chip. 3. Macadamia. 4. Mystery. 5. Mint. 6. Chocolate. 7. Powdered. Or press 0 to quit." << endl;
		cin >> cookie;
		switch (cookie) {
		case 1:
			cout << "You get one chocolate fudge cookie" << endl;
			cout << endl;
			break;
		case 2:
			cout << "You get one chocolate chip cookie." << endl;
			cout << endl;
			break;
		case 3:
			cout << "You get one macadamia cookie." << endl;
			cout << endl;
			break;
		case 4:
			cout << "You get one Mystery cookie." << endl;
			cout << endl;
			break;
		case 5:
			cout << "You get one mint cookie." << endl;
			cout << endl;
			break;
		case 6:
			cout << "You get one Chocolate cookie." << endl;
			cout << endl;
			break;
		case 7:
			cout << "You get one powdered cookie." << endl;
			cout << endl;
			break;

		}
	} while (cookie != 0);
}