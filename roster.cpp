#include "roster.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

// Function to convert string to DegreeProgram type

DegreeProgram StringToDegreeProgram(const string& userString) {
	if (userString == "SECURITY") {
		return SECURITY;
	}
	else if (userString == "NETWORK") {
		return NETWORK;
	}
	else if (userString == "SOFTWARE") {
		return SOFTWARE;
	}
	else {
		return DEFAULT;
	}
}

// Constructors

Roster::Roster(const string studentData[]) {
	string userID, userFirstName, userLastName, userEmail, token;	// token is used temporarily in order to manipulate extracted strings
	int userAge, d1, d2, d3;										// d1, d2, d3 are temporary holders for indvidual days in course
	DegreeProgram userDegreeProgram;
	istringstream ss;												// stringstream used for initial extraction of data line

	currentStudentIndex = 0;										// initializes the index tracker for the add function

	for (int i = 0; i < 5; ++i) {									// array is hard coded to 5 items
		ss.clear();													// clear stringstream
		ss.str(studentData[i]);										// insert data line into stringstream
		getline(ss, userID, ',');									// insert comma separated values into variables
		getline(ss, userFirstName, ',');
		getline(ss, userLastName, ',');
		getline(ss, userEmail, ',');
		getline(ss, token, ',');									// values that to be manipulated are first inserted into temporary token variable
		userAge = stoi(token);
		getline(ss, token, ',');
		d1 = stoi(token);											// days in course extracted individually
		getline(ss, token, ',');
		d2 = stoi(token);
		getline(ss, token, ',');
		d3 = stoi(token);
		getline(ss, token, ',');
		userDegreeProgram = StringToDegreeProgram(token);			// turns string into DegreeProgram type
		add(userID, userFirstName, userLastName, userEmail, userAge, d1, d2, d3, userDegreeProgram);
	}
}

// Destructor

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];									// loops through array and clears memory
	}
}

// Accessor

const array <Student*, ROSTER_SIZE>& Roster::GetClassRosterArray() const {
	return classRosterArray;
}

void Roster::add(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	DegreeProgram degreeprogram) {
	array <int, 3> userDaysInCourse;
	userDaysInCourse = { daysInCourse1, daysInCourse2, daysInCourse3 };		// days in course converted to array type
	if (currentStudentIndex < ROSTER_SIZE) {								// check to see if index is within range before adding item at that index
		classRosterArray[currentStudentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, userDaysInCourse, degreeprogram);
		++currentStudentIndex;
	}
	else {
		cout << "Error: Unable to add a student because roster is full." << endl;	// for debugging purposes
	}
}

void Roster::remove(string studentID) {
	bool studentFound = false;
	for (int i = 0; i < currentStudentIndex; ++i) {					// loop through to currentStudentIndex in case removal has already happened
		if (classRosterArray[i]->GetStudentID() == studentID) {
			delete classRosterArray[i];
			studentFound = true;
			for (int j = i; j < currentStudentIndex - 1; ++j) {				// shifts remaining elements to fill the gap
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classRosterArray[ROSTER_SIZE - 1] = nullptr;			// sets last element to nullptr
			--currentStudentIndex;									// sets back index counter so that add function is in range again
			break;
		}
	}
	if (studentFound == false) {
		cout << "Error: student with student ID " << studentID << " could not be found for removal" << endl;
	}
}

void Roster::printAll() {											// loop through to currentStudentIndex in case removal has already happened
	for (int i = 0; i < currentStudentIndex; ++i) {
		classRosterArray[i]->Print();
		cout << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < currentStudentIndex; ++i) {					// loop through to currentStudentIndex in case removal has already happened
		if (classRosterArray[i]->GetStudentID() == studentID) {
			int d1 = classRosterArray[i]->GetDaysInCourse()[0];
			int d2 = classRosterArray[i]->GetDaysInCourse()[1];
			int d3 = classRosterArray[i]->GetDaysInCourse()[2];
			double avgDaysInCourse = (d1 + d2 + d3) / 3.0;
			cout << fixed << setprecision(1) << "Average days in course for student with ID " << studentID << ": " << avgDaysInCourse << endl;
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {											// basic email verification... doesn't cover every case
	for (int i = 0; i < currentStudentIndex; ++i) {									// loop through to currentStudentIndex in case removal has already happened
		size_t atPos = classRosterArray[i]->GetEmailAddress().find('@');	// returns the first position of @ sign. Doesn't cover case of multiple @
		size_t dotPos = classRosterArray[i]->GetEmailAddress().rfind('.');	// returns the last position of '.' to ensure there's an email domain
		size_t spacePos = classRosterArray[i]->GetEmailAddress().find(' '); // returns the first position of ' '
		if (
			atPos == string::npos || 
			dotPos == string::npos || 
			dotPos < atPos || 
			spacePos != string::npos) {		// if @ is not there OR ' ' is not there OR last '.' precedes @ OR ' ' is found at all
			cout << "Student with ID " << classRosterArray[i]->GetStudentID() << " has invalid email address: " << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in the specified program: " << endl;
	for (int i = 0; i < currentStudentIndex; ++i) {					// loop through to currentStudentIndex in case removal has already happened
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl;
}
