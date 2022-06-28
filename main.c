#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 20

void add();
void menu();
void deleterecord();
void deleteindex(int i);
void list();
void edit();
void showalldata();
void quit();

struct employee {
  char name[50];
  long int id;
  int age;
  char job[100];
  float salary;
  char gender[10];
  int phone;
  char mail[100];
};

int num=0;
struct employee emp[max];

int main()
{
  menu();

  return 0;
}

void menu()
{
  char choice[2];
  char fname[20];
  char next='y';

  printf("\n\n****************************************************************\n");
  printf("\t\tEmployee Management System");
  printf("\n****************************************************************\n\n");
  printf("Choose the function that you want to use (Type the Number)");
  printf("\n1.Add\n2.Remove\n3.Edit\n4.Search Employee\n5.Show All Data\n6.Quit\n");
  printf("\n\nINPUT: ");
  scanf("%s", &choice);

  void (*f[5])() = {add, deleterecord, edit, list, showalldata};

  switch(choice[0]-48)
  {
  case 1:
    strcpy(fname,"add");
    break;
  case 2:
    strcpy(fname,"remove");
    break;
  case 3:
    strcpy(fname,"edit");
    break;
  case 4:
    strcpy(fname,"search employee");
    break;
  case 5:
    strcpy(fname,"show all data");
    break;
  case 6:
    strcpy(fname,"quit");
    break;
  default:
    strcpy(fname,"NULL");
  }

  if ((int)choice[0] >= 49 && (int)choice[0] <= 54){
        printf("\n\nYou had chosen %s function",fname);
        printf("\nDo you want to continue(Y for continue, N for Quit): ");
        scanf("%s",& next);
        if(next=='y'||next=='Y'){
           (*f[choice[0]-49])() ;
        }
        else{
            menu();
        }
  }
  else {
        printf("Invalid number entered.");
        menu();
  }
}

void add()
{
  int i=0;
  if (num < max)
  {
      int i = num + 1;
      printf("\n\n****************************************************************\n");
      printf("\t\t\tAdd Employee");
      printf("\n****************************************************************\n\n");
      printf("Enter the name of employee: ");
      scanf("%s", &emp[i].name);
      printf("\nEnter the id of employee: ");
      scanf("%ld", &emp[i].id);
      printf("\nEnter the age of employee: ");
      scanf("%d", &emp[i].age);
      printf("\nEnter the job of employee: ");
      scanf("%s", &emp[i].job);
      printf("\nEnter the salary of employee: ");
      scanf("%f", &emp[i].salary);
      printf("\nEnter the gender of employee: ");
      scanf("%s", &emp[i].gender);
      printf("\nEnter the phone number of employee(without '-'): ");
      scanf("%d", &emp[i].phone);
      printf("\nEnter the email of employee: ");
      scanf("%s", &emp[i].mail);
      num++;
  }
  else
  {
    printf("Employee Menu is full.\n");
  }
  char next = 'y';
  printf("Do you want to continue(Y for continue, N for Quit): ");
  scanf("%s",& next);
  if(next=='y'||next=='Y'){
      add();
  }
  else{
    menu();
  }
}

void deleterecord()
{
  printf("\n\n****************************************************************\n");
  printf("\t\t\tDelete Record");
  printf("\n****************************************************************\n\n");
  long int code;
  printf("Enter the employee's ID to delete record: ");
  scanf("%ld",&code);

  int a=-1;
  for (int i = 0; i <= num; i++) {
    if (emp[i].id == code) {
       a=i;
    }
  }

  if (a==-1){
    printf("Can't find this employee!\n");
  }
    else {
      deleteIndex(a);
      num--;
    }
  char next='y';
  printf("Do you want to continue(Y for continue, N for Quit): ");
  scanf("%s",& next);
  if(next=='y'||next=='Y'){
      deleterecord();
  }
  else{
    menu();
  }
}

