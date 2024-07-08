#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <array>
#include "degree.h"
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	array<int, 3> daysInCourse;					// Array of number of days left to complete
	DegreeProgram degreeProgram;

public:
	// Constructors
	Student();
	Student(
		string userStudentID,
		string userFirstName,
		string userSastName,
		string userEmailAddress,
		int userAge,
		array <int, 3> userDaysinCourse,
		DegreeProgram userDegreeProgram);

	// Destructor
	~Student();									// Pretty sure it's unnecessary. All data members are on the stack.

	// Accessors
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	const array<int, 3>& GetDaysInCourse() const;	// Directly returns the reference to the array
	DegreeProgram GetDegreeProgram() const;

	// Mutators
	void SetStudentID(string userStudentID);
	void SetFirstName(string userFirstName);
	void SetLastName(string userLastName);
	void SetEmailAddress(string userEmailAddress);
	void SetAge(int userAge);
	void SetDaysInCourse(array <int, 3> userDaysInCourse);
	void SetDegreeProgam(DegreeProgram userDegreeProgram);

	// Print
	void Print();
};

#endif

