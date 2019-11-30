#include <cstdio>
using namespace std;

class c1 {
    int _value = 0;
    c1();

public:
    explicit c1(const int & value) : _value(value){}
    void setvalue(const int & value){_value = value;}
    int getvalue() const {return _value;}
};

void func (const c1 & o){
    printf ("value is %d\n", o.getvalue());
}

int main (){
    //c1 o = 'x'; // implicit
    c1 o('x'); // explicit
    printf ("value is %d\n", o.getvalue());
    //func('x');// implicit
    func(c1('x'));// explicit
    return 0;
}