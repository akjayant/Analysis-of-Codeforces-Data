          #include <bits/stdc++.h>
          using namespace std;
          #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
          #define M_PI 3.14159265358979323846
          #define data data_
          #define ff first
          #define ss second

          int main()
          {
          clock_t begin = clock();
          #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
          #endif
          tani_nachi_ke  

         int n;
         cin >> n;
         long long sum = 0;
        long long a[n];
        for(int i = 0 ;i < n; i++)
          cin >> a[i];
          sort(a,a+n);
          long long aa = 0,bb=0;
          for(int i = 0; i < n/2; i++)
              aa += a[i];
          for(int i = n/2; i < n; i++)
               bb += a[i];
          cout << aa*aa + bb*bb << endl;


          #ifndef ONLINE_JUDGE 
          clock_t end = clock();
          cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
          #endif 
          return 0;
          }