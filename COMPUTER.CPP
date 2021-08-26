		     /*Railway Reservation Project*/
#include"HEAD.cpp"

char f[10]="f";
char s[10]="s";
int addr,ad,flag,f1,d,m,y,i,amt;
long PNR;
float tamt;

void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void displaycancdetail();
void cancell();
void enquiry();

void database()
{
    char *password;
    char *pass="irctc";
    x:cout<<"\n\n\n\t\tENTER THE ADMIN PASSWORD:";
    for(i=0;;)
	   {password[i]=getch();
	    if((int(password[i])==8)&&(i>0))
	      {cout<<"\b \b";
	       i--;
	      }
	    else
	    if(int(password[i])==13)
	      {password[i]='\0';
	       break;
	      }
	    else
	      {i++    ;
	       cout<<'*';
	      }
	   }

    detail a;
    fstream f;
    int ch;
    char c;
    if(strcmp(pass,password)!=0)
    {
	cout<<"\nEnter the password correctly \n";
	cout<<"You are not permitted to logon this mode\n";
	goto x;
    }
    if(strcmp(pass,password)==0)
    {
	char c;
	do
	{   clrscr();
	    showproject();
	    cout<<"\n\n\t...........ADMINISTRATOR MENU...........\n";
	    cout<<"\t1.Create detail data base\n\t2.Add details\n";
	    cout<<"\t3.Display details\n\t4.User management\n";
	    cout<<"\t5.Display passenger details\n";
	    cout<<"\t6.Display Cancellation details\n";
	    cout<<"\t7.Return to main menu\n";
	    cout<<"\n\tEnter your choice:";
	    cin>>ch;


	    cout<<endl;
	    switch(ch)
	    {
	     case 1:{
		     clrscr();
		     showproject();
		     cout<<"\n\n";
		     f.open("trains.dat",ios::binary|ios::app);
		     do
			{
			 a.getdetail();
			 f.write((char *) & a,sizeof(a));
			 cout<<"\nDo you want to add one more record?\n";
			 cout<<"Y/y-for Yesand N/n-for No\n";
			 cin>>c;
			}
		     while((c=='y')||(c=='Y'));
		     f.close();
		     break;
		    }
	    case 2:clrscr();
		   showproject();
		   cout<<"\n\n";
		   f.open("trains.dat",ios::binary|ios::in|ios::app);
		   a.getdetail();
		   f.write((char *) & a,sizeof(a));
		   f.close();
		   break;
	    case 3:clrscr();
		   showproject();
		   cout<<"\n\n";
		   f.open("trains.dat",ios::binary|ios::in|ios::app);
		   f.seekg(0);
		   gotoxy(1,3);
		   cout<<"Train No";
		   gotoxy(15,3);
		   cout<<"Train Name";
		   gotoxy(30,3);
		   cout<<"Boarding Point";
		   gotoxy(45,3);
		   cout<<"Destination";
		   gotoxy(60,3);
		   cout<<"Date of Departure";
		   int y2=4;
		   while(f.read((char *) & a,sizeof(a)))
		   {
		    a.displaydetail(y2);
		    y2++;
		   }
		   f.close();
		   getch();
		   break;
	    case 4:clrscr();
		   showproject();
		   cout<<"\n\n";
		   manage();getch();
		break;
	    case 5:clrscr();
		   showproject();
		   cout<<"\n\n";
		displaypassdetail();getch();
		break;
	    case 6:clrscr();
		   showproject();
		   cout<<"\n\n";
		displaycancdetail();getch();
		break;
	    }
	}
	while(ch<=5);

	f.close();
    }
h:
}

void manage()
{
    int ch;
    fstream f;
    char c;
    login a;

    do
    {   cout<<"\t\tUSER MANAGEMENT MENU\n\n";
	cout<<"\t1.Create id data base\n\t2.Add details\n";
	cout<<"\t3.Display details\n\t4.Return to the main menu\n";
	cout<<"\tEnter your choice:";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
	case 1:{
		clrscr();
		cout<<endl;
		f.open("identity.dat",ios::binary|ios::out);
		do
		{
		 a.getid();
		 f.write((char *) & a,sizeof(a));
		 cout<<"\n\nDo you want to add one more record\n";
		 cout<<"y-Yes\nn-No\n";
		 cin>>c;
		}
		while(c=='y');
		f.close();
		sleep(1);
		clrscr();
		break;
	       }
	case 2:{
		clrscr();
		cout<<endl;
		f.open("identity.dat",ios::in|ios::binary|ios::app);
		a.getid();
		f.write((char *) & a,sizeof(a));
		f.close();
		sleep(1);
		clrscr();
		break;
	       }
	case 3:{
		clrscr();
		cout<<endl;
		f.open("identity.dat",ios::binary|ios::in|ios::out);

		f.seekg(0);
		while(f.read((char *) & a,sizeof(a)))
		     {
		      a.displayid();
		     }
		f.close();
		getch();
		clrscr();
		break;
	       }
	}
    }
    while(ch<=3);
    sleep(2);
}

