#include <iostream>
#include <string>
#include <sstream>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Taylor,Nguyen,tngu670@wgu.edu,32,10,17,90,SOFTWARE"
	};

	cout << "Course: C867 Scripting and Programming" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010507238" << endl;
	cout << "Taylor Nguyen" << endl;

	Roster* classRoster = new Roster(studentData);

	classRoster->printAll();

	classRoster->printInvalidEmails();

	for (int i = 0; i < ROSTER_SIZE; ++i) {
		classRoster->printAverageDaysInCourse(classRoster->GetClassRosterArray()[i]->GetStudentID());
	}

	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->remove("A3");

	delete classRoster;

	return 0;
}
