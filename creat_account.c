#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ACCID;
/*********** ***************** *********/
/*********** Bank system ***** *********/
/*********** ***************** *********/

/*********** ***************** ****************/
/*  Author      : MAhmoud Shabban Gomaa       */
/*  Description : Admin functions             */
/*  Date        : 6/5/2022                    */
/*  Version     : 0.1                         */
/*********** ***************** ****************/


/* Preprocessing part */
typedef struct Data
{
    char * ClientFullNmae;
    char * ClientAddress;
    long NationalID;
    int Age;
    long BankAccountID;
    char * GurdianName ;
    long GurdianID;
    char * AccountStatus ;
    long Balance;
    long Password;

}Data;

typedef struct List_Node
{
    Data *  data;
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
void List_Void_Append(List * pl ,Data * value);
// Function to Insert value into List at specific Index
void List_Void_Insert(List * pl ,Data * value,int index);
// Function to remove Node at specific index
void remove_void_index(List * pl, int index); 
// Function to search for a given value return the index of its first occurance
void Search_void_List(List * pl, long account_id);
// Function to pop value from List last index in given variable and delete the poped value
void List_Void_Pop(List * pl, Data * poped );
// Function to check the List is full (Always return False)
int List_int_is_Full(List *pl);
// Function to check if a List is empty
int List_int_is_Empty( List * pl);
// Function to get the List size 
void get_void_list_size(List * pl, int * size);
// Functon to get the Head value in List
void get_void_Head(List * pl, Data * R);
// Function to print the List contents
void print_Void_List(List * pl);
// Function to clear the List contents
void clear_Void_List(List * pl);
//************ the user function logic ************
// Generate user id autogeneration
long gen_account_id(Node * n);
// get the client name
char*  get_name(int t);
// Get last client data 
Node * get_last_client(List * list);
// get national id
long get_national_id();
// get address
char*  get_address();
// new account
Data * new_account(List * db);
// client age
int get_age();
// account balance
long get_account_balance();
// Deposit Function
void Deposit(int chr, List *pl);
// Open Existing Account
int OpenExistingAccount(List *pl);
// Change Status
void ChangeStatus(List *pl);
// Make Transaction
void Transaction(List *pl);

int main()
{
    List DataBase;
    int status;
    int operation;
    int chr;
    int func; 

    status = 1;

    // 1- Open Existing Account Main Interface Menu
    List_Init(&DataBase);
    printf("Welcome to The Bank Management System! \n");
    printf("How can we help you?\n");
    getchar();

    while(status != 0)
    {
        system("clear");
        printf("\n\nplease entre your choice as number\n");
        printf("1-Create new account 2-Open Existin Account 3-Exit  ");
        scanf("%d",&operation);
        system("clear");
        
        if (operation == 3){ status = 0;}
        if (operation == 1)
        {
            printf("it works until here");
            getchar();
            List_Void_Append(&DataBase, new_account(&DataBase));
        }
        if (operation == 2)
        {
            func = OpenExistingAccount(&DataBase);
            getchar();
            switch (func)
            {
            case 1:
                Transaction(&DataBase);
            case 3:
                ChangeStatus(&DataBase);
                break;
            case 4:
                Deposit(chr, &DataBase);
                break;
            }
        }

    }
    system("clear");
    // printf("\n(Success) your account is created \n");
    // printf("your Account ID is: %09ld \n", get_last_client(&DataBase)->data->BankAccountID );
    print_Void_List(&DataBase);
}

/************* Function Declaration Section***********/

Data * new_account(List * db){
    Node * last_client = NULL; // to get the last client account id and create the next
    int g;
    Data * new = NULL;
    new =(Data *) malloc(sizeof(Data));
    if (List_int_is_Empty(db)){
        last_client = NULL;
    }else{
        last_client = get_last_client(db);
    }
    (*new).ClientFullNmae = get_name(0);
    (*new).Age = get_age();
    (*new).BankAccountID = gen_account_id(last_client);
    (*new).NationalID = get_national_id(0);
    (*new).AccountStatus = "Active";
    (*new).Balance = get_account_balance();
    printf("Does client have Gurdian (enter 1 for yes, 0 for no: ");
    scanf("%d",&g);
    if ( g == 0){
        (*new).GurdianID = 0;
        (*new).GurdianName = "None";
    }else if (g == 1)
    {
        (*new).GurdianName = get_name(1);
        (*new).GurdianID = get_national_id(1);
    }
    getchar();
    (*new).ClientAddress = get_address();
    (*new).Password = (*new).NationalID; // we use the national id as password
    printf("\n(Success) your account is created \n");
    getchar();
    return new;
}

long get_account_balance(){
    long b;
    printf("Enter Account Balance: ");
    scanf("%ld", &b);
    return b;
}

char*  get_address(){
    char address [30];
    
    printf("Please Entre client address: ");
    scanf("%*d");
    printf("\n");
    fgets(address, 30,stdin);
    char * r = malloc(30);
    
    // getchar();
    return strcpy(r,address);

}

long get_national_id(int t){
    long id ;
    if(t== 0){
    printf("Enter Client National ID: ");
    
    }else{
    printf("Enter Gurdian National ID: ");
    }
    scanf("%14ld",&id);
    return id;
}

long gen_account_id(Node * n){
    long last_id;
    if (n != NULL){
        last_id = n->data->BankAccountID;
    }else{ last_id = 0;}

    // static long id = 0;
    printf("Account Id Generated");
    printf("\n");
    return ++last_id;
}

char*  get_name(int t){
    char name [30];
    getchar();
    if(t == 0){
        printf("Please Entre client name: ");
    } else if (t == 1)
    {
        printf("Please Entre client name: ");
    }
    
    fgets(name, 30,stdin);
    char * r = malloc(30);
    // printf("\n");
    return strcpy(r,name);
}


int get_age(){
    int age;
    printf("Enter client age: ");
    scanf("%d",&age);
    // printf("\n");
    return age;
}


void List_Init(List * pl)
{
    pl->Head = NULL;
    pl->Tail = NULL;
}

void List_Void_Append(List * pl ,Data * value)
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
    pl->Tail->data = value;
    pl->Size ++;
}

