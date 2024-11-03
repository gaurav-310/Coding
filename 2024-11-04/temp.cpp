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




bool inc_dec(string &s,ll ind,ll c,char v){

    string temp  = s.substr(ind,4);
    (c!= -1)?(temp[c] = v):(c = 0);
    if(temp == "1100") return true;
    return false;
}
void solve(int test){
   
     ll count  = 0;
     string s;
     cin>>s;
     ll n = s.size();
     s= '#' + s;
  
    fr(i,1,n-2) if(inc_dec(s,i,-1,'0')) count++;

    ll q;
    cin>>q;

    fr(i,0,q)
    {
       ll ind;
       ll v;
       cin>>ind>>v;
       if(v == 0 and s[ind] == '1')
       {
        
        ll ind_r = ind - 3;
       
        
        if(ind_r >=1) if(inc_dec(s,ind_r,3,'0')) count++;
        ind_r++;
        if(ind_r >= 1 and (n- ind_r >= 4)) if(inc_dec(s,ind_r,2,'0')) count++;
        if(n - ind +1 >= 4) if(inc_dec(s,ind,-1,'0')) count--;
        if(n - (ind-1) + 1 >= 4) if(inc_dec(s,ind-1,-1,'0')) count--;
              

        
       }
       else if(v == 1 and s[ind] == '0')
       {
        
        ll ind_r = ind-3;


        if(ind_r >=1) if(inc_dec(s,ind_r,-1,'1')) count--;
        ind_r++;
        if(ind_r >= 1 and (n - ind_r + 1 >= 4)) if(inc_dec(s,ind_r,-1,'1')) count--;
        if(n - ind +1 >= 4) if(inc_dec(s,ind,0,'1')) count++;
        if(n - (ind-1) + 1 >= 4) if(inc_dec(s,ind-1,1,'1')) count++;

        

       }

       puts(count >= 1?"YES":"NO");
       s[ind] = (v == 0)?'0':'1';


    }


 
}


int main(){

    #ifndef ONLINE_JUDGE
    fun();
    #endif

    int t = 1;
    cin >> t;
    int x = t;
    while(t--){ solve(x - t);}
    return 0;
   
}     