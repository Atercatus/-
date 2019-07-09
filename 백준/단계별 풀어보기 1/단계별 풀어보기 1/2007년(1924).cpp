#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string dayOfTheWeek[7] = {"SUN", "MON" , "TUE" , "WED" , "THU" , "FRI" , "SAT"};

int main() {
	int M, D;
	scanf("%d %d", &M, &D);
	int days = 0;
	int month = 1;

	while (month < M) {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			days += 30;
		}
		else if (month == 2) {
			days += 28;
		}
		else {
			days += 31;
		}
		month++;
	}
	days += D;
	days %= 7;

	cout << dayOfTheWeek[days] << endl;

	return 0;
}