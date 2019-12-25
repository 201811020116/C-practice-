#include <iostream>
#include <cstring>
using namespace std;

class array
{
    char *str;
    int len;
public:
    array(char *s);
    char &operator[](int t);
    void display();
};

array::array(char *s){
    str =new char[strlen(s)+1];
    strcpy(str,s);
    len=strlen(s);
}
void array::display() {
    cout<<str;
}

char&array::operator[](int t) {
    if(t<0||t>len-1) {
        cout << "����Խ��" << endl;
        exit(1);
    }
    else
        return *(str+t);
}


int main(){
    array m("this is a object.");
    m.display();
    cout<<endl<<"�������ĸΪ��"<<m.operator[](5)<<endl;
    cout<<"���ĸ���ĸΪ��"<<m.operator[](4)<<endl;
    return 0;
}



