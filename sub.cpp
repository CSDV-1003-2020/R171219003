#include <iostream>
using namespace std;
 
int main()
{
    int x, y, subtract;
    
    cout << "Enter two integers for subtract: ";
    cin >> x >> y;
    
    subtract = x - y;
    cout << x << " - " <<  y << " = " << subtract;     
 
    return 0;
}
