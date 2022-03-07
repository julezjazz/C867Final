#include <iostream>
#include <string>
using namespace std;
#include "student.h"

string Student::getStudentId() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
int* Student::getDaysInCourses() { return this->daysInCourses; } 
DegreeProgram Student::getDegreeProgram() const { return degreeprogram; }

Student::Student(string studentIdVal, string firstNameVal, string lastNameVal, string emailAddressVal, int ageVal,
	int daysInCourses[], DegreeProgram degreeProgramVal) {
	
	studentID = studentIdVal;
	firstName = firstNameVal;
	lastName = lastNameVal;
	emailAddress = emailAddressVal;
	age = ageVal;
	for (int i = 0; i < 3; i++)
		this->daysInCourses[i] = daysInCourses[i];
	degreeprogram = degreeProgramVal;
}
void Student::setStudentId(string studId) {
	studentID = studId;
}
void Student::setFirstName(string fName) {
	firstName = fName;
}
void Student::setLastName(string lName) {
	lastName = lName;
}
void Student::setEmailAddress(string eAddress) {
	emailAddress = eAddress;
}
void Student::setAge(int studAge) {
	age = studAge;
}
void Student::setDaysInCourses(int numOfDays[]) {
	for (int i = 0; i < 3; i++)
		this->daysInCourses[i] = numOfDays[i];
}
void Student::setDegreeProgram(DegreeProgram degProgram) {
	degreeprogram = degProgram;
}

void Student::print() {
	cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName
		<< "\tAge: " << age << "\tdaysInCourse: {" << daysInCourses[0]
		<< ", " << daysInCourses[1] << ", " << daysInCourses[2] << "}"
		<< "\tDegree Program: " << degreeProgramStrings[(int)degreeprogram] << "." << endl;
}
