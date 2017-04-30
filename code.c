#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<conio.h>
#include<iostream>
#include<ctype.h>


void cunductexam();
void display();
void enter();
void exam();
void login(void);
void signup(void);
void delete1();
void calculate1(char *);
void calculate2(char *);
void calculate3(char *);
void question1(char *);
void question2(char *);
void question3(char *);
void quest(char *);
void question();
void marks1();
void marks2();
void marks3();
void crt_paper();

	
struct student
	 {
 	  char name[20];
	  char usn[20];
 	  char branch[20];
 	  char email_id[40];
	}s;


	
struct id
	{
	 char userid[50];
	 char passwd[50];
	}i;

struct question
	{
	 int q_num;
	 char q[400];
	 char op01,op02,op03,op04;
	 char opt1[20],opt2[20],opt3[20],opt4[20];
	 char ansh;
	}q;

struct anshwer
	{
	 char ans[3];
	 char usn[10];
	}a;

struct marks
	{
	int totmarks=0;
	char usn[10];
	}m;



int main()
{

char c,c1;

system("clear");

printf("\n\n\n\n\n\t  =====================================================================================================================================");
printf("\n\t   **  **  **  **  **  **  **  **  **  **  **  **  **  * WELCOME TO ONLINE EXAM ZONE *  **  **  **  **  **  **  **  **  **  **  **  **");
printf("\n\t  =====================================================================================================================================");

    l1:printf("\n\n\n\t\t\t\t\t\t 'L'ogin\t\t 'R'egister\t\t'E'xit");

printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
 
scanf("%c",&c);

c1=toupper(c);

switch(c1)  
{
    
	case 'L': system("clear");
		  login();
		  break;
    
	case 'R': system("clear");
                  signup();
                  break;
     
	case 'E': exit(1);
    
        default: printf("\n\n\t\t\t\t!!!INVALID CHOICE");

getchar();

}

goto l1;
 
return 0;

}


void signup()
{
    
FILE *fp;
    
char string[50],pass[50],pass1[50],*password,*password1; 

int flag,j;

char n,n1;

getchar();
     
l2:fp=fopen("userid_passwd.txt","ab+");

printf("\n\n\n\n\t\t\t\t-------------------------------------------------------------------------------------------");
printf("\n\t\t\t\t\t\t\t\tWELCOME TO 'SIGN UP' PAGE");
printf("\n\t\t\t\t-------------------------------------------------------------------------------------------");
printf("\n\n\n\n\t\t\t\t\t+-+-+-+--+-+-+-+-+-+-+--: ENTER YOUR DETAILS :-+-+-+-+-+-+-+-+-+-+-+-+-");

p: printf("\n\n\n\n\t\t\t\t\t\t USERNAME: ");
      
gets(string);

for(j=0;j<strlen(string);j++)
	
	{
	
		if(string[j]==' ')
   				
			{
     		
				printf("INVALID USERNAME , SHOUD NOT CONTAIN BLANK SPACE");
     				printf("\nTRY AGAIN");
				system("clear");
     				goto p;
     
   			}
  
	}
 
        
while(!feof(fp))
        
	{
          
		fread(&i,sizeof(i),1,fp);
          
		if(strcmp(string,i.userid)==0)
            
			{
				flag=0;
              
				printf("\n\n\n\n\t\t\t\t\t\t!!USERNAME EXISTS");
				printf("\n\n\t\t\t\t\t\tAGAIN TRY WITH DIFFERENT USERNAME");

				fseek(fp,0,SEEK_SET);

      				goto p;
            		}
          
		else
          
			{
				flag=1;
           
          		}
        }
  
if(flag)
           
strcpy(i.userid,string);

p1:password=getpass("\n\n\t\t\t\t\t\t PASSWORD: ");

strcpy(pass,password);

password1=getpass("\n\t\t\t\t\tre-enter PASSWORD: ");

strcpy(pass1,password1);


if(strcmp(pass1,pass)==0)
	{

		strcpy(i.passwd,password);
	} 

else
 	{
  		printf("\n\n\t\t\t\t\t\tPASSWORD IS INCORRECT, TRY AGAIN\n");
   	
		goto p1;
  	}     

system("clear");

p6:printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t'C'ontinue\n\n\n\t\t\t\t\t\t'B'ack\n\n\n\t\t\t\t\t\t'E'xit");

printf("\n\n\n\t\t\t\t\t\tENTER YOUR CHOICE: ");

scanf("%c",&n);

n1=toupper(n);

getchar();

switch(n1) 
	{
		
	case 'C': fwrite(&i,sizeof(i),1,fp);

        	  fclose(fp);

		  system("clear");
        
		  printf("\n\n\n\n\t\t\t\t\t\t\t\t~SIGN UP SUCCESSFULL~");
 
 	      l5: printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t CONTINUE TO 'S'IGN UP PAGE\n\n\n\n\t\t\t\t\t\t\t\t GO TO 'L'OGIN PAGE\n\n\n\n\t\t\t\t\t\t\t\t'E'XIT");

		  printf("\n\n\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE :");

		  scanf("%c",&n);

		  n1=toupper(n);        
	
		  switch(n1)
          
			{
              
				case 'S': system("clear");
                    			  signup();
                    			  break;
            
				case 'L': system("clear");
					  login();
					  break;
	
				case 'E': system("clear");
                    			  printf("\n\n\n\t\t\t\t\t\t\t\tTHANK YOU FOR REGISTERING\n\n\n\n\n\n\n\n");
                     			  exit(1);

       				default: printf("\n\n\t\t\t\t\t INVALID CHOICE!!!");
		
				getchar();
			
				goto l5;

          		}
        
		break;

	
	case 'B': fclose(fp);

		  system("clear");

		  goto l2;
		
  		  break;
	
	
	case 'E': exit(1);
	
 		  default:printf("\n\t\t\t\t\t!! INVALID CHOICE\n");
		 
		  goto p6;
		
		  break;
	}

    getchar();
}
  

