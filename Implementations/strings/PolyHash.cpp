const int maxn = 2e5 + 250;
const int nMOD = 2;
const int mods[] = {(int)1e9 + 7, (int)1e9 + 3777, (int)1e9 + 10777, (int)1e9 + 19777};
// 'z' is 122 is ascii
const int BASE = 333;
int pw[nMOD][maxn + 1];
 
void precalc(){
    for(int j = 0; j < nMOD; j++){
        pw[j][0] = 1;
        for(int i = 1; i <= maxn; i++)
            pw[j][i] = (1ll * pw[j][i - 1] * BASE) % mods[j];
    }
}
  
struct PolyHash{
    vector<int> val[nMOD];
    int n;
  
    PolyHash() { n = 0; }
 
    PolyHash(const string &s){
        n = sz(s);
 
        for(int j = 0; j < nMOD; j++){
            val[j].pb(s[0]);
            for(int i = 0; i < n; i++)
                val[j].pb((1ll * val[j][i - 1] * BASE + s[i]) % mods[j]);
        }
    }
 
    int Query(int j, int l, int r){
        return (1ll * val[j][r] - (l - 1 >= 0 ? 1ll * val[j][l - 1] * pw[j][r - l + 1] : 0)
             + 1ll * mods[j] * mods[j]) % mods[j];
    }

    bool operator < (const PolyHash &x) const {
        for(int i = 0; i < nMOD; i++) 
            if(val[i] != x.val[i]) 
                return (val[i] < x.val[i]);
 
        return false;
    }
};
