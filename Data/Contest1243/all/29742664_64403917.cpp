/*
    ##############################
    ## Author: Abhinav Batta #####
    ## College: IIIT-Allahabad ###
    ##############################
 
*/  
#include <bits/stdc++.h>
using namespace std;
#define int long long
void cpp()
{
     int a;
     cin>>a; 
     int p1[1000];
        int v1[1000];
        int c=0;
        for(int i=2;i*i<=a;i++)
        {
            if(a%i==0)
            {
                int cp=0;
                while(a%i==0)
                {
                    a/=i;
                    cp++;
                }
                p1[c]=i;
                v1[c]=cp;
                c++;
            }
        }
        if(a!=1)
        {
            p1[c]=a;
            v1[c]=1;
            c++;
        }
        if(c==1)
        {
          cout<<p1[0];
        }
        else
        {
           cout<<"1";
        }
     
}

void solve()
{
  int n;
  cin>>n;
 
}
int32_t main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     t=1;
     while(t--)
     cpp();    
     return 0;
}