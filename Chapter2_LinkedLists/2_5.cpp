#include <iostream>
#include <string.h>
#include <memory.h>

using namespace std;

struct Node{ 
    int val;
    Node* next;

    Node(int value, Node* next_node) : val(value), next(next_node){}
    Node(int value) : val(value), next(NULL){}
};

void convertStrToLinkedList(const string str, Node* head);
void add(Node* first_head, Node* second_head);

int main(){
    cout << "Please input the first number:" << endl;

    string first_num, second_num;

    cin >> first_num;

    cout << "Please input the second number:" << endl;

    cin >> second_num;

    Node* first_head = new Node(-1, NULL);
    Node* second_head = new Node(-1, NULL);

    convertStrToLinkedList(first_num, first_head);
    convertStrToLinkedList(second_num, second_head);

    add(first_head, second_head);

    return 0;
}

void add(Node* first_head, Node* second_head){
    Node* first_cursor = first_head;
    Node* second_cursor = second_head;
    int diff = 0;
    int longer_flag = 0;

    while(first_cursor != NULL && second_cursor != NULL){
        first_cursor = first_cursor -> next;
        second_cursor = second_cursor -> next;
    }
    
    if(first_cursor == NULL && second_cursor == NULL){
        
    } else if(first_cursor == NULL){
        longer_flag = 2;
        while(second_cursor != NULL){
            second_cursor = second_cursor -> next;
            diff ++;
        }
    } else{
        longer_flag = 1;
        while(first_cursor != NULL){
            first_cursor = first_cursor -> next;
            diff ++;
        }
    }

    first_cursor = first_head;
    second_cursor = second_head;

    Node* result_head = new Node(-1, NULL);
    Node* result_cursor = result_head;

    int two_position_carry[10];
    memset(two_position_carry, 0, sizeof(two_position_carry));
    
    for(int i = 0; i != diff; i ++){
        if(longer_flag == 1){
            if(result_head -> val != -1){
                Node* newNode = new Node(first_cursor -> val, NULL);
                result_cursor -> next = newNode;
                result_cursor = result_cursor -> next;
            } else{
                result_head -> val = first_cursor -> val;
            }
            first_cursor = first_cursor -> next;
        } else{
            if(result_head -> val != -1){
                Node* newNode = new Node(second_cursor -> val, NULL);
                result_cursor -> next = newNode;
                result_cursor = result_cursor -> next;
            } else{
                result_head -> val = second_cursor -> val;
            }
            second_cursor = second_cursor -> next;
        }
    }

    int count = diff - 1;
    int sum = 0;
    while(first_cursor != NULL){
        sum = first_cursor -> val + second_cursor -> val;
        
        if(sum > 9){
            result_cursor -> val = result_cursor -> val + 1;
            if(result_cursor > 9){
                two_position_carry[count - 1] = 1;
                result_cursor -> val = result_cursor -> val - 10;
            } 
            Node* newNode = new Node(sum - 10, NULL);
            result_cursor -> next = newNode;
        } else{
            Node* newNode = new Node(sum, NULL);
            result_cursor -> next = newNode;
        }
        result_cursor = result_cursor -> next;
    }

    //The second round, check if there are some carries
    bool isConti = true;
    bool change = false;
    int position = 0;
    while(isConti){
        result_cursor = result_head;
        if(two_position_carry[0] == 1 && result_head -> val == 9){
            Node* newNode = new Node(1, result_head);
            result_head = newNode;
            result_cursor = result_head -> next;
            two_position_carry[0] = 0;
        }
        while(result_cursor != NULL){
            if(two_position_carry[position] == 1){
                if(result_cursor -> val == 9){
                    two_position_carry[position - 1] = 1;
                    result_cursor -> val = 0;
                    change = true;
                } else{
                    result_cursor -> val = result_cursor -> val + 1;
                }
                two_position_carry[position] = 0;
            }
            result_cursor = result_cursor -> next;
            position += 1;
        }
        if(!change){
            isConti = false;
        }
    }
}

void convertStrToLinkedList(const string str, Node* head){
    Node* nextNode = NULL;

    if(str.size() == 0){
        return;
    }
    
    for(int i = str.size() - 1; i != 0; i --){
        Node* newNode = new Node(str[i] - '0', nextNode);
        
        nextNode = newNode;
    }
    
    head -> val = str[0] - '0';
    head -> next = nextNode;
}
