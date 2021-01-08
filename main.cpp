#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <limits>


using namespace std;
int locker(char a = 'B');
int unlocker();
int show();
string password = "1234";
string getpass();
void display_status();


int main(){

    display_status();

    string command;
    string pass;
    int i = 0;
    while(pass != password && i < 3){
        cout<<endl;
        cout <<" TYPE THE PASSWORD :";
        pass = getpass();
        cout<<endl;

        if(pass != password){
            cout<<endl;
            cout<< "ERROR: INVALID PASSWORD!"<<endl;
            i++;
            cout<<endl;
        }
        if(i == 3){
            cout << "================================================================" << endl;
            cout << endl;
            cout << "MULTIPLE FAILED ATTEMPTS!"<<endl;
            cout<<endl;
            cout << "TERMINATING THE PROGRAM!"<<endl;
            cout<<endl;
            locker('A');
            getch();
            return 0;
        }

    }

    if(pass == password){

        system("clear");
        display_status();
        cout << "ACCESS GRANTED!" << endl;

            while(true){
                cout<<endl;
                cout<<endl;
                cout <<  " press 1: to open folder. "<< endl;
                cout <<  " press 2: to unlock and show the folder. " << endl;
                cout <<  " press 3: to lock and hide the folder. " << endl;
                cout <<  " press 0: to close the program. " << endl;

                cout<<endl;
                cout << "CONSOLE :" <<  " Enter your command : ";
                cin >> command;

                    if(command == "1"){
                        cout<<endl;
                        system("clear");
                        system("IF exist Secret_Folder.Locked ( start Secret_Folder.Locked && echo Secret_Folder.Locked OPENED.) ELSE ( IF exist Secret_Folder ( start Secret_Folder && echo OPERATION: Secret_Folder OPENED.) ELSE (echo ERROR: NO FOLDER DETECTED, nothing to open... ) )");
                    }
                    else if(command == "2"){
                        unlocker();
                    }
                    else if(command == "3"){
                        locker();
                    }
                    else if(command == "0"){
                        cout<<endl;
                        system("clear");

                        cout <<  " Terminating program..."<<endl;
                        locker('A');
                        break;
                    }
                    else{
                        system("clear");
                        cout<<endl;

                        cout<< "ERROR:" <<  " INVALID COMMAND!!!" <<endl;
                        cout<<endl;
                    }
                display_status();
                cout<<endl;
            }// while
        }


        getch();
        return 0;
}




int locker(char a){

if(a == 'A'){
  system("IF exist Secret_Folder ( ren Secret_Folder Secret_Folder.Locked && attrib +h +s Secret_Folder.Locked && echo Locking folder before closing the program...) ELSE ( IF exist Secret_Folder.Locked ( echo Locking folder before closing the program...) ELSE ( echo ERROR: NO FOLDER DETECTED, nothing to lock...) )");
}
else{
    system("clear");
    system("IF exist Secret_Folder ( ren Secret_Folder Secret_Folder.Locked && attrib +h +s Secret_Folder.Locked && echo OPERATION: FOLDER LOCKED.) ELSE ( IF exist Secret_Folder.Locked ( echo OPERATION: FOLDER ALREADY LOCKED!) ELSE ( echo ERROR: NO FOLDER DETECTED, nothing to lock...) )");
}
return 0;
}


int unlocker(){

cout<<endl;
system("clear");
system("IF exist Secret_Folder.Locked ( attrib -h -s Secret_Folder.Locked && ren Secret_Folder.Locked Secret_Folder && echo OPERATION: FOLDER UNLOCKED.) ELSE ( IF exist Secret_Folder ( echo OPERATION: FOLDER ALREADY UNLOCKED!) ELSE (echo ERROR: NO FOLDER DETECTED, nothing to unlock... ) )");


return 0;
}

    string getpass(){
    string pass = "";
    char ch;
    ch = _getch();

    while(ch != 13){

        if(ch != 8){
            pass.push_back(ch);
            cout << "*";

        }
    else if(pass.length() > 0){

        pass.pop_back();
        cout << "\b \b";

    }

    ch = _getch();
}


return pass;
}

void display_status(){
    system("IF exist Secret_Folder.Locked ( echo STATUS: Secret_Folder.Locked detected) ELSE (IF exist Secret_Folder (echo STATUS: Secret_Folder detected) ELSE (echo STATUS: NO FOLDER DETECTED, place this program to the same directory of a folder that has a name of Secret_Folder.) )");
    cout<<endl;
}