void displaypassdetail()
{
    fstream f;
    reser b;
    f.open("passenger.dat",ios::binary|ios::in);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {   if(b.STATUS=='b')
	  {
	   b.displayresdet();
	    getch();
	  }
	clrscr();
    }
    f.close();
    getch();
}
void displaycancdetail()
{
    fstream f;
    reser b;
    f.open("passenger.dat",ios::binary|ios::in);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {   if(b.STATUS=='c')
	{ b.displaycancdet();getch();
	}
	clrscr();
    }
    f.close();
    getch();
}

void user()
{   int d,flag;
    login a;
    int ch;
    cout<<"\n\n\t_____________WELCOME TO THE USER MENU_______________\n";
    cout<<"\t____________________________________________________\n\n\n";
    char *password;

    fstream f;
    f.open("identity.dat",ios::binary|ios::in|ios::out);
    char id[100];
    cout<<endl;

    cout<<"\t\tUSERNAME:";
    gets(id);
    cout<<"\t\tPASSWORD:";

    for(i=0;;)
    {password[i]=getch();
       if((int(password[i])==8)&&(i>0))
	{cout<<"\b \b";
	i--;
	}
	else
	if(int(password[i])==13)
	  {password[i]='\0';
	   break;
	  }
	else
	  {i++    ;
	   cout<<'*';
	  }
     }
    while(f.read((char *) & a,sizeof(a)))
    {   flag=a.check(id,password);
	if(flag==1)
	{
	    do
	    {   clrscr();
		showproject();
		showname(a.name);
		cout<<"\n\tMENU\n\n";
		cout<<"\t1.ENQUIRY\n";
		cout<<"\t2.BOOKING\n";
		cout<<"\t3.CANCEL\n";
		cout<<"\t4.BACK TO MAIN....\n\n";
		cout<<"\tENTER YOUR CHOICE:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
		case 2:
		    reserve();
		    break;
		case 1:
		    clrscr();
		    showproject();
		    showname(a.name);enquiry();
		    break;
		case 3:
		    clrscr();
		    showproject();
		    showname(a.name);can();
		    break;
		}
	    }
	    while(ch<=3);
	    goto j;
	}
    else
       d=1;
   }
 if(d==1)
   cout<<"\n\nEnter the user id and password correctly\n";
 getch();
j:
}

