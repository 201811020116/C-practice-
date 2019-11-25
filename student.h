#ifndef C___HW_STUDENT_H
#define C___HW_STUDENT_H
#include <string.h>
class student{
public:
    int age;
    char id[20];
    char *name;
    std::string home;
public:
    student();

    student( int age, const char id[], char* name,std::string home );

    student(const student &r);

    ~student();

    std::basic_string<char> get();

    void set(int ,char id[],char* name ,std::string);

    void pf();
};

#endif //C___HW_STUDENT_H
