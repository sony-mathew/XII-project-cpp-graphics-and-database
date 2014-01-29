#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>

void welcomepage();
void close_help();
void execute();
int  pass2();
int  passread();
void menu();
void aboutus();
void mouseinit();
void bacck();
void menu11(int);
void create_ntry111();
int mousepro(int);
void searchsoldier(int);
void searchsoldier1();
void deletesoldier();
void previewsoldier();
void nomouse();
void outline();
void createwar();
void searchwar();
void deletewar();
void previewwar();
void createnote();
void searchnote();
void deletenote();
void previewnote();
void account1();
void change();
void others();
void others1();
void createaccount();

 int c=0;
union REGS in,out;   //mouse interupt union object declaration
 time_t t;              //in-built class to take system time,date

//*************************************************************
void main()        //main function
   { clrscr();execute();}
//************************************************************
 void execute()     //just another function to call the first fn
   {welcomepage();}
//***********************************************************************
  void welcomepage() //first page to be displayed
   {
      clrscr();
      delay(500);
      int gdriver = DETECT, gmode, errorcode;
      initgraph(&gdriver,&gmode,"c:\\tc\\bin");
      errorcode = graphresult();

      if (errorcode != grOk)  /* an error occurred */
	    {
	      printf("Graphics error: %s\n", grapherrormsg(errorcode));
	      printf("Press any key to halt:");getch();
	    }
      outline();

      setcolor(13);
      settextstyle(4,0,3);
      outtextxy(150,100,"Welcome to");
      settextstyle(4,0,4);
      outtextxy(150,150,"Indian Defence Data Base");
      setcolor(0);
      setlinestyle(0,1,3);
      line(152,176,500,176);
      setlinestyle(0,1,1);
      setcolor(8);
      settextstyle(0,0,0);
      outtextxy(150,220,"Loading......");

      setcolor(4);
      rectangle(150,250,470,300);
      setfillstyle(1,8);
      int j=0;
      for(int i=160;i<460;++i)
      { delay(20);++j;
	bar(160,260,i,290);
      }
      setcolor(8);
      rectangle(200,350,410,370);
      settextstyle(0,0,0);
      setcolor(3);
      outtextxy(202,357,"click here to continue >>>");
      mouseinit();
      mousepro(1);
    }
//****************************************************************
//***************************************************************
  class ps2         //class for storing passwords & usernames
	    {
	      public:
		  char userid[15];
		  char ps2[15];
	    } ps[4];
//*************************************************************
int pass2()
    { delay(500);
      in.x.ax=2;
      int86(51,&in,&out);
      outline();
      setcolor(8);
      rectangle(140,170,480,330);
      setcolor(4);
      settextstyle(4,0,1);
      outtextxy(240,180,"Login");
      setcolor(8);
      rectangle(250,235,400,257);
      rectangle(250,285,400,305);
      setcolor(2);
      settextstyle(4,0,1);
      outtextxy(150,235,"User ID  :");
      setcolor(8);
      settextstyle(4,0,1);
      outtextxy(150,285,"Password :");
      nomouse();
      for(int i=0;i<3;++i)
       {
	ps[i].userid[0]='\0';
	ps[i].ps2[0]='\0';
       }
      char user[15];
      char pass[15];
      passread();
      strcpy(ps[3].userid,"administrator\0");
      strcpy(ps[3].ps2,"123\0");
      gotoxy(33,16);
      gets(user);
      setcolor(8);
      settextstyle(4,0,1);
      outtextxy(150,235,"User ID  :");
      setcolor(2);
      settextstyle(4,0,1);
      outtextxy(150,285,"Password :");
      gotoxy(33,19);
      int x=255,y=281;
      i=0;
      char ch;
      while((ch=getch())!=13)
        {
         if(ch!=8)
           {setcolor(7);
             pass[i]=ch;
             outtextxy(x,y,"*");
             i++;x=x+9;
           }
         if(ch==8&&(!i)<=0)
           {i--;x=x-9;
            setcolor(0);
            outtextxy(x,y,"*");

           }
       }
      pass[i]='\0';
      for(i=0;i<4;++i)
	 {
	   if(((strcmp(ps[i].userid,user)==0))&&((strcmp(ps[i].ps2,pass)==0)))
	    {
	     if(strcmp(user,"administrator")==0)
	       { if(strcmp(pass,"123")==0)
		  {c=90;}
	       }
	     menu();
	    }
	 }

      cleardevice();
      setcolor(0);
      gotoxy(1,1);
      cout<<"\n\n\n\n\n\n\tUnauthorised Entry Detected ........ ";
      cout<<"\n\n\n\n\tDo you want to exit this program(y/n)? ";
      char b=getch();
      if (b=='y'){ exit(0); }
      else{ pass2();}
     return 0;
    }
//**********************************************************
int passread()  //reads passwords stored in a file to the class
    {
     ifstream psrd("data",ios::binary|ios::nocreate);
     if(psrd.eof()){return 1;}
     psrd.seekg(0);
     for(int i=0;i<3;++i)
	  {psrd.read((char*)&ps[i],sizeof(ps[i]));}
     psrd.close();
     return 0;
    }
//**********************************************************
//*****************************************************************
 class biodata     //class for storing details of soldiers
	    {
	      public:
		  char name[20],dob[10];
		  double pincode;
		  char addr[50],city[20],state[25];
		  void getdat();
		  void disply();
	    };
//******************************************************************
       class militant:public biodata  //class to store soldier details
	    {
	      public:
		  char code[8],specialisation[25],quali[10];
		  char regiment[8],qualification[10],camp[20],batch[10],post_place[15];
		  float pass_year,salary,phone;
		  void getdata();
		  void display();
	    } mi;


