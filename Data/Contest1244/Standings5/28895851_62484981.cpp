#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define F first
#define S second
/*
//functions from gfg

long long int power(long long int x,long long int y,long long  int p)
{
    long long int res = 1;     // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            {//d=(long double)x/p;
            res = (res*x) % p;
            }
 
        // y must be even now
        y = y>>1; // y = y/2
        x=(x*x)%p;
        
    }
    return res%p;
}

long long int gcd(long long int a,long long int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

long long int binomialCoeff(long long int n,long long int k) 
{ 
    long long int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; //add percent mod if want nCk percent mod;
    } 
    return C[k]; 
} 


*/

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    
    ll n,m,i,j,k,l,ans=0,p,w,d,hi,lo,med,winsm,drm,p1,dif;
    cin>>n>>p>>w>>d;
    
    if(n*w<p)
    {
        cout<<-1<<endl;
    }
    else if(n*w==p)
    {
        cout<<n<<" "<<0<<" "<<0<<endl;
    }
    else if(p==0)
    {
        cout<<0<<" "<<0<<" "<<n<<endl;
    }
    else
    {
        winsm=p/w;
        p1=p-winsm*w;
        drm=p1/d;
        k=p1-drm*d;
        
        dif=w-d;
        dif%=d;
        
        if(k==0)
        {
            cout<<winsm<<" "<<drm<<" "<<n-drm-winsm<<endl;
        }
        else
        {
            ll d1=d;
            if(dif==0)
            {
                cout<<-1<<endl;
            }
            else
            {
                ans=1;
                while((d1-k)%dif>0)
                {
                    if((d1-k)/dif>winsm)
                    {
                        ans=0;
                        break;
                    }
                    d1+=d;
                }
                if(ans==0)
                cout<<-1<<endl;
                else
                {
                    ll ww=winsm-(d1-k)/dif;
                    ll dd=(p-ww*w)/d;
                    ll loss=n-ww-dd;
                    if(ww<0||loss<0)
                    cout<<-1<<endl;
                    else
                    {
                        cout<<ww<<" "<<dd<<" "<<loss<<endl;
                    }
                }
            }
        }
    }
	return 0;
}
