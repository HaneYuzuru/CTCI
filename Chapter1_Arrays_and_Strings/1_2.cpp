#include <iostream>
#include <memory.h>

using namespace std;

void reverse(char* str);

int main(){
    char str[300];

    memset(str, '\0',sizeof(str));    

    cout << "Please input a string to reverse:" << endl;
    cin  >> str;

    reverse(str);

    cout << "The result is:" << endl << str << endl;
    
    return 0;
}

void reverse(char* str){
    int length = strlen(str);
    char temp;    

    for(int i = 0; i != length/2; i ++){
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