//*************************************************************************
	 void biodata::getdat()//fn to get details of soldiers(class member)
		     {
       			outline();
       			setcolor(8);
       			rectangle(50,90,568,90);
      			setcolor(6);
       			settextstyle(0,0,0);
       			outtextxy(65,78,"Add: Main Menu>>Soldier Details>>Create Entry");
       			nomouse();

			setbkcolor(0);
			setcolor(4);
			settextstyle(0,0,1);
			outtextxy(55,55,"Bio-Data");
			outtextxy(150,120,"         Personel Details(1/3)");
			outtextxy(150,150,"Name     :");
			outtextxy(150,180,"DOB      :");
			outtextxy(150,210,"Address  :");
			outtextxy(150,243,"City     :");
			outtextxy(150,275,"PinCode  :");
			outtextxy(150,308,"State    :");
			gotoxy(30,10);
			gets(name);
			gotoxy(30,12);
			gets(dob);
			gotoxy(30,14);
			gets(addr);
			gotoxy(30,16);
			gets(city);
			gotoxy(30,18);
			cin>>pincode;
			gotoxy(30,20);
			gets(state);

		     }
//*******************************************************************
	  void biodata::disply()//fn to display details of soldiers (class member)
		     {
       			outline();
       			setcolor(8);
       			rectangle(50,90,568,90);
       			setcolor(6);
        		settextstyle(0,0,0);
                        outtextxy(65,78,"Add: Main Menu>>Soldier Details>>Search>>Display");
                        nomouse();
			setbkcolor(0);
			setcolor(4);
			settextstyle(0,0,1);
			outtextxy(55,55,"Bio-Data");
			outtextxy(150,120,"         Personel Details(1/3)");
			outtextxy(150,150,"Name     :");
			outtextxy(150,180,"DOB      :");
			outtextxy(150,210,"Address  :");
			outtextxy(150,243,"City     :");
			outtextxy(150,275,"PinCode  :");
			outtextxy(150,308,"State    :");
			gotoxy(30,10);
			puts(name);
			gotoxy(30,12);
			puts(dob);
			gotoxy(30,14);
			puts(addr);
			gotoxy(30,16);
			puts(city);
			gotoxy(30,18);
			cout<<pincode;
			gotoxy(30,20);
			puts(state);
			outtextxy(170,360,"press any key to continue>>");
			getch();

		     }
//************************************************************************
	  void militant::getdata() //fn to get details of soldiers (class member)
		     {  getdat();
                        outline();
                        setcolor(8);
                        rectangle(50,90,568,90);
                        setcolor(6);
                        settextstyle(0,0,0);
                        outtextxy(65,78,"Add: Main Menu>>Soldier Details>>Create Entry");
                        nomouse();
			setbkcolor(0);
			setcolor(4);
			settextstyle(0,0,1);
			outtextxy(55,55,"Bio-Data");
			outtextxy(150,120,"         Training Details(2/3)");
			outtextxy(100,150,"Place                    :");
			outtextxy(100,180,"Batch                    :");
			outtextxy(100,210,"Passed out year          :");
			outtextxy(100,243,"Specialisation           :");
			outtextxy(100,275,"Educational Qualification:");
			gotoxy(40,10);
			gets(camp);
			gotoxy(40,12);
			gets(batch);
			gotoxy(40,14);
			cin>>pass_year;
			gotoxy(40,16);
			gets(specialisation);
			gotoxy(40,18);
			gets(quali);
                        outline();
                        setcolor(8);
                        rectangle(50,90,568,90);
                        setcolor(6);
                        settextstyle(0,0,0);
                        outtextxy(65,78,"Add: Main Menu>>Soldier Details>>Create Entry");
                        nomouse();
		        setcolor(4);
			outtextxy(55,55,"Bio-Data");
			outtextxy(150,120,"         Current Details(3/3)");
			outtextxy(150,150,"ID Code         :");
			outtextxy(150,180,"Regiment        :");
			outtextxy(150,210,"Place of Posting:");
			outtextxy(150,243,"Position        :");
			outtextxy(150,275,"Salary          :");
			outtextxy(150,308,"Contact Number  :");
			gotoxy(37,10);
			gets(code);
			gotoxy(37,12);
			gets(regiment);
			gotoxy(37,14);
			gets(post_place);
			gotoxy(37,16);
			gets(qualification);
			gotoxy(37,18);
			cin>>salary;
			gotoxy(37,20);
			cin>>phone;
		     }
//***********************************************************************
	  void militant::display() //fn to display soldier details(class member)
		     {
	disply();
        outline();
        setcolor(8);
        rectangle(50,90,568,90);
        setcolor(6);
        settextstyle(0,0,0);
        outtextxy(65,78,"Add: Main Menu>>Soldier Details>>Search>>Display");
        nomouse();
        setbkcolor(0);
        setcolor(4);
        settextstyle(0,0,1);
	outtextxy(55,55,"Bio-Data");
	outtextxy(150,120,"         Training Details(2/3)");
	outtextxy(100,150,"Place                    :");
	outtextxy(100,180,"Batch                    :");
	outtextxy(100,210,"Passed out year          :");
	outtextxy(100,243,"Specialisation           :");
	outtextxy(100,275,"Educational Qualification:");
	gotoxy(40,10);
	puts(camp);
	gotoxy(40,12);
	puts(batch);
	gotoxy(40,14);
	cout<<pass_year;
	gotoxy(40,16);
	puts(specialisation);
	gotoxy(40,18);
	puts(quali);
	outtextxy(170,360,"press any key to continue>>");
	getch();
        outline();
        setcolor(8);
        rectangle(50,90,568,90);
        setcolor(6);
        settextstyle(0,0,0);
        outtextxy(65,78,"Add: Main Menu>>Soldier Details>>Search>>Display");
        nomouse();
	setcolor(4);
	outtextxy(55,55,"Bio-Data");
	outtextxy(150,120,"         Current Details(3/3)");
	outtextxy(150,150,"ID Code         :");
	outtextxy(150,180,"Regiment        :");
	outtextxy(150,210,"Place of Posting:");
	outtextxy(150,243,"Position        :");
	outtextxy(150,275,"Salary          :");
	outtextxy(150,308,"Contact Number  :");
	gotoxy(37,10);
	puts(code);
	gotoxy(37,12);
	puts(regiment);
	gotoxy(37,14);
	puts(post_place);
	gotoxy(37,16);
	puts(qualification);
	gotoxy(37,18);
	cout<<salary;
	gotoxy(37,20);
	cout<<phone;
	outtextxy(170,360,"press any key to continue>>");
	getch();

		     }