void deleteIndex(int i)
{
  for (int j = i; j <= num - 1; j++)
  {
    strcpy(emp[j].name, emp[j + 1].name);
    emp[j].id = emp[j + 1].id;
    emp[j].age = emp[j + 1].age;
    strcpy(emp[j].job, emp[j + 1].job);
    emp[j].salary = emp[j + 1].salary;
    strcpy(emp[j].gender, emp[j + 1].gender);
    emp[j].phone = emp[j + 1].phone;
    strcpy(emp[j].mail, emp[j + 1].mail);
  }
}

void edit()
{
  long int employeenumber;

  printf("\n\n****************************************************************\n");
  printf("\t\t\tEdit Employee's Data");
  printf("\n****************************************************************\n\n");
  printf("Please input id of employee who you want to edit:");
  scanf("%ld", &employeenumber);

  int a=-1;
  for (int i = 0; i <=num;i++) {
    if (employeenumber ==emp[i].id)
    {
      a=i;
    }
  }

    if (a==-1){
      printf("\nCan't find this employee!\n");
    }
      else {
        printf("\n\nEmployee found!\n");
        printf("\nNew name of employee:");
        scanf("%s", &emp[a].name);
        printf("\nNew ID of employee:");
        scanf("%ld", &emp[a].id);
        printf("\nNew age of employee:");
        scanf("%d", &emp[a].age);
        printf("\nNew job of employee:");
        scanf("%s", &emp[a].job);
        printf("\nNew salary of employee:");
        scanf("%f", &emp[a].salary);
        printf("\nNew gender of employee:");
        scanf("%s", &emp[a].gender);
        printf("\nNew phone number of employee:");
        scanf("%d", &emp[a].phone);
        printf("\nNew mail of employee:");
        scanf("%s", &emp[a].mail);
      }

  char next='y';
  printf("Do you want to continue(Y for continue, N for Quit): ");
  scanf("%s",& next);
  if(next=='y'||next=='Y'){
      edit();
  }
  else{
    menu();
  }
}

void list()
{
    long int code;
    int a=-1;
    printf("\n\n****************************************************************\n");
    printf("\t\t\tData Of Employee");
    printf("\n****************************************************************\n\n");
    printf("Enter the Employee ID to Show Record: ");
    scanf("%ld",&code);

    for (int i = 0; i <= num; i++){
        if (emp[i].id == code){
          a=i;
        }
    }

    if (a==-1){
      printf("\nCan't find this employee!\n");
    }
      else {
        printf("\n\n\nName of employee: %s", emp[a].name);
        printf("\n\nID of employee: %ld", emp[a].id);
        printf("\n\nAge of employee: %d", emp[a].age);
        printf("\n\nJob of employee: %s", emp[a].job);
        printf("\n\nSalary of employee: %.2f", emp[a].salary);
        printf("\n\nGender of employee: %s", emp[a].gender);
        printf("\n\nPhone number of employee: %d", emp[a].phone);
        printf("\n\nMail of employee: %s", emp[a].mail);
      }

    char next='y';
    printf("\nDo you want to continue(Y for continue, N for Quit): ");
    scanf("%s",& next);
    if(next=='y'||next=='Y'){
        list();
    }
    else{
        menu();
    }
}

void showalldata()
{
  printf("\n\n****************************************************************\n");
  printf("\t\t\tAll Data Of Employee");
  printf("\n****************************************************************\n\n");
  for(int i=0; i<num; i++)
  {
    printf("\n\nName of employee: %s", emp[i+1].name);
    printf("\nID of employee: %ld", emp[i+1].id);
    printf("\nAge of employee: %d", emp[i+1].age);
    printf("\nJob of employee: %s", emp[i+1].job);
    printf("\nSalary of employee: %.2f", emp[i+1].salary);
    printf("\nGender of employee: %s", emp[i+1].gender);
    printf("\nPhone number of employee: %d", emp[i+1].phone);
    printf("\nMail of employee: %s", emp[i+1].mail);
  }
  char next='y';
  printf("\n\nDo you want to continue(Y for continue, N for Quit): ");
  scanf("%s",& next);
  if(next=='y'||next=='Y'){
      showalldata();
  }
  else{
    menu();
  }
}

void quit()
{
    return 0;
}
