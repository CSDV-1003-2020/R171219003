#include<iostream>
using namespace std;
void main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10]={0};
	for(int k=0;k<10;k++)    //to show array a
	{
		cout<<a[k]<<endl;
	}	
	for(int i=0;i<10;1++)    //to reverse the a to b
	{
		b[10-i]=a[i];
	}
	for(int j=0;j<10;j++)    //to show array b
	{
		cout<<"\n"<<b[j];
	}	
}	
