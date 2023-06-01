#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int roll;
    char name[30];
    float marks;
    int attendence;
    int achivement;
    int mock_practical;
    int x, y;

public:
    student()
    {
    }
    void getData();
    void displayData();
    int accesment();
};

int student::accesment()
{

    int obtain;
    int total = 30 + 100 + 25 + 25;

    obtain = (attendence + marks + achivement + mock_practical) * 25;

    x = obtain / total;

    return x;
}

void student ::getData()
{

    cout << "\nEnter Roll No. :: ";
    cin >> roll;
    cin.ignore();
    cout << "\nEnter Name :: ";
    cin.getline(name, 30);
    cout << "\nEnter unit test Marks out of 30 :: ";
    cin >> marks;
    cout << "\nEnter attendence out of 100:: ";
    cin >> attendence;
    cout << "\nEnter achivement (25/0):: ";
    cin >> achivement;
    cout << "\nEnter mock practical marks out of 25 :: ";
    cin >> mock_practical;

    accesment();
}

void student ::displayData()
{
    cout << "\nRoll No. :: " << roll << endl;
    cout << "\nName :: " << name << endl;
    cout << "\nMarks :: " << marks << endl;
    cout << "\nAttendence :: " << attendence << endl;
    cout << "\nAchivement :: " << achivement << endl;
    cout << "\nmock practical :: " << mock_practical << endl;
    cout << "\nAccesment :: " << x << endl;
}

int main()
{
    student s[30];
    fstream file;
    int i;

    file.open("C:\\Users\\Tejas\\Desktop\\semester 4\\miniproject\\file.docx", ios ::out);
    cout << "Writing Student information to the file :- " << endl;
    cout << "Enter students Details to the File :- " << endl;

    for (i = 0; i < 1; i++)
    {
        s[i].getData();
        // write the object to a file
        file.write((char *)&s[i], sizeof(s[i]));
    }

    file.close();

    file.open("C:\\Users\\Tejas\\Desktop\\semester 4\\miniproject\\file.docx", ios ::in);
    cout << "Reading Student information to the file :- " << endl;

    for (i = 0; i < 1; i++)
    {

        file.read((char *)&s[i], sizeof(s[i]));
        s[i].displayData();
    }

    file.close();

    return 0;
}

