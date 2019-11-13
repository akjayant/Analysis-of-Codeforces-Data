//
//  main.cpp
//  Contests
//
//  Created by Giga Khizanishvili on 6/11/19.
//  Copyright © 2019 Giga Khizanishvili. All rights reserved.
//


// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* Defines */
#define scanVector(v) for(int i = 0; i < v.size() ; i++){ cin>>v[i]; }
#define printVector(v) for(int i = 0; i < (int)v.size() ; i++){ cout<<v[i]<<" "; }
#define printlnVector(v) for(int i = 0; i < v.size(); i++){ cout<<v[i]<<endl; }
#define scanGrid(g) for(int i = 0; i < g.size(); i++){ for(int j = 0; j < g[i].size(); j++){ cin >> g[i][j]; } }
#define printGrid(g) for(int i=0; i<g.size(); i++){for(int j=0; j<g[i].size(); j++)cout<<g[i][j]<<" "; cout<<endl;}

/* Constants */
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;
const double PI = 3.141592653589793238462643383;

/* __________________________________________________________________________________ */

int main()
{   ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    
    int nTests; cin >> nTests;
    while(nTests--){
        //cout << "test: " << nTests << endl;
        int n; cin >> n;
        vector<int> v(n);
        scanVector(v);
        sort(v.begin(), v.end());
        
        for(int i = 0; i < n; i++){
            if(v[i] >= n-i){
                cout << n-i << endl;
                break;
            } else {
                //cout << "v[i]: " << v[i] << endl;
            }
        }
    }
    //cout << "bla  " << endl;
    return 0;
}
