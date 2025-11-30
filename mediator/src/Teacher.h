#ifndef _TEACHER_H_
#define _TEACHER_H_

#include <vector>
#include "People.h"
#include "mediator.h"
using namespace std;

class Student;

class Teacher : public People {
private:
    string name, subject;
    vector<pair<string,string>> mailbox;

public:
    Teacher() : People() {}
    Teacher(const Teacher& other) : People(other.mediator), name(other.name), subject(other.subject), mailbox(other.mailbox) {}
    Teacher(const string& na, const string& su) : People(nullptr), name(na), subject(su) {}
    ~Teacher() = default;

    string getName() const override { return name; }
    string getSubject() const { return subject; }

    void updateScore(const string&, double);
    void viewStudentList();
    void sendMessage(const string&, const string&);
    void receiveMessage(const string&, const string&);
    void viewMailbox();
};

#endif