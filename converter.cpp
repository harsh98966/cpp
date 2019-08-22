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


void Decdivide(int base); //logic to convert numbers before decimal point
void print(int base); 
void afterdec(double number1, int base); //logic to convert numbers after decimal point
void hexadecimal(int number);  //logic to print hexadec numbers;


int main () { 
cout << "Enter Number : " << endl;
cin >> number1;											//it takes decimal number from user like 555.55
number = int(number1);									//converts decimal number to int number like 555.55 to 555
const int number2 = number;								//used to store int number value bcz it gets changed in decdivide function  ##
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
		cout << ".";
		afterdec(number1, base);
		
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
		cout << ".";
		afterdec(number1, base);
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
		cout << ".";
		afterdec(number1, base);
		break;
	case 16:
		cout << "Hexadecimal = ";
		for (int a = remainder.size() - 1; a >= 0; a--) {
			if (remainder[remainder.size() - 1] == 0 && a == remainder.size() - 1) {
			
			}
			else {
				hexadecimal(remainder[a]);				
			}
		
		}
		cout << ".";
		afterdec(number1, base);
		break;
	
	default:
	cout << "Error In base" << endl;
		break;
	}
}






void afterdec(double number1, int base)   //ex-number1 = 555.55##
{	
	vector<int> reqnum;
	float decvalue = number1 - int(number1); 		//used to store 0.55 so that i can perform multiplication
 	for (int a = 0; a < 6; a++) {
		 decvalue *= base;
		 reqnum.push_back(int(decvalue));
		 decvalue -= int(decvalue);  				//converts 1.10 to 0.10;
	 }
	 if (base == 16) {
		 for (int a = 0; a < reqnum.size(); a++) {
		 hexadecimal(reqnum[a]);
	 }
	 }
	 else {
		 for (int a = 0; a < reqnum.size(); a++) {
		 cout << reqnum[a];
	 }
	 }

}




void hexadecimal(int number) {
	switch (number)
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
		if (number >= 0 && number <10) {
			cout << number;
		}
		else {
			cout << "Error in hexadecimal" << endl;
		}
		break;
	}

}