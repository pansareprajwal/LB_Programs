//     Complete Code of Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description :   To Insert node at first position in linked list
//  Input :         PPNODE, PPNODE, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))     //  Linked list is empty
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;                 
        (*first)->prev = *last;
    }
    else     // Linked list contains one or more
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
        
        (*last)->next = *first;                 
        (*first)->prev = *last;
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description :   To Insert node at last position in linked list
//  Input :         PPNODE, PPNODE, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))     //  Linked list is empty
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;                 
        (*first)->prev = *last;
    }
    else     // Linked list contains one or more
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description :   To Delete node at first position in linked list
//  Input :         PPNODE, PPNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))     //  Linked List in Empty
    {
        return;
    }
    else if(*first == *last)                    //  Linked List Contains one node
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description :   To Delete node at last position in linked list
//  Input :         PPNODE, PPNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))     //  Linked List in Empty
    {
        return;
    }
    else if(*first == *last)                    //  Linked List Contains one node
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;
        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;
    }

}

//////////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description :   To Display data from linked list
//  Input :         PPNODE, PPNODE
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

void Display(PNODE first, PNODE last)
{

    if((first == NULL) && (last == NULL))     
    {
        printf("Linked List is empty\n");
        return;
    }

    printf(" <=> ");
    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    } while (first != last->next);

    printf("\n");   
}

//////////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description :   To Count the node from linked list
//  Input :         PPNODE, PPNODE
//  Output :        int
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

int Count(PNODE first, PNODE last)
{
    int iCount = 0;
    
    if((first == NULL) && (last == NULL))       //  Linked list is empty
    {
        return 0;
    }

    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);

    return iCount;
}

//////////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description :   To Insert node at Defined position in linked list
//  Input :         PPNODE, PPNODE, int, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
/////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    int iCount = 0, i = 0;

    iCount = Count(*first,*last);

    if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid Positioin\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

    }
}

//////////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description :   To Delete node at Defined position in linked list
//  Input :         PPNODE, PPNODE, int, int
//  Output :        void
//  Author :        Prajwal Sanjay Pansare
//  Date :          22/12/2025
//
//////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    PNODE temp = NULL;
    int iCount = 0, i = 0;

    iCount = Count(*first,*last);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Positioin\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
        
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
    PNODE tail = NULL;

    int iRet = 0;

    InsertFirst(&head,&tail, 51);
    InsertFirst(&head,&tail, 21);
    InsertFirst(&head,&tail, 11);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&head,&tail, 101);
    InsertLast(&head,&tail, 111);
    InsertLast(&head,&tail, 121);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head,&tail);
    DeleteLast(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,&tail,105,3);
    
    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&head,&tail,3);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}