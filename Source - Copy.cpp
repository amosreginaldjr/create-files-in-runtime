#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//https://stackoverflow.com/questions/64530809/saving-a-txt-file-into-a-folder-in-the-same-folder-as-the-cpp-file-in-c
//https://stackoverflow.com/questions/853805/locking-files-using-c-on-windows
//https://www.tutorialspoint.com/the-best-way-to-check-if-a-file-exists-using-standard-c-cplusplus

bool checkIfUserExists(ifstream &seqFileIn, string fileName, string pathToFolder);
int main()
{
    ifstream seqFileIn;
    ofstream seqFileOut;
    const string pathToFolder = "C:\\Users\\amosreginald\\source\\repos\\create files in runtime\\txt_files\\";

    //Assume newDataAvailable = true
    bool newDataAvailable = true;

    string firstN, lastN;
    cout << "First Name: ";
    cin >> firstN;
    cout << "Last Name: ";
    cin >> lastN;
    
    //create user file
    string fileName = firstN + lastN + ".txt";
    if (checkIfUserExists(seqFileIn, fileName, pathToFolder)/*newDataAvailable*/ == false)
    {
        ofstream USERNAME;

        cout << "File Name is " << fileName << endl;

        USERNAME.open(pathToFolder + fileName, ios::app);
        USERNAME << "File has been created " << "\n";
        USERNAME.close();
    }
    
    //amos r
	return 0;
} 

bool checkIfUserExists(ifstream &seqFileIn, string fileName, string pathToFolder)
{
    seqFileIn.open(pathToFolder + fileName);
    if (seqFileIn)
    {
        seqFileIn.close();
        return 1; //user exists
    }
    else
    {
        cout << "You already have a file, contact support for more information" << endl;
        seqFileIn.close();
        return 0; //user does not exist
    }
}



