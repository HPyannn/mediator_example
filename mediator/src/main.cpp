#include "mediator.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>

int main()
{
    MediatorClass lop_hoc = readFile("DANHSACHLOP.TXT");
    vector<Student*> ds_sv = lop_hoc.getStudents();
    vector<Teacher*> ds_gv = lop_hoc.getTeachers();

    int pos = 0;
    while(pos != 3)
    {
        system("cls");
        menu({"Sinh Vien", "Giang vien", "Thoat"});
        cout << "\nVai tro cua ban: "; cin >> pos;
        if(pos == 1)
        {
            system("cls");
            int sv = 0;
            while(sv != ds_sv.size()+1)
            {
                system("cls");
                vector<string> temp;
                for(Student* i:ds_sv)
                    temp.push_back(i->getMSSV() + " - " + i->getName());
                temp.push_back("Thoat");
                menu(temp);
                cout << "\nBan la: "; cin >> sv;
                if(sv >= 1 && sv <= ds_sv.size())
                {
                    Student* s = ds_sv[sv-1];
                    int sv_pos = 0;
                    while(sv_pos != 6)
                    {
                        system("cls");
                        cout << "Ho va ten: " << s->getName() << "\nMSSV: " << s->getMSSV() << "\n\n";
                        menu({"Xem danh sach sinh vien", "Xem danh sach giang vien", "Xem diem", "Gui tin nhan", "Xem hom thu", "Thoat"});
                        cout << "\nToi muon: "; cin >> sv_pos; cin.ignore(1);
                        if(sv_pos >= 1 && sv_pos <=5)
                        {
                            system("cls");
                            cout << "Ho va ten: " << s->getName() << "\nMSSV: " << s->getMSSV() << "\n\n";
                            if(sv_pos == 1) s->viewStudentList();
                            else if(sv_pos == 2) s->viewTeacherList();
                            else if(sv_pos == 3) s->viewScores();
                            else if(sv_pos == 4)
                            {
                                s->viewStudentList();
                                s->viewTeacherList();
                                cout << '\n';
                                string temp_name, temp_content;
                                cout << "Ten nguoi nhan: "; getline(cin,temp_name);
                                cout << "Noi dung: "; getline(cin,temp_content);
                                s->sendMessage(temp_name,temp_content);
                            }
                            else if(sv_pos == 5) s->viewMailbox();
                            cout << '\n';
                            system("pause");
                        }
                        else if(sv_pos == 6) break;
                    }
                }
                else if(sv == ds_sv.size() + 1) break;
            }
        }
        else if(pos == 2)
        {
            system("cls");
            int gv = 0;
            while(gv != ds_gv.size()+1)
            {
                system("cls");
                vector<string> temp;
                for(Teacher* i:ds_gv)
                    temp.push_back(i->getName() + " - " + i->getSubject());
                temp.push_back("Thoat");
                menu(temp);
                cout << "\nBan la: "; cin >> gv;
                if(gv >= 1 && gv <= ds_gv.size())
                {
                    Teacher* t = ds_gv[gv-1];
                    int gv_pos = 0;
                    while(gv_pos != 5)
                    {
                        system("cls");
                        cout << "Ho va ten: " << t->getName() << "\nSubject: " << t->getSubject() << "\n\n";
                        menu({"Xem danh sach sinh vien", "Chinh sua diem", "Gui tin nhan", "Xem hom thu", "Thoat"});
                        cout << "\nToi muon: "; cin >> gv_pos; cin.ignore(1);
                        if(gv_pos >= 1 && gv_pos <=4)
                        {
                            system("cls");
                            cout << "Ho va ten: " << t->getName() << "\nSubject: " << t->getSubject() << "\n\n";
                            if(gv_pos == 1) t->viewStudentList();
                            else if(gv_pos == 2)
                            {
                                t->viewStudentList();
                                string temp_name;
                                double temp_point;
                                cout << '\n';
                                cout << "Ten sinh vien can sua: "; getline(cin,temp_name);
                                cout << "Diem moi: "; cin >> temp_point;
                                t->updateScore(temp_name,temp_point);
                            }
                            else if(gv_pos == 3)
                            {
                                lop_hoc.showStudentList();
                                lop_hoc.showTeacherList();
                                cout << '\n';
                                string temp_name, temp_content;
                                cout << "Ten nguoi nhan: "; getline(cin,temp_name);
                                cout << "Noi dung: "; getline(cin,temp_content);
                                t->sendMessage(temp_name,temp_content);
                            }
                            else if(gv_pos == 4) t->viewMailbox();
                            cout << '\n';
                            system("pause");
                        }
                        else if(gv_pos == 5) break;
                    }
                }
                else if(gv == ds_gv.size() + 1) break;
            }
        }
    }
}
