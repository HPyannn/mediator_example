#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_

#include "Student.h"
#include "Teacher.h"
#include <fstream>

class Mediator {
public: 
    virtual void sendMessage(const string&, const string&, const string&) = 0;
};

class Teacher;
class Student;

class MediatorClass : public Mediator {
private:
    vector<Teacher*> teachers;
    vector<Student*> students;

public:
    MediatorClass(vector<Student*>, vector<Teacher*>);
    ~MediatorClass();

    vector<Teacher*>& getTeachers() { return teachers; }
    vector<Student*>& getStudents() { return students; }

    void addTeacher(Teacher* teacher);
    void addStudent(Student* student);

    void sendMessage(const string&, const string&, const string&) override;
    void updateScore(const string&, string, double);
    void showStudentListToTeacher(Teacher*);
    void showStudentList();
    void showTeacherList();
};

void menu(vector<string>);
MediatorClass readFile(const string&);

#endif