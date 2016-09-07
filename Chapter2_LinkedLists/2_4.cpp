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
void partition(Node* head, int x);

int main(){
    cout << "Please input number list: " << endl;
    
    string number_list;

    cin >> number_list;

    Node* head = new Node(0, NULL);

    convertStrToLinkedList(number_list, head);

    cout << "Please input x: " <<endl;

    int x;

    cin  >> x;

    partition(head, x);

	return 0;
}

void partition(Node* head, int x){
    Node* divide = new Node(-1, NULL);
    Node* divide_head = divide;
    Node* cursor = head;
    Node* big_head = new Node(-1, NULL);

    if(cursor == NULL){
        return;
    }

    if(head -> val < x){
        divide -> val = head -> val;
    } else{
        big_head = head;
    }

    while(cursor -> next != NULL){
        if(cursor -> next -> val < x){
            if(divide -> val != -1){
                divide -> next = cursor -> next;
                cursor -> next = cursor -> next -> next;
                divide = divide -> next;
            } else{
                divide -> val = cursor -> next -> val;  
                cursor -> next = cursor -> next -> next;
            }
        } else{
            if(big_head -> val == -1){
                big_head = cursor -> next;
            }
            cursor = cursor -> next;
        }
    }

    //connect
    if(divide_head -> val != -1 && big_head -> val != -1){
        divide -> next = big_head;
        head = divide_head;
    } else if(big_head -> val == -1){
        head = divide_head;
    } else{
    }

    Node* cursor_2 = head;

    cout << "The result is:" << endl;

    while(cursor_2 != NULL){
        cout << cursor_2 -> val << " ";
        cursor_2 = cursor_2 -> next;
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
