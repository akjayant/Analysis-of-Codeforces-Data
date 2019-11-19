#include <bits/stdc++.h>
#define ll long long
#define pet pair<ll,ll>
#define one first
#define two second
using namespace std;

ll gcd(ll a,ll b)
{
    if(b==0)
    return a;

    return gcd(b,a%b);
}

void solvetest()
{
	ll n;
    cin >> n;

    ll arr1[3][n];

    for(ll i=0;i<3;i++)
    {
        for(ll j=0;j<n;j++)
        cin >> arr1[i][j];
    }

    vector<ll> arr[n];

    ll a,b;
    for(ll i=1;i<n;i++)
    {
        cin >> a >> b;
        a--;
        b--;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(ll i=0;i<n;i++)
    {
        if(arr[i].size()>2)
        {
            cout << -1 << endl;
            return;
        }

        if(arr[i].size()==1)
        a=i;
    }

    ll num[n]={0};
    ll check=1;

	vector<ll> yo;
    for(ll i=0;i<n;i++)
    {
    	//cout << a << endl;
        yo.push_back(a);
        num[a]=1;
        if(num[arr[a][0]]==0)
        	a=arr[a][0];

        else if(arr[a].size()>1)
        {
            a=arr[a][1];
        }
        //check=check%3+1;
    }

	for(ll i=0;i<n;i++)
	{
		if(i%3==0)
		num[yo[i]]=1;
		
		else if(i%3==2)
		num[yo[i]]=2;
		
		else
		num[yo[i]]=3;
	}
	
    ll costa=0,costb=0,costc=0;
	ll ca=0,cb=0,cc=0;
	
    for(ll i=0;i<n;i++)
    {
        ca+=arr1[i%3][yo[i]];
    }
    
    for(ll i=0;i<n;i++)
    {
    	costa+=arr1[num[i]-1][i];
    }
    
    for(ll i=0;i<n;i++)
    {
        costb+=arr1[(num[i])%3][i];
    }
    
    for(ll i=0;i<n;i++)
    {
        cb+=arr1[(i+1)%3][yo[i]];
    }

    for(ll i=0;i<n;i++)
    costc+=arr1[(num[i]+1)%3][i];
    
    for(ll i=0;i<n;i++)
    {
        cc+=arr1[(i+2)%3][yo[i]];
    }

	vector<ll> ans1;
	ll finans;
	vector<ll> ans2(n);
	ll finans2;
	
	
	//cout << costa << ' ' << costb << ' ' << costc << endl;
    if(costa<costb && costa<costc)
    {
    	finans=costa;
        for(ll i=0;i<n;i++)
        ans1.push_back(num[i]);
    }

    else if(costb<costc && costb<costa)
    {
    	finans=costb;
        for(ll i=0;i<n;i++)
        ans1.push_back(num[i]%3+1);
    }

    else
    {
    	finans=costc;
        for(ll i=0;i<n;i++)
        ans1.push_back((num[i]+1)%3+1);
    }
    
    //cout << ca << ' ' << cb << ' ' << cc << endl;
    if(ca<cb && ca<cc)
    {
    	finans2=ca;
    	for(ll i=0;i<n;i++)
    	ans2[yo[i]]=i%3+1;
    }
    
    else if(cb<ca && cb<cc)
    {
    	finans2=cb;
    	for(ll i=0;i<n;i++)
    	ans2[yo[i]]=(i+1)%3+1;
    }
    
    else
    {
    	finans2=cc;
    	for(ll i=0;i<n;i++)
    	ans2[yo[i]]=(i+2)%3+1;
    }
    
    //cout << finans << ' ' << finans2 << endl;
    if(finans<finans2)
    {
    	cout << finans << endl;
    	for(ll i=0;i<n;i++)
    	cout << ans1[i] << ' ';
    }
    
    else
    {
    	cout << finans2 << endl;
    	for(ll i=0;i<n;i++)
    	cout << ans2[i] << ' ';
    }
    
}

int main()
{
	ll t=1;
	//cin >> t;
	
	while(t--)
	{
		solvetest();
	}
}