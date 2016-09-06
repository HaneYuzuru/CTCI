#include <iostream>
#include <string.h>

using namespace std;

bool isSubstring(const string sub_str, const string str);
bool isSubstring_KMP(const string sub_str, const string str);
bool isRotation(const string s1, const string s2);

int main(){
    string s1, s2;

    cout << "Please input the first string:" << endl;

    cin >> s1;

    cout << "Please input the second string:" << endl;

    cin >> s2;

    bool result = isRotation(s1, s2);

    if(result){
        cout << "s1 is the rotation of s2" << endl;
    } else{
        cout << "s1 is not the rotation of s2" << endl;
    }

    return 0;
}

bool isSubstring(const string sub_str, const string str){
    int sub_length = sub_str.size();
    int length = str.size();
    bool find = true;

    for(int i = 0; i != length - sub_length + 1; i ++){
        for(int j = 0; j != sub_length; j ++){
            if(sub_str[j] != str[i + j]){
                find = false;
                break;
            }
        }
        if(find == true){
            return true;
        } else{
            find = true;
        }
    }

    return false;
}

bool isSubstring_KMP(const string sub_str, const string str){
    int sub_length = sub_str.size();
    int length = str.size();
    bool match = true;
    bool find = true;

    int match_map[sub_length];

    memset(match_map, 0, sizeof(match_map));

    //construct the match map
    for(int i = 0; i != sub_length; i ++){
        for(int j = i; j != 0; j --){
            for(int k = 0; k != j; k ++){
                if(sub_str[k] != sub_str[i - j + k + 1]){
                    match = false;
                    break;   
                }
            }
            if(match){
                match_map[i] = j;
                break;
            } else{
                match = true;
            }
        }
    }

    for(int i = 0; i < length - sub_length + 1; i ++){
        if(str[i] != sub_str[0]){
            continue;
        } else{
            for(int j = 1; j != sub_length; j ++){
                if(str[i + j] != sub_str[j]){
                    //since i will increase 1 at the end of the loop
                    i += j - match_map[j - 1] - 1;   
                    find = false;
                    break;
                }
            }
            if(find){
                return true;
            } else{
                find = true;
            }
        }
    }

    return false;
}

bool isRotation(const string s1, const string s2){
    if(s1.size() != s2.size()){
        return false;
    }    

    string s1double = s1 + s1;

    if(isSubstring_KMP(s2, s1double)){
        return true;
    } else{
        return false;
    }
}
