#include <iostream>
#include <string.h>
#include "memory.h"
using namespace std;

int main() {

	string input;

	cout << "Please input a string:" << endl;

	cin >> input;

	bool buffer[300];

	memset(buffer, 0, sizeof(buffer)); 

	for(int i = 0; i != input.size(); i ++){
		if(buffer[input[i]] == 0){
			buffer[input[i]] = 1;
		} else{
			cout << "not unique!" << endl;
			return 0;
		}
	}
	
	cout << "unique!" << endl;

	return 0;
}
