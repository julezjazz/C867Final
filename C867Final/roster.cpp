#include <iostream>
#include <string>
using namespace std;
#include "student.h"
#include "roster.h"


void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourseArray[3]{}; //changing days in course integers to an array, as student constructor requires an array
	daysInCourseArray[0] = daysInCourse1;
	daysInCourseArray[1] = daysInCourse2;
	daysInCourseArray[2] = daysInCourse3; 

	classRosterArray[index++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeprogram);
}

void Roster::parse(string dataRow) {
	size_t rhs = dataRow.find(",");
	string studentIdVal = dataRow.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string firstNameVal = dataRow.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string lastNameVal = dataRow.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string emailAddressVal = dataRow.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int ageVal = stoi(dataRow.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int daysInCourse1Val = stoi(dataRow.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int daysInCourse2Val = stoi(dataRow.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	int daysInCourse3Val = stoi(dataRow.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = dataRow.find(",", lhs);
	string strDegreeProgram = dataRow.substr(lhs, rhs - lhs);

	DegreeProgram degreeprogramVal = DegreeProgram::SECURITY;
	if (strDegreeProgram == "NETWORK") { degreeprogramVal = DegreeProgram::NETWORK; }
	else if (strDegreeProgram == "SOFTWARE") { degreeprogramVal = DegreeProgram::SOFTWARE; }

	add(studentIdVal, firstNameVal, lastNameVal, emailAddressVal,
		ageVal, daysInCourse1Val, daysInCourse2Val, daysInCourse3Val, degreeprogramVal);
}

void Roster::printAll() {
	for (int i = 0; i < index; i++) {
		classRosterArray[i]->print();
		}
	}

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < index; i++) {
		if (classRosterArray[i]->getStudentId() == studentID) {
				found = true;
				delete classRosterArray[i];
				classRosterArray[i] = classRosterArray[i + 1];
				classRosterArray[i + 1] = classRosterArray[i + 2];
				index--;
		}
	}
	if (found == false)
		cout << "Student with that ID could not be found." << endl;
} 

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentId() == studentID) {
			int days1 = classRosterArray[i]->getDaysInCourses()[0];
			int days2 = classRosterArray[i]->getDaysInCourses()[1];
			int days3 = classRosterArray[i]->getDaysInCourses()[2];
			int averageDaysInCourses = (days1 + days2 + days3) / 3;
			cout << "Student ID: " << classRosterArray[i]->getStudentId() << ", averages " << averageDaysInCourses
				<< " days in a course." << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		size_t spaceIndex = classRosterArray[i]->getEmailAddress().find(' ');
		size_t periodIndex = classRosterArray[i]->getEmailAddress().find('.');
		size_t atSignIndex = classRosterArray[i]->getEmailAddress().find('@');
		if (spaceIndex != string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << " - no spaces allowed." << endl;
		} else if (periodIndex == string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << " - missing a period." << endl;
		} else if (atSignIndex == string::npos) {
			cout << classRosterArray[i]->getEmailAddress() << " - missing an @ symbol." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < index; i++)
		delete classRosterArray[i];
}