//**************************************************************************

 void create_ntry111()
	     {
		     fstream mread;
		     mread.open("sol",ios::app);
		     mi.getdata();
		     mread.write((char*)&mi,sizeof(mi));
		     mread.close();
		     menu11(1);

	      }
//*************************************************************************
void searchsoldier(int a) //search an entry on a soldier details
       {        cleardevice();
		delay(100);
		fstream mread;
		mread.open("sol",ios::binary|ios::nocreate) ;
		mread.seekg(0);
		if(mread.eof())
		{ outline();
		  bacck();
		  setcolor(6);
		  outtextxy(250,250,"Sorry!!No Records Found ");
		  mread.close();
		  mousepro(11);
		}
		setcolor(8);
		rectangle(50,90,568,90);
		setcolor(6);
		settextstyle(4,0,1);
		outtextxy(170,100,"Search Options");
		
	       mread.close();
	       outline();
	       char name[20],code[8];
	       int k=1;
	       if(a==1)
	       {   
		   settextstyle(0,0,0);
		   outtextxy(65,78,"Add: Main Menu>>Details of Soldiers>>Search>>By Name");
		   
		   settextstyle(0,0,0);
		   outtextxy(80,166,"Enter name to be searched :");
		   gotoxy(40,11);
		   gets(name);
		   while(!mread.eof())
		    {
		      mread.read((char*)&mi,sizeof(mi));
		      if(strcmp(name,mi.name)==0)
			 {  k=0;
			    mi.display();
                            break;
			  }
		    }

		   if(k==0){menu11(1);}
		   else
		   { outline();
		     bacck();
		     setcolor(6);
		     outtextxy(250,250,"Sorry!!No Records Found ");
		     mousepro(11);
		    }
		}
		else if(a==2)
		{  
		   settextstyle(0,0,0);
		   outtextxy(65,78,"Add: Main Menu>>Details of Soldiers>>Search>>By ID Code");
		   settextstyle(0,0,0);
		   outtextxy(80,166,"Enter ID to be searched :");
		   gotoxy(40,11);
		   gets(code);
		   while(!mread.eof())
		    {
		      mread.read((char*)&mi,sizeof(mi));
		      if(strcmp(code,mi.code)==0)
			 { k=0;
			   mi.display();
			 }
		    }
		   if (k==0){menu11(1);}
		   else
		   { outline();
		     bacck();
		     setcolor(6);
		     outtextxy(250,250,"Sorry!!No Records Found ");
		     mousepro(11);
		    }
		}
	 }
//**************************************************************************
  void searchsoldier1()
  {            cleardevice();
	       delay(500);
	       outline();
	       setcolor(8);
	       rectangle(50,90,568,90);
	       setcolor(6);
	       settextstyle(0,0,0);
	       outtextxy(65,78,"Add: Main Menu>>Details of Soldiers>>Search");
	       settextstyle(4,0,1);
	       outtextxy(170,100,"Search Options");
	       setcolor(8);
	       for(int j=0;j<3;++j)
		  {rectangle(150,j*30+150,400,j*30+175);  }
	       setcolor(6);
	       settextstyle(4,0,1);
	       outtextxy(150,150,"  Search by Name");
	       outtextxy(150,180,"  Search by ID Code");
	       outtextxy(150,210,"  Back to Sub-Menu");
	       mousepro(5);
   }
//***************************************************************************
void deletesoldier()
       {	cleardevice();
		delay(100);
		fstream mread,file;
		mread.open("sol",ios::binary) ;
                file.open("temp",ios::binary);
		mread.seekg(0);
		if(mread.eof())
		{ outline();
		  bacck();
		  setcolor(6);
		  outtextxy(250,250,"Sorry!!No Records Found ");
		  mread.close();
		  mousepro(11);
		}
		char code[15];
		outline();
	        setcolor(6);
		settextstyle(0,0,0);
		outtextxy(65,78,"Add: Main Menu>>Details of Soldiers>>Search>>By ID Code");
		settextstyle(4,0,1);
		outtextxy(170,100,"Search Options");
		settextstyle(0,0,0);
		outtextxy(80,166,"Enter ID to be searched :");
		gotoxy(40,11);
		gets(code);
		char ch='n';
                while(!mread.eof())
		  {  mread.read((char*)&mi,sizeof(mi));
                     if(strcmp(code,mi.code)==0)
			{ outtextxy(70,166,"Do you really want to delete the previously displayed entry(y/n)?");
			   ch=getch();
			   if(ch=='y'||ch=='Y') {break;} 
                           else {file.write((char*)&mi,sizeof(mi));}
			}
                     else	
		     {file.write((char*)&mi,sizeof(mi));}
 		   }  	 		     	 
		mread.close();
		file.close();
		remove("sol");
		rename("temp","sol");
		cleardevice();
		outline();
		settextstyle(0,0,1);
		outtextxy(80,200,"Your request was completed succesfully...");
		bacck();
		mousepro(11);

	 }
//***********************************************************************
void previewsoldier()
  { delay(200);
    ifstream mread;
    mread.open("sol",ios::binary|ios::nocreate);
    if(mread.eof())
    {
     cleardevice();
     outline();
     bacck();
     outtextxy(210,250,"Sorry !!! No Records Found");
     mousepro(11);
    }
    int j=0;
   do
   {  cleardevice();
     delay(200);
     outline();
     setcolor(4);
     settextstyle(0,0,0);
     outtextxy(55,57,"Preview");
     gotoxy(30,10);
     cout<<"Preview Page No : "<<j+1;
     gotoxy(22,15);
     cout<<"Name             :";puts(mi.name);
     gotoxy(22,17);
     cout<<"ID Code          :";puts(mi.code);
     gotoxy(22,19);
     cout<<"Current Position :";puts(mi.qualification);
     setcolor(8);
     rectangle(165,350,225,370);
     setcolor(3);
     settextstyle(0,0,0);
     outtextxy(170,355,"<< Esc");
     setcolor(8);
     rectangle(420,350,488,370);
     setcolor(3);
     outtextxy(425,355,"Next >>");
     mousepro(12);
   } while(!mread.eof());

   in.x.ax=1;
   int86(51,&in,&out);
   menu11(1);
}
//**************************************************************
void aboutus() //displays contact us details
   {
      outline();
      setcolor(6);
      settextstyle(4,0,3);
      outtextxy(170,100," Contact Us ");
      bacck();
      setcolor(6);
      settextstyle(0,0,0);
      outtextxy(100,150,"This program has been idealised and coded by Group 007");
      outtextxy(100,170,"as part of Computer Science Project.This program is co");
      outtextxy(100,190,"pywright protected @2009.The Group Members of this pro");
      outtextxy(100,210,"ject include  : ");
      outtextxy(100,240,"-Amal Francis & -Sony Mathew");
      outtextxy(100,260,"We did this under the guidance of Honey Miss & Leema M");
      outtextxy(100,280,"iss and we thank them very much for their support.    ");
      outtextxy(100,310,"For any inquests on this project or on C++ it is true ");
      outtextxy(100,330,"that we are ready to help and please dont hesitate to ");
      outtextxy(100,350,"contact us at ynos1234@gmail.com ");
      mousepro(10);
   }
