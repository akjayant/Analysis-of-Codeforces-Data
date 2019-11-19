    #include<bits/stdc++.h>
    
    using namespace std;
    #define ll long long int
    int main()
    {
        int n;
        cin >> n;
        ll a[n];
        for(int i =0 ;i < n ; i ++)
        cin >>a[i];
        sort(a , a + n);
        ll a1 = 0;
        ll a2 = 0;
        for(int i =  0 ; i <  n ; i ++)
        {
            if( i < n/2)
            a1 += a[i];
            else
            a2 += a[i];
        }
        cout << a1 * a1 + a2 *a2 << endl;
    }