void login()
    
{
      	FILE *fp;
      
	char n, userid[50], passwd[50], *password; 

	int  cmpuid, cmppsd, flag;
       
	fp=fopen("userid_passwd.txt","ab+");  
        printf("\n\n\n\n\t\t\t\t\t===================================================================");
	printf("\n\t\t\t\t\t\t\t\tWELCOME TO LOG IN PAGE");
      	printf("\n\t\t\t\t\t===================================================================");
     
    l3: printf("\n\n\t\t\t\t\tUSERNAME: ");
        
	scanf("%s",userid);

	getchar();

	password=getpass("\n\n\t\t\t\t\tPASSWORD: ");
        
	strcpy(passwd,password);
   
      
while(!feof(fp))
        
{
        
	fread(&i,sizeof(i),1,fp);
          
	cmpuid=strcmp(userid,i.userid);
          
	cmppsd=strcmp(passwd,i.passwd);
          
	if(cmpuid==0&&cmppsd==0)
          
		{

			flag=0;
  
			system("clear");

			printf("\n\n\n\t\t\t\t\t\t\t            SIGNING SUCCESSFULL\n") ;           
			printf("\n\n\n\n\n\n\t\t    \t\t\t\tW E L C O M E		T O	O N L I N E	E X A M 	Z O N E");
			printf("\n\t\t\t\t\t\t-------------------------------------------------------------------------");
			printf("\n");
			sleep(3);
 
			cunductexam(); 

            		break;

		}

        else if(cmpuid==0&&cmppsd!=0)

        	{
			flag=0;
	
            		printf("\n\n\t\t\t\t\tWRONG PASSWORD!! ");
            
    			fseek(fp,0,SEEK_SET);
            
     			goto l3;
                
		}

        else if(cmpuid!=0)

		{
			flag=1;

        	}

        }

 
        fclose(fp);
         
if(flag==1)
          
	{
		printf("\n\n\n\t\t\t\t\t\tYOU ARE NOT YET REGISTER");
	}
else
 
exit(1) ;   

}


