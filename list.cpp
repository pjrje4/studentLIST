#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

/*
 *Justin Iness
 *11/17/2021
 *Student List
 * C++ Programming
 */

using namespace std;
struct Student { //student struct
	char firstName[20];
	char lastName[20];
	int id;
	float gpa;
};
void addStudent(vector<Student*>*);
void printStudent(vector<Student*>*);
void deleteStudent(vector<Student*>*);

int main() {
	vector<Student*>* students = new vector<Student*>();
	while (true) { //loop
		char input[20];
		cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
		cin >> input;
		if (strcmp(input, "ADD") == 0) { //add students
			addStudent(students);
		}
		else if (strcmp(input, "PRINT") == 0) { //print students
			printStudent(students);
		}
		else if (strcmp(input, "DELETE") == 0) { //delete students
			deleteStudent(students);
		}
		else if (strcmp(input, "QUIT") == 0) { //quit program
			return 0;
        	}
	}
}
void addStudent(vector<Student*>* in) {
	Student* s = new Student(); //create new student
	cout << "Please enter the student's first name:  ";
	cin >> s->firstName;
	cout << "Please enter the student's last name:  ";
	cin >> s->lastName;
	cout << "Please enter the student's ID:  ";
	cin >> s->id;
	cout << "Please enter the student's GPA:  ";
	cin >> s->gpa;
	in->push_back(s); //pushes student to vector
}
void deleteStudent(vector<Student*>* in) {
	int studentid;
	int del = false; // have we deleted a student?
	cout << "Enter the ID of a student to delete: ";
	cin >> studentid;
	for (vector<Student*>::iterator i = in->begin(); i != in->end(); i++) { //iterate vector
		if ((*i)->id == studentid) { // if the input = the students id
			cout << "Deleting Student: ";
			cout << (*i)->firstName << endl;
			in->erase(i); // delete student
			del = true;
			break;
		}
        }
	if (!del) { //if no student found
		cout << "Couldn't find a student with that ID" << endl;
	}
}
void printStudent(vector<Student*>* in) {
	for (vector<Student*>::iterator i = in->begin(); i != in->end(); i++) { // iterate vector
		cout << (*i)->firstName << " " << (*i)->lastName << " " << (*i)->id << " " << std::setprecision(3) << (*i)->gpa << endl; // output student info
	}
}

