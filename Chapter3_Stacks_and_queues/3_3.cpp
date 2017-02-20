#include <iostream>
#include <memory.h>

using namespace std;
#define MAX 100

struct Stack{
    int capacity;
    int size;
    int numbers[100];

    Stack(int c) : capacity(c), size(0){
        memset(numbers, 0, sizeof(numbers));
    }

    bool isEmpty(){
        return size <= 0;
    }

    bool isFull(){
        return size >= capacity;
    }

    bool push(int n){
        if(size < capacity){
            numbers[size] = n;
            size ++;
            return true;
        } else {
            return false;
        }
    }

    int pop(){
        if(isEmpty()){
            return -1;
        } else {
            size --;
            return numbers[size];
        }
    }
};

struct SetOfStacks{
    int stackNum;
    int stackCapacity;
    Stack* stacks[MAX];

    SetOfStacks(int capacity) : stackCapacity(capacity) {
        //memset(stacks, new Stack(capacity), sizeof(stacks));
        for(int i = 0; i < MAX; i ++){
            stacks[i] = new Stack(capacity);
        }
        stackNum = 1;
    }

    bool isEmpty(){
        return stackNum == 1 && stacks[0] -> isEmpty();
    }

    int pop(){
        if(isEmpty()){
            return -1;
        } else{
            int result = stacks[stackNum - 1] -> pop();
            while(result == -1){
                if(stackNum > 1){
                    stackNum --;
                } else{
                    break;
                }
                result = stacks[stackNum - 1] -> pop();
            }
            return result;
        }
    }

    int push(int number){
        if(stacks[stackNum - 1] -> isFull()){
            stackNum ++;
        }

        stacks[stackNum - 1] -> push(number);
    }

    int popAt(int index){
        if(index >= stackNum){
            return -1;
        } else{
            return stacks[index] -> pop();
        }
    }
};

int main() {
    cout << "Please choose operation:(1:push, 2:pop, 3:popAt, 4:exit)" << endl;
    int operation;
    SetOfStacks* stack = new SetOfStacks(2);
    bool loop_end = false;

    while(true) {
        cin >> operation;
        switch(operation){
            case 1:
                cout << "Please input the number you want to push into the stack:" << endl;
                int newNumber;
                cin >> newNumber;
                if(stack -> push(newNumber)){
                    cout << "Push seccess!" << endl;
                }
                break;
            case 2:
                int popedNumber;
                popedNumber = stack -> pop();
                if(popedNumber != -1) {
                    cout << "The stack poped the number: " << popedNumber << endl;
                } else{
                    cout << "The stack is empty" << endl;
                }
                break;
            case 3:
                int index, popNumber;
                cout << "Please input the stack you want to pop: " << endl;
                cin >> index;
                popNumber = stack -> popAt(index);
                if(popNumber != -1) {
                    cout << "The stack poped the number: " << popNumber << endl;
                } else{
                    cout << "The stack is empty" << endl;
                }
                break;
            case 4:
                loop_end = true;
                break;
            default:
                break;
        }

        if(loop_end) {
            break;
        }

        cout << "Please choose operation:(1:push, 2:pop, 3:popAt, 4:exit)" << endl;
    }
}
