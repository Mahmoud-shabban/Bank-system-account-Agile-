/*********** ***************** *********/
/*********** Linked List Based *********/
/*********** ***************** *********/

/*********** ***************** ****************/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Linked List BAsed           */
/*  Date        : 28/12/2021                  */
/*  Version     : 0.1                         */
/*********** ***************** ****************/

#include <stdio.h>
#include <stdlib.h>

/* Preprocessing part */
typedef struct List_Node
{
    int Data;
    struct List_Node * Next; 
}Node;

typedef struct Liked_List 
{
    Node * Head;
    Node * Tail;
    int Size;
}List;

/***************************/
/*    Fucntions protype    */
/***************************/
// Function to initialize the List at the first Creation
void List_Init(List * pl);
// Function to Append value into List at the end 
void List_Void_Append(List * pl ,int value);
// Function to Insert value into List at specific Index
void List_Void_Insert(List * pl ,int value,int index);
// Function to remove Node at specific index
void remove_void_index(List * pl, int index); 
// Function to search for a given value return the index of its first occurance
void Search_void_List(List * pl, int value);
// Function to pop value from List last index in given variable and delete the poped value
void List_Void_Pop(List * pl, int * poped );
// Function to check the List is full (Always return False)
int List_int_is_Full(List *pl);
// Function to check if a List is empty
int List_int_is_Empty( List * pl);
// Function to get the List size 
void get_void_list_size(List * pl, int * size);
// Functon to get the Head value in List
void get_void_Head(List * pl, int *R);
// Function to print the List contents
void print_Void_List(List * pl);
// Function to clear the List contents
void clear_Void_List(List * pl);

//************* Main Function***********//
int main(void)
{
    int size, x,pop;
    List list;
// intializing the list
    List_Init(&list);
// testing appending values (Done)
    List_Void_Append(&list,4);
    List_Void_Append(&list,11);
    List_Void_Append(&list,21);
    List_Void_Append(&list,40);
    List_Void_Append(&list,108);
    List_Void_Append(&list,-5); // we inserted 6 int
// testing the size (Done)
    get_void_list_size(&list,&size);
    printf("your size is: %d\n",size);
    printf("=======================\n");
// testing print list function (Done)
    print_Void_List(&list);
// testing get head function (Done)
    get_void_Head(&list,&x);
    printf("your Head is: %d\n",x);
    printf("=======================\n");
// testing insert function
//  1- insert at the start of the list (Done)
    List_Void_Insert(&list,77,0);
    get_void_list_size(&list,&size);
    printf("your size after insert at head is: %d\n",size);
    printf("=======================\n");
  //  print_Void_List(&list);
//  2- insert at between head and tail (Done)
    List_Void_Insert(&list,34,5);
    get_void_list_size(&list,&size);
    printf("your size after insert at index 5 is: %d\n",size);
    printf("=======================\n");
  //  print_Void_List(&list); 
//  3- inserting at the end index == list size using insert function (Done)
    List_Void_Insert(&list,90,8);
    get_void_list_size(&list,&size);
    printf("your size after insert at last index is: %d\n",size);
    printf("=======================\n");
    //print_Void_List(&list);
//  4- inserting  with wrong index (Done)
    List_Void_Insert(&list,60,-1);
    get_void_list_size(&list,&size);
    printf("your size after insert at wrong index is: %d\n",size);
    printf("=======================\n");
   // print_Void_List(&list);
// testing remove function (Done)
//  1- remove from random index
    remove_void_index(&list, 5);
    get_void_list_size(&list,&size);
    printf("your size after removeing index 5 is: %d\n",size);
    printf("=======================\n");
    print_Void_List(&list);
//  2- remove from Head index
 //   remove_void_index(&list, 0);
    get_void_list_size(&list,&size);
    printf("your size after removeing index 0 is: %d\n",size);
    printf("=======================\n");
   // print_Void_List(&list);
//  3- remove from last index
    remove_void_index(&list, size -1 );
    get_void_list_size(&list,&size);
    printf("your size after removeing last index is: %d\n",size);
    printf("=======================\n");
   // print_Void_List(&list);
// testing clear list function (Done)
    clear_Void_List(&list);
    get_void_list_size(&list,&size);
    printf("your size after clearing is: %d\n",size);
    printf("=======================\n");
    print_Void_List(&list);
    return 0;
}

/************* Function Declaration Section***********/

void List_Init(List * pl)
{
    pl->Head = NULL;
    pl->Tail = NULL;
}

void List_Void_Append(List * pl ,int value)
{
    // check if this first operation on the list and update the head
    // I'm using the pointers I have in the list to cut redundncy
    // I won't create new variables unless necessary
    if(pl->Head == NULL)
    {
        // allocate with Tail pointer
        pl->Tail = (Node*) malloc(sizeof(Node));
        // update the Head
        pl->Head = pl->Tail;
    }
    else //Not the first opetation
    {
        // allocate with the last Node "Next" pointer
        pl->Tail->Next = (Node *) malloc(sizeof(Node));
        pl->Tail = pl->Tail->Next;
    }
    // setting the last Node pointer to NULL + inserting the value in the node + updating the size
    pl->Tail->Next = NULL;
    pl->Tail->Data = value;
    pl->Size ++;
}