void enter()
{
 
//	system("clear");

	int k,j,n,flag=0,x;
	
	fflush(stdin);	
	
	char usn1[20],usn2[20],usn3[20],email_id1[50],email_id2[50],c,name1[20],dep1[20];
	
	FILE *fp1;
	
	system("clear");

        printf("\n\n\t\t- - STUDENT REGISTRATION - -");
	
	fp1=fopen("student.txt","ab+");
	
	gotoxy(8,10);
	
	printf("\n\n\t\tName : ");
	
	gets(name1);
        
     p: printf("\n\n\t\tUSN : ");      
	 
	gets(usn1);
	 
	n=strlen(usn1);

	if(n>10)
         	{
           	printf("\n\tInvalid USN size must be 10 !!\n");
	 	}
        k=0;
	
	while(usn1[k]) 

	{
	 	usn2[k]=toupper(usn1[k]);
          	k++;
         
        }       
	
	usn2[k]='\0';
	
	for(j=0;j<strlen(usn1);j++)
		{
  	  	
			if(usn2[j]==' ')
   	   			{
     	     				printf("\n\n\tINVALID USN , SHOUD NOT CONTAIN BLANK SPACE");
     	     				printf("\n\n\tTRY AGAIN");
	    				// system("clear");
     	     				goto p;
	   			}
		}
	

while(!feof(fp1))
        
	{
          
		fread(&s,sizeof(s),1,fp1);
          
		if(strcmp(usn2,s.usn)==0)
            
			{
				flag=0;
              			
				printf("\n\n\t!!USN EXISTS");
				printf("\n\n\tTRY AGAIN");
				
				fseek(fp1,0,SEEK_SET);

     				 goto p;
            		}
          
		else
          
			{
				flag=1;
           
        		}
        }
  
	if(flag==1)
           
	strcpy(usn3,usn2);

	printf("\n\n\t\tBranch : ");
	
	gets(dep1);

    p1: printf("\n\n\t\tEmail id : ");
	 
	gets(email_id1);

        k=0;
        
	while(email_id1[k])
        
		{
         
			email_id2[k]=toupper(email_id1[k]);
          		k++;
        	}
	
	email_id2[k]='\0';
		
	for(j=0;j<strlen(email_id1);j++)

        	{
        		if(email_id2[j]==' ')
        			{
        				printf("\n\n\tINVALID EMAIL ID , SHOUD NOT CONTAIN BLANK SPACE");
        				printf("\n\n\tTRY AGAIN");
       					// system("clear");
        				goto p1;
        			}
        	}
	
	fseek(fp1,0,SEEK_SET);
	
	while(!feof(fp1))
        
		{
          
			fread(&s,sizeof(s),1,fp1);
          
			if(strcmp(email_id2,s.email_id)==0)
            
				{
	
					flag=0;
              
					printf("\n\n\t\t!!ONE STUDENT HAVE ALREADY THIS EMAIL\n");
					printf("\n\n\t\tAGAIN TRY WITH ANOTHER EMAIL ID\n");
	
					fseek(fp1,0,SEEK_SET);

      					goto p1;
        
				}
          
			else
          
				{
					flag=1;
           
        			}
        	}
  
	if(flag)
           
		strcpy(s.email_id,email_id2);
		
	strcpy(s.usn,usn2);
	
	strcpy(s.branch,dep1);
	
	strcpy(s.name,name1);
	
	fwrite(&s,sizeof(s),1,fp1);

        fclose(fp1);

printf("\n\n\t\t - - REGISTRATION SUCCESSFUL - -");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();

}


void display()

{

//system("clear");

FILE *fp1;

int count=0;

fp1=fopen("student.txt","rb");

//printf("\n\n\n\t\t - - L I S T   O F   A L L   S T U D E N T - - ");
 
while(fread(&s,sizeof(s),1,fp1))
	{	
		
		system("clear");

		printf("\n\n\n\t\t - - L I S T   O F   A L L   S T U D E N T - - ");

		count++;
		printf("\n\n\n\n\t\t\tS no.-%d",count); 	
        	printf("\n\n\n\t\t\tNAME : ");
        	puts(s.name);
	
		printf("\n\n\t\t\tUSN : ");
		puts(s.usn);
	
		printf("\n\n\t\t\tBranch : ");
		puts(s.branch);
	
		printf("\n\n\t\t\tEMAIL ID : ");
		puts(s.email_id);

                printf("\n\n\n\n\n\t\t\tPREE ENTER FOR 'NEXT' STUDENT RECORD");
		getchar();
		//system("clear");
 	}
 
	fclose(fp1);
printf("\n\n\t\tEND OF RECORD");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();
 
} 

