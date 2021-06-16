#include<iostream>
#include<conio>
#include<stdio>
#include<string>
#include<fstream>
#include<process>
//****************************************************
//GOBAL DECLARATION
//****************************************************
 fstream x,y;
/******************************************************/
//              CLASS FOR THE PROGRAM
/******************************************************/
using namespace std;
 class inn
 {
  String nationality,type,name,date;
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

  
