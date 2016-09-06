#include <iostream>
#include <string.h>
#include <map>

using namespace std;

bool isPermutation(const string& str_1, const string& str_2);

int main(){
    string str_1, str_2;

    cout << "Please input the first string:" << endl;
    cin  >> str_1;

    cout << "Please input the second string:" << endl;
    cin >> str_2;

    bool result = isPermutation(str_1, str_2);

    if(result == true){
        cout << "The second string is a permutaion of the first one!" << endl;
    } else{
        cout << "The second string is not a permutation of the first one!" << endl;
    }

    return 0;

}

bool isPermutation(const string& str_1, const string& str_2){
    if(str_1.size() != str_2.size()){
        return false;
    }

    map<char, int> char_map;

    for(int i = 0; i != str_1.size(); i ++){
        char this_char = str_1[i];
        if(char_map.find(this_char) != char_map.end()){
            char_map[this_char] = char_map[this_char] + 1;
        } else{
            char_map[this_char] = 1;
        }
    }

    for(map<char, int>::iterator it = char_map.begin(); it != char_map.end(); it ++ ){
        cout << it -> first << "=>" << it -> second << endl;
    }

    for(int i = 0; i != str_1.size(); i ++){
        char this_char = str_2[i];
        if(char_map.find(this_char) != char_map.end()){
            if(char_map[this_char] <= 0){
                return false;
            } else{
                char_map[this_char] --;
            }
        } else{
            return false;
        }
    }
    
    return true;
}
