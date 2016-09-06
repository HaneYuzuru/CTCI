#include <iostream>
#include <memory.h>

using namespace std;

struct Node{
    char val;
    Node* next;

    Node(char value, Node* next_node) : val(value), next(next_node){}
    Node(char value) : val(value), next(NULL){}
};

void remove1(Node* head);
void convertStrToLinkedList(const string str, Node* head);

int main(){
    cout << "Please input the string to remove duplicates:" << endl;

    string str;
    
    cin >> str;

    Node* head = new Node('0', NULL);

    convertStrToLinkedList(str, head);

    remove1(head);

    cout << "The result is:" << endl;

    Node* cursor = head;
    while(cursor != NULL){
        cout << cursor -> val << " ";
        cursor = cursor -> next;
    }

    cout << endl;

    return 0;
}

void remove1(Node* head){
    if(head == NULL){
        return;
    } else{
        bool isOccurred[256];
        memset(isOccurred, false, sizeof(isOccurred));

        Node* cursor = head;
        isOccurred[cursor -> val] = true;        

        while(cursor -> next != NULL){
            if(isOccurred[cursor -> next -> val]){
                cursor -> next = cursor -> next -> next;
            } else{
                isOccurred[cursor -> next -> val] = true;
				cursor = cursor -> next;
            }
        }
    }
}

void convertStrToLinkedList(const string str, Node* head){
    Node* nextNode = NULL;

    if(str.size() == 0){
        return;
    }
    
    for(int i = str.size() - 1; i != 0; i --){
        Node* newNode = new Node(str[i], nextNode);
        
        nextNode = newNode;
    }
    
    head -> val = str[0];
    head -> next = nextNode;
}