//************************************************************
//****************************************************************
void account1()
   { cleardevice();
     in.x.ax=2;
     delay(200);
     in.x.ax=1;
     int86(51,&in,&out);
     outline();
     setcolor(8);
     rectangle(50,90,568,90);
     setcolor(6);
     settextstyle(0,0,0);
     outtextxy(65,78,"Add: Main Menu>>settings");
      setcolor(8);
      settextstyle(4,0,1);
      if(c==90)
      {b=6;}
      else
      {b=4;}
      for(int j=0;j<b;++j)
      {rectangle(150,j*30+150,400,j*30+175);  }
      setcolor(6);
      outtextxy(150,150,"  Change Password ");
      outtextxy(150,180,"  Log Out");
      outtextxy(150,210,"  Exit");
      outtextxy(150,240,"  Back to Main Menu");
      if(c==90)
      {outtextxy(150,270," Other Accounts");
       outtextxy(150,300," Create Account");
       mousepro(8);
      }
      mousepro(9);
   }
//*********************************************************************
void change()
{
cleardevice();
delay(200);
outline();
char user[15],pass[15],user1[15],pass1[15];
setcolor(8);
rectangle(50,90,568,90);
setcolor(6);
settextstyle(0,0,0);
outtextxy(65,78,"Add: Main Menu>>Account settings>>Change password");
nomouse();

setbkcolor(0);
setcolor(4);
settextstyle(0,0,1);
outtextxy(55,55,"Change password");
outtextxy(150,120,"         Settings");
outtextxy(150,150,"Old Username      :");
outtextxy(150,180,"Old Password      :");
outtextxy(150,243,"New Username      :");
outtextxy(150,275,"New Password      :");
gotoxy(40,10);
gets(user);
gotoxy(40,12);
gets(pass);
gotoxy(40,16);
gets(user1);
gotoxy(40,18);
gets(pass1);
outtextxy(200,380,"Press any key to continue >>>>");
getch();
if(strcmp(user,"administrator")==0)
   {   setcolor(6);
       settextstyle(0,0,0);
       outtextxy(100,250,"Sorry !!The Administrator password cannot be changed");
       outtextxy(100,270,"Change initiation aborted........");
       outtextxy(100,290,"Press any key to continue......");
       getch();
       account1();
    }
ofstream ot("data",ios::binary|ios::trunc);
for(int i=0;i<3;++i)
 {
     if(((strcmp(ps[i].userid,user)==0))&&((strcmp(ps[i].ps2,pass)==0)))
	    {  ps[i].userid[0]='\0';
	       ps[i].ps2[0]='\0';
	       strcpy(ps[i].userid,user1);
	       strcpy(ps[i].ps2,pass1);
	       for(int u=0;u<3;++u)
	          { ot.write((char*)&ps[u],sizeof(ps[u]));}
	       cleardevice();
	       outline();
	       settextstyle(0,0,0);
	       outtextxy(200,250,"Change succesfully initiated...");
	       outtextxy(200,300,"press any key to continue>>>");
	       getch();
	       account1();
	    }
 }
cleardevice();
outline();
setcolor(6);
settextstyle(0,0,0);
outtextxy(100,250,"Sorry !!There seems some problem with the");
outtextxy(100,270,"data you have recently entered........");
outtextxy(100,310,"Press any key to continue   >>>>");
getch();
menu();
}
//*********************************************************************
void others1()
  { cleardevice();
    delay(200);
    outline();
    setcolor(4);
    int w=10;
    settextstyle(0,0,1);
    outtextxy(55,55,"Other users");
    outtextxy(150,120,"         Settings");
    for(int i=0;i<4;++i)
	 {
	 gotoxy(20,w);
	 cout<<"User "<<i+1<<":   ";puts(ps[i].userid);
	 w+=2;
	 }
	outtextxy(200,300,"press any key to continue>>>");
	getch();
      	account1();
  }
 //********************************************************************
 void others()
   {
     cleardevice();
     in.x.ax=2;
      outline();
       setcolor(8);
       rectangle(50,90,568,90);
       setcolor(6);
       settextstyle(0,0,0);
       outtextxy(65,78,"Add: Main Menu>>settings>>others");

      setcolor(8);
      settextstyle(0,0,0);
      setcolor(6);
      outtextxy(150,180,"Do you want to create a new account(y/n)?");
      char ch=getch();
      if(ch=='y'||ch=='Y')
      {createaccount();}
      else
      {account1();}
   }
