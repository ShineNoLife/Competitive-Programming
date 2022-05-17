#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using str = string;
using db = long double;
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;
 
using vi = vector<int>;
using vl = vector<ll>;
using vdb = vector<db>;
using vb = vector<bool>;
using vs = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdb = vector<pdb>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
//pairs
#define sz(x) (int)(x.size())
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front
 
const int MOD = 1e9+7;
//const int MOD = 998244353;
const ll INF = 1e18;
 
void solve(){
    ll total = 0, pos = 0;
    str s, temp = "";
    cin >> s;
    ll cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < s.size(); i++)
        cnt[s[i]-'A']++;
    for(int i = 0; i < 26; i++){
        if(cnt[i]%2 != 0){
            total++;
            pos = i;
            if(total > 1){
                cout << "NO SOLUTION" << '\n';
                return;
            }
        }
        for(int j = 0; j < cnt[i]/2; j++)
            temp+=(char)('A'+i);
    }
    str other = temp;
    reverse(other.begin(), other.end());
    if(total == 1)
        cout << temp+((char)('A'+pos))+other << '\n';
    else
        cout << temp+other << '\n';
}  
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}