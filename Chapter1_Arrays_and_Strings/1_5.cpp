#include <iostream>
#include <string.h>

using namespace std;

void compress(char* str);

int main(){
	char str[300];	

	cout << "Please input the string to compress:" << endl;

	cin  >> str;

	compress(str);

	cout << "The result is:" << endl << str << endl;
}

void compress(char* str){
	char compressed[300];

	char lastChar = '\0';
	int count = 1;
	int position = 0;

	for(int i = 0; i != strlen(str); i ++){
		if(lastChar == str[i]){
			count ++;
		} else{
			if(lastChar != '\0'){
				compressed[position] = lastChar;
				compressed[position + 1] = count + '0';
				position += 2;
			} else{
			}
			lastChar = str[i];
			count = 1;
		}
	}

    compressed[position] = lastChar;
    compressed[position + 1] = count + '0';

	compressed[position + 2] = '\0';

	if(strlen(compressed) <= strlen(str)){
		strcpy(str, compressed);
	}
}