//************************************************************************
void createaccount()
  {
       cleardevice();
       delay(200);
       outline();
       char user[15],pass[15],pass1[15];
       setcolor(8);
       rectangle(50,90,568,90);
       setcolor(6);
       settextstyle(0,0,0);
       outtextxy(65,78,"Add: Main Menu>>Account settings>>Others>>Create Account");
       nomouse();

        setbkcolor(0);
	setcolor(4);
	settextstyle(0,0,1);
	outtextxy(55,55,"New Account");
	outtextxy(150,120,"         Settings");
	outtextxy(150,150,"New Username      :");
	outtextxy(150,180,"New Password      :");
	outtextxy(150,243,"Confirm Password  :");
	gotoxy(40,10);
	gets(user);
	gotoxy(40,12);
	gets(pass);
	gotoxy(40,16);
	gets(pass1);
        if(strcmp(user,"administrator")==0)
           {   cleardevice();
               outline();
               setcolor(6);
               settextstyle(0,0,0);
               outtextxy(100,250,"Sorry !!An account in the name Administrator already exists");
               outtextxy(100,270,"New account creation step initiation aborted........");
               outtextxy(100,290,"Press any key to continue......");
               getch();
               account1();
           }
	if(strcmp(pass,pass1)!=0)
	{ outtextxy(150,300,"Sorry !!There is some problem with password confirmation..");
	  outtextxy(150,320,"Press any key to continue   >>>");
	  getch();
	  account1();
	}
	outtextxy(200,380,"Press any key to continue >>>>");
	getch();

	ofstream ot("data",ios::binary|ios::trunc);
	ot.close();
	for(int i=0;i<3;++i)
	    { if( ps[i].userid[0]=='\0'&&ps[i].ps2[0]=='\0')
	       {
	          strcpy(ps[i].userid,user);
	          strcpy(ps[i].ps2,pass1);
	          for(int u=0;u<3;++u)
	             { ot.open("data",ios::binary|ios::app);
		       ot.write((char*)&ps[u],sizeof(ps[u]));
		       ot.close();
                     }
	          cleardevice();
	          outline();
	          settextstyle(0,0,0);
	          outtextxy(200,250,"New Account Succesfully Created...");
	          outtextxy(200,300,"press any key to continue>>>");
	          getch();
	          account1();
	       }
	    }
      cleardevice();
      outline();
      setcolor(6);
      settextstyle(0,0,0);
      outtextxy(100,250,"Sorry !!Max number of supported users are already active..");
      outtextxy(100,270,"Sorry new account cannot be supported.....................");
      outtextxy(100,310,"Press any key to continue   >>>>");
      getch();
      account1();
  }
//*************************************************************
//******************************************************************
 class warcops          //class to store warcop details
	   {
	    public:
	    char type[15],code[10],descrip[100],charge[20],place[20];
	    char camp[20],number[10];
	    void get();
	    void display();
	   } war;
//*******************************************************************
 void warcops::get()      //last modified on 6:34 AM 10/26/2009
    {
       			outline();
      			setcolor(8);
    			rectangle(50,90,568,90);
       			setcolor(6);
      			settextstyle(0,0,0);
       			outtextxy(65,78,"Add: Main Menu>>Warcop Details>>Create Entry");
       			nomouse();
			setbkcolor(0);
			setcolor(4);
			settextstyle(0,0,1);
			outtextxy(55,55,"War-Cops");
			outtextxy(150,120,"         Warcop Details");
			outtextxy(150,150,"Type              :");
			outtextxy(150,180,"Code              :");
			outtextxy(150,210,"Place             :");
			outtextxy(150,243,"Camp              :");
			outtextxy(150,275,"Major in Charge   :");
			outtextxy(150,308,"Quantity or Number:");
			outtextxy(150,341,"Short Description :");
			gotoxy(40,10);
			gets(type);
			gotoxy(40,12);
			gets(code);
			gotoxy(40,14);
			gets(place);
			gotoxy(40,16);
			gets(camp);
			gotoxy(40,18);
			gets(charge);
			gotoxy(40,20);
			gets(number);
			gotoxy(40,22);
			gets(descrip);

     }
//************************************************************************
void warcops::display()
     {
			outline();
     			setcolor(8);
      			rectangle(50,90,568,90);
      			setcolor(6);
    			settextstyle(0,0,0);
    			outtextxy(65,78,"Add: Main Menu>>Warcop Details>>Display Entry");
      			nomouse();
			setbkcolor(0);
			setcolor(4);
			settextstyle(0,0,1);
			outtextxy(55,55,"War-Cops");
			outtextxy(150,120,"         Warcop Details");
			outtextxy(150,150,"Type              :");
			outtextxy(150,180,"Code              :");
			outtextxy(150,210,"Place             :");
			outtextxy(150,243,"Camp              :");
			outtextxy(150,275,"Major in Charge   :");
			outtextxy(150,308,"Quantity or Number:");
			outtextxy(150,341,"Short Description :");
			gotoxy(40,10);
			puts(type);
			gotoxy(40,12);
			puts(code);
			gotoxy(40,14);
			puts(place);
			gotoxy(40,16);
			puts(camp);
			gotoxy(40,18);
			puts(charge);
			gotoxy(40,20);
			puts(number);
			gotoxy(40,22);
			puts(descrip);
			outtextxy(200,380,"Press any key to continue >>>>");
			getch();
	   }

//*******************************************************************

void createwar()
      {           cleardevice();
		  ofstream mread;
		  mread.open("warcops",ios::binary|ios::app) ;
		  war.get();
		  mread.write((char*)&war,sizeof(war));
		  mread.close();
		  menu11(2);

       }
//***********************************************************************
void searchwar()
  {             cleardevice();
		fstream mread;
		mread.open("warcops",ios::binary|ios::nocreate) ;
		mread.seekp(0);
		if(mread.eof())
		{ outline();
		  bacck();
		  setcolor(6);
		  outtextxy(250,250,"Sorry!!No Records Found ");
		  mread.close();
		  mousepro(11);
		}
                outline();
	        char code[8];
	        int k=0;
		setcolor(6);
		settextstyle(0,0,0);
		outtextxy(65,78,"Add: Main Menu>>Details of Warcops>>Search>>By Code");
		settextstyle(4,0,1);
		outtextxy(170,100,"Search Options");
		settextstyle(0,0,0);
		outtextxy(80,166,"Enter Code to be searched :");
		gotoxy(40,11);
		gets(code);
		while(!mread.eof())
		 {
		   mread.read((char*)&war,sizeof(war));
		    if(strcmp(code,war.code)==0)
			 { k=1;
			   war.display();
			 }
		 }
                mread.close();
		if (k==1){menu11(2);}
		else
		   { outline();
		     bacck();
		     setcolor(6);
		     outtextxy(250,250,"Sorry!!No Records Found ");
		     mousepro(11);
		    }
	 }
