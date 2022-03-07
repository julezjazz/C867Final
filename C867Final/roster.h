#ifndef ROSTER_H
#define ROSTER_H



class Roster {
public:
	Student* classRosterArray [5]{};

	~Roster();

	int index = 0;

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	void parse(std::string dataRow);

	void remove(std::string studentID);

	void printAll();

	void printAverageDaysInCourse(std::string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif // ROSTER_H