#include <iostream>
#include <memory.h>

using namespace std;

struct Node{ 
    char val;
    Node* next;

    Node(char value, Node* next_node) : val(value), next(next_node){}
    Node(char value) : val(value), next(NULL){}
};

void convertStrToLinkedList(const string str, Node* head);

int main(){

	return 0;
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