//************************************************************************
void deletewar()

  {             cleardevice();
		fstream mread,ynos;
		mread.open("warcops",ios::binary|ios::nocreate);
                ynos.open("temp",ios::binary|ios::app);
		mread.seekp(0);
		if(mread.eof())
		{ outline();
		  bacck();
		  setcolor(6);
		  outtextxy(250,250,"Sorry!!No Records Found ");
		  mread.close();
		  mousepro(11);
		}
                 char code[8];
		 outline();
		 nomouse();
		 setcolor(8);
		 rectangle(50,90,568,90);
		 setcolor(6);
		 settextstyle(0,0,0);
		 outtextxy(65,78,"Add: Main Menu>>Details of Warcops>>Delete>>By Code");
		 settextstyle(4,0,1);
		 outtextxy(170,100,"Delete Options");
		 settextstyle(0,0,0);
		 outtextxy(80,166,"Enter Code to be searched :");
		 gotoxy(40,11);
		 gets(code);
                 char ch;
		 while(!mread.eof())
		  {
		    mread.read((char*)&war,sizeof(war));
		    if(strcmp(code,war.code)==0)
			 {
			  war.display();
			  cleardevice();
			  outline();
			  nomouse();
			  setcolor(8);
			  settextstyle(0,0,0);
			  outtextxy(80,166,"Do you want to delete the previously displayed entry(y/n)?");
			  ch=getch();
			  if (ch=='y'){}
			  else
			     { outtextxy(80,200,"You have cancelled the deletion process..");
                               ynos.write((char*)&war,sizeof(war));
			     }
			 }
		    else {ynos.write((char*)&war,sizeof(war));}
		}		
		mread.close();
		ynos.close();
		remove("temp");
                rename("temp","warcops");
		cleardevice();
		outline();
		settextstyle(0,0,1);
		outtextxy(80,200,"Your request was completed succesfully...");
		bacck();
		mousepro(11);
      }
//**************************************************************************
void previewwar()
  {
    ifstream mread;
    mread.open("warcops",ios::binary|ios::nocreate);
    if(!mread)
    {cleardevice();
     outline();
     bacck();
     settextstyle(0,0,0);
     outtextxy(210,250,"Sorry !!! No Records Found");
     mousepro(11);
    }
   int i=0;
   while(!mread.eof())
   { mread.read((char*)&war,sizeof(war));
     delay(100);
     ++i;
     cleardevice();
     outline();
     nomouse();
     setcolor(4);
     settextstyle(0,0,0);
     outtextxy(55,57,"Preview");
     gotoxy(30,10);
     cout<<"Preview Page No : "<<i;
     gotoxy(22,15);
     cout<<"Type        :";puts(war.type);
     gotoxy(22,17);
     cout<<"Code        :";puts(war.code);
     gotoxy(22,19);
     cout<<"Description :";puts(war.descrip);
     setcolor(8);
     rectangle(165,350,225,370);
     setcolor(3);
     settextstyle(0,0,0);
     outtextxy(170,355,"<< Esc");
     setcolor(8);
     rectangle(420,350,488,370);
     setcolor(3);
     outtextxy(425,355,"Next >>");
     mousepro(12);
   }
   in.x.ax=1;
   int86(51,&in,&out);
   menu11(2);
}
//***********************************************************

//**************************************************************
void bacck()
		    {   setbkcolor(0);
			setcolor(8);
			rectangle(80,100,130,115);
			setcolor(2);
			settextstyle(0,0,0);
			outtextxy(81,104,"<<Back");
		    }
//*************************************************************
	void close_help() //fn to display "X" and "?" in upper right corners
		    {   setbkcolor(0);
			setfillstyle(1,0);
			bar(530,50,568,70);
			setcolor(8);
			rectangle(531,50,550,70);
			rectangle(551,50,568,70);
			setcolor(4);
			settextstyle(0,0,2);
			outtextxy(553,52,"x");
			outtextxy(533,54,"?");
		     }
//******************************************************************
void outline()
      {  cleardevice();
       setbkcolor(0);
       setcolor(8);
       rectangle(50,50,568,410);
       rectangle(50,70,568,70);
       close_help();
      }
//******************************************************************

//****************************************************************
 class notes
	  { public:
	    time_t g;
	    char subject[20],note[50],sign[15];
	    void get();
	    void display();
	  }note;
//****************************************************************
void notes::get()
   {         time(&t);
	     g=t;
	     cleardevice();
	     delay(300);
	     setcolor(8);
	     rectangle(50,70,568,90);
	     setcolor(6);
	     settextstyle(0,0,0);
	     outtextxy(65,78,"Add: Main Menu>>Dates and Notes>>Create Entry");
	     setcolor(4);
	     settextstyle(0,0,1);
	     outtextxy(55,55,"Dates and Notes");
	     outtextxy(150,120,"  Important  Dates and Notes");
	     gotoxy(15,12);
	     printf("Date and Time :%s",ctime(&g));
	     gotoxy(15,14);
	     printf("Subject :"); gets(subject);
	     gotoxy(15,16);
	     printf("Notes   :"); gets(note);
	     gotoxy(15,20);
	     printf("Ur Name :"); gets(sign);
	   }
//************************************************************************
void notes::display()
	  {  cleardevice();
	     delay(500);
	     setcolor(8);
	     rectangle(50,70,568,90);
	     setcolor(6);
   	     settextstyle(0,0,0);
	     outtextxy(65,78,"Add: Main Menu>>Dates and Notes>>Display Entry");
	     setcolor(4);
	     settextstyle(0,0,1);
	     outtextxy(55,55,"Dates and Notes");
	     outtextxy(150,120,"  Important  Dates and Notes");
	     gotoxy(15,12);
	     printf("Date and Time:%s",ctime(&g));
	     gotoxy(15,16);
	     printf("Subject :"); puts(subject);
	     gotoxy(15,18);
	     printf("Notes   :"); puts(note);
	     gotoxy(15,22);
	     printf("Ur Name :"); puts(sign);
	     printf("\n\nPress Any Key to Continue  >>>>> ");
	     getch();
	 }