void List_Void_Insert(List * pl ,Data * value,int index)
{
    if(!List_int_is_Empty(pl))
    {
        // 00- Declaring the variables I will use in this function
        int i, steps;
        Node * New, * vistor, * catcher;

        // 1- Creat the New Node to be inserted, catch it with "New" pointer and add the value data
        New = (Node *) malloc(sizeof(Node));
        New->data = value;
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
    // else if(index == pl->Size -1)
    // {
    //     int  temp;
    //     printf("******** 1 *********\n");
    //     List_Void_Pop(pl,&temp);
    // }
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

void Search_void_List(List * pl, long account_id)
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
            if(account_id == vistor->data->BankAccountID)
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

void List_Void_Pop(List * pl, Data * poped )
{
    poped = pl->Tail->data;
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

void get_void_Head(List * pl, Data * R)
{
    R = pl->Head->data;
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
        Node * vistor = pl->Head;
        
        // using the Tail to traverse the list
        // pl->Tail = pl->Head;
        
        do{
            // when this loop finish we still have last node not printed
            // printf("%d\n",pl->Tail->data);
            printf("\nBank account number: %09ld\n",vistor->data->BankAccountID);
            printf("client name is: %s",vistor->data->ClientFullNmae);
            printf("client age is: %d\n",vistor->data->Age);
            printf("client address is: %s",vistor->data->ClientAddress);
            printf("client balance is: %ld\n",vistor->data->Balance);
            printf("account password is: %ld\n",vistor->data->Password);
            vistor = vistor->Next;
        }while(vistor !=NULL);
        
       // printing the last node data
        // printf("%d\n",pl->Tail->data);
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



Node * get_last_client(List * list)
{
    Node * last_client = NULL;
    // last_client = list->Tail->data;
    // setting the tail at the list start point
    Node * vistor;
    vistor = list->Head;
    // make the vistor move on each node from heat to tail
    if (list->Head == NULL){
        return last_client;
    }
    while(vistor->Next != NULL)
    {
        // when the visotr is not at the one before the last.
       vistor = vistor->Next;
    }
    // now we now we at the node befor the last so we move only one step
    // vistor->Next;
    // catching the last client data
    last_client = vistor;
    vistor = NULL;
    return last_client;
}

// Open Existing Account
int OpenExistingAccount(List *pl)
{
    // BankAccount ExistingAccount;
    int choose;
    long AccId;
    Node* tempPointer = pl->Head;
    printf("Please enter your bank account id: ");
    scanf("%li", &AccId);
    ACCID = AccId;

    while (AccId != tempPointer->data->BankAccountID)
    {
        tempPointer = tempPointer->Next;
    }
    if (AccId == tempPointer->data->BankAccountID)
    {
        printf("Account Exists ! \n");
        printf("Choose the function you want to perform:");
        printf("\n 1- Make Transaction");
        printf("\n 2- Get Cash");
        printf("\n 3- Change Status");
        printf("\n 4- Deposit in Account");
        printf("\n 5- Return to main menu\n");
        scanf("\n%d", &choose);
        return choose;
    }
    else{
        printf("Account Does not Exist ! \n");
        return 9;
    }
}

// 5- Deposit Function
void Deposit(int chr, List *pl)
{
    long amount;
    Node *tempPointer = pl->Head;
    while (ACCID != tempPointer->data->BankAccountID)
    {
        tempPointer = tempPointer->Next;
    }
    if (ACCID == tempPointer->data->BankAccountID)
    {
        printf("\nEnter Amount you want to add: ");
        scanf("%li", &amount);
        printf("\nAmount To add is: %li\n", amount);
        tempPointer->data->Balance = tempPointer->data->Balance + amount;
        printf("\nBalance for the account is Updated: %li\n", tempPointer->data->Balance);
    }
}

void ChangeStatus(List *pl)
{
    Node *tempPointer = pl->Head;
    while (ACCID != tempPointer->data->BankAccountID)
    {
        tempPointer = tempPointer->Next;
    }
    if (ACCID == tempPointer->data->BankAccountID){
        if (strcmp(tempPointer->data->AccountStatus, "Active") == 0){
            tempPointer->data->AccountStatus = "Deactive";
        }
        else{
            tempPointer->data->AccountStatus = "Active";
        }
        printf("\nAccount Status Changed!\n");
    }
}
void Transaction(List *pl)
{
    // Enter Bank Acc Id to transfer to
    long AccTransferTo;
    long Money;

    Node *tempPointer = pl->Head;
    Node *tempPointerMe = pl->Head;

    printf("Please enter bank account id to transfer to: ");
    scanf("%li", &AccTransferTo);

    while (AccTransferTo != tempPointer->data->BankAccountID)
    {
        tempPointer = tempPointer->Next;
    }
    while (ACCID != tempPointerMe->data->BankAccountID)
    {
        tempPointerMe = tempPointerMe->Next;
    }
    if (AccTransferTo == tempPointer->data->BankAccountID)
    {
        // Enter amount of money to transfer to this acc.
        printf("What is the amount of money to transfer ? \n");
        scanf("%li", &Money);
        
        // Make sure amount money is less than clinet balance balance.
        if (Money < tempPointer->data->Balance)
        {
            tempPointer->data->Balance = tempPointer->data->Balance + Money;
            tempPointerMe->data->Balance = tempPointerMe->data->Balance - Money;
        }
        else
        {
            printf("Can't Make Transaction ! \n");
        }
    }
    // Reciver
}

// 000000001
