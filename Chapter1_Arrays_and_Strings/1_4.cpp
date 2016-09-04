#include <iostream>
#include <memory.h>

using namespace std;

void replace(char* str);

int main(){
	char str[300];

	cout << "Please input the string to replace:" << endl;

	cin.getline(str, 300);

	replace(str);

	cout << "The result is:" << endl << str << endl;
}

void replace(char* str){
	int plus = 0;
	size_t length = strlen(str);
	
	for(size_t i = 0; i != length; i ++){
		if(str[i] == ' '){
			plus += 2;
		}
	}

	int endPoint = length + plus;

	str[endPoint] = '\0';
	endPoint --;

	for(size_t i = length - 1; i != -1; i --){
		if(str[i] != ' '){
			str[endPoint] = str[i];
			endPoint --;
		} else{
			str[endPoint] = '0';
			endPoint --;
			str[endPoint] = '2';
			endPoint --;
			str[endPoint] = '%';
			endPoint --;
		}
	}
}
