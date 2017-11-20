#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <stdexcept>

using namespace std;

void TestUserNameLength(string user_name){
    if (user_name.length() < 5){
        throw runtime_error("User name is too short");
    } else if (user_name.length() > 30){
        throw runtime_error("User name is too long");
    }
}

void TestPasswordLength(string password){
    if (password.length() < 5){
        throw runtime_error("Password is too short");
    } else if(password.length() > 30){
        throw runtime_error("Password is too long");
    }
}

void TestPasswordStrength(string user_name, string password){
    if(user_name == password){
        throw runtime_error("Password and user name can not be the same");
    }
}

int main () {

    string user_name;
    string password;
    bool finished = false;

    while(finished == false){
        try{
        cout << "Enter a user name: " << endl;
        getline(cin, user_name);
        TestUserNameLength(user_name);
        cout << "Enter a password: " << endl;
        getline(cin, password);
        TestPasswordLength(password);
        TestPasswordStrength(user_name, password);
        finished = true;

        }
        catch(runtime_error &err){
            cout << err.what();
            Sleep(3000);
            system("cls");
            //continue;
        }
    }

    if (finished){
        time_t now = time(0);
        char *dt = ctime(&now);
        cout << "Successful registration at: " << dt;
    }

    return 0;
}
