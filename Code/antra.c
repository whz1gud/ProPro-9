#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int n;
    int *pArr; // pointer to first array element
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
    /* Below are test to see whether all functions work properly. */

    Stack stack;
    initStack(&stack);                                       // Initiating stack with values of 0
    push(&stack, 5);
    push(&stack, 20);                                        // Pushing two values
    printf("Stack size = %d\n", getStackSize(&stack));       // Should be 2 after pushing 2 values
    printStack(&stack);                                      // Printing stack that has 2 pushed values

    printf("Popped element = %d\n", pop(&stack));            // Popping last value from dynamic array
    printf("Stack size = %d\n", getStackSize(&stack));       // Should be 1 after popping 1 value
    printStack(&stack);                                      // Should be one element left after pop

    destroyStack(&stack);                                    
    printf("Stack size = %d\n", getStackSize(&stack));       // Should be 0 after destroyStack() function was called.
    printStack(&stack);                                      // Should not print the stack array after destroyStack() function was called.

    return 0;
}

void initStack(Stack *stack)
{
    stack->n = 0;
    stack->pArr = (int *)calloc(stack->n, sizeof(int));
}

void printStack(Stack *stack)
{
    for (int i = 0; i < stack->n; ++i)
    {
        printf("Stack element[%d] = %d\n", i, stack->pArr[i]);
    }
}

int getStackSize(Stack *stack)
{
    return stack->n;
}

void push(Stack *stack, int value)
{
    int temp = stack->n;
    stack->n++;
    stack->pArr = (int *)realloc(stack->pArr, (stack->n) * (sizeof(int)));
    stack->pArr[temp] = value;
}

int top(Stack *stack)
{
    if (stack->n == 0)
    {
        return 0;
    }
    else
        return stack->pArr[stack->n - 1];
}

int pop(Stack *stack)
{
    int lastElement = top(stack);
    stack->n--;
    stack->pArr = (int *)realloc(stack->pArr, (stack->n) * sizeof(int));
    return lastElement;
}

void destroyStack(Stack *stack)
{
    free(stack->pArr);
    initStack(stack);
}