#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct Student {
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
	while (true) {
		char input[20];
		cin >> input;
		if (strcmp(input, "ADD") == 0) {
			addStudent(students);
		}
		else if (strcmp(input, "PRINT") == 0) {
			printStudent(students);
		}
		else if (strcmp(input, "DELETE") == 0) {
			deleteStudent(students);
		}
		else if (strcmp(input, "QUIT") == 0) {
			return 0;
        	}
	}
}
void addStudent(vector<Student*>* in) {
	Student* s = new Student();
	cout << "Please enter the student's first name:  ";
	cin >> s->firstName;
	cout << "Please enter the student's last name:  ";
	cin >> s->lastName;
	cout << "Please enter the student's ID:  ";
	cin >> s->id;
	cout << "Please enter the student's GPA:  ";
	cin >> s->gpa;
	in->push_back(s);
}
void deleteStudent(vector<Student*>* in) {
	int studentid;
	cout << "Enter the ID of a student to delete: ";
	cin >> studentid;
	for (vector<Student*>::iterator i = in->begin(); i != in->end(); i++) {
		if ((*i)->id == studentid) {
			cout << "delete";
		}
        }
}
void printStudent(vector<Student*>* in) {

}
