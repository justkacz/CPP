// configuration settings for VSC - using GCC (g++) compiler and GDB debugger (mingw-w64) - https://code.visualstudio.com/docs/cpp/config-mingw

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    int number;
    cout<<"Please provide a number: " <<endl;
    cin>>number;
    cout<<"Provided number is: "<< number<< endl;

    for (int i = 0; i<=number; i++) {
        cout<<"Printing each number till 0: "<< number-i<< endl;
    }
        cout<<"The end!!!"<<endl;
}