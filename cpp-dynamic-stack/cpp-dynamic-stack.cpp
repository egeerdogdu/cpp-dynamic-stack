#include <iostream>
using namespace std;

struct stnode {
    struct stnode* top;
    int data;
};
typedef struct stnode* STACK;

STACK getnode() {
    STACK node;
    node = (STACK)malloc(sizeof(struct stnode));
    return node;
}

STACK makeStack(int x) {
    STACK s;
    s = getnode();
    s->top = NULL;
    s->data = x;
    return s;
}

void setTop(STACK stack, int x) {
    if (stack->top != NULL)
        cout << "Stack top is full!\n";
    else {
        STACK s;
        s = makeStack(x);
        stack->top = s;
    }
}

void stackPush(STACK stack, int x) {
    STACK temp;
    temp = stack;
    while (temp->top != NULL) {
        temp = temp->top;
    }
    setTop(temp, x);
}

void stackPop(STACK stack) {
    STACK temp;
    STACK temp2;
    temp = stack;
    temp2 = stack;
    while (temp->top != NULL) {
        temp2 = temp;
        temp = temp->top;
    }
    cout << temp->data << " : Deleted Data" << endl;
    temp2->top = NULL;
    delete temp;
}

void displayStack(STACK stack) {
    STACK temp;
    temp = stack;
    if (temp != NULL) {
        cout << temp->data << " ";
        displayStack(temp->top);
    }
} // Bottom to Top

int main()
{
    STACK test = makeStack(50);
    stackPush(test, 60);
    stackPush(test, 70);
    stackPush(test, 80);
    stackPush(test, 90);
    stackPush(test, 100);
    displayStack(test);
    cout << "\n";
    stackPop(test);
    displayStack(test);
    cout << "\n";
    stackPop(test);
    displayStack(test);
    cout << "\n";
}
