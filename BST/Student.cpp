#include "Student.h"
#include <iostream>

using namespace std;


Student::Student()
{}

Student::Student(int id, string m_Fname, string m_Lname, string m_grade, string m_major, double m_gpa, int m_advisor)
{
  setID(id);
  setFirstName(m_Fname);
  setLastName(m_Lname);
  setGrade(m_grade);
  setMajor(m_major);
  setGPA(m_gpa);
  setAdvisor(m_advisor);
}

Student::~Student()
{}



//setters
void Student::setID(int id){
  m_studentID = id;
}
void Student::setFirstName(string FirstName){
  m_studentFirstName = FirstName;
}
void Student::setLastName(string LastName){
  m_studentLastName = LastName;
}
void Student::setGrade(string grade){
  m_studentGrade = grade;
}
void Student::setMajor(string major){
  m_studentMajor = major;
}
void Student::setGPA(double gpa){
  m_studentGPA = gpa;
}
void Student::setAdvisor(int advisorID){
  m_advisorField = advisorID;
}

//getters
int Student::getID(){
  return m_studentID;
}
string Student::getFirstName(){
  return m_studentFirstName;
}
string Student::getLastName(){
  return m_studentLastName;
}
string Student::getGrade(){
  return m_studentGrade;
}
string Student::getMajor(){
  return m_studentMajor;
}
double Student::getGPA(){
  return m_studentGPA;
}
int Student::getAdvisor(){
  return m_advisorField;
}



string Student::displayStudent() //creates a string of information about the student to be accessed in the tree by the ID number
{
  std::string strID = std::to_string(m_studentID);
  std::string strGPA = std::to_string(m_studentGPA);
  std::string strAdvisor = std::to_string(m_advisorField);



  entry = "ID: " + strID + " | Name: " + getFirstName() + " " + getLastName() + " | Grade: " + getGrade() + " | Major: " + getMajor() + " | GPA: " + strGPA + " | Advisor ID#: " + strAdvisor;
  return entry;
}

void Student::printEntry() //primarily used for testing
{
  cout << entry << endl;
}
