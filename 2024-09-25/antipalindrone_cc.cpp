#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")

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

using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;

typedef vector<int> vec;
typedef vector<long long> vecl;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const double pi = 3.1415926535;

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*________________________________________________*/

vecl sieve(ll n){vector<bool> prime(n+1, true); for (ll p = 2; p * p <= n; p++) if (prime[p] == true) for (ll i = p * p; i <= n; i += p) prime[i] = false; vecl v;
for (ll p = 2; p <= n; p++){if (prime[p]) v.pb(p);} return v;}
ll gcd(ll a, ll b){ if(b == 0){ return a;} return gcd(b, a%b);}
ll nCr(int n, int r){ll p = 1, k = 1;if (n - r < r) {r = n - r;} if (r != 0) {while (r) {p *= n;k *= r; ll m = gcd(p, k);p /= m;k /= m;n--;r--;}}else {p = 1;} return p;}
void google(int t){cout << "Case #" << t << ":" << " ";}
void precision(int x){cout << fixed << setprecision(x);}
ll fastexpo(ll x, ll y){ll res = 1; while (y) {if (y % 2 == 1)res = (res * x);y = y >> 1ll;x = (x * x);}return res;}
ll fastexpomod(ll x, ll y, ll p) { ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0) { if (y & 1ll) res = (res*x) % p; y = y>>1ll;x = (x*x) % p; } return res; } 
// ll nfactors(ll n){for(ll i = 2; i <= n; i++){for(ll j = i; j <= n; j += i)fact[j]++;}}
/*________________________________________________*/

void solve(int test){
     ll n,q;
     cin>>n>>q;
     vecl v(n);
    vector<array<ll,3>> c(n+2,{0,0,0});
     fr(i,0,n){
         cin>>v[i];
         c[i+1][0] = c[i][0] + (v[i] == 1);
         c[i+1][1] = c[i][1] + (v[i] == 2);
         c[i+1][2] = c[i][2] + (v[i] == 3);
         
          
     }
     fr(i,0,q){
        ll l,r;
        cin>>l>>r;
        ll m = r - l + 1;
        if((m&1)){
            cout<<"NO"<<nl;
            continue;
        }
        ll val = m/2;
        ll one  = c[r][0] - c[l-1][0];
        ll two  = c[r][1] - c[l-1][1];
        ll three =c[r][2] - c[l-1][2];
        if(one >val or two > val or three > val){
            cout<<"NO"<<nl;

        }  
        else{
            cout<<"YES"<<nl;
            
        }
     }
    
 
}


int main(){


    precision(10); 
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("errorf.txt", "w", stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto start = high_resolution_clock::now();
    int t = 1;

    cin >> t;

    int x = t;
    while(t--){
        solve(x - t);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
      
      #ifndef ONLINE_JUDGE
        cout <<nl << "Time: "
         << (float)duration.count()/1000000 << " s" << endl;
        #endif
}     