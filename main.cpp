
#include "mstring.h"

int main () {
    String s1 ( "hi ");
    String s2( "there");
    String s3 = s1+s2;
    s3.print();

    s3.strcpy(s3.data.get(), s2.data.get());
    s3.print();

    std::cout << s3.strcmp(s1.data.get(), s3.data.get()) << '\n';

    s2.strcpy(s1.data.get(), s3.data.get());
    s1.print();
    s2.print();
    s3.print();

    String s4(s3);
    s4.print();
    char symbol = 'e';

    char* resus = s4.strtok(s4.data.get(), &symbol);
    std::cout << resus << '\n';
    

    return 0;
}