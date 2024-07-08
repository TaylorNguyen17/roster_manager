#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <array>

const int ROSTER_SIZE = 5;				// global variable in case the program needs to be rewritten for a different array size

class Roster {
private:
	array <Student*, ROSTER_SIZE> classRosterArray;
	int currentStudentIndex;			// this really only exists to keep track of the current index when adding items to the array, per the requirements


public:
	Roster(const string studentData[]);	// Constructor with data input in the form of an array. Unsure if default constructor is needed
	~Roster();							// Destructor

	const array <Student*, ROSTER_SIZE>& GetClassRosterArray() const;	// Accessor for classRosterArray. Pass by reference for efficiency

	void add(							// adds a new student object to the roster. Helper function. Should probably be private.
		string studentID, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		int daysInCourse1, 
		int daysInCourse2, 
		int daysInCourse3, 
		DegreeProgram degreeprogram);

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

};

#endif

