// Author : Smit Mangukiya
// Problem Link :  https://codeforces.com/contest/1247/problem/C

#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define fast ios:: sync_with_stdio(false),cin.tie(0);
 
int32_t main(){
	fast;
	int n,p;
	cin >> n >> p;
 
	int  ans = -1;
	for(int mid = 1 ; mid <= 31 ; mid++)
	{
		
		int x = n - mid*p;
		if(x >= 0)
		{
			int y = __builtin_popcount(x);
			if(mid >= y && mid <= x)
			{
				cout << mid ; return 0;
			}
		}
		
	}
 
	cout << ans;
}
