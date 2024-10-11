#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top_a;
    int top_b;
    int *arr;
};
void push_A(struct stack *ptr)
{
    int val;
    printf("Enter value to enqueue : ");
    scanf("%d", &val);
    if (ptr->top_a + 1 == ptr->top_b || ptr->top_a == ptr->size-1)
    {
        printf("Stack is full.\n");
    }
    else
    {
        ptr->top_a++;
        ptr->arr[ptr->top_a] = val;
    }
}
void push_B(struct stack *ptr)
{
    int val;
    printf("Enter value to enqueue : ");
    scanf("%d", &val);
    if (ptr->top_b-1 == ptr->top_a)
    {
        printf("Stack is full.\n");
    }
    else
    {
        if (ptr->top_b == -1)
        {
            ptr->top_b = ptr->size - 1;
        }
        else
        {
            ptr->top_b--;
        } 
        ptr->arr[ptr->top_b] = val;
    }
}
void pop_A(struct stack *ptr)
{
    int val;
    if (ptr->top_a == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        val = ptr->arr[ptr->top_a];
        ptr->top_a--;
    }
}
void pop_B(struct stack *ptr)
{
    int val;
    if (ptr->top_b == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        val = ptr->arr[ptr->top_b];
        if (ptr->top_b == ptr->size - 1)
        {
            ptr->top_b = -1;
        }
        else
        {
            ptr->top_b++;
        } 
    }
}
void display_A(struct stack *ptr)
{
    if (ptr->top_a == -1)
    {
        printf("Stack A is empty.\n");
    }
    else
    {
        printf("Stack A: ");
        for (int i = 0; i <= ptr->top_a; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}

void display_B(struct stack *ptr)
{
    if (ptr->top_b == ptr->size || ptr->top_b == -1)
    {
        printf("Stack B is empty.\n");
    }
    else
    {
        printf("Stack B: ");
        for (int i = ptr->size-1; i >= ptr->top_b; i--)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top_a = -1;
    sp->top_b = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    do
    {
        printf("1.Push in stack A\n2.Push in stack B\n3.Pop in stack A\n4.Pop in stack B\n5.Display stack A\n6.Display stack B\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push_A(sp);
            break;
        case 2:
            push_B(sp);
            break;
        case 3:
            pop_A(sp);
            break;
        case 4:
            pop_B(sp);
            break;
        case 5:
            display_A(sp);
            break;
        case 6:
            display_B(sp);
            break;
        }
    } while (ch >=1 && ch <= 6);
}
