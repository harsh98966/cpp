/*A program to convert Decimal Numbers to other Number System(Binary, Octal, Hexadecimal)*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

std::vector<int> remainder;
double number1;
int number;
std::vector<int> base {2,8,10,16};
bool stop = false;


void Decdivide(int base);
void print(int base);


int main () { 
cout << "Enter Number : " << endl;
cin >> number1;
number = int(number1);
const int number2 = number;
cout << endl;
for (int i : base) {
	stop = false;
	remainder.clear();
while (!stop) {
Decdivide(i);
	}
	print(i);
	cout << endl;
	number= number2;
}
cin.get();

return 0;
} 



void Decdivide(int base) {

	int rema;
	rema = number % base;
	remainder.push_back(rema);
	number /= base;
	if (number == 0 || number == 1) {
		stop = true;
		remainder.push_back(number);
	}
	
}




void print(int base) {
	switch (base)
	{
	case 2:
		cout << "Binary = ";
		for (int a = remainder.size() - 1; a >= 0; a--) {
			cout << remainder[a];
		}
		
		break;
	case 8:
		cout << "octal = ";
		for (int a = remainder.size() - 1; a >= 0; a--) {
			if (remainder[remainder.size() - 1] == 0 && a == remainder.size() - 1) {
			
			}
			else {
				cout << remainder[a];
			}
		}
		break;
	case 10:
		cout << "Decimal = ";
		for (int a = remainder.size() - 1; a >= 0; a--) {
			if (remainder[remainder.size() - 1] == 0 && a == remainder.size() - 1) {
			
			}
			else {
				cout << remainder[a];
			}
		}
		break;
	case 16:
		cout << "Hexadecimal = ";
		for (int a = remainder.size() - 1; a >= 0; a--) {
			if (remainder[remainder.size() - 1] == 0 && a == remainder.size() - 1) {
			
			}
			else {
				if (remainder[a] >= 10) {
					switch (remainder[a])
					{
					case 10:
						cout << "A";
						break;
					case 11:
						cout << "B";
						break;
					case 12:
						cout << "C";
						break;
					case 13:
						cout << "D";
						break;
					case 14:
						cout << "E";
						break;
					case 15:
						cout << "F";
						break;
					
					default:
					cout << "in hexadecimal " << endl;
						break;
					}
				}
				else {
					cout << remainder[a];
				}
			}
		}
		break;
	
	default:
	cout << "Error In base" << endl;
		break;
	}
}