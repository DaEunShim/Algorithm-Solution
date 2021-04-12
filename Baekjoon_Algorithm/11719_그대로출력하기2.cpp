#include <iostream>

using namespace std;

int main(void){
    char c;
    while(true){
        c = getchar();
        if(c == -1) break;
        putchar(c);
    }
    return 0;
}
