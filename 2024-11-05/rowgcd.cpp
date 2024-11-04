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


ll gcd(ll a, ll b){ if(b == 0){ return a;} return gcd(b, a%b);}

void solve(int test){
   
         ll n,m;
         cin>>n>>m;
         ll ans = 0;
         vecl v(n+1,0);
         fr(i,1,n+1){
            cin>>v[i];
            if(i != 1) ans = gcd(ans,v[i] - v[1]);
         }

        fr(i,1,m+1){
            ll temp ;
            cin>>temp;
            temp = gcd(ans,temp+v[1]);
            cout<<abs(temp)<<" ";
        }





 
}


int main(){

    #ifndef ONLINE_JUDGE
    fun();
    #endif
    solve(1);
    return 0;
   
}     