void List_Void_Insert(List * pl ,int value,int index)
{
    if(!List_int_is_Empty(pl))
    {
        // 00- Declaring the variables I will use in this function
        int i, steps;
        Node * New, * vistor, * catcher;

        // 1- Creat the New Node to be inserted, catch it with "New" pointer and add the value data
        New = (Node *) malloc(sizeof(Node));
        New->Data = value;
        // *** check if user trying to insert at the begining of the list
        if(index == 0)
        {
            // catching the second node in the list
            New->Next = pl->Head;
            // updating the head
            pl->Head = New;
        } 
        // *** inserting anywhere between the Head and Tail
        else if(index > 0 && index < pl->Size -1)
        {
            // 1- calculating the number of steps to the specified index
            steps = index -1;
            // 2- creat new vistor pointer to get to the required location then set at the begining of the list
            vistor = pl->Head;
            // 3- looping to get to specified location
            for(i = 0; i< steps; i++)
            {
                // when we get out of the loop we will have the node *** AFTER *** which we will insert New node
                vistor = vistor->Next;
            }
            // 4- Catch the Nod which we will insert *** BEFORE ***
            catcher = vistor->Next;
            // 5- update the Vistor "Next" pointer to the "New" Node
            vistor->Next = New;
            // 6- Update the "New" Next pointer to the catcher
            New->Next = catcher;
        }
        // *** If the user give a wrong index we assume it is  "Appending" operation
        else 
        {
            List_Void_Append(pl, value);
            // to get the size Append function increase it 
           pl->Size--;
        }

        pl->Size++;
    }
    // trying to insert at while the List is empty
    else
    {
        List_Void_Append(pl,value);
    }

}

void remove_void_index(List * pl, int index)
{
    // 1- List is empty
    if(List_int_is_Empty(pl))
    {
        printf("Your List is Empty\n");
    }
    // 2- Wrong index input
    else if(index > pl->Size -1 || index < 0)
    {
        printf("Your index is out of boundary\n");
    }
    // 3- trying to remove the last index similar to (pop operation)
    else if(index == pl->Size -1)
    {
        int  temp;
        printf("******** 1 *********\n");
        List_Void_Pop(pl,&temp);
    }
    // 4- trying to remove the first Node
    else if (index == 0)
    {
        Node * temp;
        temp = pl->Head;
        printf("******** 2 *********\n");
        pl->Head = pl->Head->Next;
        free(temp);
        pl->Size--;
        // if the list contains only one node then we reset our pointers
        if(pl->Size == 0)
        {
            pl->Head = NULL;
            pl->Tail = NULL;
        }
    }
    // 5- trying to remove anywher else
    else
    {
        
        int i ;
        Node * vistor = pl->Head, * catcher;
        printf("********* 3 ********\n");
        for(i = 1; i < index ; i++) // we start the loop at 1 accounting for vistor pointer inintilization
        {
            // when we get out of this loop we have the node befor required catched with vistor pointer
            vistor = vistor->Next;
        }
       // printf("test is: %d\n",vistor->Data);
        // catcher the node After the node to be removed (the other half of the chain)
        catcher = vistor->Next->Next;
        free(vistor->Next);
        vistor->Next = catcher;
        pl->Size--;
    }
} 

void Search_void_List(List * pl, int value)
{
    if(List_int_is_Empty(pl))
    {
        printf("Your List is Empty\n");
    }
    else
    {
        Node * vistor = pl->Head;
        int index = 0; // counts the steps taken to the value
        while (vistor !=NULL)
        {
            if(value == vistor->Data)
            {
                printf("your value is at index: %d\n",index);
                return;
            }
            else
            {
                vistor = vistor->Next;
                index++;
            }
        }
        printf("Value Is Not in The List");
        
    }
}

void List_Void_Pop(List * pl, int * poped )
{
    * poped = pl->Tail->Data;
    // setting the tail at the list start point
    pl->Tail = pl->Head;
    // check if tail setting before the last node(to be poped)
    while(pl->Tail->Next->Next != NULL)
    {
        // when we get out of this node the tail will be pointing to the node before last.
        pl->Tail = pl->Tail->Next;
    }
    // now we free the last node using the Tail->Next pointer
    free(pl->Tail->Next);
    // resting the Tail->Next to NULL
    pl->Tail->Next = NULL;
    pl->Size--;
}

int List_int_is_Full(List *pl)
{
    return 1;
}

int List_int_is_Empty( List * pl)
{
    return pl->Head == NULL;
}

void get_void_list_size(List * pl, int * size)
{
    *size = pl->Size;
}

void get_void_Head(List * pl, int *R)
{
    *R = pl->Head->Data;
}

void print_Void_List(List * pl)
{
    if(List_int_is_Empty(pl))
    {
        printf("Your List is Empty\n");
    }
    else
    {
        // creating vistor pointer to print the data
        //Node * vistor = pl->Head;

        // using the Tail to traverse the list
        pl->Tail = pl->Head;
        while(pl->Tail->Next !=NULL)
        {
            // when this loop finish we still have last node not printed
            printf("%d\n",pl->Tail->Data);
            pl->Tail = pl->Tail->Next;
        }
        
       // printing the last node data
        printf("%d\n",pl->Tail->Data);
    }
}

void clear_Void_List(List * pl)
{
    // using the head and tail pointers
    if(List_int_is_Empty(pl))
    {
        printf("Your List is Empty\n");
    }
    else
    {
        while(pl->Head != NULL)
        {
            pl->Tail = pl->Head->Next;
            free(pl->Head);
            pl->Head = pl->Tail;
        }
        pl->Head = NULL;
        pl->Tail = NULL;
        pl->Size = 0;
    }
}