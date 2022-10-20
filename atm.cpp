#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user
{
	char name[50];
	char phone[50];
	char pass[50];
	int money;
};

int menu()
{
	int temp;
	
	printf("==================");
	printf("\nChoose an option");
	printf("\n==================");
	printf("\n1. Register");
	printf("\n2. Login");
	printf("\n3. Exit");
	printf("\n==================");
	printf("\n\nInput: ");
	
	scanf("%d",&temp);
	getchar();
	
	return temp;
}

int menu2()
{
	int temp;
	
	printf("==================");
	printf("\nChoose an option");
	printf("\n==================");
	printf("\n1. Deposit");
	printf("\n2. Withdrawal");
	printf("\n3. Balance check");
	printf("\n4. Exit");
	printf("\n==================");
	printf("\n\nInput: ");
	
	scanf("%d",&temp);
	getchar();
	
	return temp;
}

int main()
{
	struct user usr[50];
	int acc=0;
	int temp=0;
	int curr;
	int depo;
	int wd;
	
	do
	{
		temp=menu();
		if(temp==1)
		{
			printf("\nEnter your name: ");
			scanf("%[^\n]",usr[acc].name);
			getchar();
			printf("\nEnter your phone number: ");
			scanf("%[^\n]",usr[acc].phone);
			getchar();
			printf("\nEnter your password: ");
			scanf("%[^\n]",usr[acc].pass);
			getchar();
			usr[acc].money=0;
			acc++;
			printf("\nData has been saved\n\n");
		}
		else if(temp==2)
		{
			temp=0;
			char name_log[50];
			char pass_log[50];
			do
			{
				temp=0;
				printf("\nEnter your name: ");
				scanf("%[^\n]",&name_log);
				getchar();
				for(int i=0;i<acc;i++)
				{
					if(strcmp(name_log,usr[i].name)==0)
					{
						temp=1;
						curr=i;
						break;
					}
				}
				if(temp==0)
				{
					printf("\nThat name is not in the database");
				}
			}while(temp==0);
			do
			{
				temp=0;
				printf("\nEnter your password: ");
				scanf("%[^\n]",&pass_log);
				getchar();
				if(strcmp(pass_log,usr[curr].pass)==0)
				{
					temp=1;
					break;
				}
				if(temp==0)
				{
					printf("\nIncorrect password");
				}
			}while(temp==0);
			
			do
			{
				temp=menu2();
				
				if(temp==1)
				{
					printf("\nInput how much money do you want to deposit: ");
					scanf("%d",&depo);
					getchar();
					usr[curr].money+=depo;
					temp=0;
				}
				else if (temp==2)
				{
					printf("\nInput how much money do you want to withdraw: ");
					scanf("%d",&wd);
					getchar();
					if(usr[curr].money<wd)
					{
						printf("\nYour withdrawal cannot be above your account balance\n");
					}
					else if(usr[curr].money>=wd)
					{
						usr[curr].money-=wd;
						temp=0;
					}
				}
				else if(temp==3)
				{
					printf("\nYour balance: %d\n",usr[curr].money);
				}
			}while(temp!=4);
			if(temp==4)
			{
				temp=0;
			}
		}
	}while(temp!=3);
		
	return 0;
}
