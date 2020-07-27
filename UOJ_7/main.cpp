#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
using namespace std;

int main() {

    freopen("example_in.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int m,n,k,t;
    // input
    cin>>m;
    Course** course = new Course* [m];
    for (int i = 0; i < m; ++i) {
        string subject, tname;
        cin>>n>>subject>>tname;
        course[i] = new Course(n,subject);
        course[i]->addTeacher(tname);
        for (int j = 0; j < n; ++j) {
            string sname,sinfo;
            int score;
            cin>>sname>>sinfo>>score;
            course[i]->addStudent(sname, score, sinfo);
        }
    }

    // query student
    cout<<"========================================"<<endl;
    cin>>k;
    for (int i = 0; i < k; ++i) {
        // for each query
        string sname, subject;
        cin>>sname>>subject;
        for (int j = 0; j < m; ++j) {
            if (course[j]->getSubject()==subject){
                // find correct course
                Student* student = course[j]->getStudent(sname);
                if (student!=nullptr){
                    cout<<student->getInfo()<<endl;
                } else{
                    cout<<"student not exist"<<endl;
                }
                break;
            }
        }
    }
    cout<<"----------------------------------------"<<endl;
    // query teacher
    cin>>t;
    for (int i = 0; i < t; ++i) {
        // for each query
        string subject;
        cin>>subject;
        cout<<subject<<":";
        for (int j = 0; j < m; ++j) {
            if (course[j]->getSubject()==subject){
                // find correct course
                Teacher* teacher = course[j]->getTeacher();
                if (teacher!= nullptr){
                    cout<<" "<<teacher->getName()<<endl;
                } else{
                    cout<<"teacher not exist"<<endl;
                }
                break;
            }
        }
    }
    cout<<"========================================"<<endl;
    for (int i = 0; i < m; ++i) {
        delete course[i];
    }
    delete [] course;

    return 0;
}