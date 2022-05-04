#include <iostream>
#include <ctime>
#include "functions_.cpp"


using namespace std;

void SayHi(string name2) {
    cout<<"Hello "<<name2<<"!"<<endl;
}

double cube (double num) {
    double result = num*num*num;
    return result;
}

int getMax(int num1, int num2, int num3) {
    int result;
    if (num1>num2 && num1>num3){
        result=num1;
    } else if (num2>num1 && num2>num3) {
        result=num2;
    } else {
        result = num3;
    }
    return result;
}


string getDayName2(int dayNumber){

    string dayName;

    switch(dayNumber) {
     case 0:
        dayName="Monday";
        break;
     case 1:
        dayName="Tuesday";
        break;
     case 2:
        dayName="Wednesday";
        break;
     case 3:
        dayName="Thursday";
        break;
     case 4:
        dayName="Friday";
        break;
     case 5:
        dayName="Saturday";
        break;
     case 6:
        dayName="Sunday";
        break;
     default:
        dayName="Invalid day number.";
        break;

    }

    return dayName;

}
/*
 arrList(arr) {
        for(int z=0; z<3; z++){
            for (int u=0; u<2; u++){
                cout<<arr[z][u];
            }
            cout<<endl;
        }

    }
*/



int main()
{
    string name;
    cout<<"What is your name?" << endl;
    getline(cin, name);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int age;
    cout << "What is your year of birth?" << endl;
    cin>>age;

    SayHi(name);
    cout<<"You are: "<<(1900 + ltm->tm_year) - age<< " years old."<< endl;

    double answ=cube(6);
    cout<<"The result of the cube function is: "<<answ<<endl;
    cout<<"The result of the getMax function is: "<<getMax(10,3,15)<<endl;

    calculator();
    cout<<"\nThe result of getDayName function is: "<<getDayName(5)<<endl;
    printingValues();
    cout<<guessGame()<<endl;
    cout<<power(2,3)<<endl;

    // 2D ARRAY:

int arr_mat[3][2] ={{1,2},
                       {3,4},
                       {5,6}};
cout<<arr_mat[0][1];
    // POINTER -> refers to the memory address - marked with '&' and variable name;
    //POINTER VARIABLE -> noted with * at the beginning results with the value stored under pointer address
    // e.g. int x=6
    //      int *px=&x
    //      cout<< &x => address;
    //      cout<< *&x => 6 value


    return 0;
}
