#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class account_query
{
private:
    int account_number;
    int db_accountno;
    char firstName[10];
    char lastName[10];
    float total_Balance;
    fstream infile;
    fstream outfile;

public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
    void default_fun();
};
void account_query::read_data()
{
    cout << "\nEnter Account Number: ";
    cin >> account_number;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Balance: ";
    cin >> total_Balance;
    cout << endl;

    int flag = 0;
    infile.open("record.txt", ios::in | ios::out);

    infile >> db_accountno >> firstName >> lastName >> total_Balance;
    while (!infile.eof())
    {
        if (db_accountno == account_number)
        {
            cout << "\tAccount is Already Created in this Account Number.... \n\n";
            cout << "\tPlease enter Unique Account Number.... \n\n";
            flag++;
            default_fun();
            break;
        }
        else
        {
            infile >> db_accountno >> firstName >> lastName >> total_Balance;
        }
    }
    if (flag == 0)
    {

        outfile.open("record.txt", ios::app);
        outfile << " " << account_number << " " << firstName << " " << lastName << " " << total_Balance << "\n";
        outfile.close();
        default_fun();
    }
}
void account_query::show_data()
{

    infile.open("record.txt", ios::in | ios::out);

    cout << "\t-----All Banking Records-----\n\n";
    infile >> account_number >> firstName >> lastName >> total_Balance;
    while (!infile.eof())
    {

        cout << "\t-->Acccout number:" << account_number << endl;
        cout << "\t-->First name:" << firstName << endl;
        cout << "\t-->Last name:" << lastName << endl;
        cout << "\t-->Total balance:" << total_Balance << "\n\n";

        infile >> account_number >> firstName >> lastName >> total_Balance;
    }
    infile.close();
    default_fun();
}
void account_query::search_rec()
{
    int n, a, token = 0;
    cout << "enter the account number to search " << endl;
    cin >> n;

    infile.open("record.txt");
    if (!infile)
    {
        cout << "file doesn't exits " << endl;
    }
    else
    {

        infile >> account_number >> firstName >> lastName >> total_Balance;
        while (!infile.eof())
        {
            if (n == account_number)
            {
                cout << "\tSearched record is Here \n\n";
                cout << "\t-->Acccout number :" << account_number << endl;
                cout << "\t-->First name :" << firstName << endl;
                cout << "\t-->Last name :" << lastName << endl;
                cout << "\t-->Total balance :" << total_Balance << endl;
                token++;
                break;
            }
            else
            {
                infile >> account_number >> firstName >> lastName >> total_Balance;
            }
        }
    }
    if (token == 0)
    {
        cout << " Record not be found! Sorry.....";
    }
    infile.close();
    default_fun();
}
void account_query::edit_rec()
{
    fstream data, data1;
    int ac, bal, n;
    string fn, ln;
    int token = 0;

    cout << "enter the account number to edit " << endl;
    cin >> n;

    data.open("record.txt", ios::in);
    if (!data)
    {
        cout << "file doesn't exits " << endl;
    }
    else
    {
        data1.open("tmpfile.txt", ios::app | ios::out);

        data >> account_number >> firstName >> lastName >> total_Balance;
        while (!data.eof())
        {
            if (n == account_number)
            {
                cout << " new acccout number:";
                cin >> ac;
                cout << " new first name:";
                cin >> fn;
                cout << " new last name:";
                cin >> ln;
                cout << " new total balance:";
                cin >> bal;
                data1 << " " << ac << " " << fn << " " << ln << " " << bal << "\n";

                cout << "Record Edited Sucessfully ...";
                token++;
            }
            else
            {
                data1 << " " << account_number << " " << firstName << " " << lastName << " " << total_Balance << "\n";
            }
            data >> account_number >> firstName >> lastName >> total_Balance;
        }
        data.close();
        data1.close();

        remove("record.txt");
        rename("tmpfile.txt", "record.txt");

        if (token == 0)
        {
            cout << "record not found ... sorry ";
        }
    }
    default_fun();
}
void account_query::delete_rec()
{

    fstream data, data1;
    int ac, bal, n;
    string fn, ln;
    int token = 0;

    cout << "enter the account number to delete record " << endl;
    cin >> n;

    data.open("record.txt", ios::in);
    if (!data)
    {
        cout << "file doesn't exits " << endl;
    }
    else
    {
        data1.open("tmpfile.txt", ios::app | ios::out);

        data >> account_number >> firstName >> lastName >> total_Balance;
        while (!data.eof())
        {
            if (n == account_number)
            {
                cout << "Record Deleted Sucessfully ...";
                token++;
            }
            else
            {
                data1 << " " << account_number << " " << firstName << " " << lastName << " " << total_Balance << "\n";
            }
            data >> account_number >> firstName >> lastName >> total_Balance;
        }
        data.close();
        data1.close();

        remove("record.txt");
        rename("tmpfile.txt", "record.txt");

        if (token == 0)
        {
            cout << "record not found ... sorry ";
        }
    }
    default_fun();
}
void account_query::default_fun()
{
def:
    int p;
    cout << "\n\t[1]MAIN MENU  [2]EXIT " << endl;
    cin >> p;
    if (p == 1)
    {
    }
    else if (p == 2)
    {
        cout << "Thank you for working with our bank record system ";
        exit(0);
    }
    else
    {
        cout << "\n\t Something went Wrong you enter wrong input..";
        goto def;
    }
}
int main()
{
    account_query A;
    int choice;
    do
    {
        cout << "\t"
             << "\n\n";
        cout << "\t"
             << "------------------------------------------" << endl;
        cout << "\t"
             << "Sr no|"
             << "\t---BANK RECORD SYSTEM---" << setw(11) << "|" << endl;
        cout << "\t"
             << "------------------------------------------|";
        cout << "\t"
             << "\n\t1"
             << "    "
             << "|\t-->Add record to file" << setw(14) << "|";
        cout << "\t"
             << "\n\t2"
             << "    "
             << "|\t-->Show record from file" << setw(11) << "|";
        cout << "\t"
             << "\n\t3"
             << "    "
             << "|\t-->Search Record from file" << setw(9) << "|";
        cout << "\t"
             << "\n\t4"
             << "    "
             << "|\t-->Update Record" << setw(19) << "|";
        cout << "\t"
             << "\n\t5"
             << "    "
             << "|\t-->Delete Record" << setw(19) << "|";
        cout << "\t"
             << "\n\t6"
             << "    "
             << "|\t-->Quit" << setw(28) << "|" << endl;
        cout << "\t"
             << "-------------------------------------------" << endl;
        cout << "\t"
             << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            A.read_data();
            break;
        case 2:
            A.show_data();
            break;
        case 3:
            A.search_rec();
            break;
        case 4:
            A.edit_rec();
            break;
        case 5:
            A.delete_rec();
            break;
        case 6:
            cout << "Thank you for working with our bank record system ";
            exit(0);
            break;
        default:
            cout << "Something Went wrong,\nPlese wait we will resolve it. \nPlese check your have chosen correct option?? ";
            exit(0);
        }
    } while (choice != 6);
    return 0;
}