//******************************************************************
void createnote()
   { ofstream mread;
     mread.open("notes",ios::binary|ios::app);
     note.get();
     mread.write((char*)&note,sizeof(note));
     mread.close();
     menu11(3);
   }
//**************************************************************************
void searchnote()
 {   cleardevice();
     ifstream mread;
     mread.open("notes",ios::binary|ios::nocreate);
     mread.seekg(0);
     if(mread.eof())
     { outline();
       bacck();
       mread.close();
       outtextxy(200,250,"Sorry!!! No Records Found ....");
       mousepro(11);
     }
     delay(500);
     outline();
     nomouse();
     setcolor(8);
     rectangle(50,90,568,90);
     setcolor(6);
     outtextxy(55,77,"Add  :Main Menu>>Dates and Notes>>Search");
     char subject[20];
     int i=0;
     gotoxy(16,18);
     cout<<"Enter Subject to be searched for   :";
     gets(subject);
     while(!mread.eof())
	  {
	    mread.read((char*)&note,sizeof(note));
	    if(note.subject==subject)
	    { i=1;
             note.display();}
	  }
     mread.close();
       if(i==0)
	{   cleardevice();
	    outline();
	    bacck();
	    mread.close();
	    outtextxy(200,250,"Sorry!!! No Records Found ....");
	    mousepro(11);
 	 }
     mread.close();
     menu11(3);
 }
//************************************************************************
void deletenote()
  {             cleardevice();
		fstream mread,wehtam;
		mread.open("notes",ios::binary|ios::nocreate) ;
                wehtam.open("temp",ios::binary|ios::app);
		mread.seekp(0);
		if(mread.eof())
		{ outline();
		  bacck();
		  setcolor(6);
		  outtextxy(250,250,"Sorry!!No Records Found ");
		  mread.close();
		  mousepro(11);
		}
		 char subject[20];
		 outline();
		 nomouse();
		 setcolor(8);
		 rectangle(50,90,568,90);
		 setcolor(6);
		 settextstyle(0,0,0);
		 outtextxy(65,78,"Add: Main Menu>>Dates and Notes>>Delete>>By Subject");
		 settextstyle(4,0,1);
		 outtextxy(170,100,"Delete Options");
		 settextstyle(0,0,0);
		 outtextxy(80,166,"Enter subject to be searched :");
		 gotoxy(40,11);
		 gets(subject);
		 int i=0;
                 char ch;
		while(!mread.eof())
		 {
		 mread.read((char*)&note,sizeof(note)); 		
	         if(strcmp(subject,note.subject)==0)
		  {i=1;	 
		   note.display();
		   cleardevice();
		   outline();
		   nomouse();
		   settextstyle(0,0,0);
		   outtextxy(80,166,"Do you want to delete the previously displayed entry(y/n)?");
		   ch=getch();
		   if (ch=='y'){}
		   else
			  {
			  outtextxy(80,200,"You have cancelled the deletion process..");
			  wehtam.write((char*)&note,sizeof(note));
			  }
		   }
		 else
		 { wehtam.write((char*)&note,sizeof(note)); }
		}
		   if(i==0)
		   { outline();
		     bacck();
		     setcolor(6);
		     outtextxy(250,250,"Sorry!!No Records Found ");
		     mousepro(11);
		    }
                mread.close();
                wehtam.close();
		remove("notes");
		rename("temp","notes");
		cleardevice();
		outline();
		settextstyle(0,0,1);
		outtextxy(80,200,"Your request was completed succesfully...");
		bacck();
		mousepro(11);
  }
//**********************************************************************
void previewnote()
 {
    ifstream mread;
    mread.open("notes",ios::binary|ios::nocreate);
    if(!mread)
    {cleardevice();
     outline();
     bacck();
     mread.close();
     settextstyle(0,0,0);
     outtextxy(210,250,"Sorry !!! No Records Found");
     mousepro(11);
    }
    int i=0;
   do
   { mread.read((char*)&note,sizeof(note));
     ++i;
     delay(100);
     cleardevice();
     outline();
     nomouse();
     setcolor(4);
     settextstyle(0,0,0);
     outtextxy(55,57,"Preview");
     gotoxy(30,10);
     cout<<"Preview Page No : "<<i;
     gotoxy(22,15);
     printf("Date and Time :%s",ctime(&note.g));
     gotoxy(22,17);
     cout<<"Subject   :";puts(note.subject);
     gotoxy(22,19);
     cout<<"Signed by :";puts(note.sign);
     setcolor(8);
     rectangle(165,350,225,370);
     setcolor(3);
     settextstyle(0,0,0);
     outtextxy(170,355,"<< Esc");
     setcolor(8);
     rectangle(420,350,488,370);
     setcolor(3);
     outtextxy(425,355,"Next >>");
     mousepro(12);
   }while(!mread.eof());
   mread.close();
   menu11(3);
 }
//*******************************************************************
//********************************************************************
	void mouseinit()   //show mouse
	     {
	       in.x.ax=1;
	       int86(51,&in,&out);
	       in.x.ax=7;
	       in.x.cx=0;
	       in.x.dx=getmaxx();
	       int86(51,&in,&out);
	       in.x.ax=8;
	       in.x.cx=0;
	       in.x.dx=getmaxy();
	       int86(51,&in,&out);
	     }
