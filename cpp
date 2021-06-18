//******************************************************/
//HEADER FILES INCLUDED
/******************************************************/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
//****************************************************
//GOBAL DECLARATION
//****************************************************
 fstream x,y;
/******************************************************/
//              CLASS FOR THE PROGRAM
/******************************************************/
 class inn
 {
  char nationality[25],type[25],name[25],date[20];
  int cno,r,nod;
  public:
	 void add();
	 void modify();
	 void del();
	 void display();
	 void display_all();

  void get()
  {
  cout<<"\n PLEASE ENTER CUSTOMER NUMBER:";
  cin>>cno;
  cout<<"\n ENTER YOUR NAME :";
  gets(name);
  cout<<"\n ENTER YOUR NATIONALITY:";
  gets(nationality);
  cout<<"\n ENTER NO OF DAYS OF LODGING:";
  cin>>nod;
  cout<<"\n ENTER CHECKIN DATE:";
  gets(date);
  cout<<"\n ENTER TYPE OF ROOM (AC/NON AC):";
  gets(type);
  cout<<"\n ENTER NO OF ROOM:";
  cin>>r;
  }

  void disp()
  {
  cout<<"\n CUSTOMER NUMBER:"<<"\n"<<cno;
  cout<<"\n CUSTOMER NAME :";
  puts(name);
  cout<<"\n NATIONALITY:";
  puts(nationality);
  cout<<"\n NO OF DAYS OF LODGING:"<<nod;
  cout<<"\n ENTER CHECKIN DATE:";
  puts(date);
  cout<<"\n ENTER TYPE OF ROOM (AC/NON AC):";
  puts(type);
  cout<<"\n ENTER NO OF ROOM:"<<r;
  }


  int ret_cno()
  {
   return cno;
  }

 }obj;

  //****************************************************
		  //reserving
  //*****************************************************

  void inn:: add()
  {
  x.open("inn.dat",ios::app|ios::binary);
  obj.get();
  x.write((char*)&obj,sizeof(obj));
  x.close();
  cout<<"\n YOUR ROOM HAS BEEN RESERVED";
  }

  //*****************************************************
		      //modification
  //*****************************************************
  void inn:: modify()
  {
  int ch,no;
  cout<<"\n ENTER CUSTOMER NUMBER:";
  cin>>no;
  x.open("inn.dat",ios::in|ios::out|ios::binary);
  x.read((char*)&obj,sizeof(obj));
  while(!x.eof())
  {
   if(no==obj.ret_cno())
   {
   cout<<"\n PRESS 1 TO CHANGE THE NUMBER OF DAYS OF LODEGING";
   cout<<"\n PRESS 2 TO CHANGE THE TYPE OF ROOM";
   cout<<"\n PRESS 3 TO CHANGE THE NUMBER OF ROOMS";
   cout<<"\n ENTER THE CHOICE:";
   cin>>ch;
   switch(ch)
   {
     case 1 : {   char room_type[25];
	       cout<<"\n CHANGE THE ROOM TYPE TO(AC/NON AC);";
	       gets(room_type);
	       strcpy(type,room_type); }
	       break;
     case 2  : {    int no_days;
	       cout<<"\n CHANGE NUMBER OF DAYS TO;";
	       cin>>no_days;
	       nod=no_days;  }
	       break;
     case 3  : {    int no_rooms;
	       cout<<"\n CHANGE NUMBER OF ROOMS TO:";
	       cin>>no_rooms;
	       r=no_rooms; }
	       break;
     default :     cout<<"\n INVALID OPTION";
   }
  x.seekg(-101,ios::cur);
  x.write((char*)&obj,sizeof(obj));
  }
  x.read((char*)&obj,sizeof(obj));
  }
  x.close();
  cout<<"\n YOUR RESERVATION DATA HAS BEEN MODIFIED";
  }

  //*****************************************************
		   //delect
  //*****************************************************
  void inn:: del()
   {
   int num;
   cout<<"\n ENTER THE CUSTOMER NUMBER:";
   cin>>num;
   x.open("inn.dat",ios::in|ios::binary);
   y.open("temp.dat",ios::out|ios::binary);
   x.read((char*)&obj,sizeof(obj));
   while(!x.eof())
   {
    if(num!=obj.ret_cno() )
    y.write((char*)&obj,sizeof(obj));
    x.read((char*)&obj,sizeof(obj));
   }
   x.close();
   y.close();
   remove("inn.dat");
   rename("temp.dat","inn.dat");
   cout<<"\n YOUR RESERVATION HAS BEEN CANCELLED";
   }
   //****************************************************
		       //info of 1 guests
   //****************************************************
   void inn:: display()
    {
   int no;
   cout<<"\n ENTER CUSTOMER NUMBER";
   cin>>no;
   x.open("inn.dat",ios::in|ios::binary);
  // x.read((char*)&obj,sizeof(obj));
 x.seekg(0);
  while( x.read((char*)&obj,sizeof(obj)))
   {
    if(no==obj.ret_cno())
    obj.disp();
    x.read((char*)&obj,sizeof(obj));
   }
   x.close();
   }
  //*****************************************************
		     //info of all guests
 //*****************************************************
   void inn:: display_all()
   {
   x.open("inn.dat",ios::in|ios::binary);
   x.read((char*)&obj,sizeof(obj));
   while(!x.eof())
   {
   obj.disp();
   x.read((char*)&obj,sizeof(obj));
   }
   x.close();
   }




 //*****************************************************
		   //main function
 //*****************************************************
void main()
{
  int an;
  char ans;
  do
  {
   clrscr();
   cout<<"\n\t\t      PROJECT PRESENTED BY AJAY .A.N                    ";
   cout<<"\n\t\t########################################################";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                 __HOTEL BLUESTAR__                   #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t########################################################";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#************************MENU**************************#";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t#\t1. RESERVING                                   #";
   cout<<"\n\t\t#\t2. CANCELLING                                  #";
   cout<<"\n\t\t#\t3. MODIFICATION                                #";
   cout<<"\n\t\t#\t4. VIEW INFO OF 1 GUEST                        #";
   cout<<"\n\t\t#\t5. VIEW INFO OF ALL GUEST                      #";
   cout<<"\n\t\t#\t6. EXIT                                        #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t########################################################";
   cout<<"\n\t\t  ENTER THE OPTION: ";
   cin>>an;
   switch(an)
    {
     case 1 : obj.add();          break;
     case 2 : obj.del();          break;
     case 3 : obj.modify();       break;
     case 4 : obj.display();      break;
     case 5 : obj.display_all();  break;
     case 6 : exit(0);            break;
     default: cout<<"\n INVALID OPTION"<<"\n PLEASE TRY AGAIN";
    }
   cout<<"\n DO YOU WANT TO CONTINUE(Y/N) ";
   cin>>ans;
  }while(ans=='Y'||ans=='y');
  clrscr();
  cout<<"\n\n\n\n\n\n\n\n\n******************************************************************************           ";
  cout<<"\n\n\t\t\t\t ....THANK YOU....";
  cout<<"\n\n\t\t\t  ... HOPE YOU ENJOYED YOUR STAY...";
  cout<<"\n\n\t\t\t       .. PLEASE VISIT AGAIN..               \n\n\n\n\n ";
  cout<<"******************************************************************************           ";  getch();
  getch();
}

