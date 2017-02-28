#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

void Annoying();

int main() {
	Annoying();
}

void Annoying() {
	Beep(400, 1000);
	system("Color C");
	for (int i = 0; i <= 25; i++) {
		cout << "Sucks to suck" << endl;
	}
	MessageBox(0, "I HATE YOU", "BLEH", 0);
	Beep(2000, 1000);
	system("Color 4D");
	for (int i = 0; i <= 25; i++) {
		cout << "Your stupid!" << endl;
	}
	
	system("Color 2B");
	
	Beep(30000, 4000);
}
