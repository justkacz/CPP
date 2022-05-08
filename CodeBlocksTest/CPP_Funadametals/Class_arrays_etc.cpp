// - private members of a class are accessible only from within other members of the same class (or from their "friends").
// - protected members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
// - public members are accessible from anywhere where the object is visible.



#include <iostream>
#include <sstream>
#include <string>

using namespace std;



class Book{
    public:
        string author;
        string title;
        int pages;
        // constructor function:
        Book (string aAuthor, string aTitle, int aPages){
            author=aAuthor;
            title=aTitle;
            pages=aPages;
        }
        bool manyPages() {
            if(pages>100) {
                return true;
            }
            return false;
        }

};

class Movie{
    private:
        string rating; // available only within class
    public:
        string title;
        string director;

        Movie(string aTitle, string aDirector, string aRating){
            title=aTitle;
            director=aDirector;
            //rating=aRating; cannot be used when it is declared as private
            setRating(aRating);
        }
        void setRating(string aRating){
            if (rating =="Good" || rating =="Bad" || rating=="Quite good"){  // private rating parameter can have only declared values
                rating=aRating; // rating might be used in the function although is declared as private
            } else {
                rating="Default";
            }
        }

        string getRating(){   //setRating only assigned value to the rating variable, still is private with no access
            return rating;   // function returning rating obligatory
        }
};

class Rectangle {
    int width, height;
public:
    void Rectangle(int, int);  // constructor -> definition is below, out of the class; the constructor function is declared just like a regular member function,
    int area(){return width*height;};           // but with a name that matches the class name and without any return type; not even void
};                                              // Constructors never return values, they simply initialize the object


void Rectangle::Rectangle(int x, int y){
    width=x;
    height=y;
}




// CLASS INHERITANCE:
class Chef{
    public:
        void makeTofu(){
            cout<<"The chef makes tofu"<<endl;
        };
         void makeSalad(){
            cout<<"The chef makes salad"<<endl;
        };
         void makeSpecialDish(){
            cout<<"The chef makes special dish"<<endl;
        };
};

class NewChef : public Chef{
    public:
        void makePasta(){
            cout<<"The chef makes pasta"<<endl;
        }
        // overwriting function from Chef Class:
        void makeSpecialDish(){
            cout<<"The chef makes special Italian dish"<<endl;
        };
};


//ARRAYS DECLARATION:

int arr[] {10, 20, 3, 6, 40, 65};

int result =0;

int arr2D[3][2] {{1,2},
               {3,4},
               {5,6}};


// an array of characters - initialization:
char arrString[]={'H','e','l','l','o','\0'}; //a null character ('\0') has been added in order to indicate the end of the sequence
//the same as:
char arrString2[]="Hello"; // with "" the null character \0 is added automatically


//Function that lists array elements:
void printarray(int arr[], int length){
    for (int n=0; n<length; n++ ){
        cout<<arr[n]*2<<' ';
    } cout<<endl;
}

void printString(char arr[], int length){
    for (int n=0; n<length; n++){
        cout<<arr[n]<<' ';
    }cout<<endl;
}

// CONSTANT DECLARATION:
const char tab = '\t';
const char nl='\n';

//or by using preprocessor definition:
#define tab2 '\t';


void duplicate(int& a, int& b, int& c){
    a*=2;
    b*=2;
    c*=2;
}


void evenOdd (){
    int n;
    do{
    cout<<"Enter number (0 to exit): "<<endl;
    cin>>n;
    if (n==0){
        cout<<"0 was entered - the end"<<endl;
        break;
    } else if (n%2==0){
        cout<<"The number is even"<<endl;
    } else {
        cout<<"The number is odd"<<endl;
    }
    }
    while (n!=0);
}

namespace space1 {
    int a=5;
    int b=10;

}

namespace space2 {
    int a =15;
    int b=20;
    void spacefunc () {
    cout<<"Namespace space2 was called"<<endl;
    }
}














