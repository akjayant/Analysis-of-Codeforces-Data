#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

int main(){
	int t;
	cin >> t;
	for (int i=0;i<t;i++){
		int a,b;
		cin >> a >> b;
		int x = gcd(a,b);
		if (x == 1){
			cout << "Finite" << endl;
		}
		else {
			cout << "Infinite" << endl;
		}
	}
}