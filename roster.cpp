#include <iostream>
#include <string>

#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

// Default Constructor
Roster::Roster() {
	this->maxArraySize = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxArraySize) {
	this->maxArraySize = maxArraySize;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [maxArraySize];
}

// Deconstructor/Destructor
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		// Delete each data in array and set the array to null.
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

// Sets the instance variables from the Student class and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int dayOne, int dayTwo, int dayThree, DegreeProgram degreeprogram) {
	// Add all days integer to an array
	int daysNum[3] = { dayOne, dayTwo, dayThree };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysNum, degreeprogram);
}

// Removes student from the roster by student ID.
// If the student ID does not exist, display that the student was not found.
void Roster::remove(string studentID) {
	bool successful = false;

	for (int i = 0; i <= lastIndex; i++) {
		// If the value matches a studentID.
		if (classRosterArray[i]->getID() == studentID) {
			successful = true;
			// Swap the value of the the studentID to the last index value.
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
			// Decrement lastIndex so that the removed studentID does not show up.
			lastIndex--;
		}
	}
	// Display that the studentID has been removed.
	if (successful) {
		cout << "Student ID: " << studentID << " removed." << endl;
	}
	// Display error if studentID is not valid.
	else {
		cout << "Student ID: " << studentID << " not found." << endl;
	}
}

// Prints a formatted list of student data by looping through the array and calling the print function for each student.
void Roster::printAll() {
	for (int i = 0; i < lastIndex + 1; i++) {
		classRosterArray[i]->print();
	}
}

// Prints a student’s average number of days in the three courses using the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
	// There are three days in course integers per student.
	int* courseDays = new int[3];
	int average = 0;

	for (int i = 0; i < lastIndex + 1; i++) {
		if (classRosterArray[i]->getID() == studentID) {
			// Set the value from the function to a variable.
			courseDays = classRosterArray[i]->getDays();
			// Divide the sum of all three days in course to get the average.
			average = (courseDays[0] + courseDays[1] + courseDays[2]) / 3;
			cout << studentID << ": " << average << endl;
		}
	}
}

// Displays all invalid email addresses.
// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; i++) {
		// Set the value from the function to a variable.
		string emailAdd = classRosterArray[i]->getEmail();
		// If the function finds a space, does not find an ('@') symbol, or does not find a ('.') symbol then the email address is invalid.
		if ((emailAdd.find(" ") != string::npos) || (emailAdd.find('@') == string::npos) || (emailAdd.find('.') == string::npos)) {
			cout << emailAdd << " is not valid" << endl;
		}
	}
}

// Prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int count = 0;

	for (int i = 0; i < lastIndex + 1; i++) {
		// Increase the count variable for all students with the given degree program.
		if (classRosterArray[i]->getDegree() == degreeProgram) {
			count++;
			cout << count << " ";
			// Display all the students with the given degree program.
			classRosterArray[i]->print();
		}
	}
}

// Parse data function to separate data from a given list.
void Roster::parseData(const string studentData) {
	// Used size_t so that there is less chances of data loss through conversion.
	// Find the first (',') symbol and set string before that to the studentID value.
	size_t rhs = studentData.find(",");
	string stuID = studentData.substr(0, rhs);

	// Find the next (',') symbol and set the string before that to the student's first name value.
	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string stuFirst = studentData.substr(lhs, rhs - lhs);

	// Find the next (',') symbol and set the string before that to the student's last name value.
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string stuLast = studentData.substr(lhs, rhs - lhs);

	// Find the next (',') symbol and set the string before that to the student's email address value.
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string stuEmail = studentData.substr(lhs, rhs - lhs);

	// Find the next (',') symbol and set the string before that to the student's age value.
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int stuAge = stoi(studentData.substr(lhs, rhs - lhs));

	// Find the next (',') symbol and set the string before that to the student's days in course value.
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dayOne = stoi(studentData.substr(lhs, rhs - lhs));

	// Find the next (',') symbol and set the string before that to the student's another days in course value.
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dayTwo = stoi(studentData.substr(lhs, rhs - lhs));

	// Find the next (',') symbol and set the string before that to the student's another days in course value.
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int dayThree = stoi(studentData.substr(lhs, rhs - lhs));

	// Find the null character and set the string before that to the student's degree program value.
	lhs = rhs + 1;
	rhs = studentData.find("\0", lhs);
	string dg = studentData.substr(lhs, rhs - lhs);

	// Set the variable value to SECURITY.
	DegreeProgram degreeType = SECURITY;
	// If the first two characters are S and O, set value to SOFTWARE.
	if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') {
		degreeType = SOFTWARE;
	}
	// If the first two characters are N and E, set value to NETWORK.
	else if (studentData.at(lhs) == 'N' && studentData.at(lhs + 1) == 'E') {
		degreeType = NETWORK;
	}
	// Add the values to array.
	add(stuID, stuFirst, stuLast, stuEmail, stuAge, dayOne, dayTwo, dayThree, degreeType);
}