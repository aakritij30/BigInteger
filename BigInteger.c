#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct BigInteger
{
    node *head;
}BigInteger;

BigInteger initialise(char* str) 
{
    BigInteger num;
    num.head = NULL;
    int length = strlen(str);
    for (int i = 0; i < length; i++) 
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = str[i] - '0';
        newNode->next = num.head;
        num.head = newNode;
    }
    return num;
}

void reverse_display(node *head)
{
    if(head == NULL)
    {
        return;
    }
    reverse_display(head->next);
    printf("%d", head->data);
}

void display(BigInteger number)
{
    reverse_display(number.head);
    printf("\n");
}

BigInteger add(BigInteger a, BigInteger b) 
{
    BigInteger result; // Create a new BigInteger for the result
    result.head = NULL; // Initialize the result's linked list to be empty
    node* resulthead = NULL; // Temporary pointer to the result's linked list
    node* ptr1 = a.head;
    node* ptr2 = b.head;
    int carry = 0;
    while (ptr1 || ptr2 || carry) 
    {
        int sum = carry;
        if (ptr1) 
        {
            sum += ptr1->data;
            ptr1 = ptr1->next;
        }
        if (ptr2) 
        {
            sum += ptr2->data;
            ptr2 = ptr2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = sum;
        newnode->next = NULL;
        if (!resulthead) 
        {
            resulthead = newnode;
            result.head = resulthead; // Update the result's head
        } 
        else 
        {
            node* temp = resulthead;
            while (temp->next != NULL) 
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return result;
}


node * rev(node *head)
{
    node *prev = NULL;
    node *curr = head;
    while(curr)
    {
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node * NewNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addAtEnd(node** head, int data) 
{
    node* newNode = NewNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

BigInteger sub(BigInteger a, BigInteger b) 
{
    BigInteger result; // Create a new BigInteger for the result
    result.head = NULL; // Initialize the result's linked list to be empty

    node* resulthead = NULL; // Temporary pointer to the result's linked list
    node* current1 = a.head;
    node* current2 = b.head;
    int borrow = 0;
    while (current1 || current2) 
    {
        int digit1 = (current1 != NULL) ? current1->data : 0;
        int digit2 = (current2 != NULL) ? current2->data : 0;

        int difference = digit1 - digit2 - borrow;
        if (difference < 0) 
        {
            difference += 10;
            borrow = 1;
        } 
        else 
        {
            borrow = 0;
        }

        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = difference;
        newnode->next = NULL;
        if(!resulthead)
        {
            resulthead = newnode;
            result.head = resulthead; // Update the result's head
        }
        else
        {
            node *temp = resulthead;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }   
            temp->next = newnode;
        }

        if (current1 != NULL) 
        {
            current1 = current1->next;
        }
        if (current2 != NULL) 
        {
            current2 = current2->next;
        }
    }
    return result;
}
