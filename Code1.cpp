#include<iostream>
using namespace std;
int add()
{
	return (2+3);
}
}
float add(float a, float b)
{
	return (a+b);
}                                     //This is for addition
void main()
{
	int x=10,y=20;
	float m=10.2,n=20.2;
	float m=3.2,n=7.2;
	add();
	add(m,n);
	x=4,y=5;
	m=3.2,n=7.2;
	sub();
	sub(x,y);
	sub(m,n);
}                                     //This is main function

//From here changes are from Aditya RAJ

int sub()
{
	return (2-3);
}
int sub(int a,int b)
{
	return (a-b);
}
float add(float a, float b)
{
	return (a-b);
}                                     //This is for substraction


