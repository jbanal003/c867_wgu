#pragma once

#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {
public:
	int maxArraySize;
	int lastIndex = -1;
	int numStudents = 5;

	Roster();
	Roster(int maxArraySize);
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void parseData(const string studentData);
	Student** classRosterArray;
};
#endif