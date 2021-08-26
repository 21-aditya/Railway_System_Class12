//				Header Files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<time.h>
#include<dos.h>
#include<fstream.h>

//				validate

void showproject()
{
 cout<<"\t\tBEYOND BORDERS TRAVELLING AND BOOKING CORPORATIONS\n";
}
void showname(char a[])
{
 cout<<"Welcome "<<a<<endl;
}

int validate(int a,int b, int c)
{int ch;
 if((a<=0)||(b<=0)||(c<=0))
   {ch=0;
   }
 else
   {if((a<=29)&&(b==2)&&(c%4==0))
	 ch=1;
    else if((a<=31)&&((b==1)||(b==3)||(b==5)||(b==7)||(b==8)||(b==10)||(b==12)))
	   ch=1;
    else if((a<=30)&&((b==4)||(b==6)||(b==9)||(b==11)))
	   ch=1;
    else if((a<=28)&&(b==2)&&(c%4!=0))
	   ch=1;
    else
	ch=0;
   }
 if(ch==0)
   cout<<"\nInvalid date .Please check\n";
   getch();
   return ch;
}

//				classes and Structures
class login
{
 private:
    char id[100];
 protected:
    char pass[100];
 public:
    char name[20];
    void getid();
    void displayid()
    {   cout<<"Name:";
	puts(name);
	cout<<"ID:";
	puts(id);
	cout<<"Password:";
	puts(pass);
    }
    int check(char *a,char *b)
    {if((strcmpi(id,a)==0)&&(strcmp(pass,b)==0))
	return 1;
     else
	return 0;
    }
};

void login::getid()
{   int i;
	cout<<"\nName :";
	gets(name);
	cout<<"\nUser ID:";
	gets(id);
	cout<<"Enter the password:";
	for(i=0;;)
	   {pass[i]=getch();
	    if((int(pass[i])==8)&&(i>0))
	      {cout<<"\b \b";
	       i--;
	      }
	    else
	    if(int(pass[i])==13)
	      {pass[i]='\0';
	       break;
	      }
	    else
	      {i++    ;
	       cout<<'*';
	      }
	   }
}

class detail
{
 private:
    char tname[100];
    int tno;
 public:
    int c1,c1fare,c2,c2fare,d,m,y,flag6,d1,d2,d3,d4,x,y1;
    char bp[100],dest[100],dest1[100],temp;
    void getdetail();
    void displaydetail(int y2)
    {   gotoxy(1,y2);
	cout<<tno;
	gotoxy(15,y2);
	cout<<tname;
	gotoxy(30,y2);
	cout<<bp;
	gotoxy(45,y2);
	cout<<dest;
	gotoxy(60,y2);
	cout<<d<<"-"<<m<<"-"<<y<<"\t";

    }
    int check(int b)
    {if(b==tno)
	return 1;
     else
	return 0;
    }
};
void detail::getdetail()
{
	randomize();
	cout<<"Enter the details as follows\n";
	tno=10000+random(89999);
	cout<<"Boarding point:";
	gets(bp);
	cout<<"Destination pt:";
	gets(dest);
	strcpy(dest1,dest);
	strcat(dest1," Exp");
	strcpy(tname,dest1);
	cout<<"No of seats in first class:";
	cin>>c1;
	cout<<"Fare per Ticket:";
	cin>>c1fare;
	cout<<"No of seats in second class:";
	cin>>c2;
	cout<<"Fare per Ticket:";
	cin>>c2fare;
	do
	{ cout<<"Date of travel:";
	  x=wherex();y1=wherey();
	  cout<<"dd-mm-yyyy";
	  gotoxy(x,y1);
	  temp=getch();cout<<temp;
	  d1=(temp-48);
	  temp=getch();cout<<temp;
	  d2=(temp-48);
	  d=(d1*10)+d2;
	  x+=3;
	  gotoxy(x,y1);
	  temp=getch();cout<<temp;
	  d1=(temp-48);
	  temp=getch();cout<<temp;
	  d2=(temp-48);
	  m=(d1*10)+d2;
	  x+=3;
	  gotoxy(x,y1);
	  temp=getch();cout<<temp;
	  d1=(temp-48);
	  temp=getch();cout<<temp;
	  d2=(temp-48);
	  temp=getch();cout<<temp;
	  d3=(temp-48);
	  temp=getch();cout<<temp;
	  d4=(temp-48);
	  y=(d1*1000)+(d2*100)+(d3*10)+d4;
	  x+=3;
	  flag6=validate(d,m,y);
	}
	while(flag6==0);
}

