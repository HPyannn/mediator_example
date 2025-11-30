#include "Student.h"
#include "Teacher.h"
#include <iostream>

void Student::setScore(const string& subj, double score)
{
    for(pair<string,double>& i:scores)
        if(subj == i.first)
        {
            i.second = score;
            cout << "Cap nhat diem thanh cong.\n";
            return;
        }
    cout << "Khong tim thay mon hoc.\n";
}

void Student::viewScores()
{
    cout << "====== BANG DIEM ======\n";
    for(pair<string,double> sco:scores)
        cout << sco.first << ":\t" << sco.second << '\n';
}

void Student::viewStudentList()
{
    mediator->showStudentList();
}

void Student::viewTeacherList()
{
    mediator->showTeacherList();
}

void Student::sendMessage(const string& dest, const string& msg)
{
    if(dest == name) {
        cout << "Khong the gui tin nhan cho chinh minh.";
        return;
    }
    cout << "[Student] " << name << " da gui tin nhan\n";
    string temp = "[Student] " + name;
    mediator->sendMessage(dest,temp,msg);
}

void Student::receiveMessage(const string& from, const string& msg)
{
    mailbox.push_back({from, msg});
    cout << "[Student] " << name << " da nhan tin nhan\n";
}

void Student::viewMailbox()
{
    cout << "====== HOM THU ======\n";
    for(pair<string,string> mail:mailbox)
    {
        cout << "<From: " << mail.first << ">\n";
        cout << "\t" << mail.second << "\n\n";
    }
}