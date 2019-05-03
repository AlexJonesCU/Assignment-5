#include "Faculty.h"
#include <iostream>

using namespace std;


//very similar to Student class except changed the variable names

Faculty::Faculty()
{}

Faculty::Faculty(int m_facultyID, string m_facultyFirstName, string m_facultyLastName, string m_level, string m_department, int m_studID)
{

  setID(m_facultyID);
  setFirstName(m_facultyFirstName);
  setLastName(m_facultyLastName);
  setLevel(m_level);
  setDepartment(m_department);
  setAdvisee(m_studID);
}

Faculty::~Faculty()
{}



//setters
void Faculty::setID(int id){
  m_facultyID = id;
}
void Faculty::setFirstName(string FirstName){
  m_facultyFirstName = FirstName;
}
void Faculty::setLastName(string LastName){
  m_facultyLastName = LastName;
}
void Faculty::setLevel(string level){
  m_level = level;
}
void Faculty::setDepartment(string department){
  m_department = department;
}
void Faculty::setAdvisee(int studID){
  m_studID = studID;
}

//getters
int Faculty::getID(){
  return m_facultyID;
}
string Faculty::getFirstName(){
  return m_facultyFirstName;
}
string Faculty::getLastName(){
  return m_facultyLastName;
}
string Faculty::getLevel(){
  return m_level;
}
string Faculty::getDepartment(){
  return m_department;
}
int Faculty::getAdvisee(){
  return m_studID;
}



string Faculty::displayFaculty()
{
  std::string strID = std::to_string(m_facultyID);
  std::string strAdvisee = std::to_string(m_studID);



  entryFaculty = "ID: " + strID + " | Name: " + getFirstName() + " " + getLastName() + " | Level: " + getLevel() + " | Department: " + getDepartment() + " | Advisee ID#: " + strAdvisee;
  return entryFaculty;
}

void Faculty::printEntry()
{
  cout << entryFaculty << endl;
}
