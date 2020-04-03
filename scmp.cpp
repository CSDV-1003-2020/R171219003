#include<iostream>
using namespace std;
struct node
{
	int data;
	Node *link;
};
int main()
{
	int current, maximum, choice;
	cout<<"Enter the maximum value of stack:";
	cin>>maximum;
	A: cout<<"\nEnter your choice\n1.Insertion\n2.Deletion\n3.Display top value\n4.Exit\n:";
	   cin>>choice;
	   switch(choice)
	   {
		   case'1': push(maximum, &current); goto A;
	   	   case'2': pop(&current); goto A;
		   case'3': cout<<top->data; goto A;
		   case'4': exit(0);
		   default: cout<<"\nEnter the choice for given above"; goto A;
	   }
	   return 0;
}
