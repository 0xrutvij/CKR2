#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

int sp = 0;               /* next free stack position */
double stack[STACK_SIZE]; /* stack of values */

void push(double f);

double pop(void);

double poll(void);

void duplicate(void);

void swap(void);

#endif