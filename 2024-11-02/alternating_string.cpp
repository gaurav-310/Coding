#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fore(e, v) for(auto &&e : v)

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
ll modpar(ll a){return ((a%mod) + mod) % mod; }
ll modadd(ll a,ll b){ return modpar(modpar(a)+modpar(b)); }
ll modmul(ll a,ll b){ return modpar(modpar(a)*modpar(b)); }


void add_value(map<ll,vecl> &m, char c, ll ind){
    ll Index = c - 'a';
    
    if (ind == 0) m[ind] = vecl(26, 0); 
    else if(ind == 1) m[ind] = vecl(26,0);
    else m[ind] = m[ind - 2];
    
    m[ind][Index]++;  
}
void add_v(map<ll,vecl> &m,char c,ll ind,ll n){
    ll index = c - 'a';
    
    if(ind == n-1) m[n-1] = vecl(26,0);
    else if(ind == n-2) m[n-2] = vecl(26,0);
    else m[ind] = m[ind+2];

    m[ind][index]++;
}

ll fun(vecl &a,vecl &b,vecl &c,vecl &d,ll n){
        vecl x,y;
        fr(i,0,26){
            x.pb(a[i] + b[i]);
            y.pb(c[i] + d[i]);
        }
        ll max_odd_value = 0;
        ll max_even_value = 0;
        fr(i,0,26){
            max_odd_value = max(max_odd_value,x[i]);
            max_even_value = max(max_even_value,y[i]);
        } 
        ll ans =  (n/2 - max_even_value) + (n/2 - max_odd_value);
        return ans;

}
void printt(map<ll,vecl> &m){
    for(auto it:m){
        cerr<<it.first<<nl;
        int count = 0;
        for(auto itt:it.second){
            if(itt != 0){
                char ch = count + 'a';
                cerr<<ch<<" "<<itt<<"   ";

            }
            count++;
        }
        cerr<<nl;
    }
}
void solve(int test){
    ll n;
    cin>>n;
    string s;
    cin >> s;
    int ans = 0;
    if(n == 1){ cout<<1<<endl; return;}
    if(n == 2){ cout<<0<<endl; return;}

    map<ll, vecl> m,mm;
    m[-2] = vecl(26,0);
    m[-1] = vecl(26,0);
    m[n+1] = vecl(26,0);
    m[n]  = vecl(26,0);
    mm[-2] = vecl(26,0);
    mm[-1] = vecl(26,0);
    mm[n+1] = vecl(26,0);
    mm[n]  = vecl(26,0);

    
    
    for(int i = 0; i < n; i++) add_value(m,s[i],i);
    for(int i = n-1;i>=0;i--) add_v(mm,s[i],i,n);


    if(n&1){
        ll ans = INT_MAX;
         fr(i,0,n){
               
               if(i&1)  ans = min(fun(m[i-2],mm[i+1],mm[i+2],m[i-1],n),ans);                       
               else ans = min(ans,fun(m[i-1],mm[i+2],m[i-2],mm[i+1],n));

         }
         cout<<ans+1<<nl;
         return;

    }
    else{   
            vecl v1(26,0),v2(26,0);
            ll ans = fun(m[n-1],v1,v2,m[n-2],n);
            cout<<ans<<endl;
            return;
            

    }
    



    

    dbg(m);  
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
        cout << nl << "Time: " << (float)duration.count()/1000000 << " s" << endl;
    #endif
}
