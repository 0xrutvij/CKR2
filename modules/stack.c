#include "stack.h"
#include <stdio.h>

/* push: push f onto value stack */
void push(double f)
{
    if (sp < STACK_SIZE)
        stack[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* poll: print stack's top element */
double poll(void)
{
    if (sp > 0)
        return stack[sp - 1];
    else
        printf("error: stack is empty");
}

/* duplicate: push a copy of the top element onto the stack */
void duplicate(void)
{
    if (sp < STACK_SIZE)
        push(poll());
    else
        printf("error: stack full, can't duplicate.");
}

/* swap: exchange top two elements */
void swap(void)
{
    float temp;

    if (sp < 1)
        printf("error: stack empty can't swap");
    else
    {
        temp = stack[sp - 1];
        stack[sp - 1] = stack[sp - 2];
        stack[sp - 2] = temp;
    }
}