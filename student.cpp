#include "student.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

// Constructors

Student::Student() {			// Default constructor. Should not be used, but just in case
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysInCourse = {0, 0, 0};
	degreeProgram = DEFAULT;
}

Student::Student(				// Main constructor
	string userStudentID,
	string userFirstName,
	string userLastName,
	string userEmailAddress,
	int userAge,
	array <int, 3> userDaysinCourse,
	DegreeProgram userDegreeProgram
) {
	studentID = userStudentID;
	firstName = userFirstName;
	lastName = userLastName;
	emailAddress = userEmailAddress;
	age = userAge;
	daysInCourse = userDaysinCourse;
	degreeProgram = userDegreeProgram;
}


// Destructor

Student::~Student() {			// Defined, but there's no dynamically allocated memory
}

// Accessors

string Student::GetStudentID() const{
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

const array<int, 3>& Student::GetDaysInCourse() const {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}

// Mutators

void Student::SetStudentID(string userStudentID) {
	studentID = userStudentID;
}

void Student::SetFirstName(string userFirstName) {
	firstName = userFirstName;
}

void Student::SetLastName(string userLastName) {
	lastName = userLastName;
}

void Student::SetEmailAddress(string userEmailAddress) {
	emailAddress = userEmailAddress;
}

void Student::SetAge(int userAge) {
	age = userAge;
}

void Student::SetDaysInCourse(array <int, 3> userDaysInCourse) {
	daysInCourse = userDaysInCourse;
}

void Student::SetDegreeProgam(DegreeProgram userDegreeProgram) {
	degreeProgram = userDegreeProgram;
}

// Print all info

void Student::Print() {
	cout  << GetStudentID() << "\t";
	cout << "First Name: " << GetFirstName() << "\t";
	cout << "Last Name: " << GetLastName() << "\t";
	cout << "Age: " << GetAge() << "\t";
	cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} Degree Program: ";
	if (GetDegreeProgram() == SECURITY) {
		cout << "SECURITY";
	}
	else if (GetDegreeProgram() == NETWORK) {
		cout << "NETWORK";
	}
	else if (GetDegreeProgram() == SOFTWARE) {
		cout << "SOFTWARE";
	}
	else {
		cout << "DEFAULT";
	}
	cout << endl;
}