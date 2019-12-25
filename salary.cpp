#include <iostream>
#include <cstring>
using  namespace std;

class staff{
protected:
    char * name;
    char * id;
public:
    staff(const char*, char *);
    virtual ~staff();
    char *getname();
    char *getid();
    virtual char getsalary();
    virtual void print();
};
class manager:public staff{
private:
    float salary2;
public:
    manager(const char*,const char *,float );
    virtual void print();
    virtual char getsalary();
};

staff::staff(const char *na, char *id) {
    if(name != NULL){
        name = new char[strlen(reinterpret_cast<const char *>(name)) + 1];
        strcpy(reinterpret_cast<char *>(name), na);
    }
    if(id != NULL){
        id = new char[strlen(reinterpret_cast<const char *>(id)) + 1];
        strcpy(reinterpret_cast<char *>(id), id);
    }
}
staff::~staff() {
    delete []name;
    delete []id;
}
char* staff::getid() {
    return id;
}
char* staff::getname() {
    return name;
}
char staff::getsalary() {
    return 0.0;
}
void staff::print() {
    cout<<"a staff :"<<endl;
}
manager::manager(const char *, const char *, float s):staff(name,id){
 salary2=s;
}

void manager::print() {
    cout<<"a staff :"<<endl;
}
char manager::getsalary() {
    return 0.0;
}


int main(){
    staff *p;
    manager m("lixialian","20m18110m20m116",666);
    p=&m;
    p->print();
    cout<<"salary is:"<<p->getsalary()<<endl;
    cout<<"salary is:"<<m.getsalary()<<endl;
    return 0;

}