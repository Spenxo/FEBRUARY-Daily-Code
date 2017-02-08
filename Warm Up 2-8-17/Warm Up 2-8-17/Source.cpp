#include <iostream>
using namespace std;

int main() {
		int volume;
		int height;
		int width;
		cout << "What is the height?" << endl;
		cin >> height;
		cout << "What is the width?" << endl;
		cin >> width;
		volume = (width*height) / 3;
		cout << "Your volume is " << volume << "." << endl;
}
