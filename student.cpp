#include <iostream>
#include <string>

#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

// Constructor
Student::Student(string ID, string first, string last, string email, int ageNum, int daysNum[], DegreeProgram degreeName) {
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = ageNum;

	// Loop to get all days in course
	for (int i = 0; i < 3; i++) {
		this->days[i] = daysNum[i];
	}

	this->degree = degreeName;
}

// Accessors (Getters)
// Get student ID
string Student::getID() const {
	return studentID;
}

// Get student first name
string Student::getFirst() const {
	return firstName;
}

// Get student last name
string Student::getLast() const {
	return lastName;
}

// Get student email address
string Student::getEmail() const {
	return emailAddress;
}

// Get student age
int Student::getAge() const {
	return age;
}

// Get days in course
int* Student::getDays() {
	return this->days;
}

// Get student degree
DegreeProgram Student::getDegree() {
	return this->degree;
}

// Mutators (Setters)
// Set studentID
void Student::setID(string studID) {
	studentID = studID;
}

// Set student first name
void Student::setFirst(string studFirst) {
	firstName = studFirst;
}

// Set student last name
void Student::setLast(string studLast) {
	lastName = studLast;
}

// Set student email address
void Student::setEmail(string studEmail) {
	emailAddress = studEmail;
}

// Set student age
void Student::setAge(int studAge) {
	age = studAge;
}

// Set student's days in course
void Student::setDays(int courseDays[]) {
	for (int i = 0; i < 3; i++) {
		days[i] = courseDays[i];
	}
}

// Set student's degree program
void Student::setDegree(DegreeProgram studDegree) {
	this->degree = studDegree;
}

// Displays data from the class roster array.
void Student::print() {
	cout << studentID;
	cout << "\tFirst Name: " << firstName;
	cout << "\tLast Name: " << lastName;
	cout << "\tAge: " << age;
	cout << "\t daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "} ";

	// Set degree variable default value to Security
	string deg = "Security";

	// Change output depending on the degree value
	if (degree == NETWORK) {
		deg = "Network";
	}
	else if (degree == SOFTWARE) {
		deg = "Software";
	}

	cout << "Degree Program: " << deg << endl;
}