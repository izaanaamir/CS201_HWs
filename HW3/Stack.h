#pragma once
#include "Stack.h"
#include <string>
#include <cstdlib>
using namespace std;

template <class T> class Stack {

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty() const;
    bool push(T newItem);
    bool pop();
    bool pop(T& stackTop);
    bool getTop(T& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        T item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};
