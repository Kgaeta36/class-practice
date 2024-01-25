#include <iostream>
using namespace std;
/**
Title: HW03-1.cpp
Abstract: This program will use classes to hold and manipulate school course
rosters. Author: Kimberly Gaeta Email: Kgaeta@csumb.edu Date: 2/11/2023
Estimate: 3 hours
  **/
const int MAX = 30;
class Student {
public:
  Student();
  Student(string name, int ID);
  string getName() const;
  int getID() const;
  void setName(string name);

private:
  string myName;
  int myID;
};
class Course {
public:
  Course();
  Course(string title, int number, string instructor);
  string getTitle();
  int getNumber();
  string getInstructor();
  bool add(Student s);
  bool remove(Student s);
  void printAll() const;

private:
  string myTitle;
  int myNumber;
  string myInstructor;
  Student myRoster[MAX];
  int myRosterCount = 0;
};

int main() {
  Course c1("History of Stuff", 420, "Dr. Historian");
  Student s1("Max", 8008);
  Student s2("Jessica", 6969);
  Student s3("Kat", 7738);
  Student s4("Ivan", 1776);
  c1.add(s1);
  c1.add(s2);
  c1.add(s3);
  c1.add(s4);
  c1.add(s3);
  c1.printAll();
  c1.remove(s2);
  c1.printAll();
}
Course::Course() {
  myTitle = 1;
  myNumber = 1;
  myInstructor = 1;
}
Course::Course(string title, int number, string instructor) {
  myTitle = title;
  myNumber = number;
  myInstructor = instructor;
}
string Course::getTitle() { return myTitle; }
int Course::getNumber() { return myNumber; }
string Course::getInstructor() { return myInstructor; }

bool Course::add(Student s) {
  for (int i = 0; i < MAX; i++) {
    if (s.getID() == myRoster[i].getID()) {
      cerr << "--Student already added!--\n";
      return false;
    }
  }
  myRoster[myRosterCount] = s;
  myRosterCount++;
  return true;
}
bool Course::remove(Student s) {
  for (int i = 0; i < myRosterCount; i++) {
    if (s.getID() == myRoster[i].getID()) {
      for (int k = i; k < myRosterCount; k++) {
        myRoster[k] = myRoster[k + 1];
      }
      myRosterCount--;
      return true;
    }
  }
  cerr << "--Student is not in roster!--\n";
  return false;
}
void Course::printAll() const {
  cout << "Course Title: " << myTitle << "\n";
  cout << "Course Number: " << myNumber << "\n";
  cout << "Instructor: " << myInstructor << "\n";
  cout << "Enrollment: " << myRosterCount << "\n";
  for (int i = 0; i < myRosterCount; i++) {
    cout << myRoster[i].getName() << ": " << myRoster[i].getID() << "\n";
  }
  cout << "\n";
}
Student::Student() {
  myName = 1;
  myID = 1;
}
Student::Student(string name, int ID) {
  myName = name;
  myID = ID;
}
string Student::getName() const { 
  return myName;
}
int Student::getID() const {
  return myID; 
}
void Student::setName(string name) {
  myName = name; 
}