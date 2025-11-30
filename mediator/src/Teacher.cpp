#include "Teacher.h"
#include <iostream>

void Teacher::updateScore(const string& sv, double score)
{
    mediator->updateScore(sv,subject,score);
}

void Teacher::viewStudentList()
{
    mediator->showStudentListToTeacher(this);
}

void Teacher::sendMessage(const string& dest, const string& msg)
{
    if(dest == name) {
        cout << "Khong the gui tin nhan cho chinh minh.";
        return;
    }
    cout << "[Teacher] " << name << " da gui tin nhan\n";
    string temp = "[Teacher] " + name;
    mediator->sendMessage(dest,temp,msg);
}

void Teacher::receiveMessage(const string& from, const string& msg)
{
    mailbox.push_back({from, msg});
    cout << "[Teacher] " << name << " da nhan tin nhan\n";
}

void Teacher::viewMailbox()
{
    cout << "====== HOM THU ======\n";
    for(pair<string,string> mail:mailbox)
    {
        cout << "<From: " << mail.first << ">\n";
        cout << "\t" << mail.second << "\n\n";
    }
}