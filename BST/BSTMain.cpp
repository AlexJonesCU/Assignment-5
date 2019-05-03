#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  BST studentTree;
  BST facultyTree;


  Student S1;
  Faculty F1;


  string studentString[10]; // can change for however many students the database will hold. For trial sake, I set it to 10
  int studentOrder[10]; //^counter for only the id of the student
  //^ also used for advisor order
  int advisorIDString[10]; //saves the values of the input to use to find the references later

  string facultyString[10];
  int facultyOrder[10];

  int i = 0; //primarily for students
  int j = 0; //primarily for faculty

  int studentID;
  string studentFirstName;
  string studentLastName;
  string grade;
  string major;
  double gpa = 0.0;
  int advisorID;
  string yesOrNo = "no";
  int choice;
  int idCheck;
  string findID;
  int deleteID;
  string findFaculty;
  string lookupID;
  int changeId;
  int newID;

  int MfacultyID;
  string MfacultyFirstName;
  string MfacultyLastName;
  string Mlevel;
  string Mdepartment;
  int MstudID;

  while(choice != 14)
  {
    cout << endl;
    cout << "With this database you can: " << endl;

    cout << "1. Print all students and their information (sorted by ascending id #) [if it doesnt print the information, enter 1 again]" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << endl;
    cout << "Enter the number of the choice you wish to select: ";
    cin >> choice;

    if (choice == 1)
    {
      string line;
      ifstream recFile("RecordFile.txt"); //reads file to find student id's in ascending order
      while (getline (recFile, line))
      {
        //cout << line << endl;
        for(int m = 0; m < 10; m++)
        {
          std::string strIDOnly = std::to_string(studentOrder[m]);
          if(line == strIDOnly)
          {
            cout << "- " << studentString[m] << endl;
          }
        }
      }
      recFile.close();
    }
    else if (choice == 2)
    {
      string line;
      ifstream recFile("RecordFile.txt"); //reads file to find student id's in ascending order
      while (getline (recFile, line))
      {
        for(int m = 0; m < 10; m++)
        {
          std::string strIDOnly = std::to_string(facultyOrder[m]);
          if(line == strIDOnly)
          {
            cout << "- " << facultyString[m] << endl;
          }
        }
      }
      recFile.close();

    }

    else if (choice == 3)
    {
      cout << "What ID do you want to lookup?: " << endl;
      cin >> findID;
      string line;
      ifstream recFile2("RecordFile.txt"); //reads file to find student id's in ascending order
      while (getline (recFile2, line))
      {
        //cout << line << endl;
        for(int m = 0; m < 10; m++)
        {
          std::string strIDOnly = std::to_string(studentOrder[m]);
          if(line == strIDOnly)
          {
            if (strIDOnly == findID)
            {
              cout << "- " << studentString[m] << endl;
            }
          }
        }
      }
      recFile2.close();
    }
    else if (choice == 4)
    {
      cout << "What ID do you want to lookup?: " << endl;
      cin >> findID;
      string line;
      ifstream recFile2("RecordFile.txt"); //reads file to find student id's in ascending order
      while (getline (recFile2, line))
      {
        for(int m = 0; m < 10; m++)
        {
          std::string strIDOnly = std::to_string(facultyOrder[m]);
          if(line == strIDOnly)
          {
            if (strIDOnly == findID)
            {
              cout << "- " << facultyString[m] << endl;
            }
          }
        }

      recFile2.close();
      }
    }
    else if (choice == 5)
    {
      cout << "Enter the student ID: " << endl;
      cin >> findFaculty;

      string line;
      ifstream recFile2("RecordFile.txt"); //reads file to find student id's in ascending order
      while (getline (recFile2, line))
      {
        for(int m = 0; m < 10; m++)
        {
          std::string strIDOnly = std::to_string(studentOrder[m]);
          if(line == strIDOnly)
          {
            if (strIDOnly == findFaculty)
            {
              cout << advisorIDString[m] << endl;
              //print advisor's info using this id
            }
          }
        }
      }
      recFile2.close();

    }
    else if (choice == 6)
    {
      cout << "What is the faculty id of the staff member you want to lookup?: ";
      cin >> lookupID;

      string line;
      ifstream recFile("RecordFile.txt"); //reads file to find student id's in ascending order
      while (getline (recFile, line))
      {
        for(int m = 0; m < 10; m++)
        {
          std::string strIDOnly = std::to_string(advisorIDString[m]);
          if(line == strIDOnly)
          {
            cout << "- " << facultyString[m] << endl;
          }
        }
      }
      recFile.close();

    }
    else if (choice == 7)
    {
      cout << "What is the student ID?: ";
      cin >> studentID;
      cout << "What is the student's first name?: ";
      cin >> studentFirstName;
      cout << "What is the student's last name?: ";
      cin >> studentLastName;
      cout << "What is the student's grade level?: ";
      cin >> grade;
      cout << "What is the student's major?(use letter abbreviatio - Ex: CPSC): ";
      cin >> major;
      cout << "What is the student's GPA?: ";
      cin >> gpa;
      cout << "What is the student's advisor's ID #?: ";
      cin >> advisorID;

      S1.setID(studentID);
      S1.setFirstName(studentFirstName);
      S1.setLastName(studentLastName);
      S1.setGrade(grade);
      S1.setMajor(major);
      S1.setGPA(gpa);
      S1.setAdvisor(advisorID);

      //adds a new student by adding it to the tree and creating a string reference

      studentString[i] = S1.displayStudent();
      studentOrder[i] = studentID;
      advisorIDString[i] = advisorID; //saves the advisor id for choice 5

      studentTree.insert(studentID);
      studentTree.printTree(); //writes to file also displays tree after each input, I like this so that it shows a live update of each id into the tree
      i++;
    }
    else if (choice == 8)
    {
      if(studentTree.isEmpty())
      {
        cout << "There are no students in the database. Choose another option." << endl;
      }
      else
      {
        cout << "What is the student ID of the student you want to delete?: ";
        cin >> deleteID;
        studentTree.deleteNode(deleteID);
        cout << "Updated Tree" << endl;
        studentTree.printTree(); //writes to file also displays tree after each input, I like this so that it shows a live update of each id into the tree

        cout << "Student with id: " << deleteID << " was deleted";
      }
    }
    else if (choice == 9)
    {
      cout << "What is the faculty ID?: ";
      cin >> MfacultyID;
      cout << "What is the faculty's first name?: ";
      cin >> MfacultyFirstName;
      cout << "What is the faculty's last name?: ";
      cin >> MfacultyLastName;
      cout << "What is the faculty's level? (lecturer, assistant prof, associate prof, etc): ";
      cin >> Mlevel;
      cout << "What is the faculty's department?: ";
      cin >> Mdepartment;
      cout << "What is the faculty's advisees' ID #?: ";
      cin >> MstudID;

      F1.setID(MfacultyID);
      F1.setFirstName(MfacultyFirstName);
      F1.setLastName(MfacultyLastName);
      F1.setLevel(Mlevel);
      F1.setDepartment(Mdepartment);
      F1.setAdvisee(MstudID);

      F1.displayFaculty();
      F1.printEntry();

      facultyString[j] = F1.displayFaculty();
      facultyOrder[j] = MfacultyID;
      advisorIDString[j] = MstudID; //saves the advisor id for choice 5

      facultyTree.insert(MfacultyID);
      facultyTree.printTree(); //writes to file also displays tree after each input, I like this so that it shows a live update of each id into the tree
      j++;

    }
    else if (choice == 10)
    {
      if(facultyTree.isEmpty())
      {
        cout << "There is no faculty in the database. Choose another option." << endl;
      }
      else
      {
        cout << "What is the student ID of the student you want to delete?: ";
        cin >> deleteID;
        facultyTree.deleteNode(deleteID);
        cout << "Updated Tree" << endl;
        facultyTree.printTree(); //writes to file also displays tree after each input, I like this so that it shows a live update of each id into the tree

        cout << "Faculty with id: " << deleteID << " was deleted";
      }
    }
    else if (choice == 11)
    {
      cout << "What is the student id?: ";
      cin >> changeId;

      studentTree.deleteNode(changeId);
      studentTree.insert(changeId);

      cout << "What is the new faculty id?: ";
      cin >> newID;

      MfacultyID = newID; //replaces faculty id
    }
    else if (choice == 12)
    {
      cout << "What is the faculty id?: ";
      cin >> changeId;

      studentTree.deleteNode(changeId);
      studentTree.insert(changeId);

      cout << "What is the removed student id?: ";
      cin >> newID;

      studentID = newID;
    }
    else if (choice == 13)
    {
      // Rollback
      //uses copy constructors and saves copies up to 5 choices
      
    }
    else if (choice == 14)
    {
      cout << "Exiting." << endl;
    }
    else

      cout << "Error! Please enter a number 1-14." << endl;
    }
  }
  return 0;
}
