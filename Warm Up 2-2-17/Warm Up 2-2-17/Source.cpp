#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int song;
	do {
		cout << "Which song do you pick?" << endl;
		cout << "1. We Are Number One " << endl;
		cout << "2. Cook it by the Book" << endl;
		cout << "3. FUN" << endl;
		cout << "Or press '0' to quit." << endl;
		cin >> song;
		if (song == 1)
			cout << "Here's a little lesson in trickery, this is going down in history." << endl << endl;
		if (song == 2)
			cout << "The cake will end up crazy. If you do the cookin' by the book. Then you'll have a cake!" << endl << endl;
		if (song == 3)
			cout << "F is for friends who do stuff together. U is for you and me!" << endl << endl;;

	} while (song != 0);
}