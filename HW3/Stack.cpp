#include <iostream>
#include "Stack.h"
#include <string>
#include <cstdlib>
using namespace std;

template <class T> Stack<T>::Stack() : topPtr(NULL) {}

template <class T> Stack<T>::Stack(const Stack& aStack) {

    if (aStack.topPtr == NULL)
        topPtr = NULL;  // original stack is empty

    else {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        // copy rest of stack
        StackNode* newPtr = topPtr;
        for (StackNode* origPtr = aStack.topPtr->next;
            origPtr != NULL;
            origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}

template <class T> Stack<T>::~Stack() {

    // pop until stack is empty
    while (!isEmpty())
        pop();

}

template <class T> bool Stack<T>::isEmpty() const {

    return topPtr == NULL;

}

template <class T> bool Stack<T>::push(T newItem) {

    // create a new node
    StackNode* newPtr = new StackNode;

    // set data portion  of new node
    newPtr->item = newItem;

    // insert the new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

template <class T> bool Stack<T>::pop() {

    if (isEmpty())
        return false;

    // stack is not empty; delete top
    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}

template <class T> bool Stack<T>::pop(T& stackTop) {

    if (isEmpty())
        return false;

    // not empty; retrieve and delete top 
    else {
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;

        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}

template <class T>bool Stack<T>::getTop(T& stackTop)
const {

    if (isEmpty())
        return false;

    // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }
}

//void TemporaryFunction()
//{
//    Stack<char> aStack;
//    Stack<string> bStack;
//}



