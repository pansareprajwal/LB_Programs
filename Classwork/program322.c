#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)      //  InsertFirst..
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)   
    {
        *first = newn;
    }
    else               
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

void InsertLast(PPNODE first, int no)       //  InsertLast..
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)   
    {
        (*first) = newn;
    }
    else               
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

void Display(PNODE first)                   //  Display..
{
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)                      //  Count..         
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void DeleteFirst(PPNODE first)              //  DeleteFirst..
{
    PNODE temp = NULL;

    if(*first == NULL)                      // Case 1
    {
        return;
    }
    else if((*first)->next == NULL)         // Case 2
    {
        free(*first);
        *first = NULL;
    }
    else                                    // Case 3
    {
        temp = *first;
        *first = (*first) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)               // DeleteLast..
{
    PNODE temp = NULL;

    if(*first == NULL)                      // Case 1
    {
        return;
    }
    else if((*first)->next == NULL)         // Case 2
    {
        free(*first);
        *first = NULL;
    }
    else                                    // Case 3
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,75);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);      // Call by address(&head)

    Display(head);              // Call by value(head)

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);              // Call by value(head)

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);         // Call by address(&head)

    Display(head);              // Call by value(head)

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);          // Call by address(&head)

    Display(head);              // Call by value(head)

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);    
    
    return 0;
}
