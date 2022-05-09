#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char*  get_address(){
    char address [30];
    printf("Please Entre client address: ");
    fgets(address, 30,stdin);
    char * r = malloc(30);
    // printf("\n");
    getchar();
    return strcpy(r,address);

}

long get_national_id(int t){
    long id ;
    if(t== 0){
    printf("Enter Client National ID: ");
    
    }else{
    printf("Enter Gurdian National ID: ");
    }
    scanf("%ld",&id);
    // printf("\n");
    return id;
}
long gen_account_id(long last_id){
    // long last_id;
    // if (n != NULL){
    //     last_id = n->data->BankAccountID;
    // }else{ last_id = 0;}

    // static long id = 0;
    return ++last_id;
}

char*  get_name(int t){
    char name [30];
    if(t == 0){
        printf("Please Entre client name: ");
    }else{
        printf("Enter gurdian name : ");
    }
    fgets(name, 30,stdin);
    char * r = malloc(30);
    return strcpy(r,name);
}


int get_age(){
    int age;
    printf("Enter client age: ");
    scanf("%d",&age);
    // printf("\n");
    return age;
}
Data * new_account(){
    // Node * last_client;
    Data * new;
    int g;
    new =(Data *) malloc(sizeof(Data));
    // if (List_int_is_Empty(db)){
    //     last_client = NULL;
    // }else{
    //     last_client = get_last_client(db);
    // }
    (*new).ClientFullNmae = get_name(0);
    (*new).Age = get_age();
    (*new).BankAccountID = gen_account_id(324);
    printf("Account Id Generated\n");
    (*new).NationalID = get_national_id(0);
    (*new).AccountStatus = "Active";
    printf("Enter Account Balance: ");
    scanf("%ld", &(*new).Balance);
    
    // getchar();
    
    printf("Does client have Gurdian (enter 1 for yes, 0 for no: ");
    scanf("%d",&g);
    if ( g == 0){
        (*new).GurdianID = 0;
        (*new).GurdianName = "None";
    }else{
        
        (*new).GurdianName = get_name(1);
        (*new).GurdianID = get_national_id(1);
    }
    (*new).ClientAddress = get_address();
    (*new).Password = (*new).NationalID;
    return new;
}

void main(){
//    const char * s ;
//    const char * a;
//     s = get_name(0);
//     a = get_address();
//     printf("your s is: %s",s);
    // printf("\n");
    Data * test;
    printf("your address is: Done****\n");
    system("clear");
    test = new_account();
    printf("your address is: Done****");
    printf("\n");
    system("clear");
    getchar();

}



// char*  get_address(){
//     char address [30];
//     printf("Please Entre client address: ");
//     fgets(address, 30,stdin);
//     char * r = malloc(30);
//     // printf("\n");
//     getchar();
//     return strcpy(r,address);

// }

// char*  get_name(int t){
//     char name [30];
//     if(t == 0){
//         printf("Please Entre client name: ");
//     }
//     fgets(name, 30,stdin);
//     char * r = malloc(30);
//     // printf("\n");
//     // getchar();
//     return strcpy(r,name);
// }