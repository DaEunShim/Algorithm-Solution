#include <iostream>
#include <string>

using namespace std;

int main(void){
    char c, temp;
    int cnt = 0;
    bool first = false;
    while(true){
        c = getchar();
        if(c == '\n') break;
        if(c == ' ') {
            if(!first){
                first = true;
            }
            else cnt++;
        }
        first = true;
        temp = c;
    }
    if(temp != ' ') cnt++;

    cout << cnt << endl;

    return 0;
}