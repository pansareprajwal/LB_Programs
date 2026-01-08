//    Complete Singly Linear Linked-list code

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description :   To Insert node at first position in linked list
//  Input :         PPNODE, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
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
        newn->next = *first;
        *first = newn;
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description :   To Insert node at last position in linked list
//  Input :         PPNODE, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp->next != NULL)       //  Type 2 loop (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newn;
        
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description :   To Delete node at First position in linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;

        free(temp);
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description :   To Delete node at Last position in linked list
//  Input :         PPNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)     // Type 3 loop (temp->next->next)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description :   To Display data of the linked list
//  Input :         PNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

//////////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description :   To Count Number of nddes from linked list
//  Input :         PNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

//////////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description :   To Insert node at defined position in linked list
//  Input :         PPNODE, int, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    
    int iSize = 0;
    iSize = Count(*first);

    if((pos < 1) || (pos > iSize +1))           // Filter
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;    //1
        temp->next = newn;          //2
        
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description :   To Delete node from defined positon in linked list
//  Input :         PNODE, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          18/12/2025
//
//////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    iSize = Count(*first);

    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > iSize))           // Filter
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;  // 1
        free(target);                // 2

    }
}

//////////////////////////////////////////////////////////////
//
//  Entry point function for the application
//
//////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);   

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);   

    InsertAtPos(&head,105,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);  

    DeleteAtPos(&head,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);  
    
    return 0;
}
