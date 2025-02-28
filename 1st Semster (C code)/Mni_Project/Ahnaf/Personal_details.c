
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();
void list();
void edit();
void delete1();
void search();


void login()
{

	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="admin";
    do
{
	system("cls");

    printf("\n  =============  LOGIN FORM  =============  ");
    printf(" \n        ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n        ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

int main(){
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;

	system("cls");
 	printf("\t\t=============================================\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|       ----------------------------        |\n");
	printf("\t\t|           HOTEL BOOKING SYSTEM            |\n");
	printf("\t\t|       ----------------------------        |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t=============================================\n\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nDate and Time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");

	getch();
    system("cls");
    login();
    system("cls");
	while (1)
	{
		system("cls");

        for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t\t|MAIN MENU|  \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t Select an option:");
		printf("\n\n");
		printf(" \n 1 Book a room");
		printf(" \n 2 View Customer Detail");
		printf(" \n 3 Delete Customer Detail");
		printf(" \n 4 Search Record");
		printf(" \n 5 Update Record");
		printf(" \n 6 Exit");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nDate and Time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t ****THANK YOU****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
			//	Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

void add()
{
	FILE *f;
	char test;
	f=fopen("cus.txt","a+");
	if(f==0)
	{   f=fopen("cus.txt","w+");
		system("cls");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("cus.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{

		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("cus.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");

		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("cus.txt");
	rename("temp.txt","cus.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("cus.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("cus.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}