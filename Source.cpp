#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class CreateNewUserFile;

//https://stackoverflow.com/questions/64530809/saving-a-txt-file-into-a-folder-in-the-same-folder-as-the-cpp-file-in-c
//https://stackoverflow.com/questions/853805/locking-files-using-c-on-windows
//https://www.tutorialspoint.com/the-best-way-to-check-if-a-file-exists-using-standard-c-cplusplus

class CreateNewUserFile
{
private:
    string first_name;
    string last_name;
    string full_file_name = first_name + last_name + ".txt";
    ifstream seqFileIn;
    ofstream seqFileOut;
    string path_to_folder;// = "C:\\Users\\amosj\\source\\repos\\Create files in runtime\\txt_files\\";

public:
    void set_first_name(string fn);
    string get_first_name();
    void set_last_name(string ln);
    string get_last_name();
    bool user_file_exists();
    void set_path_to_folder(string ptf);
    string get_path_to_folder();
    void create_new_file();
    string get_file_name();
    string get_file_path();

    bool check_for_specific_user_file();
};

void CreateNewUserFile::set_first_name(string fn) { first_name = fn; }
string CreateNewUserFile::get_first_name() { return first_name; }
void CreateNewUserFile::set_last_name(string ln) { last_name = ln; }
string CreateNewUserFile::get_last_name() { return last_name; }
string CreateNewUserFile::get_file_name() { return first_name + last_name + ".txt"; }
string CreateNewUserFile::get_file_path() { return path_to_folder; }

void CreateNewUserFile::set_path_to_folder(string ptf)
{
    /*//make some automation so that if the users input doesnt have \\ you turn their \ into \\*/
    this->path_to_folder = ptf;
}

string CreateNewUserFile::get_path_to_folder()
{
    return path_to_folder;
}

bool CreateNewUserFile::check_for_specific_user_file()
{//LEFT HERE
    fstream check;
    check.open(get_file_path() + get_file_name());
    if (check) return 1;
}

bool CreateNewUserFile::user_file_exists()
{
    //seqFileIn.open(path_to_folder + full_file_name);

    //LEFT HERE

    if (seqFileIn)
    {
        cout << "true\n";
        seqFileIn.close();
        return 1; //user exists
    }
    else
    {
        create_new_file();
        cout << "You already have a file, contact support for more information" << endl;
        seqFileIn.close();
        return 0; //user does not exist
    }
}

void CreateNewUserFile::create_new_file() //not finished
{
    ofstream send_to_file;
    send_to_file.open(get_file_path() + get_file_name(), ios::app);
    //send_to_file << "Written Inside File" << endl;
    send_to_file.close();
}


int main()
{
    CreateNewUserFile cnuf;

    cnuf.set_first_name("Amos");
    cnuf.set_last_name("Reginald");

    //cnuf.user_file_exists();

    cnuf.set_path_to_folder("C:\\Users\\amosj\\source\\repos\\Create files in runtime\\txt_files\\");

   // cout << cnuf.get_file_name() << endl;
    //cout << cnuf.get_file_path() << endl;
    //cnuf.create_new_file();
    cout << cnuf.check_for_specific_user_file() << endl;

   

    //amos r
    return 0;
}