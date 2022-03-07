#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;

int main() {

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001547030" << endl;
	cout << "Name: Julez Hudson" << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Julez,Hudson,jhud158@wgu.edu,31,34,4,18,SOFTWARE"
	};

	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}

	cout << "Printing Software Students:" << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	
	classRoster.remove("A3");

	cout << "Student A3 Removed" << endl;

	classRoster.printAll();

	classRoster.remove("A3");

	return 0;
}


