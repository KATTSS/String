//#include <iostream>
#include "mstring.h"

int main () {
    String s1 ( "hi ");
    String s2( "there");
    String s3 = s1+s2;
    s3.print();
    
    //std::cout << s1+s2;

    return 0;
}