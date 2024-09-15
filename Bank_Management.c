#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void menu();
void transfer(); void cho(); void depposite(); void withdrawl(); void cheak();
void passbook();
int choice, num, dipp=0, with=0, tra=0, balance=0, i=0, j=0;
char name[20];
int history[50];


int main()
{
  printf("\n  enter your name: ");
  fgets(name, 20, stdin);
  printf("\n\n  enter last 4 digits of your account number: ");
  scanf("%d", &num);
  menu();
  printf("\n  Enter your choice:");
  scanf("%d", &choice);
  while(1){
  cho();
  printf("\n  Enter your choice:");
  scanf("%d", &choice);
  i++;
  }
  return 0;
}


void menu(){
  printf("\n  1. depposite money: ");
  printf("\n  2. withdrawl money: ");
  printf("\n  3. transfer money: ");
  printf("\n  4. cheak bank balance: ");
  printf("\n  5. show passbook: ");
  printf("\n  6. show transation history: ");
  printf("\n  7. to take Exit\n\n");
  getch();
  return;
}
void cho(){
  switch(choice){
    case 1:
    depposite();
    break;

    case 2:
    withdrawl();
    break;

    case 3:
    transfer();
    break;

    case 4:
    cheak();
    break;

    case 5:
    passbook();
    break;

    case 6:
    for(j=0; j<=i-3; j++){
    if(history[j] == 0)
    printf("\n\n  transation failed!: %d",history[j]);
    else
    printf("\n\n  history is: %d",history[j]);}
    break;
    
    case 7:
    printf("\n\n  press to confirm Exit!");
    getchar();
    exit(0);
    break;

    default:
    printf("\n\n  Something Eror!");

  }
  
return;
}

void depposite(){
  printf("\n\n  enter deppositable ammount: ");
  scanf("%d", &dipp);
  if(dipp>=0){
    balance += dipp;
    history[i] = +dipp;
  printf("\n  dipposite succesfully");}
  else
{  printf("\n\n  invalid request");
depposite();
} 
}

void withdrawl(){
  printf("\n\n  enter withdrawl ammount: ");
  scanf("%d", &with);
  if(with>=0){ if (with<=balance){
    balance -= with;
    history[i] = -with;
  printf("\n  withdrawl succesfully");}
  else{
  printf("\n\n  insufficient balance!");
  withdrawl();}
  }
  else
{  printf("\n\n  invalid request");
withdrawl();
} 
}

void transfer(){
  printf("\n\n  enter tranferable ammount: ");
  scanf("%d", &tra);
  if(tra>=0){
    if(tra<=balance)
    {balance -= tra;
    history[i] = -tra;
  printf("\n  transfered succesfully");
    }
    else{
    printf("\n\n  insufficien balance");
    transfer();}
  }
  else
{  printf("\n\n  invalid request");
transfer();
} 
}

void cheak(){
  printf("\n  balance :%d", balance);
}

void passbook()
{ printf("\n********************************");
  printf("\n  Accont Holder: %s", name);
  printf("  Account number: %d", num);
  printf("\n  total balance: %d", balance);
  printf("\n  recent withdrawled balance: %d", with);
  printf("\n  recent transfered balance: %d", tra);
  printf("\n********************************\n");
}