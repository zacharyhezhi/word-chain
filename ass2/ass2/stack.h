// Stack ADT header file ... COMP9024 17s2

typedef struct StackRep *stack;

stack newStack(void);             // set up empty stack
void  dropStack(stack);       // remove unwanted stack
int   StackIsEmpty(stack);    // check whether stack is empty
void  StackPush(stack, int);  // insert an int on top of stack
int   StackPop(stack);        // remove int from top of stack
