# C867 - Scripting and Programming - Applications
## Class Roster

You are hired as a contractor to help a university migrate an existing student system to a new platform using C++ language. Since the application already exists, its requirements exist as well, and they are outlined in the next section. You are responsible for implementing the part of the system based on these requirements. A list of data is provided as part of these requirements. This part of the system is responsible for reading and manipulating the provided data. 

You must write a program containing two classes (i.e., Student and Roster). The program will maintain a current roster of students within a given course. Student data for the program include student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree program. This information can be found in the “studentData Table” below. The program will read a list of five students and use function calls to manipulate data (see part F4 in the requirements below). While parsing the list of data, the program should create student objects. The entire student list will be stored in one array of students called classRosterArray. Specific data-related output will be directed to the console.

![Screenshot 2024-12-12 223703](https://github.com/user-attachments/assets/48c63fbc-384b-41ef-b08a-8c616d0f688b)

The data should be input as follows:
const string studentData[] = <br>
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

#

#### A. Modify the “studentData Table” to include your personal information as the last item.

#### B. Create a C++ project in your integrated development environment (IDE) with the following files:

<ul>
  <li> degree.h
  <li> student.h and student.cpp
  <li> roster.h and roster.cpp
  <li> main.cpp*
</ul>

&nbsp;&nbsp;&nbsp; Note: There must be a total of six source code files.

#### C. Define an enumerated data type Degree Program for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

&nbsp;&nbsp;&nbsp; Note: This information should be included in the degree.h file.

#### D. For the Student class, do the following:

  1. Create the class Student in the files student.h and student.cpp, which includes each of the following variables:

  <ul>
    <li> student ID
    <li> first name
    <li> last name
    <li> email address
    <li> age
    <li> array of number of days to complete each course
    <li> degree program
  </ul>

  2. Create each of the following functions in the Student class:

  <ul>
    <li> An accessor (i.e., getter) for each instance variable from part D1
    <li> A mutator (i.e., setter) for each instance variable from part D1
    <li> All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
    <li> Constructor using al l of the input parameters provided in the table
    <li> Print() to print specific student data
  </ul>
  
#### E. Create a Roster class (roster.cpp) by doing the following:
    
  1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
  
  2. Create a student object for each student in the data table and populate classRosterArray.

     a. Parse each set of data identified in the “studentData Table.”
     
     b. Add each student object to classRosterArray.
  
  3. Define the following functions:
  
      a. public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
           int daysInCourse3, DegreeProgram degreeProgram) that sets the instance variables from part D1 and updates the roster.
     
      b. public void remove(string studentID) that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message                   indicating that the student was not found.

      c. public void printAll() that prints a complete tab-separated list of student data in the provided format:
     
        &nbsp;&nbsp;&nbsp; A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.

        &nbsp;&nbsp;&nbsp; The printAll() function should loop through al l the students in classRosterArray and call the print() function for each student.

      d. public void printAverageDaysInCourse(string studentID) that correctly prints a student’s average number of days in the three courses. The student is identified by the             studentID parameter.

      e. public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.

      &nbsp;&nbsp;&nbsp; Note: A valid email should include an at sign (' @') and period ('.') and should not include a space (' ').

      f. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
     
#### F. Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:

  1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

  2. Create an instance of the Roster class called classRoster.

  3. Add each student to classRoster.

  4. Convert the following pseudo code to complete the rest of the main() function:

      classRoster.printAll(); <br>
      classRoster.printInvalidEmails();

      //loop through classRosterArray and for each element:

      classRoster.printAverageDaysInCourse(/*current_object's student id*/);

      &nbsp;&nbsp;&nbsp; Note: For the current_object's student id, use an accessor ( i .e., getter) for the

      classRosterArray to access the student id. <br>
      classRoster.printByDegreeProgram(SOFTWARE); <br>
      classRoster.remove("A3"); <br>
      classRoster.printAll(); <br>
      classRoster.remove("A3");

      //expected: the above line should print a message saying such a student with this ID was not found.

  5. Implement the destructor to release the memory that was allocated dynamically in Roster.

       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", <br>
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", <br>
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", <br>
        "A5,[firstname],[lastname],[emailaddress],[age],[numberofdaystocomplete3courses],SOFTWARE"
