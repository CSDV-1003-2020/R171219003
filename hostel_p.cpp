#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

fstream fout;
fstream fin;


class hostel
{

	public:
	 int rtype;
	 hostel()
	 {
	 rtype=0;

	 }
	int feescal(int r)
	{
	 switch(r)
	 {
	 case 1:
	 cout<<"1900000";
	 break;
	 case 2:
	 cout<<"1705000";
	 break;
	 case 3:
	 cout<<"1600000";
	 break;
	 default:
	 cout<<"\n INVLAID CHOICE";
	 break;
	 }
	 return 0;
	}


}ho1;

class user:private hostel
{
	char name[50];
	double std;
	char address[100];
	public:
	void details()
	{

	 cout<<"\n\tENTER THE DETAILS OF THE STUDENT ";

	 cout<<"\n ENTER THE NAME[USE CAPITAL LETTERS] - ";
	 gets(name);

	 cout<<"\n ENTER THE ADDRESS - ";
	 gets(address);

	 cout<<"\n ENTER THE CLASS - ";
	 cin>>std;

	 cout<<"\n ENTER 1 FOR SINGLE BED-ROOM\n "<<"ENTER 2 FOR DOUBLE BED-ROOM\n"<<"ENTER 3 FOR TRIPLE BED-ROOM\n";
	 cin>>rtype;
	 cout<<"\n " ;


	}
	void toshow()
	{

	 cout<<"\nNAME:"<<name<<"\nCLASS:"<<std<<"\nADDRESS:"<<address<<"\nROOM TYPE:"<<rtype<<"\nHOSTEL FEES:";
	 cout<<feescal(rtype);
	}

	char* getname()
	{return name;}
	void tomodify();

}stu;

int tosearch(int &f)
{
	char na[50];
	cout<<"ENTER THE NAME OF THE STUDENT - ";
	gets(na);

	fin.seekg(0);
	while(fout.read((char*)&stu,sizeof(stu)))
	{
		if(strcmp(stu.getname(),na)==0)
		{f=1;break;}

	} return f;
};

	void todelet()
	{  fin.open("hostel.dat",ios::in|ios::binary);
		ofstream file("temp.dat",ios::out|ios::binary);
		cout<<"\nDELETION:\n";

		int t=0;
		char yn='N';
		char na[50];
		cout<<"ENTER THE NAME OF THE STUDENT - ";
		gets(na);

		fin.seekg(0);
		while(fin.read((char*)&stu,sizeof(stu)))
	  {
		if(strcmp(stu.getname(),na)==0)
		{t=1;
		 stu.toshow();
		 cout<<"\nARE YOU SURE YOU WANT TO DELET THIS DATA(Y/N):";
		 cin>>yn;
		 if(yn=='N')
		 file.write((char*)&stu,sizeof(stu));
		}
		else
		 file.write((char*)&stu,sizeof(stu));
	  }
	 if(t==0)
	 cout<<"RECORD NOT FOUND";
	 fin.close();
	 file.close();
	 remove("hostel.dat");
	 rename("temp.dat","hostel.dat");
	 if(yn=='Y')
	 cout<<"FILE DELETED SUCCESCFULLY";
	}
void user::tomodify()
{cout<<"\nMODIFICATION: ";
 int g=0,clas;
 char naam[50],add[100];
 tosearch(g);
  fin.seekg(-1*sizeof(stu),ios::cur);
 if(g!=0)
 {
  stu.toshow();
  cout<<"\nENTER THE NEW DETAILS BELOW:[press 1 to copy old data]\n"<<"NAME:";
  gets(naam);
  cout<<"\nCLASS:";cin>>clas;
  cout<<"ADDRESS:";gets(add);
  if(strcmp(naam,"1")!=0)
  strcpy(stu.name,naam);
  if(clas!=1)
  stu.std=clas;
  cout<<endl;
  if(strcmp(add,"1")!=0)
  strcpy(stu.address,add);
  fout.seekg(fout.tellg()-sizeof(stu));
  fout.write((char*)&stu,sizeof(stu));
  stu.toshow();
 }


 if(g==0)
	 cout<<"RECORD NOT FOUND";
}


void main()
 {int ch;
  int a=0;
  cout<<"\t\tHOSTEL MANAGEMENT \n";
  cout<<"\nPLEASE USE CAPITAL LETTERS\n";
  char co='Y';
  for(;co=='Y';)
  {
	cout<<"\n1.NEW ADMISSION"<<"\n2.SEARCH A STUDENT"<<"\n3.WITHDRAWING A STUDENT\n"<<"4.MODIFY STUDENT DETAILS\n";
	cin>>ch;
	switch(ch)
	{case 1:fout.open("hostel.dat",ios::app|ios::in|ios::binary);
			 stu.details();
			 fout.write((char*)&stu,sizeof(stu));
			 stu.toshow() ;fout.close();break;
	 case 2:fout.open("hostel.dat",ios::app|ios::in|ios::binary);
			 cout<<"\n\nSEARCHING:\n";
			 tosearch(a);
			 if(a!=0)
			 {cout<<"FOUND"<<"\nWANT TO SHOW THE DETAILS? (Y/N):";
			  char yn;
			  cin>>yn;
			  if(yn=='Y')
			  { stu.toshow();
				break;
			  }
			 }
			 if(a==0)
			 cout<<"NOT FOUND";
			 fout.close();break;
	 case 3:todelet();break;
	 case 4:fout.open("hostel.dat",ios::app|ios::in|ios::binary);
			  stu.tomodify();
			 fout.close();break; }
	cout<<"\n\nDO YOU WISH TO CONTINUE?(Y/N):";
	cin>>co;
  }
 }