void reserve()
{
    int ch;
    do
    {   clrscr();
	showproject();
	cout<<"\n\tRESERVATION MENU\n\n";
	cout<<"\t1.BOOKING\n\t2.BACK TO USER MENU....\n";
	cout<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
	case 1:
	    res();
	    break;
	}
    }
    while(ch==1);
    getch();clrscr();
}
void res()
{
    detail a;
    reser b;
    fstream f1,f2;
    time_t t;
    f1.open("trains.dat",ios::binary|ios::in|ios::out);
    f2.open("passenger.dat",ios::binary|ios::in|ios::app);
    int ch;
    b.getresdet();

    while(f1.read((char *) &a,sizeof(a)))
    {   flag=a.check(b.tno);
	if(flag==1)
	{  flag=1;
	    if(strcmp(b.clas,f)==0)
	    {
		if(a.c1>=b.nosr)

		{
		    amt=a.c1fare;
		    a.c1=a.c1-b.nosr;
		    f1.seekp(f1.tellg()-sizeof(a));
		    f1.write((char *) & a,sizeof(a));
		    b.amc=b.nosr*amt;

		    srand((unsigned) time(&t));
		    b.PNR=rand();
		    b.STATUS='b';
		    f2.write((char *) & b,sizeof(b));
		    getch();
		    clrscr();
		    b.displayresdet();
		    cout<<"________________________________________________\n";
		    cout<<"______________Your ticket is reserved___________\n";
		    cout<<"__________________End of reservation menu_______\n";
		    getch();
		    clrscr();
		}
		else
		{
		    cout<<"**********Sorry req seats not available********\n";

		}
	    }
	    else if(strcmp(b.clas,s)==0)
	    {
		if(a.c2>=b.nosr)
		{
		    amt=a.c2fare;
		    a.c2=a.c2-b.nosr;
		    f1.seekp(f1.tellg()-sizeof(a));
		    f1.write((char *) & a,sizeof(a));
		    b.amc=b.nosr*amt;
		}
		    b.STATUS='b';
		    f2.write((char *) & b,sizeof(b));
		    b.displayresdet();
		    cout<<"_______________________________________\n";
		    cout<<"________Your ticket is reserved________\n";
		    cout<<"____________End of reservation_________\n";
		    getch();
		    clrscr();

		}
		else


		{
		    cout<<"-------Sorry req no of seats not available-------\n";
		}
		}
	else
	{
	    flag=0;
	}
    }
    if(flag==0)
    {
	cout<<"............Wrong train no......................\n";
	cout<<"......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();
    getch();
h:
}

void enquiry()
{

    fstream f;
    f.open("trains.dat",ios::binary|ios::in|ios::app);
    detail a;
    int y2=6;
    gotoxy(1,5);
		   cout<<"Train No";
		   gotoxy(15,5);
		   cout<<"Train Name";
		   gotoxy(30,5);
		   cout<<"Boarding Point";
		   gotoxy(45,5);
		   cout<<"Destination";
		   gotoxy(60,5);
		   cout<<"Date of Departure";
    while(f.read((char *) & a,sizeof(a)))
    {
	a.displaydetail(y2);
	y2++;
    }
    getch();
}

void getcancdet()
{       clrscr();
	showproject();
	cout<<"Enter the details as follows\n";
	cout<<"Pnr no:";
	cin>>PNR;
	int x,y1,d1,d2,d3,d4;char temp;
	x1:cout<<"Date of cancellation:";x=wherex();y1=wherey();
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
	cout<<"\n...........END OF GETTING DETAILS...........\n";
}


void cancell()
{
    int flag1,flag2,addr;
    detail a;
    reser b;
    fstream f1,f2;
    f1.open("trains.dat",ios::binary|ios::in|ios::out);
    f2.open("passenger.dat",ios::binary|ios::in|ios::out);
    cout<<"___________CANCELLATION MENU__________\n";
    getcancdet();
    while(f2.read((char *) & b,sizeof(b)))
	 {flag=b.check1(PNR);
	  if(flag==1)
	    {
	     while(f1.read((char *) & a,sizeof(a)))
		  {
		      flag1=a.check(b.tno);
		      if(flag1==1)
			{if(b.STATUS=='b')
			   {
			    a.c1=a.c1+b.nosr;
			    f1.seekp(f1.tellg()-sizeof(a));
			    f1.write((char *) & a,sizeof(a));
			    tamt=b.amc;
			    if((d==a.d)&&(m==a.m))
			      {
			       cout<<"You are cancelling on the date of departure\n";
			       b.amc=tamt-((tamt*60)/100);
			       b.STATUS='c';
			       addr=f2.tellg();
			       f2.seekp(addr-sizeof(b));
			       f2.write((char *) & b,sizeof(b));
			       goto h;
			      }
			    else if(m==a.m)
			    {
			     cout<<"You are cancelling in the month of departure\n";
			     b.amc=tamt-((tamt*50)/100);
			     b.STATUS='c';
			     addr=f2.tellg();
			     f2.seekp(addr-sizeof(b));
			     f2.write((char *) & b,sizeof(b));
			     goto h;
			    }
			    else if(a.m>m)
			    {
			     cout<<"You are cancelling one month before the date of departure\n";
			     b.amc=tamt-((tamt*20)/100);
			     b.STATUS='c';
			     addr=f2.tellg();
			     f2.seekp(addr-sizeof(b));
			     f2.write((char *) & b,sizeof(b));
			     goto h;

			    }
			    else
			    {
			     cout<<"Cancelling after the departure\n";
			     cout<<"Your request cannot be completed\n";
			    }
			   }
			   else
			   {
			    cout<<"\n\n\t\t\tAlready Cancelled\n";
			    getch();
			   }
		    }
		}
	    }


    }
    if (flag==0)
	{
	    cout<<"Enter correct PNR number\n";

	}


  h:f1.close();
    f2.close();
    getch();
}
void can()
{
    int ch;
    do
    {   clrscr();
	showproject();
	cout<<".................CANCELLATION MENU.........\n";
	cout<<"1.Cancel Tickets\n2.Return to the USER Menu\n";
	cout<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
	case 1:
	    cancell();
	    break;
	}
    }
    while(ch==1);
    getch();
}

