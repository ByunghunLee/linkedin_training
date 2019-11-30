#include <cstdio>
using namespace std;

class A{
    int ia = 0;
    const char* sb = "";
    int ic = 0;
public:
    A(const int ia, const char *sb, const int ic) : ia(ia), sb(sb), ic(ic) {};
    void seta(const int a){ia = a;}
    void setb(const char* b){sb = b;}
    void setc(const int c){ic = c;}
    int geta () const {return ia;}
    const char* getb() const {return sb;}
    int getc() const {return ic;}
};

int main(){
    A a(1, "two", 3);
    printf("ia is %d, sb is %s, ic is %d\n", a.geta(), a.getb(), a.getc());
}