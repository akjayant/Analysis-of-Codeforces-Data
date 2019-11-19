    #include<bits/stdc++.h>
    
    using namespace std;
    #define ll long long int
    int main()
    {
        int t;
        cin >> t;
        while( t--)
        {
            ll c=0,c1= 0,c2 =0 ,c3 = 0;
            int n;
            cin >> n;
            int a[n];
            for(int i= 0; i  <n ; i ++)
            {
                cin >> a[i];
                if(a[i]%2==0)
                c ++;
                else
                c1++;
            }
            int m;
            cin >> m;
            int a1[m];
            for(int i= 0; i  <m ; i ++)
            {
                cin >> a1[i];
                if(a1[i]%2==0)
                c2 ++;
                else
                c3++;
            }
            ll ans = 0;
            ans += c*c2;
            ans += c1 * c3;
            cout << ans << endl;
        }
    }