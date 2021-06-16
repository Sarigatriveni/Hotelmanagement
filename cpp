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

  
