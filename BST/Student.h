#include <iostream>

using namespace std;

class Student
{
  private:


  public:
    Student();
    Student(int id, string m_Fname, string m_Lname, string m_grade, string m_major, double m_gpa, int m_advisor);
    ~Student();


    //setters
    void setID(int id);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setGrade(string grade);
    void setMajor(string major);
    void setGPA(double gpa);
    void setAdvisor(int advisorID);

    //getters
    int getID();
    string getFirstName();
    string getLastName();
    string getGrade();
    string getMajor();
    double getGPA();
    int getAdvisor();

    string displayStudent();
    void printEntry();

    string entry;

    int m_studentID;
    string m_studentFirstName;
    string m_studentLastName;
    string m_studentGrade;
    string m_studentMajor;
    double m_studentGPA;
    int m_advisorField; //contains faculty ID of their advisor

};
