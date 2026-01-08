//  Complete Code of Singly Circular Linked-List

#include<stdio.h>
#include<stdlib.h>

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

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

    (*last)->next = *first;     // @
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

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;   // @
        *last = newn;           // @
    } 

    (*last)->next = *first;     // @
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
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))     //  Case 1
    {
        return;
    }
    else if(*first == *last)                    //  Case 2
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                        //  Case 3
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);

        (*last)->next = *first;
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
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))     //  Case 1
    {
        return;
    }
    else if(*first == *last)                    //  Case 2
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                        //  Case 3
    {
        temp = *first;

        while(temp->next != *last)
        {
            temp = temp->next;
        }

        free(*last);
        *last = temp;

        (*last)->next = *first;
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
    do
    {
        printf("| %d | -> ",first->data);
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
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);
    
    printf("\n");

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
//////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    int iCount = 0;
    int iCnt = 0;

    iCount = Count(*first, *last);

    if((pos < 0) || (pos > iCount+1))
    {
        printf("Invalid Postion\n");
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

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

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
    PNODE target = NULL;

    int iCount = 0;
    int iCnt = 0;

    iCount = Count(*first, *last);

    if((pos < 0) || (pos > iCount))
    {
        printf("Invalid Position\n");
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

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);

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
    PNODE tail = NULL;      // @

    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes : %d\n",iRet);

    DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes : %d\n",iRet);

    DeleteLast(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes : %d\n",iRet);

    InsertAtPos(&head,&tail,105,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes : %d\n",iRet);

    DeleteAtPos(&head,&tail,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of nodes : %d\n",iRet);

    return 0;
}