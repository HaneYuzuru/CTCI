#include <iostream>
#include <string.h>
#include "memory.h"
using namespace std;

bool solution1(const string& input);
bool solution2(const string& input);
bool solution3(const string& input);

int main() {

	string input;

	cout << "Please input a string:" << endl;

	cin >> input;

	if(solution3(input)){
		cout << "unique" << endl;
	} else{
		cout << "not unique" << endl;
	}

	return 0;
}

bool solution1(const string& input){
	for(int i = 1; i != input.size(); i ++){
                for(int j = 0; j != i; j ++){
                        if(input[i] == input[j]){
                                return false;
                        }
                }
        }

        return true;
}

bool solution2(const string& input){
	bool buffer[256];

	memset(buffer, 0, sizeof(buffer)); 

	for(int i = 0; i != input.size(); i ++){
		if(buffer[input[i]] == 0){
			buffer[input[i]] = 1;
		} else{
			return false;
		}
	}
	
	return true;
}

//solution from Jin, support 64 bit
bool solution3(const string& input){
	unsigned long flag = 0;

	for(int i = 0; i != input.size(); i ++){
		int val = input[i] - 'a';

		if(1 & (flag >> val)){
			// attention
			return false;
		} else{
			flag |= 1 << val;
		}
	}
	
	return true;
}
