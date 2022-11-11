#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int LogReg;
bool whileValue;

bool find(string search) {

    bool found = false;
    string line;
    int offset;
    
    ifstream readFile;
    readFile.open("Database.txt");

    if (readFile.is_open()) {

        while(!readFile.eof()) {

            getline(readFile, line);

            if ((offset = line.find(search, 0)) != string::npos) {

                found = true;
                
            }

        }

        readFile.close();
    }
    return found;
}

bool findUsername(string search) {

    bool found = false;
    string line;
    int offset;
    
    ifstream readFile;
    readFile.open("Usernames.txt");

    if (readFile.is_open()) {

        while(!readFile.eof()) {

            getline(readFile, line);

            if ((offset = line.find(search, 0)) != string::npos) {

                found = true;
                
            }

        }

        readFile.close();
    }
    return found;
}




void Registration() {

    bool hasFound = true;
    bool Strong;
    string tempUser;
    string user;
    string tempPassword;
    string Password;

    system("CLS");

    //Create Username
    while (hasFound == true) {

        cout << "Create a Username: ";
        cin >> tempUser;

        hasFound = find(tempUser);

        if (hasFound == true){
            cout << "Error- Username already exists! Please choose a different username \n";
        }
        else {
            user = tempUser;
        }
    }

    cout << "Create a Password: ";
    cin >> tempPassword;

    //Create Password
    while (Strong == false) {
        

        if (tempPassword.length() < 8) {
            system("CLS");
            cout << "Error - Password is too weak! \n";
            cout << "Create a Username: " + user << "\n";
            cout << "Create a Password: ";
            cin >> tempPassword;
        }   else {
            Password = tempPassword;
            Strong = true;
            
            
        }
    }
    ofstream userBase;
    userBase.open("Database.txt", ios::out | ios::app );
    userBase <<"Username: " << user << " / Password: " << Password << endl; 
    userBase.close();

    ofstream usernameBase;
    usernameBase.open("Usernames.txt", ios::out | ios::app);
    usernameBase << user << endl;

    system("pause");

}

void Login() {
    bool UsernameFound = false;
    bool PasswordFound = false;

    string LoginSearch;

    string tempUserLogin;
    string UserLogin;

    string LoginPassword;
    bool Login = false;

    system("CLS");

    while (Login == false){

        UsernameFound = false;

        //Username
        while (UsernameFound == false) {

            cout << "Enter your Username: ";
            cin >> tempUserLogin;

            UsernameFound = findUsername(tempUserLogin);

            if (UsernameFound == false){
                system("CLS");
                cout << "Error- Username doesn't exists! Please try again \n";
            }
            else {
                UserLogin = tempUserLogin;
            }
        }

        //Password
        cout << "Enter your password: ";
        cin >> LoginPassword;

        LoginSearch = "Username: " + UserLogin + " / Password: " + LoginPassword;
        // cout << LoginSearch;

        PasswordFound = find(LoginSearch);

        if (PasswordFound == false){
            system("CLS");
            cout << "Error - Username or Password are incorrect! Please try again \n";
        } else {
            Login = true;
            cout << "Access Provided";
            system("pause");
        }
    }


}

int main() {
    system("CLS");

    while (whileValue == false){

    cout << "1. Register \n";
    cout << "2. Login \n";
    cout << "3. Exit \n";
    cout << "Enter Option: ";
    cin >> LogReg; 

    if (LogReg == 1) {
        whileValue = true;
        Registration();

    }   else if(LogReg == 2){
        whileValue = true;
        Login();

    }   else if(LogReg == 3) {
        exit(EXIT_FAILURE);

    }   else {
        system("CLS");
        cout << "Error - Invalid Option \n";
    }
    }

    



    return 0;
};