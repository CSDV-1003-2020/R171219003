void pop(int *curr) 
{ 
if(*curr == 0) 
cout<<“\nStack is EMPTY\n ”; 
else 
{ 
Node *ptr = top; 
top = top -> link; 
delet(ptr); 
*curr--; 
} 
} 