struct reser
{
    int PNR,tno,age[20],nosr,i,d,m,y,d1,d2,d3,d4,x,y1;
    char tname[100],bp[10],dest[100],pname[10][100],clas[10];
    float amc;
    char STATUS,temp;
    void getresdet();
    void displayresdet();
    void getcancdet();
    void displaycancdet();
    int check1(int);
};

void reser::getresdet()
{
	cout<<"Enter the details as follows\n";
	cout<<"Train no:";
	cin>>tno;
	cout<<"Train name:";
	gets(tname);
	cout<<"Boarding point:";
	gets(bp);
	cout<<"Destination pt:";
	gets(dest);
	cout<<"No of seats required:";
	cin>>nosr;
	for(i=0; i<nosr ; i++)
	{
	    cout<<"Passenger name:";
	    gets(pname[i]);
	    cout<<"Passenger age:";
	    cin>>age[i];
	}
	cout<<"Enter the class f-first class s-second class:";
	gets(clas);
	x1:cout<<"Date of Travel:";
	x=wherex();y1=wherey();
	cout<<"dd-mm-yyyy";
	gotoxy(x,y1);
	temp=getch();cout<<temp;
	d1=(temp-48);
	temp=getch();cout<<temp;
	d2=(temp-48);
	d=(d1*10)+d2;
	x+=3;
	gotoxy(x,y1);
	temp=getch();cout<<temp;
	d1=(temp-48);
	temp=getch();cout<<temp;
	d2=(temp-48);
	m=(d1*10)+d2;
	x+=3;
	gotoxy(x,y1);
	temp=getch();cout<<temp;
	d1=(temp-48);
	temp=getch();cout<<temp;
	d2=(temp-48);
	temp=getch();cout<<temp;
	d3=(temp-48);
	temp=getch();cout<<temp;
	d4=(temp-48);
	y=(d1*1000)+(d2*100)+(d3*10)+d4;
	x+=3;
	int f=validate(d,m,y);
	if(f==0)
	  goto x1;

	cout<<"............END OF GETTING DETAILS............\n";
}
void reser::displayresdet()
{
	cout<<"\t\tBOOKING DETAILS\n\n";

	cout<<"Pnr no:"<<PNR;
	cout<<"\nTrain no:"<<tno;
	cout<<"\nTrain name:";
	puts(tname);
	cout<<"Boarding point:";
	puts(bp);
	cout<<"Destination pt:";
	puts(dest);
	cout<<"No of seats reserved:"<<nosr;
	for(i=0; i<nosr; i++)
	{
	    cout<<"\nPassenger name:";
	    puts(pname[i]);
	    cout<<"Passenger age:"<<age[i];
	}

	cout<<"\nYour class:";
	puts(clas);
	cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
	cout<<"\nYou must pay:"<<amc<<endl;
	cout<<"____________________________________________\n";
	cout<<"............END OF RESERVATION..............\n";
	cout<<"____________________________________________\n";
    }

int reser::check1(int a)
{if(a==PNR)
       return 1;
     else
       return 0;
}

void reser::displaycancdet()
{
	cout<<"\t\tCANCELLATION DETAILS\n\n";

	cout<<"Pnr no:"<<PNR;
	cout<<"\nTrain no:"<<tno;
	cout<<"\nTrain name:";
	puts(tname);
	cout<<"Boarding point:";
	puts(bp);
	cout<<"Destination pt:";
	puts(dest);
	cout<<"No of seats reserved:"<<nosr;
	for(i=0; i<nosr; i++)
	{
	    cout<<"\nPassenger name:";
	    puts(pname[i]);
	    cout<<"Passenger age:"<<age[i];
	}

	cout<<"\nYour class:";
	puts(clas);
	cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
	cout<<"\nAMOUNT RETURNED:"<<amc<<endl;
}
