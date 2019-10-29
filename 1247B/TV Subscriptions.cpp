// Author :Smit Mangukiya
// Link : https://codeforces.com/contest/1247/problem/B1  
// Link1 : https://codeforces.com/contest/1247/problem/B2

#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb emplace_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define F first
#define S second
#define fast ios:: sync_with_stdio(false),cin.tie(0);
 
void solve()
{
	int n,k,d;
	cin >> n >> k >> d;
 
	int a[n+5];
 
	for(int i=1 ; i<=n ; i++)
	cin >> a[i];
 
	int ans = INT_MAX;
 
	map<int,int>f;
 
	for(int i=1 ; i<=d ; i++)
	{
		f[a[i]]++;
	}
 
	ans = min(ans,(int)f.size());
 
	for(int j=d+1 ; j<=n ; j++)
	{
 
 
		f[a[j]]++;
		f[a[j-d]]--;
 
		auto it = f.find(a[j-d]);
		
		if(it->S==0)   f.erase(it);
 
		ans = min(ans,(int)f.size());
 
	}
	cout << ans << "\n";
}
int32_t main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
}
 
 
 
