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
// ll nfactors(ll n){for(ll i = 2; i <= n; i++){for(ll j = i; j <= n; j += i)fact[j]++;}}
ll modpar(ll a){return ((a%mod) + mod) % mod; }
ll modadd(ll a,ll b){ return modpar(modpar(a)+modpar(b)); }
ll modmul(ll a,ll b){ return modpar(modpar(a)*modpar(b)); }

void solve(int test){
   
     ll count  = 0;

     string s;
     
     
     cin>>s;
     ll n = s.size();
    s= '#' + s;
  
    fr(i,1,n-2){
        string temp = s.substr(i,4);
      
        if(temp == "1100") count++;
    }
    ll q;
    cin>>q;
    fr(i,0,q){
       ll ind;
       ll v;
       cin>>ind>>v;
       if(v == 0 and s[ind] == '1'){
        ll ind_r = ind - 3;
       
        
        if(ind_r >=1) {
            string tt = s.substr(ind_r,4);
         
            tt[3] = '0';
         
            if(tt == "1100") count++;
        }
        ind_r++;
        if(ind_r >= 1 and (n- ind_r +1 >= 4)){
            string tt = s.substr(ind_r,4);
            tt[2] = '0';
            if(tt == "1100") count++;
        }
        
        if(n - ind +1 >= 4){
            string temp = s.substr(ind,4);
            dbg(temp);
            if(temp == "1100") count--;
            
            
        }
        if(n - (ind-1) + 1 >= 4){
               string temp = s.substr(ind-1,4);
               dbg(temp);
               if(temp == "1100") count--;

        }  
       }
       else if(v == 1 and s[ind] == '0'){
        ll ind_r = ind-3;
        if(ind_r >=1) {
            string tt = s.substr(ind_r,4);
            dbg(tt);
            if(tt == "1100") count--;
        }
        ind_r++;
        if(ind_r >= 1 and (n - ind_r + 1 >= 4)){
            string tt = s.substr(ind_r,4);
            
            if(tt == "1100") count--;
        }
        
        if(n - ind +1 >= 4){
            string temp = s.substr(ind,4);
            temp[0] = '1';
            if(temp == "1100") count++;
            
            
        }
        if(n - (ind-1) + 1 >= 4){
               string temp = s.substr(ind-1,4);

               temp[1] = '1';
               if(temp == "1100") count++;

        }  

       }
       if(count>=1){
        cout<<"YES"<<nl;
       }
       else cout<<"NO"<<nl;
       s[ind] = (v == 0)?'0':'1';
    //    cout<<puts(((count>=1) ? ("YES"):("NO")))<<nl;

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