void modify()
{
 
FILE *fp2,*fp3;

char USN[20],USN1[20],name1[30],branch1[20],email_id1[30],email_id2[30];

int flag=0,k=0,n;
 
system("clear");

fp2=fopen("student.txt","rb+");

fp3=fopen("temp.txt","w+");

printf("\n\n\n\t\t- - . . M O D I F I C A T I O N . . - -");

printf("\n\n\t\t  Enter USN of student : ");

gets(USN);

while(USN[k])

{

 USN1[k]=toupper(USN[k]);
 
k++;

}

USN1[k]='\0';



while(fread(&s,sizeof(s),1,fp2))

{
	
	if(strcmp(s.usn,USN1)!=0)
	
	{
		fwrite(&s,sizeof(s),1,fp3);
	
	}

	else
	{
	
	flag=1;

	printf("\n\n\n\t\tWHAT DO YOU WANT TO MODIFY\n\n\n\t\t1.NAME\n\n\t\t2.USN\n\n\t\t3.BRANCH\n\n\t\t4.EMAIL_ID");
 
        printf("\n\n\t\tEnter choice :");
	
	scanf("%d",&n);

	getchar();

	switch(n)

	{
		case 1:printf("\n\n\n\t\tEnter new NAME : ");

			gets(name1);

			strcpy(s.name,name1);

			break;

		case 2:printf("\n\n\n\t\tEnter new USN : ");

			gets(USN);
			k=0;
			
			while(USN[k])

			{

 			USN1[k]=toupper(USN[k]);

			k++;

			}			

			USN1[k]='\0';

			strcpy(s.usn,USN1);

			break;

		case 3:printf("\n\n\n\t\tEnter new BRANCH : ");

			gets(branch1);

			strcpy(s.branch,branch1);

			break;

		case 4:printf("\n\n\n\t\tEnter new EMAIL ID : ");

			gets(email_id1);

			k=0;

			while(email_id1[k])
			{
				email_id2[k]=toupper(email_id1[k]);
				k++;
			}
			email_id2[k]='\0';

			strcpy(s.email_id,email_id2);

			break;

		default:printf("\n\n\n\t\t\t !!!Invalid choice");
			break;
	}

	fwrite(&s,sizeof(s),1,fp3);

	}
}

if(flag==0)

{
	printf("\n\n\t\t\tUSN is not present");
}

else{
printf("\n\n\t\t--..UPDATE SUCCESSFUL..--");
}
fclose(fp2);

fclose(fp3);

fp3=fopen("temp.txt","rb");

fp2=fopen("student.txt","wb+");

while(fread(&s,sizeof(s),1,fp3))
{
 
 fwrite(&s,sizeof(s),1,fp2);

}

fclose(fp2);

fclose(fp3);

system("rm temp.txt");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");

getchar();

}


void delete1()

{

FILE *fp2,*fp3;

char USN[20],USN1[20];

int flag=0,k=0,n;
 
system("clear");

fp2=fopen("student.txt","rb+");

fp3=fopen("temp.txt","w+");

printf("\n\n\n\t\t- - D E L E T I O N - -");

printf("\n\n\n\t\t  Enter USN of student : ");

gets(USN);

while(USN[k])

{

 USN1[k]=toupper(USN[k]);
 
k++;

}

USN1[k]='\0';


while(fread(&s,sizeof(s),1,fp2))

{
	
	if(strcmp(s.usn,USN1)!=0)
	
	{
		fwrite(&s,sizeof(s),1,fp3);
	
	}

	else
	{
	
	flag=1;


	}
}

if(flag==0)

{
	printf("\n\n\n\t\t\t !!! USN is not present");
}

else
{

printf("\n\n\n\t\t\tDELETE SUCCESSFUL\n\n");

}

fclose(fp2);

fclose(fp3);

fp3=fopen("temp.txt","rb");

fp2=fopen("student.txt","wb+");

while(fread(&s,sizeof(s),1,fp3))

{

 fwrite(&s,sizeof(s),1,fp2);

}

fclose(fp2);

fclose(fp3);

system("rm temp.txt");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");

getchar();
 
}

void exam()

