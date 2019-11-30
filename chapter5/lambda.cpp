#include <cstdio>
#include <locale>
#include <algorithm>
using namespace std;

constexpr size_t _maxlen = 128;

class ftitle{
    char lastc;
public:
    ftitle():lastc(0){}
    char operator() (const char & c);
};

char ftitle::operator()(const char &c) {
    const char r = (lastc == ' ' || lastc == 0) ? toupper(c): tolower(c);
    lastc = c;
    return r;
}

int main(){
    char lastc = 0;
    char s[] = "big light in sky slated to appear in east";
    //transform(s, s + strnlen(s, _maxlen), s, ftitle());
    transform(s, s + strnlen(s, _maxlen), s, [&lastc](const char & c) mutable -> char{
        const char r = (lastc == ' ' || lastc == 0) ? toupper(c): tolower(c);
        lastc = c;
        return r;
    });
    puts(s);

    return 0;
}