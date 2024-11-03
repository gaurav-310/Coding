#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define dbg(...) 42
#else
#include "debug.h"
#endif

#define mem(a, b)      memset(a, b, sizeof(a))
#define nl             '\n'
#define mod            1000000007
#define MOD            998244353
#define mod2           100000000
#define pb             push_back
#define mp             make_pair
#define INF            4e18
#define ff             first
#define ss             second
#define tt             third
#define ppb            pop_back
#define sz(x)          ((int)(x).size())
#define pcnt(x)        __builtin_popcount(x)
#define all(x)         (x).begin(), (x).end()
#define sum(A)         accumulate(A.begin(), A.end(), 0)
#define fr(i, s, e)    for(int i = s; i < e; i++)
#define fore(e, v) for(auto &&e : v)


typedef vector<int> vec;
typedef vector<long long> vecl;
typedef long long ll;

// 1 - > D  allowed for anyone = left , down 





string traverse(vector<vector<char>> &a,ll i,ll j,ll n,ll m){
    string temp = "";
    
    // horizontal
    ll count = 0;
    cerr<<i<<" "<<j<<nl;
    while(count < m){
        temp += a[i][j];
        j++;
        count++;
    }
    j--;
    temp.pop_back();
    ll count1 = 0;
    while(count1 < n){
      
        temp += a[i][j];
        i++;
        count1++;
    }
    i--;
    temp.pop_back();

    count = 0;
    while(count < m){
        temp+= a[i][j];
        j--;
        count++;
    }
    temp.pop_back();
    j++;
    count1 = 0;
    while(count1 < n){
         temp += a[i][j];
        i--;
        count1++;
    }
    temp.pop_back();
    temp+= temp[0];
    temp+= temp[1];
    temp+= temp[2];
    return temp;
}
ll check(string &s){
    ll count = 0;
    dbg(s);
    fr(i,0,s.size() -3){
        string temp = s.substr(i,4);
        if(temp == "1543") count++;
    }
    return count;
}
void solve(int test){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<pair<ll,ll>> one;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    dbg(a);
    ll i = 0;
    ll j = 0;
    ll count = (min(n,m))/2;
    ll ans = 0;
    while(count--){
        string temp = traverse(a,i,j,n,m);
        n-=2;
        m-=2;
        i+=1;
        j+=1;
        ans += check(temp);
        
    }
    cout<<ans<<nl;


}


int main(){

     #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("errorff.txt", "w", stderr);
    #endif

    int t = 1;
    cin >> t;
    int x = t;
    while(t--){ solve(x - t);}
    return 0;
   
}     