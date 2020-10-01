#include<bits/stdc++.h>
 
using namespace std;
 
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000
#define ll long long
#define int ll
#define db double
#define str string
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Forrev(i,s,e) for (ll i=(s); i>=(e); i--)
#define all(v) v.begin(),v.end()
 
#define vll vector<ll>
#define vs vector<string>
#define mapll map<ll,ll>
#define pll pair<ll,ll>
#define initialise(a, x) memset(a, x, sizeof(a))
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll,vector<ll> ,greater<ll>>
 
#define ff first
#define ss second
#define endl "\n"
#define mp make_pair
const ll mod=1e9 + 7;
 
ll takemod(ll a) {
    return ((a%mod)+mod)%mod;
}
 
ll gcd(ll a, ll b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);        
}
 
ll fast_exp(ll base, ll expo) {
    ll res=1;
    while(expo>0) {
        if(expo&1) res=(res*base)%mod;
        base=(base*base)%mod;
        expo>>=1;}
    return res;
}
 
ll modinv(ll a) {
    return takemod(fast_exp(takemod(a), mod-2));
}

const int N = 1e5+1;
int arr[3*N];
int n;

int ansvalues[35][2];

void dpfunc(int bit, vector<int> value)
{
    if (bit < 0 or value.size() == 0)
        return;

    int size1 = value.size();

    vector<int> v1, v2;

    int temp[size1] = {0};

    for (int i = 0; i < size1; i++)
    {
        if (((1LL<<bit)&value[i]))
        {
            temp[i] = 1;
            v1.push_back(value[i]);
        }
        else
        {
            temp[i] = 0;
            v2.push_back(value[i]);
        }
    }
    int sumx1 = 0, sumx2 = 0;

    int cnt1 = 0, cnt2 = 0;

    for (int i = size1-1; i >= 0; i--)
    {
        if (temp[i] == 0)
            cnt1++;
        else
            sumx1 += cnt1;

        if (temp[i] == 1)
            cnt2++;
        else
            sumx2 += cnt2;
    }

    ansvalues[bit][0] += sumx1;
    ansvalues[bit][1] += sumx2;


    dpfunc(bit-1, v1);
    dpfunc(bit-1, v2);
}
 
void solve() 
{
    cin >> n;

    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v1.push_back(arr[i]);
    }
    memset(ansvalues, 0, sizeof(ansvalues));
    dpfunc(30,v1);
    
    int x = 0, ans2 = 0;

    for (int i = 0; i < 30; i++)
    {
        if (ansvalues[i][0] <= ansvalues[i][1])
        {
            ans2 += ansvalues[i][0];
        }
        else
        {
            x += (1LL<<i);
            ans2 += ansvalues[i][1];
        }
    }
    cout << ans2 << " " << x << endl;
}
 
signed main() 
{
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("C:/IO/in.txt", "r", stdin);
    freopen("C:/IO/out.txt", "w", stdout);
    #endif
    
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    
    
    return 0;    
}