{

	FILE *fpp;
	
	int qn;

	char question[400];

	char op1,op2,op3,op4,ch;

	char opti1[100],opti2[100],opti3[100],opti4[100];

        char ans;
   
    p1: system("clear");

	printf("\n\n\t- - Q U E S T I O N   P R E P A R A T I O N - - ");

	fpp=fopen("question.txt","ab+");
   
	printf("\n\n\t\tEnter question number : ");
	scanf("%d",&qn);

	getchar();

	printf("\n\n\t\tEnter question : ");
	gets(question);
	
	printf("\n\n\t\tEnter option id1 : ");
	scanf("%c",&op1);
	getchar();

	printf("\n\n\t\tEnter option 1: ");
	gets(opti1);

 	printf("\n\n\t\tEnter option id2 : ");
	scanf("%c",&op2);
	getchar();

	printf("\n\n\t\tEnter option 2: ");
        gets(opti2);

	printf("\n\n\t\tEnter option id3 : ");
        scanf("%c",&op3);
	getchar();

	printf("\n\n\t\tEnter option 3: ");
        gets(opti3);
 
	printf("\n\n\t\tEnter option id4 : ");
        scanf("%c",&op4);
	getchar();
	

	printf("\n\n\t\tEnter option 4: ");
        gets(opti4);

 	printf("\n\n\t\tEnter answer :");
        scanf("%c",&ans);
        getchar();

	q.q_num=qn;	
	strcpy(q.q,question);

	q.op01=op1;
	strcpy(q.opt1,opti1);

	q.op02=op2;
	strcpy(q.opt2,opti2);

	q.op03=op3;
	strcpy(q.opt3,opti3);

	q.op04=op4;
	strcpy(q.opt4,opti4);
  
        q.ansh=ans;

	fwrite(&q,sizeof(q),1,fpp);
	fclose(fpp);

	printf("\n\n\t\t Do you want to enter next question (y/Y) : ");

	scanf("%c",&ch);

	if(ch=='y'||ch=='Y')
	goto p1;

printf("\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();

}

void crt_paper()
{

 FILE *fp,*fpp1,*fpp2,*fpp3;

 int i; 

 char array[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
 
 fp=fopen("question.txt","rb");

 fpp1=fopen("paper1.txt","ab+");

 fpp2=fopen("paper2.txt","ab+");

 fpp3=fopen("paper3.txt","ab+");

 while(fread(&q,sizeof(q),1,fp))

 {

  for(i=0;i<5;i++)

  { 

   if(q.q_num==array[i])

   {

    fwrite(&q,sizeof(q),1,fpp1);

   }

  }


  for(i=5;i<10;i++)

  {

   if(q.q_num==array[i])

   {

    fwrite(&q,sizeof(q),1,fpp2);

   }

  }


  for(i=10;i<15;i++)

  {

   if(q.q_num==array[i])

   {

    fwrite(&q,sizeof(q),1,fpp3);

   }

  }

 
 }

 fclose(fp);

 fclose(fpp1);

 fclose(fpp2);

 fclose(fpp3);

 system("clear");
 printf("\n\n\n\n\t\t\t\t\t\t- - :  QUESTION PAPER CREATION SUCCESSFULL : - -");
 printf("\n");
 sleep(2);
 
 

}


void quest(char USN[])

{


system("clear");

 char ch,ch1,usn[10];


l1:system("clear");

printf("\n\n\t\t- - C H O O S E  S U B J E C T  F O R   E X A M - -");

printf("\n\n\t\t\tA. Exam for subject 1\n\n\t\t\tB. Exam for subject 2\n\n\t\t\tC .Exam for subject 3 ");

printf("\n\n\tEnter your choice : ");

scanf("%c",&ch);

ch1=toupper(ch);

strcpy(usn,USN);

switch(ch1)

        {
                case 'A':question1(usn);
                        break;
                case 'B':question2(usn);
                        break;
                case 'C':question3(usn);
                        break;
                default:printf("\n\n\t\t!!!Invalid choice");
                        goto l1;
        }

}


void question()
{
 
 FILE *fp;

 char USN[11],USN1[11];

 int flag=1,k=0;

 system("clear");

 fp=fopen("student.txt","ab+");{

 perror("file");}

 printf("\n\n\t - - STUDENT LOGIN - -");

 printf("\n\n\n\t\tEnter USN : ");

//memset(USN,0,sizeof(USN));
//memset(USN1,0,sizeof(USN1));

gets(USN);

  while(USN[k])

{

USN1[k]=toupper(USN[k]);

k++;

}

USN1[k]='\0';

fseek(fp,0,SEEK_SET);

flag=1;

while(fread(&s,sizeof(s),1,fp))

{	

        if(strcmp(s.usn,USN1)==0)
         
	{
	
	flag=0;
	break;

        }
}

if(flag==1)

{
        printf("\n\n\t\t !!! USN is not present");

       printf("\n");

       sleep(3);

        fclose(fp);

}

else if(flag==0)
 
{

                printf("\n\n\t\tName : ");

                puts(s.name);

                printf("\n\n\t\tBranch : ");

                puts(s.branch);

		printf("\n\n\t\tEMAIL_ID:");

		puts(s.email_id);

                //sleep(3);
 
fclose(fp);

quest(USN1);

}

printf(" PRESS ENTER TO CONTINUE ");
getchar();

}



void question1(char USN[])

{
 
 getchar();
 
 int j=0,count=1;

 char ansh,ch,ch1;

 FILE *fp,*ans1,*fp1;

// system("clear");
  
 fp=fopen("paper1.txt","rb");

 while(fread(&q,sizeof(q),1,fp))

 {
 system("clear");

 printf("\n\n\n\n\t - - GIVE ANSWER FOR THIS QUESTION - -");

 printf("\n\n\n\t\t%d.",count++);

 printf("%s",q.q);
 
 printf("\n\n\n\t\t(%c).",q.op01);

 printf("%s",q.opt1);

 printf("\n\n\t\t(%c).",q.op02);

 printf("%s",q.opt1);

 printf("\n\n\t\t(%c).",q.op03);

 printf("%s",q.opt3);

 printf("\n\n\t\t(%c).",q.op04);

 printf("%s",q.opt4);
 
 printf("\n\n\n\t\tAns - ");

 scanf("%c",&ansh);

 getchar();

 a.ans[j]=ansh;

 j++;

 }
 
 strcpy(a.usn,USN);
 
 ans1=fopen("ansher1.txt","ab+");

 fwrite(&a,sizeof(a),1,ans1);

 fclose(ans1);

fclose(fp);

printf("\n\n\t\tEXAM COMPLETED");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();

calculate1(USN);

}

 

void question2(char USN[])

{

 getchar();

 int j=0,count=1;

 char ansh,ch,ch1;

 FILE *fp,*ans2,*fp1;

 system("clear");

 fp=fopen("paper2.txt","rb");

 while(fread(&q,sizeof(q),1,fp))

 {

 system("clear");

 printf("\n\n\n\n\t - - GIVE ANSWER FOR THIS QUESTION - -");


 printf("\n\n\n\t\t%d.",count++);

 printf("%s",q.q);

 printf("\n\n\n\t\t(%c).",q.op01);

 printf("%s",q.opt1);

 printf("\n\n\t\t(%c).",q.op02);

 printf("%s",q.opt1);

 printf("\n\n\t\t(%c).",q.op03);

 printf("%s",q.opt3);

 printf("\n\n\t\t(%c).",q.op04);

 printf("%s",q.opt4);
 
 printf("\n\n\n\t\tAns-");

 scanf("%c",&ansh);

 getchar();

 a.ans[j]=ansh;

 j++;

}
 
 strcpy(a.usn,USN);

 ans2=fopen("ansher2.txt","ab+");
 
 fwrite(&a,sizeof(a),1,ans2);
 
 fclose(ans2);

fclose(fp);

printf("\n\n\t\tEXAM COMPLETED");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();



calculate2(USN);

}


void question3(char USN[])

{

 getchar();

 int j=0,count=1;

 char ansh,ch,ch1;

 FILE *fp,*ans3,*fp1;

 system("clear");

 fp=fopen("paper3.txt","rb");

 while(fread(&q,sizeof(q),1,fp))

 {

  system("clear");

 printf("\n\n\n\n\t - - GIVE ANSWER FOR THIS QUESTION - -");



 printf("\n\n\n\t\t%d.",count++);

 printf("%s",q.q);

 printf("\n\n\n\t\t(%c).",q.op01);

 printf("%s",q.opt1);

 printf("\n\n\t\t(%c).",q.op02);

 printf("%s",q.opt1);

 printf("\n\n\t\t(%c).",q.op03);

 printf("%s",q.opt3);

 printf("\n\n\t\t(%c).",q.op04);

 printf("%s",q.opt4);
 
 printf("\n\n\n\t\tAns-");

 scanf("%c",&ansh);

 getchar();

 a.ans[j]=ansh;

 j++;

}

 strcpy(a.usn,USN);
// system("rm answer3.txt");

 ans3=fopen("ansher3.txt","ab+");

 fwrite(&a,sizeof(a),1,ans3);

 fclose(ans3);

fclose(fp);

printf("\n\n\t\tEXAM COMPLETED");

printf("\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();



calculate3(USN);

}

void calculate()

{

char ch,ch1;


system("clear");

l2:printf("\n\n\t\t - - M A R K S  C H E C K - - ");

printf("\n\n\t\tA. Calculate marks of subject 1\n\n\t\tB. Calculate marks of subject 2\n\n\t\tC .Calculate marks of subject 3");

printf("\n\n\t\tEnter Your choice : ");

scanf("%c",&ch);

ch1=toupper(ch);

switch(ch1)

	{
		case 'A':marks1();
			break;

		case 'B':marks2();
			break;

		case 'C':marks3();
			break;

		default:printf("!!!Invalid choice");
			goto l2;

	}
}



void calculate1(char USN[])

{

 FILE *fp,*fpp,*fp1;

 int count=0,i=0,j=0,flag=0;

 char ans1[3],ans2[3];
 
 fp=fopen("paper1.txt","ab+");

 while(fread(&q,sizeof(q),1,fp))

 { 

  ans1[i]=q.ansh;

  i++;

 }

 i=0;

 system("rm ansher1.txt");

 fpp=fopen("ansher1.txt","ab+");

 fread(&a,sizeof(a),1,fpp);

 strcpy(ans2,a.ans);

 count=0;

 for(i=0,j=0;i<5;i++,j++)
  
  {

    if(ans1[i]==ans2[j])

      {

        count=count+4;

     //   printf("%d",count);
    
      }

    else

	{

	 count=count-1; 

//	 printf("%d",count);

 	}

}

//printf("total marks1 = %d",count);


fp1=fopen("marks1.txt","ab+");

m.totmarks=count;

//printf("%d",m.totmarks);

strcpy(m.usn,USN);

fwrite(&m,sizeof(m),1,fp1);

fclose(fp1);

fclose(fpp);

fclose(fp);

}


void marks1()

{

 system("clear");

 getchar();

 int count=1,k=0,flag=0;

 char USN[11],USN1[10];

 FILE *fp,*fp1;

 fp1=fopen("marks1.txt","ab+");

 printf("\n\n\t\t- - M A R K S  O F  S U B J E C T  1 - - ");

 printf("\n\n\t\tEnter USN : ");

 gets(USN);

 while(USN[k])

   {

    USN1[k]=toupper(USN[k]);

    k++;

   }

 USN1[k]='\0';

 while(fread(&m,sizeof(m),1,fp1))

        {

        if(strcmp(m.usn,USN1)==0){

        flag=1;

        printf("\n\n\n\n\t\tTEST %d",count++);

	printf("\n\n\t\tMARKS=%d",m.totmarks);

       }

      }

if(flag==0)

	{

        printf("i\n\n\t\tUSN is not present");

	}

fclose(fp1);

printf("\n\n\n\n\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();

}



void calculate2(char USN[])

{

 FILE *fp,*fpp,*fp1;

 int count=0,i=0,j=0,flag=0;

 char ans1[3],ans2[3];

 fp=fopen("paper2.txt","ab+");

 while(fread(&q,sizeof(q),1,fp))

  {

   ans1[i]=q.ansh;

   i++;

  }

 i=0;
 
 system("rm ansher2.txt");

 fpp=fopen("ansher2.txt","ab+");

  {perror("file");}
 
 fread(&a,sizeof(a),1,fpp);

 strcpy(ans2,a.ans);

 count=0;

 for(i=0,j=0;i<5;i++,j++)
  
  {

   if(ans1[i]==ans2[j])

    {

      count=count+4;

    }

 else

   {

     count=count-1; 

   }

 }

//printf("total marks2 = %d",count);

fp1=fopen("marks2.txt","ab+");

{perror("file");}

m.totmarks=count;

//printf("%d",m.totmarks);

strcpy(m.usn,USN);

fwrite(&m,sizeof(m),1,fp1);

fclose(fp1);

fclose(fpp);

fclose(fp);

}






void marks2()

{

 getchar();

 int count=1,k=0,flag=0;

 char USN[11],USN1[10];

 FILE *fp,*fp1;


 fp1=fopen("marks2.txt","ab+");

 system("clear");

 printf("\n\n\t\t- - M A R K S   O F   S U B J E C T  2 - -");


 printf("\n\n\t\tEnter USN : ");

 gets(USN);

 while(USN[k])

  {

    USN1[k]=toupper(USN[k]);

    k++;

  }

 USN1[k]='\0';


 while(fread(&m,sizeof(m),1,fp1))

        {

        if(strcmp(m.usn,USN1)==0)

	 {

         flag=1;

         printf("\n\n\n\n\t\tTEST %d",count++);

         printf("\n\n\t\tMARKS=%d",m.totmarks);

        }

      }

 if(flag==0)

  { 

        printf("\n\n\t\t !!! USN is not present");

  }

fclose(fp1);
printf("\n\n\n\n\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();
}





void calculate3(char USN[])

{

 FILE *fp,*fpp,*fp1;

 int count=0,i=0,j=0,flag=0;

 char ans1[3],ans2[3];

 fp=fopen("paper3.txt","ab+");

 while(fread(&q,sizeof(q),1,fp))

  {

   ans1[i]=q.ansh;

   i++;
 }

 i=0;

 system("rm ansher3.txt");

 fpp=fopen("ansher3.txt","ab+");

 fread(&a,sizeof(a),1,fpp);

 strcpy(ans2,a.ans);

 count=0;

 for(i=0,j=0;i<5;i++,j++)
  
  {

   if(ans1[i]==ans2[j])

    {

      count=count+4;

   //   printf("%d",count);

   }

else

{

 count=count-1;

// printf("%d",count);

}

}

//printf("total marks1 = %d",count);


 fp1=fopen("marks3.txt","ab+");

 m.totmarks=count;

// printf("%d",m.totmarks);

 strcpy(m.usn,USN);

 fwrite(&m,sizeof(m),1,fp1);

 fclose(fp1);
 
 fclose(fpp);

 fclose(fp);

}






void marks3()

{

 getchar();

 int count=1,k=0,flag=0;

 char USN[11],USN1[10];

 FILE *fp,*fp1;

 fp1=fopen("marks3.txt","ab+");

 system("clear");

 printf("\n\n\t\t- - M A R K S   O F   S U B J E C T  3 - -");

 printf("\n\n\t\tEnter USN : ");

 gets(USN);

 while(USN[k])

  {

    USN1[k]=toupper(USN[k]);

    k++;

  }

 USN1[k]='\0';

 while(fread(&m,sizeof(m),1,fp1))

        {

         if(strcmp(m.usn,USN1)==0)
	 
          {
  
           flag=1;
   
           printf("\n\n\n\n\t\tTEST %d",count++);
    
           printf("\n\n\t\tMARKS=%d",m.totmarks);
     
          }

        }

 if(flag==0)

   {

        printf("\n\n\t\tUSN is not present");

   }

fclose(fp1);

printf("\n\n\n\n\n\n\t\tPRESS ENTER TO CONTINUE");
getchar();
}



void cunductexam()

{

 system("clear") ;
 
 char c;

 int x; 

 while(1)
	{

	system("clear");

        gotoxy(60,10);
	
	printf("=================================");

	gotoxy(60,11);

	printf("\t  - - O P T I O N S - -");

	gotoxy(60,12);

	printf("=================================");
    
 		printf("\n\n\n\n\n\t\t1.Register student\n\n\t\t2.Detail of all register students\n\n\t\t3.Modify student detail\n\n\t\t4.Delete student\n\n\t\t5.Prepare Questions\n\n\t\t6.Start exam \n\n\t\t8.Create paper \n\n\t\t9.balculate \n\n\t\t10.exit");
 		printf("\n\n\t\tEnter Your Choice _");
        	
		scanf("%d",&x);
	
		getchar();
       
        	switch(x)
        		
			{
                	
				case 1:enter();
                       			break;
                		
				case 2:display();
                        		break;

				case 3:modify();
					break;

				case 4:delete1();
					break;

				case 5:exam();
					break;

				case 6:question();
					break;

				case 8:crt_paper();
					break;

				case 9:calculate();
					break;

				case 10:exit(0);                

			       default:printf("\n\n\t\tINVALID CHOICE!!!\n") ;
		       			break;
        		}
	}
}
