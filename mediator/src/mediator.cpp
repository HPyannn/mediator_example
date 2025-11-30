#include "mediator.h"
#include <iostream>

MediatorClass::MediatorClass(vector<Student*> ds_sv, vector<Teacher*>ds_gv)
{
    students = ds_sv;
    teachers = ds_gv;
    for(Student* i:ds_sv)
        i->setMediator(this);
    for(Teacher* i:ds_gv)
        i->setMediator(this);
}

MediatorClass::~MediatorClass()
{
    for(Teacher* i: teachers)
        delete i;
    for(Student* i: students)
        delete i;
    teachers.clear();
    students.clear();
}

void MediatorClass::addTeacher(Teacher* teacher)
{
    teachers.push_back(teacher);
}

void MediatorClass::addStudent(Student* student)
{
    students.push_back(student);
}

void MediatorClass::sendMessage(const string& dest, const string& scr, const string& msg)
{
    for(Student* i:students)
    {
        if(i->getName() == dest)
        {
            i->receiveMessage(scr,msg);
            return;
        }
    }
    
    for(Teacher* i:teachers)
    {
        if(i->getName() == dest)
        {
            i->receiveMessage(scr,msg);
            return;
        }
    }

    cout << "Khong tim thay nguoi nhan.\n";
}

void MediatorClass::updateScore(const string& sv_name, string subj, double score)
{
    for(Student* sv:students)
        if(sv_name == sv->getName())
        {
            sv->setScore(subj,score);
            return;
        }
    cout << "Khong tim thay sinh vien.\n";
}

void MediatorClass::showStudentListToTeacher(Teacher* t)
{
    cout << "====== DANH SACH SINH VIEN ======\n";
    string subj = t->getSubject();
    for(Student* s:students)
    {
        vector<pair<string,double>> ds_score = s->getScores();
        for(pair<string,double> sco:ds_score)
            if(sco.first == subj)
            {
                cout << s->getMSSV() << " - " << s->getName() << "\t" << sco.second << '\n';
                break;
            }
    }
}

void MediatorClass::showStudentList()
{
    cout << "====== DANH SACH SINH VIEN ======\n";
    for(Student* i:students)
        cout << i->getMSSV() << " - " << i->getName() << '\n';
}

void MediatorClass::showTeacherList()
{
    cout << "====== DANH SACH GIANG VIEN ======\n";
    for(Teacher* i:teachers)
        cout << i->getName() << " - " << i->getSubject() << '\n';
}

void menu(vector<string> ve)
{
    int cnt = 0;
    for(string s:ve)
        cout << " " << ++cnt << ". " << s << '\n';
}

MediatorClass readFile(const string& filename)
{
    vector<Student*> ds_sv;
    vector<Teacher*> ds_gv;
    ifstream fin("DANHSACHLOP.TXT");
    int n,m;
    fin >> n >> m;
    while(fin.peek() == ' ' || fin.peek() == '\n') fin.ignore();
    for(int i=0;i<n;i++)
    {
        string mssv,name;
        vector<pair<string,double>> scores;
        getline(fin,name,',');
        while(fin.peek() == ' ' || fin.peek() == '\n') fin.ignore();
        fin >> mssv;
        while(fin.peek() == ' ' || fin.peek() == '\n') fin.ignore();
        for(int j=0;j<m;j++)
        {
            string subj;
            double score;
            fin >> subj >> score;
            while(fin.peek() == ' ' || fin.peek() == '\n') fin.ignore();
            scores.push_back({subj,score});
        }
        Student* s = new Student(name,mssv,scores);
        ds_sv.push_back(s);
    }
    for(int i=0;i<m;i++)
    {
        string name,subj;
        getline(fin,name,',');
        while(fin.peek() == ' ' || fin.peek() == '\n') fin.ignore();
        fin >> subj;
        while(fin.peek() == ' ' || fin.peek() == '\n') fin.ignore();
        Teacher* t = new Teacher(name,subj);
        ds_gv.push_back(t);
    }
    fin.close();
    return MediatorClass(ds_sv,ds_gv);
}
