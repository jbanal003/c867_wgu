#include <iostream>
#include <string>

#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
	cout << "Course Title: C687 - Scripting and Programming" << endl;
	cout << "Programming Language used: C++" << endl;
	cout << "WGU Student ID: StudentID" << endl;
	cout << "Name: Student Name" << endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jane,Doe,jane.doe@gmail.com,27,40,45,50,SOFTWARE"
	};

	int studentNums = 5;

	// Create roster object (from the roster construction) then reference
	Roster* classRoster = new Roster(studentNums);

	// Parse data from the class roster array then add each student to class roster.
	for (int i = 0; i < studentNums; i++) {
		classRoster->parseData(studentData[i]);
	}
	cout << endl;

	// Displays all data from the class roster array.
	cout << "*****DISPLAY ALL STUDENTS*****" << endl;
	classRoster->printAll();
	cout << endl;

	// Displays all invalid emails from the class roster array.
	cout << "*****INVALID EMAILS*****" << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	// Loop through the ClassRosterArray and display average of days in course per student ID.
	cout << "*****AVERAGE DAYS IN COURSE*****" << endl;
	for (int i = 0; i < studentNums; i++) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getID());
	}
	cout << endl;

	// Display all students in the given degree program.
	cout << "*****SOFTWARE DEGREE PROGRAM*****" << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	// Remove studentID A3 from class roster array
	cout << "*****REMOVING A3*****" << endl;
	classRoster->remove("A3");
	cout << endl;

	// Display classRosterArray after removing student A3. 
	cout << "*****PRINTING ALL*****" << endl;
	classRoster->printAll();
	cout << endl;

	// Remove studentID A3 again and output an error.
	cout << "*****REMOVING A3 AGAIN*****" << endl;
	classRoster->remove("A3");

	return 0;
}