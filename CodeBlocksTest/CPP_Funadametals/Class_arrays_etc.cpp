#include <iostream>

using namespace std;


//ARRAYS DECLARATION:

int arr[] {10, 20, 3, 6, 40, 65};

int result =0;

int arr2D[3][2] {{1,2},
               {3,4},
               {5,6}};



int main() {


for (int i=0; i<6; i++) {
    result+=arr[i];
    cout<<arr[i]<<endl;
}
cout<<"Sum of array: "<<result<<endl;


for (int i=0; i<3; i++) {
    for (int j=0; j<2; j++) {
        cout<<arr2D[i][j];
    } cout<<endl;
}


return 0;
}
