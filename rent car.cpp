/******************************** RENT CARS
******************************/
/******HEADER FILE DECLARATION******/
#include<fstream>
#include<stdio>
#include<conio>
#include<string>
#include<process>
#include<iomanip>
#include<dos>
#include<graphics>
/******GLOBAL VARIABLES******/
fstream file;
ifstream infile;
ofstream outfile;
char res1;
int res,temp_color=0;
/******FUNCTION DECLARATION USED FOR GRAPHICS******/
void boundary1();
void check_temp_color();
void credits();
void front_page();
struct proprietor
{
char name[50],address[80],car_name[80],car_no[20];
char phone[10],status[50];
float amt_per_day;
};
struct customer
{
char name[50],address[80],phone[10],car_no[20];
int no_of_people,no_of_days;
char car_chosen[80];
float payble_amount;
date d;
};
/******DECLARAING A CLASS******/
class employee
{
proprietor e; //Object of structure proprietor
customer c; //Object of structure customer
float collection;
public:
employee() //Constructor to initialize collection
{
collection=0;
}
~employee() //Destructor to destroy the created object
{
cout<<"MEMORY DESTROYED";
}
/**********FUNCTION DECLARATION**********/
void rent_a_car();
void rentyourcar();
void company_employee();
void edit_details();
void employees();
void check_details();
void delete_record();
void cars_rented();
float collected_amount();
}emp;
/*********************************************************************
*******
The function is used to take a car on rent from car proprietor. Cars
are
taken after proper validation. After entering all the details the
records are
appended in employee.dat data file.
**********************************************************************
*****/
void employee::rentyourcar()
{
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
check_temp_color();
settextstyle(7,0,2);
outtextxy(38,63,"WELCOME TO LIMO PVT. LMT.");
outtextxy(35,73,"-------------------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(35,10);
cout<<"FILL THIS FORM TO RENT YOUR CAR:";
outfile.open("employee.dat",ios::binary | ios::app);
strcpy(e.status,"NOT BOOKED");
gotoxy(35,11);
cout<<"Name:";gets(e.name);
gotoxy(35,12);
cout<<"Phone no:";cin>>e.phone;
gotoxy(35,13);
cout<<"Address:";gets(e.address);
gotoxy(29,14);
cout<<"Are you having REGISTRATION of your car(y/n):";cin>>res1;
if(res1=='n')
{
outfile.close();
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,2);
outtextxy(38,63," LIMO PVT. LMT.");
outtextxy(35,73,"---------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(17,10);
cout<<" YOUR REQUEST IS CANCELLED DUE TO FAILURE OF CAR REGISTRATION
";
gotoxy(17,15);
cout<<" PRESS ANY KEY FOR MAIN MENU! ";
getch();
return;
}
gotoxy(35,15);
cout<<"Enter name of car:";cin>>e.car_name;
gotoxy(35,16);
cout<<"Enter car number:";gets(e.car_no);
gotoxy(34,17);
cout<<"Amount you want to charge per day:";cin>>e.amt_per_day;
gotoxy(35,18);
cout<<"Wants to confirm(y/n):";cin>>res1;
if(res1=='n')
{
file.close();
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,2);
outtextxy(38,63," LIMO PVT. LMT.");
outtextxy(35,73,"---------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(17,10);
cout<<" YOUR CAR REQUEST IS CANCELLED! ";
gotoxy(17,15);
cout<<" PRESS ANY KEY FOR MAIN MENU! ";
getch();
return;
}
else
outfile.write((char*)&e,sizeof(e));
outfile.close();
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(30,5);
cout<<"Name:"<<e.name;
gotoxy(30,7);
cout<<"Phone no:"<<e.phone;
gotoxy(30,9);
cout<<"Address:";
puts(e.address);
gotoxy(30,11);
cout<<"Name of car:"<<e.car_name;
gotoxy(30,13);
cout<<"Car number:"<<e.car_no;
gotoxy(30,15);
cout<<"Amount charged per day:"<<e.amt_per_day;
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,2);
outtextxy(38,63," LIMO PVT. LMT.");
outtextxy(35,73,"---------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(17,10);
cout<<" YOU ARE NOW A MEMBER OF OUR GROUP ";
gotoxy(17,15);
cout<<" THANK YOU! ";
gotoxy(18,24);
cout<<" PRESS ANY KEY TO CONTINUE!";
getch();
}
/*********************************************************************
*******
The rent_a_car() function provides a screen to rent a car after
entering
all the details of the same and are appended in customer.dat data
file.
*********************************************************************
******/
void employee::rent_a_car()
{
char temp_car_no[20];
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,3);
outtextxy(35,42,"WELCOME TO LIMO PVT. LMT.");
outtextxy(35,54,"--------------------------");
gotoxy(30,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(30,11);
cout<<"ENTER FOLLOWING DETAILS TO RENT A CAR:\n";
outfile.open("customer.dat",ios::binary);
infile.open("employee.dat",ios::binary);
if(!infile)
exit(0);
gotoxy(30,13);
cout<<"Name:";gets(c.name);
gotoxy(30,15);
cout<<"Phone no:";cin>>c.phone;
gotoxy(30,17);
cout<<"Address:";gets(c.address);
gotoxy(30,19);
cout<<"Number of peoples going:";cin>>c.no_of_people;
gotoxy(30,21);
cout<<"Number of days:";cin>>c.no_of_days;
xx:
int flag=0,y=7;
cleardevice();
boundary1();
settextstyle(3,0,5);
outtextxy(49,20,"CARS AVAILABLE");
settextstyle(7,0,3);
outtextxy(33,90,"CAR NAME CAR NUMBER");
while(!infile.eof())
{
infile.read((char*)&e,sizeof(e));
if(infile.eof())
break;
if(strcmpi(e.status,"NOT BOOKED")==0)
{
y+=2;
flag=1;
gotoxy(7,y);
cout<<setw(10)<<e.car_name<<setw(25)<<e.car_no<<endl;
}
}
infile.close();
gotoxy(5,20);
if(flag!=1)
{
cout<<"SORRY! No Cars Available, All Are Booked";
getch();
return;
}
else
cout<<"Enter car number of your desired car:";gets(temp_car_no);
flag=0;
long pos;
file.open("employee.dat",ios::binary|ios::in|ios::out);
if(!file)
exit(0);
while(!file.eof())
{
pos=file.tellp();
file.read((char*)&e,sizeof(e));
if(strcmpi(e.car_no,temp_car_no)==0)
{
strcpy(e.status,"BOOKED!");
file.seekp(pos,ios::beg);
file.write((char*)&e,sizeof(e));
flag=1;
strcpy(c.car_chosen,e.car_name);
strcpy(c.car_no,e.car_no);
c.payble_amount=(e.amt_per_day +
(0.6*e.amt_per_day))*c.no_of_days;
collection+=0.6*e.amt_per_day*c.no_of_days; //Earning 60 %
profit
break;
}
}
if(flag==0)
{
cout<<"\nEnter correct car number!";
getch();
goto xx;
}
file.close();
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(30,5);
cout<<"Name:"<<c.name;
gotoxy(30,7);
cout<<"Phone no:"<<c.phone;
gotoxy(30,9);
cout<<"Address:";puts(c.address);
gotoxy(30,11);
cout<<"Number of peoples going:"<<c.no_of_people;
gotoxy(30,13);
cout<<"Number of days:"<<c.no_of_days;
gotoxy(30,15);
cout<<"Car Name:"<<c.car_chosen;
gotoxy(30,17);
cout<<"Payble Amount:"<<c.payble_amount;
gotoxy(30,19);
cout<<"Wants to confirm(y/n)";cin>>res1;
if(res1=='y')
{
outfile.write((char*)&c,sizeof(c));
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,2);
outtextxy(38,63," LIMO PVT. LMT.");
outtextxy(35,73,"---------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(17,10);
cout<<" YOUR CAR IS BOOKED! ";
gotoxy(17,15);
cout<<" ENJOY YOUR JOURNEY ";
gotoxy(17,20);
cout<<" PRESS ANY KEY FOR MAIN MENU! ";
getch();
return;
}
else
{
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,2);
outtextxy(38,63," LIMO PVT. LMT.");
outtextxy(35,73,"---------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(17,10);
cout<<" YOUR REQUEST IS CANCELLED ";
gotoxy(17,15);
cout<<"GOOD BYE! ";
getch();
return;
}} /*********************************************************************
*******
This function is used to check, edit or find the number of car
proprietors
and other details from respective files.
**********************************************************************
******/
void employee::company_employee()
{
ZZ:
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,temp_color++);
gotoxy(30,5);
cout<<"1.........REDRAFT PROPRIETORS INFO";
gotoxy(30,7);
cout<<"2.........ABSOLUTE NO. OF PROPRIETORS";
gotoxy(30,9);
cout<<"3.........DETAIL OF A SPECIFIC PROPRIETOR";
gotoxy(30,11);
cout<<"4.........OBLITERATE PROPRIETOR'S ACCOUNT";
gotoxy(30,13);
cout<<"5.........CARS ON TARIFF";
gotoxy(30,15);
cout<<"6.........NET COLLECTION";
gotoxy(30,17);
cout<<"7.........MAIN MENU";
gotoxy(30,19);
cout<<"8.........ESCAPE ROUTE";
gotoxy(10,25);
cout<<"Enter Choice:";
cin>>res;
switch(res)
{
case 1:
emp.edit_details();
break;
case 2:
emp.employees();
break;
case 3:
emp.check_details();
break;
case 4:
emp.delete_record();
break;
case 5:
emp.cars_rented();
break;
case 6:
cout<<emp.collected_amount();
break;
case 7:
return;
case 8:
credits();
exit(0);
}
getch();
goto ZZ;
}
/*********************************************************************
*******
This function is used to modify the details of car proprietor by
comparing
his name and car number from existing file i.e. employee.dat data
file.
**********************************************************************
******/
void employee::edit_details()
{
int flag=0;
float pos=0;
char temp_name[25],temp_carno[20];
file.open("employee.dat",ios::binary|ios::in|ios::out);
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(20,10);
cout<<"ENTER FOLLOWING DETAILS TO CONTINUE";
gotoxy(20,14);
cout<<"ENTER YOUR NAME: ";gets(temp_name);
gotoxy(20,18);
cout<<"ENTER YOUR CAR NO: ";gets(temp_carno);
if(!file)
exit(0);
while(!file.eof())
{
pos=file.tellp();
file.read((char*)&e,sizeof(e));
if(file.eof())
break;
if(strcmpi(temp_name,e.name)==0 &&
strcmpi(temp_carno,e.car_no)==0)
{
flag=1;
break;
}
else
{
gotoxy(17,18);
cout<<"WRONG CAR NO.OR NAME ";
return;
}
}
if (flag==1)
{
yy:
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(30,5);
cout<<"EDIT DETAILS";
gotoxy(30,7);
cout<<"1____________CHANGE YOUR CAR";
gotoxy(30,9);
cout<<"2____________CHANGE AMOUNT OF CAR";
gotoxy(30,11);
cout<<"3____________CHANGE YOUR MOBILE NO.";
gotoxy(30,13);
cout<<"4____________CHANGE ALL THE DETAILS";
gotoxy(30,15);
cout<<"ENTER YOUR CHOICE";
cin>>res;
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
switch(res)
{
case 1:
gotoxy(17,10);
cout<<"Hii "<<e.name;
gotoxy(17,12);
cout<<"Name of your car :";cin>>e.car_name;
gotoxy(17,14);
cout<<"ARE YOU HAVING REGISTERED DOCUMENTS OF YOUR CAR [y/n]
:";cin>>res1;
if(res1=='n')
{
gotoxy(17,15);
cout<<" YOUR REQUEST IS CANCELLED DUE TO FAILURE OF CAR
REGISTRATION ";
getch();
return;
}
else
{
gotoxy(17,16);
cout<<"CAR NO.: ";gets(e.car_no);
gotoxy(17,18);
cout<<"AMOUNT YOU WANT TO CHARGE PER DAY
:";cin>>e.amt_per_day;
cout<<"PRESS ANY KEY TO CONTINUE!";
getch();
}
break;
case 2:
gotoxy(17,9);
cout<<"Hii "<<e.name;
gotoxy(17,19);
cout<<"AMOUNT YOU WANT TO CHARGE PER DAY
:";cin>>e.amt_per_day;
gotoxy(17,21);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
break;
case 3:
gotoxy(17,9);
cout<<"Hii "<<e.name;
gotoxy(17,11);
cout<<"MOBILE : "<<e.phone;
gotoxy(17,21);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();
break;
case 4:
gotoxy(17,9);
cout<<"NAME : ";gets(e.name);
gotoxy(17,11);
cout<<"MOBILE : ";cin>>e.phone;
gotoxy(17,13);
cout<<"ARE YOU HAVIND REGISTERED DOCUMENTS OF YOUR CAR [y/n]
:";cin>>res1;
if(res1=='n')
{
gotoxy(17,15);
cout<<" YOUR REQUEST CAN NOT BE PROCESSED DUE TO FAILURE OF
CAR REGISTRATION ";
gotoxy(18,22);
cout<<" PRESS ANY KEY FOR MAIN MENU! ";
getch();
return;
}
else
if(res1=='y')
{
gotoxy(17,15);
cout<<"Name of your car :";cin>>e.car_name;
gotoxy(17,17);
cout<<"CAR NO.: ";gets(e.car_no);
gotoxy(17,19);
cout<<"AMOUNT YOU WANT TO CHARGE PER DAY
:";cin>>e.amt_per_day;
gotoxy(17,21);
cout<<"PRESS ANY KEY TO CONTINUE ";
getch();
}
break;
}
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(22,5);
cout<<"COFIRMATION";
gotoxy(17,9);
cout<<"NAME : "<<e.name;
gotoxy(17,11);
cout<<"MOBILE : "<<e.phone;
gotoxy(17,13);
cout<<"Name of your car :"<<e.car_name;
gotoxy(17,15);
cout<<"CAR NO.: "<<e.car_no;
gotoxy(17,17);
cout<<"AMOUNT YOU WANT TO CHARGE PER DAY :"<<e.amt_per_day;
gotoxy(17,20);
cout<<"DO YOU WANT TO CONFIRM(y/n):";cin>>res1;
if(res1=='y')
{
file.seekp(pos,ios::beg);
file.write((char*)&e,sizeof(e));
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(17,10);
cout<<" THANK YOU ";
gotoxy(17,15);
cout<<"YOU ARE NOW A MEMBER OF OUR GROUP ";
getch();
}
else
goto yy;
file.close();
}
}
/*********************************************************************
*******
The employees() function is used to display absolute number of
proprietors
with details of there car name, car number and status of booking.This
is a
global report to display all proprietors record in the screen.
**********************************************************************
******/
void employee::employees()
{
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
int y=10;
infile.open("employee.dat",ios::binary);
if(!infile)
exit(0);
gotoxy(30,5);
cout<<setw(5)<<"Name"<<setw(10)<<"Car Name"<<setw(13)<<"Car Number"
<<setw(12)<<"Status"<<endl<<endl;
while(!infile.eof())
{
infile.read((char*)&e,sizeof(e));
if(infile.eof())
break;
gotoxy(30,y);
cout<<setw(5)<<e.name<<setw(10)<<e.car_name<<setw(13)
<<e.car_no<<setw(15)<<e.status<<endl;
y+=2;
}
infile.close();
}
/*********************************************************************
*******
The check_details() function is used to display the details of a
particular
propritor by comparing its name and car number from employee.dat data
file.
**********************************************************************
******/
void employee::check_details()
{
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
infile.open("employee.dat",ios::binary) ;
char temp_name[80];
char temp_carno[20];
gotoxy(17,10);
cout<<"Enter the Name of the employee:";
cin>>temp_name;
gotoxy(17,12);
cout<<"Enter Car number:";
gets(temp_carno);
if(!infile)
{
gotoxy(17,14);
cout<<"File does not exist";
exit(0);
}
while(!infile.eof())
{
infile.read((char*)&e,sizeof(e));
if(infile.eof())
break;
else
if(strcmpi(temp_carno,e.car_no)==0 &&
strcmpi(temp_name,e.name)==0)
{
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
gotoxy(30,5);
cout<<"Name:"<<e.name;
gotoxy(30,7);
cout<<"Phone no:"<<e.phone;
gotoxy(30,9);
cout<<"Address:";
puts(e.address);
gotoxy(30,11);
cout<<"Name of car:"<<e.car_name;
gotoxy(30,13);
cout<<"Car number:"<<e.car_no;
gotoxy(30,15);
cout<<"Amount charged per day:"<<e.amt_per_day;
}
}
infile.close();
}
/*********************************************************************
*******
This fuction is used to remove a proprietors account from employee.dat
data
file, this is a copy method to delete the account from file.
**********************************************************************
******/
void employee::delete_record()
{
int flag=0;
char temp_car_no[20];
infile.open("employee.dat",ios::binary);
outfile.open("temp.dat",ios::binary);
gotoxy(17,10);
cout<<"Enter the CAR NUMBER";
gets(temp_car_no);
if(!infile)
{
gotoxy(17,12);
cout<<"File does not exist";
exit(0);
}
while(!infile.eof())
{
infile.read((char*)&e,sizeof(e));
if(infile.eof())
break;
if(strcmpi(temp_car_no,e.car_no)==0)
{
if(strcmpi(e.status,"BOOKED!")==0)
{
flag=1;
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
boundary1();
settextstyle(7,0,2);
outtextxy(38,63," LIMO PVT. LMT.");
outtextxy(35,73,"---------------");
gotoxy(35,7);
cout<<"AFFILIATED TO CAR CLUB...";
gotoxy(17,10);
cout<<" OOPS!! SORRY ";
gotoxy(17,12);
cout<<"THIS ACCOUNT CAN NOT BE DELETED";
gotoxy(17,14);
cout<<"AS THIS CAR NUMBER IS ALREADY BOOKED!";
gotoxy(17,18);
cout<<"PRESS ANY KEY FOR MAIN MENU!";
getch();
break;
}
}
else
outfile.write((char*)&e,sizeof(e));
}
infile.close();
outfile.close();
if(flag==0)
{
gotoxy(17,14);
cout<<"DELETED Successfully";
remove("employee.dat");
rename("temp.dat","employee.dat");
}
else
remove("temp.dat");
}
/*********************************************************************
*******
This is a return fuction to return a float value collection. It tells
about
the total amount earned in a day.
**********************************************************************
******/
float employee::collected_amount()
{
cleardevice();
setcolor(temp_color++);
boundary1();
check_temp_color();
setbkcolor(temp_color++);
settextstyle(1,0,6);
outtextxy(50,45," LIMO PVT. LMT.");
gotoxy(27,8);
cout<<"AFFILIATED TO CAR CLUB....";
gotoxy(17,15);
cout<<"OUR NET COLLECTION :";
return(collection);
}
/*********************************************************************
*******
The function cars_rented is used to find the status of booked car,
that is,
the car is rented to whom and for how many days.
**********************************************************************
******/
void employee::cars_rented()
{
cleardevice();
boundary1();
check_temp_color();
setbkcolor(temp_color++);
ifstream temp_infile("customer.dat",ios::binary);
infile.open("employee.dat",ios::binary);
if(!infile || !temp_infile)
exit(0);
gotoxy(5,5);
cout<<setw(10)<<"Owner Name"<<setw(15)<<"Car Name"<<setw(15)<<"Car
Number"<<setw(12)<<"Rented to"<<setw(15)<<"No of Days"<<endl<<endl;
while(!infile.eof())
{
infile.read((char*)&e,sizeof(e));
if(infile.eof())
break;
if(strcmpi(e.status,"BOOKED!")==0)
while(!temp_infile.eof())
{
temp_infile.read((char*)&c,sizeof(c));
if(temp_infile.eof())
break;
if(strcmpi(e.car_no,c.car_no)==0)
cout<<setw(10)<<e.name<<setw(15)
<<e.car_name<<setw(15)<<e.car_no<<setw(12)<<c.name<<setw(15)
<<c.no_of_days<<endl;
}
}
infile.close();
temp_infile.close();
}
/*********************************************************************
*******
This function is to display GROUP MEMBERS NAME.
**********************************************************************
******/
void credits()
{
cleardevice();
setcolor(12);
settextstyle(4,0,6);
setbkcolor(0);
outtextxy(110,8,"THANKS....^-^");
setcolor(10);
settextstyle(1,0,2);
outtextxy(50,200,"Submitted To:-");
settextstyle(1,0,2);
outtextxy(50,250,"Father Jose");
settextstyle(1,0,2);
outtextxy(400,200,"Submitted By:-");
settextstyle(1,0,2);
outtextxy(400,250,"AMAN SHARMA");
outtextxy(400,284,"ANMOL SINGH");
outtextxy(400,320,"DHRUV JAIN");
outtextxy(300,300,"***");
for(int j=0;j<9;j++)
{
if(kbhit())
break;
for(int i=25;i<450;i=i+15)
{
setcolor(j);
arc(25,i,90,270,7);
arc(10,i,270,90,7);
setcolor(j+1);
arc(610,i,270,90,7);
arc(625,i,90,270,7);
}
for(i=25;i<620;i+=15)
{
setcolor(j);
arc(i,25,0,180,7);
arc(i,10,180,0,7);
setcolor(j+1);
arc(i,445,180,360,7);
arc(i,460,360,180,7);
}
delay(200);
if(j==8)
j=0;
}}
/*********************************************************************
******
This function is to provide the border to the page.
**********************************************************************
*****/
void boundary1()
{
check_temp_color();
setbkcolor(temp_color++);
for(int i=25;i<450;i=i+15)
{
arc(25,i,90,270,7);
arc(610,i,270,90,7);
arc(10,i,270,90,7);
arc(625,i,90,270,7);
}
for(i=25;i<620;i+=15)
{
arc(i,25,0,180,7);
arc(i,445,180,360,7);
arc(i,10,180,0,7);
arc(i,460,360,180,7);
}
}
/*********************************************************************
*******
This function is to check that variable temp_color should not exceed
13. The
variable is used to have different background colour on each page.
**********************************************************************
******/
void check_temp_color()
{
if(temp_color==13)
temp_color=0;
if(temp_color==7)
temp_color++;
}
/*********************************************************************
******
This function is used for displaying front page.
**********************************************************************
*****/
void front_page()
{
int i=0,j=0;
boundary1();
while(!kbhit())
{
if(kbhit())
break;
setcolor(i);
settextstyle(7,0,60);
outtextxy(45,45,"RENT");
settextstyle(7,0,8);
outtextxy(180,250,"CARS");
delay(250);
if(i==7)
{
setbkcolor(j++);
i=0;
}
if(j==8)
j=0;
i++;
}
getch();
}
void main()
{
int gdriver=DETECT,mode;
initgraph(&gdriver,&mode,"\\TurboC3\\bgi");
front_page();
XX:
cleardevice();
check_temp_color();
setbkcolor(temp_color++);
check_temp_color();
setcolor(temp_color++);
boundary1();
gotoxy(30,6);
settextstyle(1,0,6);
outtextxy(50,45," LIMO PVT. LMT.");
gotoxy(27,8);
cout<<"AFFILIATED TO CAR CLUB....";
gotoxy(17,10);
cout<<"ARE YOU A:";
gotoxy(28,11);
cout<<"1.............CAR TENANT";
gotoxy(28,13);
cout<<"2............CAR PROPRIETER";
gotoxy(28,15);
cout<<"3...........COMPANY EMPLOYEE";
gotoxy(28,17);
cout<<"4.........EXIT";
gotoxy(17,21);
cout<<"CHOOSE ANY ONE ALTER";
gotoxy(17,23);
cout<<"ENTER YOUR CHOICE:";
cin>>res;
switch(res)
{
case 1:
emp.rentyourcar();
break;
case 2:
emp.rent_a_car();
break;
case 3:
emp.company_employee();
break;
case 4:
credits();
exit(0);
}
getch();
goto XX;
}
