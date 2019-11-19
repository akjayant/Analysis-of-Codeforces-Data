#include<bits/stdc++.h>
using namespace std;

// code taken from https://www.geeksforgeeks.org/prlong long int-all-prime-factors-of-a-given-number/
void primeFactors(long long int n, unordered_set<long long int> &se)  
{  
    // Prlong long int the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        se.insert(2);  
        n = n/2;  
    }  
  
    // n must be odd at this polong long int. So we can skip  
    // one element (Note i = i +2)  
    for (long long int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, prlong long int i and divide n  
        while (n % i == 0)  
        {  
            se.insert(i);  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        se.insert(n); 

 //    for(auto x: se)
	// 	cout << x << " ";
	// cout << "\n"; 
}  

int main()
{
	long long int n, i, j, k;
	cin >> n;
	unordered_set<long long int> se;
	primeFactors(n, se);

	if(se.size() == 1)
		for(auto x: se)
			cout << x << "\n";

	else
		cout << "1\n";
}