#include <iostream>
#include <string.h>
using namespace std;

char upper(char a){
    if ( a >= 'A' && a<= 'Z')
        return a;
    else if(a >= 'a' && a<= 'z')
        return 'A'-'a'+a;
    else
        return a;
}

int main() {
    string orgin, real_input;
    string re;
    cin>>orgin>>real_input;
    int i = 0;
    int len = orgin.length();
    for (i=0; i<len; i++){
        if (real_input.find_first_of(orgin.at(i)) == string::npos) {
            if (re.find_first_of(upper(orgin.at(i))) == string::npos)

                re.append(1, upper(orgin.at(i)));
        }
    }
    std::cout << re << std::endl;
    return 0;
}