
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h" // ClientData class definition
using namespace std;
int enterChoice();
void createTextFile( fstream& ):
void updateRecord( fstream& );
void newRecord( fstream& );
void deleteRecord( fstream& );
void outputLine( ostream&, const C1ientData & );
int getAccount( const char * const );
enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };
int main()
{
    //open file for reading and writing
    fstream inOutCredit( "credit.dat", ios::in | ios::out | ios::binary );
    // exit program if fstream cannot open file
    if ( !inOutCredit )
    {
        cerr << "File could not be opened." << endl;
        exit (1);
    } // end if
    int choice; // store user choice
    // enable user to specify action
    while ( ( choice = enterChoice() ) != END )
    {
        switch ( choice )
        {
            case PRINT: // create text file from record file
                createTextFile( inOutCredit );
                break;
            case UPDATE: // update record
                updateRecord( inOutCredit );
                break;
            case NEW: // create record
                newRecord( inOutCredit );
                break;
            case DELETE: // delete existing record
                deleteRecord( inOutCredit );
                break;
            default: // display error if user does not select valid choice
                cerr << "Incorrect choice" << end1;
                break;
        }// end switch
        inOutCredit.clear(); // reset end-of-file indicator
    } // end while
} // end main
// enable user to input menu choice
int enterChoice()
// display available options
{
cout << "InEnter your choice" << endl;
<< "'1 - store a formatted text file of accounts" << endl
<< "    called \"print.txt\"| for printing" << endl;
<< "'2 - update an account" << endl;
<< "3 - add a new account" << endl;
<< "4 - delete an account" << endl;
<< "5 - end program\n? ";
int menuChoice;
cin >> menuChoice; // input menu selection from user
return menuChoice;
// end function enterChoice
}
// create formatted text file for printing
void createTextFile( fstream &readFromFile )
{
    // create text file
    ofstream outPrintFile( "print.txt", ios::out );
    // exit program if ofstream cannot create file
    if ( !outPrintFile )
    {
        cerr << "File could not be created." << end1;
        exit( 1);
    }
    // end if
    outPrintFile << 1eft << setw( 10 ) << "Account" << setw( 16 )
    << "Last Name" << setw( 11 ) << "First Name" << right
    << setw( 10 ) << "Balance" << end1;
    set file-position pointer to beginning of readFromFile
    readFromFile.seekg( 0);
    // read first record from record file
    ClientData client;
    readFromFile.read( reinterpret_cast< char * >( &client),
    sizeof( ClientData ) );
    while ( !readFromFile.eof() )
    {
        // write single record to text file
        if ( client.getAccountNumber() !=0 ) // skip empty records
        outputLine( outPrintFile, client );
        // read next record from record file
        readFromFile.read( reinterpret_cast char * >( &client),
        sizeof(C1ientData ) );
        // end while
    }
}

