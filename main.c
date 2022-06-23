#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define Employee struct emp

void add();
void menu();
void remove_data();
void list();
void edit();

struct emp
{
    char name[50];
    int id;
    int age;
    char job[10];
    float salary;
    char gender[10];
    int phone[15];
    char mail[100];
};

int main()
{
    menu();

    return 0;
}

void add()
{
    Employee e;
    char next = 'y';

    while(next=='y'||next=='Y')
    {

        printf("\n\n****************************************************************\n");
        printf("\t\t\tAdd Employee");
        printf("\n****************************************************************\n\n");
        printf("\nEnter the name of employee: ");
        scanf("%s",&e.name);
        printf("\nEnter the id of employee: ");
        scanf("%d",&e.id);
        printf("\nEnter the age of employee: ");
        scanf("%d",&e.age);
        printf("\nEnter the job of employee: ");
        scanf("%s",&e.job);
        printf("\nEnter the salary of employee: ");
        scanf("%f",&e.salary);
        printf("\nEnter the gender of employee: ");
        scanf("%s",&e.gender);
        printf("\nEnter the phone number of employee(without '-'): ");
        scanf("%d",&e.phone);
        printf("\nEnter the email of employee: ");
        scanf("%s",&e.mail);

        printf("\n\nEnter 'Y' to continue adding or 'N' to quit: ");
        scanf("%s",&next);

    }
    menu();
}

void menu()
{
    int choice;

    printf("\n\n****************************************************************\n");
    printf("\t\t\tEmployee Management System");
    printf("\n****************************************************************\n\n");
    printf("Choose the function that you want to use");
    printf("\n1.Add\n2.Remove\n3.Edit\n4.Show Record\n");
    printf("INPUT: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        remove_data();
        break;
    case 3:
        edit();
        break;
    case 4:
        list();
        break;
    default:
        printf("Invalid number entered.");
        menu();
    }
}

void remove_data()
{
    printf("You had choosen the remove fucntion");
    menu();
}

void list()
{
    printf("You had choosen the list fucntion");
    menu();
}

void edit()
{
    printf("You had choosen the edit fucntion");
    menu();
}
