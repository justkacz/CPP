//small program that identifies if user is logged or not


#include <iostream>
#include <fstream> //Input/output stream class to operate on files
#include <string>


using namespace std;

bool isLogged()
{
    string username, password, un, pw;

    cout<<"Enter username: "<<endl;
    cin>>username;
    cout<<"Enter password: "<<endl;
    cin>>password;

    ifstream read(username+".txt");
    getline(read,un);
    getline(read,pw);

    if(un==username && pw==password){
        return true;
    } else {
        return false;
    }

}

int main() {
    int choice;
    cout<<"1: Register\n2: Login\nYour choice: "<<endl;
    cin>>choice;

    if (choice==1){

        string username, password;
        cout<<"Enter username: "<<endl; cin>>username;
        cout<<"Enter password: "<<endl; cin>>password;

        ofstream file;
        file.open(username+".txt");
        file<<username<<endl<<password;
        file.close();

        main();
    }
    else if (choice ==2){
        bool status = isLogged();

        if(!status){ //status=False
            cout<<"Login failed"<<endl;
            system("Pause");
            return 0;
        }
        else {
            cout<<"Successfully logged in"<<endl;
            system("Pause");
            return 1;
        }
    }

}