//************************************************************************
int b,d;
int mousepro(int a)	//process close,help,back of mouse
  { int x,y,t,flag=0;
    if(a!=10&&a!=11&&a!=12)
    {b=a;}
    do{
      do{ in.x.ax=1;
	  in.x.ax=3;
	  int86(51,&in,&out);
	  t=out.x.bx;
	  x=out.x.cx;
	  y=out.x.dx;
	} while(t!=1);
    if((x>551&&x<568)&&(y>50&&y<70)){ d=1;flag=1;}
    else if((x>531&&x<550)&&(y>50&&y<70)){ d=2;flag=1;}
    else if (a==1)
       {if((x>200&&x<410)&&(y>350&&y<370)){ d=3;flag=1;}}
    else if (a>1&&a<9)
       {   if(x>150&&x<400)
	     {
		 if(y>150&&y<175)    //first option
		  { if(a==3){d=4;flag=1;}
		    else if(a==4){d=5;flag=1;}
		    else if(a==5){d=6;flag=1;}
		    else if(a==6){d=7;flag=1;}
		    else if(a==7){d=8;flag=1;}
		    else if(a==8||a==9){d=9;flag=1;}
		  }
		 else if(y>180&&y<205)    //second option
		  {if(a==3){d=10;flag=1;}
		   else if(a==4){d=11;flag=1;}
		   else if(a==5){d=12;flag=1;}
		   else if(a==6){d=13;flag=1;}
		   else if(a==7){d=14;flag=1;}
		   else if(a==8||a==9) {d=3;flag=1;}
		  }
		 else if(y>210&&y<235)    //third option
		  { if (a==5){d=4;flag=1;}
		    else if (a==3){d=15;flag=1;}
		    else if (a==4){d=16;flag=1;}
		    else if (a==6){d=17;flag=1;}
		    else if (a==7){d=18;flag=1;}
		    else if (a==8||a==9) {d=1;flag=1;}
		     }
		 else if(y>240&&y<265)    //fourth option
		   {if(a==3){d=3;flag=1;}
		    else if(a==4){d=19;flag=1;}
		    else if(a==6){d=20;flag=1;}
	       	    else if(a==7){d=21;flag=1;}
		    else if(a==8||a==9) {d=22;flag=1;}
		   }
		 else if(y>270&&y<295)    //fifth option
		   { if(a==4||a==6||a==7)
			{d=22;flag=1;}
		     else if(a==3)
			{d=24;flag=1;}
		     else if(a==8)
			{d=25;flag=1;}
		   }
		 else if(y>300&&y<325)    //sixth option
		   { if(a==3){d=1;flag=1;}
                     else if(a==8){d=27;flag=1;} 
                   }
		 else if(y>330&&y<355)    //seventh option
		    { if(a==3){d=2;flag=1;}}
	      }
	 }
	 else if(a==10||a==11)
		{   if((x>80&&x<130)&&(y>100&&y<115))
			   { if(b==1){d=23;flag=1;}
			     else if(b==2) {d=3;flag=1;}
			     else if(b==3) {d=22;flag=1;}
			     else if(b==4) {d=4;flag=1;}
			     else if(b==5) {d=11;flag=1;}
			     else if(b==6) {d=10;flag=1;}
			     else if(b==7) {d=15;flag=1;}
			   }
		}
	else if(a==12)
		{  if((x>165&&x<225)&&(y>350&&y<370))
		     {d=4;flag=1;}
		   if((x>420&&x<488)&&(y>350&&y<370))
		     {d=26;flag=1;}
		}
     }while(!flag);
     if(d==1)  {exit(0);}
     else if(d==2) {aboutus();}
     else if(d==3) {pass2();}
     else if(d==4) {menu11(1);}
     else if(d==5) {create_ntry111();}
     else if(d==6) {searchsoldier(1);}
     else if(d==7) {createwar();}
     else if(d==8) {createnote();}
     else if(d==9) {change();}
     else if(d==10){menu11(2);}	
     else if(d==11){searchsoldier1();}
     else if(d==12){searchsoldier(2);}
     else if(d==13){searchwar();}
     else if(d==14){searchnote();}
     else if(d==15){menu11(3);}
     else if(d==16){deletesoldier();}
     else if(d==17){deletewar();}
     else if(d==18){deletenote();}
     else if(d==19){previewsoldier();}
     else if(d==20){previewwar();}
     else if(d==21){previewnote();}
     else if(d==22){menu();}
     else if(d==23){welcomepage();}
     else if(d==24){account1();}
     else if(d==25){others1();}
     else if(d==26){return 0;}
     else if(d==27){others();}
     return 0;
   }
//***********************************************************************
void nomouse()
   { setcolor(8);
     rectangle(50,390,568,390);
     settextstyle(0,0,0);
     outtextxy(52,395,"Note: Mouse Not Available or Not Currently Active");
   }
//********************************************************************
//*****************************************************************
void menu() //displays the main menu
   {
      in.x.ax=1;
      int86(51,&in,&out);
      delay(500);
      outline();
       setcolor(8);
       rectangle(50,90,568,90);
       setcolor(6);
       settextstyle(0,0,0);
       outtextxy(65,78,"Add: Main Menu");

      setcolor(8);
      settextstyle(4,0,1);
      for(int j=0;j<7;++j)
      {rectangle(150,j*30+150,400,j*30+175);  }
      setcolor(6);
      outtextxy(150,150,"  Details of soldiers ");
      outtextxy(150,180,"  Details of warcops");
      outtextxy(150,210,"  Important dates & notes");
      outtextxy(150,240,"  Log Out");
      outtextxy(150,270,"  Account Settings");
      outtextxy(150,300,"  Exit");
      outtextxy(150,330,"  Contact Us");
      in.x.ax=1;
      int86(51,&in,&out);
      mousepro(3);
   }
//*****************************************************************
 void menu11(int a)  //first sub-menu
	    {     cleardevice();
		  delay(500);
		  outline();
		  setcolor(8);
		  for(int j=0;j<5;++j)
		  {rectangle(150,j*30+150,400,j*30+175);  }
		  rectangle(50,90,568,90);
		  setcolor(6);
		  settextstyle(0,0,0);
		  if(a==1)
		  {outtextxy(65,78,"Add: Main Menu>>Details of Soldiers");}
		  else if(a==2)
		  {outtextxy(65,78,"Add: Main Menu>>Details of Warcops");}
		  else if(a==3)
		  {outtextxy(65,78,"Add: Main Menu>>Dates and Notes");}
		  settextstyle(4,0,1);
		  outtextxy(150,150,"  Create an Entry ");
		  outtextxy(150,180,"  Search an Entry");
		  outtextxy(150,210,"  Delete an Entry");
		  outtextxy(150,240,"  Preview all Entries");
		  outtextxy(150,270,"  Back to Main Menu ");
		  if(a==1)
		  {mousepro(4);}
		  else if(a==2)
		  {mousepro(6);}
		  else if(a==3)
		  {mousepro(7);}
	     }
//***************************************************************