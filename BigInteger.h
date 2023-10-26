#ifndef BigInteger_h
#define BigInteger_h

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct BigInteger
{
    node *head;
}BigInteger;

BigInteger initialise(char* str);
void rev_display(node *head);
void display(BigInteger num);
BigInteger add(BigInteger a, BigInteger b);
node * rev(node *head);
node * NewNode(int data);
void addAtEnd(node** head, int data);
BigInteger sub(BigInteger a, BigInteger b);
#endif
