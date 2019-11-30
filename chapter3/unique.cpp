
#include <cstdio>
#include <memory>
#include <utility>
#include "strc.h"

void message (const char * s){
    printf("\n%s\n", s);
    fflush(stdout);
}

void disp(std::unique_ptr<strc> & o){
    if(o) puts(o->value());
    else puts("null");
    fflush(stdout);
}

int main(){
    message("create unique pointer one");
    std::unique_ptr<strc> a (new strc("one"));

    message("make_unique two");
    auto b = std::make_unique<strc>("two");
    disp(a);
    disp(b);

    message("reset a to three");
    a.reset(new strc("thress"));
    disp(a);
    disp(b);

    message("move b to c");
    auto c = std::move(b);
    disp(a);
    disp(b);
    disp(c);

    strc * d = new strc("four");

    std::unique_ptr<strc> u_d (d);
    disp(a);
    disp(b);
    disp(c);
    disp(u_d);


    message("reset a");
    a.reset();
    disp(a);
    disp(b);
    disp(c);
    disp(u_d);

    message("release u_d");
    u_d.release();
    message("delete d");
    delete d;

    message("release c");
    c.release();
    disp(a);
    disp(b);
    disp(c);
    disp(u_d);

    message("end of scope");
}