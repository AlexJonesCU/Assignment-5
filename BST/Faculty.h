#include <iostream>


using namespace std;

class Faculty
{

  public:
    Faculty();
    Faculty(int m_facultyID, string m_facultyFirstName, string m_facultyLastName, string m_level, string m_department, int m_studID);
    ~Faculty();


    //setters
    void setID(int facultyID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setLevel(string level);
    void setDepartment(string department);
    void setAdvisee(int advisorID);

    //getters
    int getID();
    string getFirstName();
    string getLastName();
    string getLevel();
    string getDepartment();
    int getAdvisee();

    string displayFaculty();
    void printEntry();

    string entryFaculty;

    int m_facultyID;
    string m_facultyFirstName;
    string m_facultyLastName;
    string m_level;
    string m_department;
    int m_studID;

};
