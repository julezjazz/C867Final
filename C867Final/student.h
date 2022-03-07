#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"

class Student {
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourses[3];
	DegreeProgram degreeprogram;

public:
	std::string getStudentId() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmailAddress() const;
	int getAge() const;
	int* getDaysInCourses();
	DegreeProgram getDegreeProgram() const;

	void setStudentId(std::string studId);
	void setFirstName(std::string fName);
	void setLastName(std::string lName);
	void setEmailAddress(std::string eAddress);
	void setAge(int studAge);
	void setDaysInCourses(int numOfDays[]);
	void setDegreeProgram(DegreeProgram degProgram);

	Student();
	Student(
		std::string studentIdVal, std::string firstNameVal, std::string lastNameVal, std::string emailAddressVal, int ageVal,
		int daysInCourses[], DegreeProgram degreeProgramVal
	); 
	
	void print();

};
#endif // STUDENT_H


