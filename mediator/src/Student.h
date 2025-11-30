#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <cstring>
#include "People.h"
#include "mediator.h"
using namespace std;

class Student : public People {
private:
    string name, mssv;
    vector<pair<string,double>> scores;
    vector<pair<string,string>> mailbox;

public:
    Student() : People() {}
    Student(const Student& other) : People(other.mediator), name(other.name), mssv(other.mssv), scores(other.scores), mailbox(other.mailbox) {}
    Student(const string& na, const string& ms,
            const vector<pair<string,double>>& sc) : People(nullptr), name(na), mssv(ms), scores(sc) {}
    ~Student() = default;

    void setScore(const string&, double);
    vector<pair<string,double>> getScores() const { return scores; }
    string getName() const override { return name; }
    string getMSSV() const { return mssv; }

    void viewScores();
    void viewStudentList();
    void viewTeacherList();
    void sendMessage(const string&, const string&);
    void receiveMessage(const string&, const string&);
    void viewMailbox();
};

#endif