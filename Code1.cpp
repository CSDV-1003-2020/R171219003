#include<iostream>
using namespace std;
int add()
{
	return (2+3);
}
int add(int a,int b)
{
	return (a+b);
}
float add(float a, float b)
{
	return (a+b);
}
void main()
{
	int x=4,y=5;
	float m=3.2,n=7.2;
	add();
	add(x,y);
	add(m,n);
}
