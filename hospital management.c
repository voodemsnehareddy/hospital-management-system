#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
 void enter_patient_details(void);//function prototype for entering patient detail
 void view_patient_details(void);//function prototype for viewing patient detail
 void doctors_enquiry(void);//function prototype for doctors enquiry
 void details_of_software(void);//function prototype for getting details about software
 void for_feedback(void);//function prototype for taking feedback
 void quit(void);//function prototype for quitting the programme
 void log_in();//function prototype for log in as administrator
 exit(void);//exit prototype for exit function
 void usercheck(void);//function prototype for giving privilages between user and administrator
 char privilage='\0';
 void menu(void);//function prototype for calling the main menu
struct patient
{
char p_id[10];
char name[20];
char sex[10];
char age[4];
char address[50];
char diagnosis[200];
char bloodgroup[10];
char test[200];
};
void main()
{
 printf("welcome to");
 printf("\n ***** Hospital Management Simulation ***** ");
 userchk();//module checks the user and administrator
}
void usercheck()//module that differentiates user & administrator
 {
char passuser[]={"hospital"};// password for user
char passadmin[]={"authority"};//password for administrator
char s1[15];//entered password of administrator
int i=0;
char ch='\0';
char s2[15];//entered password of user
int us_choice;// choice between user and administrator
int us_check; // varible that compare integers
printf("\nenter choice\n 1 - administrator \n 2 - user \n");
scanf("%d",&us_choice);
if(us_choice==1)
{
printf(" enter password\n");
while(ch!=13)
{
ch=getch();
s1[i++]=ch;
printf("*");
}
s1[i-1]='\0';
us_check = stricmp(passadmin,s1);
 // printf("us_check=%d",us_check);
if(us_check==0)
{
printf("\nwelcome administrator");
privilage = 'a';
menu();
//return;
}
else
{
printf("\nentered password is wrong\n");
printf("\nPlease Choose the correct User Mode \n Enter correct password");
userchk();
}
}
if(us_choice==2)
{
printf("enter password\n");
while(ch!=13)
{
ch=getch();
s2[i++]=ch;
printf("*");
}
s2[i-1]='\0';
us_check = stricmp(passuser,s2);
 // printf("%d",us_check);
if(us_check==0)
{
printf("welcome user");
privilage = 'u';
menu();
}
else
{
printf("entered password is wrong");
}
}
}
void menu()
 {
 int choice;//choice for main menu
 int mm;// choice for the goto tag
 system("cls");
 printf("welcome to");
 printf("\n ***** Hospital Management Simulation ***** ");
 //main menu starts from here
 printf("\n ***********hospital management software***********");
 printf(" \n1 - Entering patient detail 2 - View patient detail ");
 printf(" \n3 - Doctors enquiry 4 - Details about software");
  printf(" \n5 - Feedback 6 - Exit ");
 printf(" \n7- Change current User Mode");
 printf(" \n");
 n1:
 printf("\n enter choice");
 scanf("%d",&choice);
 switch(choice)
 {
case 1 :
 printf("enter patient detail");
 enter_patient_details();//module for enterting patient detail
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 2 :
 printf(" view patient detail");
 view_patient_details();//module for veiwing existing patient detail
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 3 :
 printf("Welcome to doctor's enquiry section");
 doctors_enquiry();//module for doctors enquiry section
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 4:
 printf("details about software");
 details_of_software();// module for details about s/w n programmer
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 5 :
 printf(" welcome to feedback section:");
 for_feedback();// module for feedback
 printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
 break;
 }
case 6 :
 printf("you are about to exit");
 quit(); // module for exit
 /* printf(" \nwould you like to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
exit();
// break;
}*/
case 7 :
printf("case 7");
log_in();
printf(" \nwould you like to goto the main menu");
printf(" \n 1 - yes \t\t 0 - no\n\t");
scanf("%d",&mm);
if(mm==1)
 {
 menu();
}
 else
 {
exit();
// break;
}
default :
 printf("not valid");
 printf(" \nwould you liike to goto the main menu");
 printf(" \n 1 - yes \t\t 0 - no\n\t");
 scanf("%d",&mm);
 if(mm==1)
 {
menu();
}
else
{
break;
}
}
}
void enter_patient_details()//module for enterting patient detail
{
FILE *source;
char another='y';
struct patient detail;
source=fopen("pat_det.dat","ab");
while(another=='y' || another=='Y')
{
printf("\n Enter Details of a patient --\n");
printf("\n Patient ID : ");
fflush(stdin);
gets(detail.p_id);
printf("\n Name : ");
fflush(stdin);
gets(detail.name);
printf("\n Sex : ");
fflush(stdin);
gets(detail.sex);
printf("\n Age : ");
gets(detail.age);
printf("\n Bloodgroup : ");
fflush(stdin);
gets(detail.bloodgroup);
printf("\n Address : ");
fflush(stdin);
gets(detail.address);
printf("\n Diagnosis : ");
fflush(stdin);
gets(detail.diagnosis);
printf("\n Test : ");
fflush(stdin);
gets(detail.test);
if(source==NULL)
{
printf("\n Can not open file.");
}
else
{
// fprintf(source,"%s%s%s%s",detail->name,detail->p_id,detail->age,detail->sex);
fwrite(&detail,sizeof(detail),1,source);
fclose(source);
}
printf("\n Add another record (y/n) :");
another=getche();
}
}
void view_patient_details() //module for veiwing existing patient detail
{
FILE *target;
struct patient detail;
char ch;
target=fopen("pat_det.dat","rb");
if(target==NULL)
{
printf("\n Can not open file");
}
else
{
while(fread(&detail,sizeof(struct patient),1,target)==1)
{
printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
//fseek(target,sizeof(struct patient),SEEK_CUR);
}
fclose(target);
}
}
void doctors_enquiry()//module for d/module for doctors enquiry section
 {
 int choice1;
 printf("\n choose respected medical field");
 printf("\n 1 - surgeon \t 2 - neurology ");
 printf("\n 3 - orthopaedics \t4 - eye specialist ");
 printf("\n 5 - dermatologist  \t 6 - physician ");
 printf("\n enter field for which you want to see consultation time ");
 scanf("%d",&choice1);
 if(choice1==1)
 {
 printf("the timings are 11:00");
 }
 else if(choice1==2)
 {
 printf("the timings are 11:00");
 }
else if(choice1==3)
 {
 printf("the timings are 11:00");
 }
 else if(choice1==4)
 {
 printf("the timings are 11:00");
 }
 else if(choice1==5)
 {
 printf("the timinggs are 11:00");
 }
 else if(choice1==6)
 {
 printf("the timings are 11:00");
 }
 else{
 printf("invalid choice please retype again");
 }
 }
