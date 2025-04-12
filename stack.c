/*
Includes definitions:
    - typedef struct {...} Stack;
    - int isEmptyStack(Stack *s);
    - int isFullStack(Stack *s);
    - int pushStack(Stack *s,int value);
    - int popStack(Stack *s);
    - void displayStack(Stack *s);
    - Stack *initializeStack();
    - int peekStack(Stack *s);
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Definition of stack
typedef struct {
    int stack[MAX];
    int top;
} Stack;

/*
Initializes and allocates memory for a new stack.
Returns the pointer to the new stack
*/
Stack *initializeStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack)); 
    s->top=-1;
    return s;
}

/* 
returns 1 if a stack is empty, else returns 0
*/ 
int isEmptyStack(Stack *s) {
    if (s->top==-1) return 1;    //true
    else return 0;              //false
}

/* 
returns 1 if a stack is full, else returns 0
*/ 
int isFullStack(Stack *s) {
    if (s->top==MAX-1) return 1;
    else return 0;
}

/*
Inserts new value in the stack structure 
It takes the following parameters: 
    - stack (`Stack *`)   : pointer of the stack struct, in order to modify it
    - value (`int`)       : value to insert (push)

If successful, returns 0, else returns -1
*/
int pushStack(Stack *s,int value) {
    if (isFullStack(s)) return -1;

    s->stack[++s->top] = value;
    return 0;
}

/*
Deletes and returns the element from the top of the stack structure 
It takes the following parameters: 
    - stack (`Stack *`)   : pointer of the stack struct, in order to modify it

If no element is left to delete then returns `INT_MIN` from `limits.h`
*/
int popStack(Stack *s) {
    if (!isEmptyStack(s)) {
        int value = s->stack[s->top--];
        return value;
    }
    else return INT_MIN;
}

/*
Returns the element from the top of the stack structure 
It takes the following parameters: 
    - stack (`Stack *`)   : pointer of the stack struct, in order to modify it

If the stack is empty, then returns `INT_MIN` from `limits.h`
*/
int peekStack(Stack *s) {
    if (!isEmptyStack(s))
        return s->stack[s->top];
    else 
        return INT_MIN;
}

/*
Prints the elements of the stack in an array-like fashion,
    - [a1,a2,a3,...]
*/
void displayStack(Stack *s) {
    printf("[");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d, ",s->stack[i]);
    }
    printf("]\n");
}

/*
Searches for a given element in the stack and returns 
the index of the found value nearest to the top.
    - stack (`Stack *`)   : pointer of the stack struct, in order to modify it
    - int (`int`)         : value to search for in the stack
Returns `-1` if value is not found.
*/
int searchStack(Stack *s, int value) {
    for (int i=s->top;i>=0;i--)
        if (value==s->stack[i]) return i;
    return -1;
}

// Main for Debugging Purpose only

// int main() {
//     Stack *s = initializeStack();
//     pushStack(s,12);
//     pushStack(s,12);
//     pushStack(s,23);
//     pushStack(s,34);
//     pushStack(s,45);
//     pushStack(s,56);

//     printf("%d",searchStack(s,12));
// }
