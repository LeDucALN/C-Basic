/**** Tạo hàng đợi Queue bằng danh sách liên kết đơn ****/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define FULL 10

typedef struct
{
    char name[50];
    char TelephoneNumber[50];
    char Email[50];
} ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;
typedef struct Queue
{
    int count;
    Node *front;
    Node *rear;
} Queue;
void initialize(Queue *q);
int isempty(Queue *q);
void enQueue(Queue *q, ElementType value);
ElementType deQueue(Queue *q);
// void display(Node *head);