int main() {


for (int i=0; i<6; i++) {
    result+=arr[i];
    cout<<arr[i]<<endl;
}
cout<<"Sum of array: \a"<<result<<endl;


for (int i=0; i<3; i++) {
    for (int j=0; j<2; j++) {
        cout<<arr2D[i][j];
    } cout<<endl;
}


  int firstarray[] = {5, 10, 15};
  int secondarray[] = {2, 4, 6, 8, 10};
  printarray (firstarray,3);
  printarray (secondarray,5);

Book book1("xxx", "yyy", 100);

cout<<"The book "<<book1.title<<" has: "<<nl<<book1.pages<<" pages; it is more than 100: "<<book1.manyPages()<<endl;

Movie movie1("Movie Title", "Kowalski", "Good");
movie1.setRating("Very well");

cout<<"Movie: "<<movie1.title<<" has :"<<tab<< movie1.getRating()<< " rating."<<endl;

Chef chef1;
chef1.makeTofu();

NewChef newchef1;
newchef1.makeSpecialDish();
newchef1.makePasta();



Rectangle rect;
rect.set_val(5,4);
cout<<"Rectangle area: "<<rect.area()<<endl;

// LOGICAL OPERATORS:
// && -> true only if (true && true) ; if the first expression is false the second one is not verified
// || -> true if the left-hand side expression is true, the second one is never evaluated

// CASTING OPERATOR - converts a value of a given type to another type:
int i;
float j = 3.14;  // floor rounding
i=(int) j;

cout<<i<<endl;


// cin and string variable:
 // cin allows to provide only a single word;

 // string myString;
 // getline(cin, myString);


 //<sstream> header =stringsteam -> allows a string to be treated as a stream

string myS = "1234";
int myI;
stringstream(myS)>>myI;
cout<<myI<<endl;

//RANGE-BASED FOR LOOP:

string newS="Justyna";

for (char c: newS){
    cout<<'['<<c<<']';
} cout<<endl;



//GOTO STATEMENT:

int n=10;
xxx:
    cout<<n<<endl;
    n--;
    while(n>3)
        goto xxx;
cout<<"The end"<<endl;


// FUNCTIONS -> ARGUMENTS PASSED BY VALUE AND BY REFERENCE -> ampersand (&) following the parameter type;
// when a variable is passed by reference, what is passed is no longer a copy, but the variable itself;
// functions with reference parameters allows to avoid copying some expensive to copy e.g. strings arguments
// but it also allows to modify the original values - to avoid it -> parameters should be declared as constant


/*void duplicate(int& a, int& b, int& c){  MUST BE DECLARED OUT OF THE MAIN FUNCTION
    a*=2;
    b*=2;
    c*=2;
}
*/
int a=1, b=3, c=7;

duplicate(a,b,c);
cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;  //if by value ( creating instead copies of their values) - the output of the program would have been the values of x, y, and z without being modified (i.e., 1, 3, and 7).

// the INLINE specifier informs the compiler that inline expansion is preferred over the usual function call (better efficiency)
evenOdd();

// NAMESPACES - allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope
// variable declared within the scope of the namespace can be accessed outside the namespace using syntax:
// namespacename::variablename ; or 'using namespace namespaceName'
// variables might have the same name within each namespace

/* must be declared out of main function
namespace space1 {
    int a=5;
}

namespace space2 {
    void spacefunc () {
    cout<<"Namespace space2 was called"<<endl;
    }
}
*/
cout<<space1::a<<endl;
space2::spacefunc();

printString(arrString, 5);
printString(arrString2, 5);

//transforming null-terminated character sequence into string and string into null-terminated character sequences by using either of string's member functions c_str or data:
char myntcs[]="some sequence\n";
string mystring = myntcs;  // convert c-string to string
cout << mystring;          // printed as a library string
cout << mystring.c_str();  // printed as a c-string


// POINTER => The variable that stores the address of another variable, marked with '&':
int a1,c1,d1;
a1=5;
auto b1=&a1;
c1=a1;
d1=*b1;   // using asterisk with a pointer variable -> the original value of the variable which pointer refers to is visible

cout<<"a = "<<a1<<endl<<"pointer = "<<b1<<endl<<"c = "<<c1<<endl<<"with dereference operator = "<<d1<<endl;

//declaring pointer - > using asterisk:
int a2;
int * pointer2;

pointer2=&a2;   // a2 is not directly set any value in the program, it ends up with a value set indirectly through the use of pointer2
*pointer2=10;
cout<<"pointer2 = "<<pointer2<<" and a2 = "<<a2<<endl;

//DYNAMIC MEMORY ALLOCATION :
  int i1;
  int * p;  //pointer declaration
  cout << "How many numbers would you like to type? ";
  cin >> i1;
  p= new int[i1]; // dynamic memory allocation
  if (p == nullptr)
    cout << "Error: memory could not be allocated";
  else
  {
    for (int n=0; n<i1; n++)
    {
      cout << "Enter number: ";
      cin >> p[n];
    }
    cout << "You have entered: ";
    for (int n=0; n<i1; n++)
      cout << p[n] << ", ";
    delete[] p;
  }

return 0;
}
