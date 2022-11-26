#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point
{
    double x;
    double y;
} Point;

typedef struct stack
{
    int n;
    Point *pArr; // pointer to first array element of type Point
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point point);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);
double getDistance (Stack *stack, int i);

int main()
{
    Stack stack;
    Point p1 = {-2, 4}, p2 = {1, 1}, p3 = {5, -3}, p4 = {-7, 0}, p5 = {-6, -8};
    Point poppedElem;
    initStack(&stack);
    push(&stack, p1); push(&stack, p2); push(&stack, p3); push(&stack, p4); push(&stack, p5);
    printf("Stack size = %d\n", getStackSize(&stack));
    printStack(&stack);

    /* Below are test to see whether all functions work properly. */

    // poppedElem = pop(&stack);
    // printf("Popped element = (%.1lf, %.1lf)\n", poppedElem.x, poppedElem.y);
    // printf("Stack size = %d\n", getStackSize(&stack));
    // printStack(&stack);

    // destroyStack(&stack);
    // printf("Stack size = %d\n", getStackSize(&stack));   // Should be 0 after destroyStack() function was called.
    // printStack(&stack);                                  // Should not print the stack array after destroyStack() function was called.

    return 0;
}

void initStack(Stack *stack)
{
    stack->n = 0;
    stack->pArr = (Point *)calloc(stack->n, sizeof(Point));
}

void printStack(Stack *stack)
{
    for (int i = 0; i < stack->n; ++i)
    {
        printf("Point elem[%d] = (%.1lf, %.1lf);", i, stack->pArr[i].x, stack->pArr[i].y);
        printf(" Distance to (0, 0) = %.1lf\n", getDistance(stack, i));
    }
}

int getStackSize(Stack *stack)
{
    return stack->n;
}

void push(Stack *stack, Point point)
{
    int temp = stack->n;
    stack->n++;
    stack->pArr = (Point *)realloc(stack->pArr, (stack->n) * (sizeof(Point)));
    stack->pArr[temp] = point;
}

Point top(Stack *stack)
{
    if (stack->n == 0)
    {
        Point p0;
        return p0;
    }
    else
        return stack->pArr[stack->n - 1];
}

Point pop(Stack *stack)
{
    Point lastPoint = top(stack);
    stack->n--;
    stack->pArr = (Point *)realloc(stack->pArr, (stack->n) * sizeof(Point));
    return lastPoint;
}

void destroyStack(Stack *stack)
{
    free(stack->pArr);
    initStack(stack);
}

double getDistance (Stack *stack, int i)
{
    double distance = sqrt(pow(stack->pArr[i].x, 2) + pow(stack->pArr[i].y, 2));
    return distance;
}