void details_of_software()// module for details about s/w n programmmer
 {
 printf("\n*****this section contains program n contact details*****");
 printf("\n hospital simulation software");
 printf("\n Company :- Smec infosystem\t\t \t Programmer :- sneha reddy");
 printf("\n Front End :- 'c' \t\t \t Back End :- MS word,files");
 printf("\n Contact Address:-SMEC COLLEGE OF ENGINEERING AND TECHNOLOGY\n \t\t dhulapally \n\t\t 500014");
 printf("\n Contact No.:-\t +919911003477,+919452967808");
 printf("\n Email : snehareddy@gmail.com \n \t smeccoders@gmail.com");
 printf("\n HOPE YOU LIKE IT");
 }
 void for_feedback()// module for feedback
 {
char feed_check;
FILE *feedback;
char feed[2000];//limit for feedback
printf(" \n You are welcomed for Feedback Section ");
printf(" \n Let us describe you the Requisites for giving Feedback ");
printf(" \n while the System is preparing itself for feedback ");
printf(" \n You are required to write your feedback regarding in not more than ");
printf(" \n 2000 characters,alphanumeic allowed and an space has its own value.");
 if(privilage=='u')
{ printf("\n\n\n\n\n\n\n\n Now give your feedback");
feedback =fopen("feed.txt","w+");
 if(feedback==NULL)
{
puts("cannot open file");
puts("cannot open file");
return;
}
fflush(stdin);
gets(feed);
fprintf(feedback,"%s",feed);
fclose(feedback);
}
 if(privilage=='a')
{
 printf("\n welcome Administrator");
 printf("\n Please select a task to do");
printf("\n a - to read feedback file \t b - append feedback for future visit\n\n\n\n\n\t");
 fflush(stdin);
 feed_check = getchar();
 if(feed_check=='a')
{
FILE *fopen(), *fp;
int c , linecount;
char filename[40], reply[40];
system("cls");
printf("Enter file name: ");
fflush(stdin);
gets( filename );
fp = fopen( filename, "r" ); /* open for reading */
if ( fp == NULL ) /* check does file exist etc */
{
printf("Cannot open %s for reading \n",
filename );
exit(); /* terminate program */
 }
linecount = 1 ;
reply[0] ='\0' ;
c = getc( fp ) ; /* Read 1st character if any */
while ( c != EOF && reply[0] != 'Q' && reply[0] !=
'q')
{
putchar( c ) ; /*
Display character */
if ( c == '\n' )
linecount = linecount+ 1 ;
if ( linecount == 20 )
{
linecount = 1 ;
printf("[Press Return to continue, Q to quit]");
gets( reply ) ;
}
c = getc ( fp );
}
fclose( fp );
 }
 if(feed_check=='b')
 {
feedback =fopen("feed.txt","a+");
 if(feedback==NULL)
{
puts("cannot open file");
return;
}
 fflush(stdin);
gets(feed);
fprintf(feedback,"%s",feed);
fclose(feedback);
 }
}
 }
 void quit()//module for exit
 {
     printf("\nplease wait the program ends");
        exit();
         }
  void log_in()//module for log in as administrator
  {
      usercheck();
  }

