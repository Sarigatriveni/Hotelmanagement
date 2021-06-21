#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<process.h>
using namespace std;
//****************************************************
//GOBAL DECLARATION
//****************************************************
 fstream x,y;
/******************************************************/
//              CLASS FOR THE PROGRAM
/******************************************************/
 class inn
 {

  public:

	  string name,date,type,nationality;
	 int cno,r,ro,nod,total_amt1, total_amt2;
	 void add();
	 void modify();
	 void del();
	 void display(int display_cno);
	 void display();

  void get()
  {
  cout<<"\n PLEASE ENTER CUSTOMER NUMBER:";
  cin>>cno;
  cout<<"\n ENTER YOUR NAME :";
  getline(cin>>ws,name);
  cout<<"\n ENTER YOUR NATIONALITY:";
  getline(cin>>ws,nationality);
  cout<<"\n ENTER NO OF DAYS OF LODGING:";
  cin>>nod;
  cout<<"\n ENTER CHECKIN DATE:";
  getline(cin>>ws,date);
  cout<<"\n ENTER TYPE OF ROOM (AC/NON/BOTH) :";
  getline(cin>>ws,type);
  cout<<"\n ENTER NO OF ROOMS AC:";
  cin>>r;
  cout<<"\n ENTER NO OF ROOMS  NON AC:";
  cin>>ro;
  }

  void disp()
  {
  cout<<"\n CUSTOMER NUMBER:"<<" "<<cno;
  cout<<"\n CUSTOMER NAME :"<<" "<<name;

  cout<<"\n NATIONALITY:"<<" "<<nationality;

  cout<<" "<<"NO OF DAYS OF LODGING:"<<" "<<nod;
  cout<<"\n CHECKIN DATE:";
  cout<<date;
  cout<<"\n TYPE OF ROOM (AC/NON/BOTH):";
  cout<<type;
  cout<<"\n NO OF ROOMS AC:"<<r;
  cout<<"\n NO OF ROOMS NON AC:"<<ro;
  cout<<endl;
  }


  int ret_cno()
  {
   return cno;
  }

 }obj;

class Bill:public inn
{
    public:
    int num,room_no,days,total_amt1, total_amt2;
    string t;
    void getbill();
}obj1;

    void Bill:: getbill()
  {
   float  total_amt1=0, total_amt2=0;
    int room_ac,room_nac, days;
    string NON_AC="NON";
    string AC="AC";
    string BOTH="BOTH";
    cout<<"ENTER CUSTOMER NUMBER";
    cin>>num;
     x.open("inn.dat",ios::in|ios::out|ios::binary);
     while(!x.eof())
     {
	x.read((char*)&obj,sizeof(obj));
	if(obj.ret_cno()==num)
	{
	    t=obj.type;
        room_ac=obj.r;
	    room_nac = obj.ro;
	    days=obj.nod;

	}
     }

    if(t==AC)
    {
     total_amt2 = room_ac * days* 1000;
     cout<<"\n Total amt due in checkout2: "<<total_amt2;
    }
    if(t==NON_AC)
    {
     total_amt1=room_nac*days*800;
     cout<<"\n Total amt due in checkout1: "<<total_amt1;
    }
   if(t==BOTH)
    {
     total_amt1=(room_ac*days*1000)+(room_nac*days*800);
     cout<<"\n Total amt due in checkout1: "<<total_amt1;
    }
     x.close();
  }

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
  long pos;
  cout<<"\n ENTER CUSTOMER NUMBER:";
  cin>>no;
  x.open("inn.dat",ios::in|ios::out|ios::binary);

  while(!x.eof())
  {
    pos=x.tellg();
    x.read((char*)&obj,sizeof(obj));
   if(no==obj.ret_cno())
   {
   cout<<"\n PRESS 1 TO CHANGE THE TYPE OF ROOM";
   cout<<"\n PRESS 2 TO CHANGE THE NUMBER OF DAYS OF LODGING ";
   cout<<"\n PRESS 3 TO CHANGE THE NUMBER OF ROOMS";
   cout<<"\n ENTER THE CHOICE:";
   cin>>ch;
   switch(ch)
   {
     case 1 : {   string room_type;
	       cout<<"\n CHANGE THE ROOM TYPE TO(AC/NON AC/BOTH)"<<endl;
	       getline(cin>>ws,room_type);
	       type=room_type; }
	       break;
     case 2  : {    int no_days;
	       cout<<"\n CHANGE NUMBER OF DAYS TO:";
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
  x.seekg(pos);
  x.write((char*)&obj,sizeof(obj));
  break;
   }
  }
  x.close();
  cout<<"\n YOUR RESERVATION DATA HAS BEEN MODIFIED";
  }


  //*****************************************************
		   //delete
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
    void inn:: display(int display_cno)
    {

      x.open("inn.dat",ios::in|ios::binary);
       x.seekg(0);


  while(!x.eof())
   {
    x.read((char*)&obj,sizeof(obj));

    if(display_cno == obj.ret_cno())
    {

    obj.disp();
    break;
    }

    }
 x.close();
   }


  //*****************************************************
		     //info of all guests
 //*****************************************************
    void inn:: display()
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
int main()
{
  int an;
  char ans;
  do
  {
    system("cls");

   cout<<"\n\t\t      PROJECT PRESENTED BY GROUP 3                 ";
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
   cout<<"\n\t\t#\t6. BILLING                                     #";
   cout<<"\n\t\t#\t7. EXIT                                        #";
   cout<<"\n\t\t#                                                      #";
   cout<<"\n\t\t########################################################";
   cout<<"\n\t\t  ENTER THE OPTION: ";
   cin>>an;
   switch(an)
    {
     case 1 : obj.add();          break;
     case 2 : obj.del();          break;
     case 3 : obj.modify();       break;
     case 4 : {
	      cout<<"ENTER CUSTOMER NUMBER:";
	      int display_cno;
	      cin>>display_cno;
	      obj.display(display_cno);
	      }   break;
     case 5 : obj.display();      break;
     case 6 : obj1.getbill();      break;
     case 7 : {
         system("cls");

	      cout<<"\n\n\n\n\n\n\n\n\n******************************************************************************           ";
	      cout<<"\n\n\t\t\t\t ....THANK YOU....";
	      cout<<"\n\n\t\t\t  ... HOPE YOU ENJOYED YOUR STAY...";
	      cout<<"\n\n\t\t\t       .. PLEASE VISIT AGAIN..               \n\n\n\n\n ";
	      cout<<"******************************************************************************           ";  getch();
	      getch();
	      exit(0);
	      }   break;
     default: cout<<"\n INVALID OPTION"<<"\n PLEASE TRY AGAIN";
    }
   cout<<"\n DO YOU WANT TO CONTINUE(Y/N) ";
   cin>>ans;
  }while(ans=='Y'||ans=='y');
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n******************************************************************************           ";
  cout<<"\n\n\t\t\t\t ....THANK YOU....";
  cout<<"\n\n\t\t\t  ... HOPE YOU ENJOYED YOUR STAY...";
  cout<<"\n\n\t\t\t       .. PLEASE VISIT AGAIN..               \n\n\n\n\n ";
  cout<<"******************************************************************************           ";  getch();
  getch();
  return 0;
}



