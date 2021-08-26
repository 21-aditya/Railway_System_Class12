#include"COMPUTER.cpp"



void main()
{   textbackground(WHITE);
    textcolor(BLACK);

    int ch;
    do
    {   clrscr();
	showproject();
	cout<<"\n";
	cout<<"\tWELCOMES YOU...\n";
	cout<<"\n";
	getch();
	cout<<"\t\t\tMAIN MENU\n";
	cout<<"\n\t\t1.ADMINISTRATOR MODE\n";
	cout<<"\t\t2.USER ACCESS MODE\n";
	cout<<"\t\t3.EXIT\n\n";
	cout<<"\t\tEnter your choice:";cin>>ch;
	switch(ch)

	{
	case 1:{
		clrscr();
		showproject();
		database();
		sleep(1);
		break;
	       }
	case 2:{
		clrscr();
		showproject();
		user();
		sleep(1);
		break;
	       }
	case 3:{
		cout<<"\n\t\tThank You for visiting this application\n";
		cout<<"\n\t\tTerminating";
		sleep(1);cout<<".";
		sleep(1);cout<<".";
		sleep(1);cout<<".";
		sleep(1);
		exit(0);
	       }
	}
    }
    while(ch<=3);
    getch();
}