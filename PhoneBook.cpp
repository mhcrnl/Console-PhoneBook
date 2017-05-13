#include <iostream> 
#include <fstream> 
#include <string> 
#include <stdlib.h>

using namespace std;

//Function Prototype
void Show();
void Add();
void Leave();




int main() {



        //Choice means the user will pick out a option
        string choice;

        //Here, are the options
        cout << "*****************************************************************************" << endl;
        cout << "What do you want to do?" << endl;
        cout << "A: Show all the contact(s)" << endl;
        cout << "B: Add new contact" << endl;
        cout << "C: Close Program" << endl;
        cout << "*****************************************************************************" << endl;

        //The user decides what they want to d
        cin >> choice;

        //If the user picks A or a
        if ( choice == "A" || choice == "a" ) {
                Show();
        }

        //If the user picks B or b
        else if ( choice == "B" || choice == "b" ) {
                Add();
        }

        //If the user picks C or c
        else if ( choice == "C" || choice == "c" ) {
                Leave();

        }





        return 0;
}

//This function will show the phone book to the user
void Show() {

        ifstream inFile;
        inFile.open( "PhoneBook.txt" );
        string sHold, Again;
        if ( inFile.good() ) {
                //The two columns
                cout << "Name(s)         Phone Numbers" << endl;


        }

        else if ( inFile.fail() ) {
                cout << "Error" << endl;

        }

        while ( getline( inFile, sHold ) ) {

                cout << sHold << endl;

        } // end while

        //The file pointer is now at the end of the file. 
        inFile.clear(); //Clear the flag
        inFile.seekg( 0, ios::beg ); // Back to the beginning of the file. 
        cout << endl << endl; //some spacing for clarity

        //Close the file	
        inFile.close();


        cout << "Do you want to show all the contact(s) again?(Y/N)" << endl;
        cin >> Again;

        if ( Again == "Y" ) {
                Show();

        }

        else if ( Again == "N" ) {
                cout << "Do you want to go to the menu?(Y/N)" << endl;
                cin >> Again;
                if ( Again == "N" ) {
                        exit( 0 );

                }
                else if ( Again == "Y" ) {
                        main();
                }

        }

}











//Add contacts to the phone book
void Add() {



                string sDataToWrite, FName, LName, Number, Again;
                fstream myFileStream;


                myFileStream.open( "PhoneBook.txt", ios::out | ios::app );
                cin.ignore( 256, '\n' ); //This line tells the computer to ignore any junk left in the buffer, without it, the getline would only read junk and skip over the user's input

                cout << "Enter the first name" << endl;
                cin >> FName;

                myFileStream << FName << " ";
                cout << "Enter the Last name" << endl;
                cin >> LName;

                myFileStream << LName << " " << " ";
                cout << "Enter the Phone Number" << endl;
                cin >> Number;

                myFileStream << Number << endl;


                getline( cin, sDataToWrite ); // We want the entire line, not just the first word

                myFileStream << sDataToWrite; //Write the data to the file
                myFileStream.close(); //Close the file for writing


                //Reopen the file for reading
                myFileStream.open( "PhoneBook.txt" );
                myFileStream.close(); //Close the filestream, program over.	

                cout << "Do you want to add another contact?(Y/N)" << endl;
                cin >> Again;

                if ( Again == "Y" ) {
                        Add();

                }

                else if ( Again == "N" ) {
                        cout << "Do you want to go to the menu?(Y/N)" << endl;
                        cin >> Again;
                        if ( Again == "N" ) {
                                exit( 0 );

                        }
                        else if ( Again == "Y" ) {
                                main();
                        }

                }

}
                //If the phone book quits
                void Leave() {
                        string Leave;
                        cout << "Are you sure you want to exit the program?(Y/N)" << endl;
                        cin >> Leave;

                        if ( Leave == "Y" ) {
                                exit( 0 );


                        }

                        else if ( Leave == "N" ) {
                                main();


                        }

                        else if ( Leave != "N" || Leave != "Y" ) {
                                cout << "Try again" << endl;
                                main();



                        }



                }
