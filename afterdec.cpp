#include<iostream>
#include<string>
#include<vector>
using namespace std;




int main () { 
double number;
int base = 2;

std::vector<int> multiplyside;
cout << "Enter Number : " << endl;
cin >> number ;
cout << endl;

    for (int i = 0; i < 4; i++) {
        number *= base;
        cout << "number = " << number << "   " << int(number) << endl;
        multiplyside.push_back(int(number));
        number -= int(number);
        cout << number << endl;
        cin.get();
    }

    cout << endl;
cin.get();
return 0;
}