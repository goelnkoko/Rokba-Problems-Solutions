#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1.5e7 + 1;

vi d(MAX, 1);

void crivo(){
    for(int i=2; i <= MAX; i++)
        if(d[i] == 1)
            for(int j=i; j <= MAX; j += i)
                d[j] = i;
}

vi fact(int n){
    vi res;
    while(n > 1){
        res.push_back(d[n]);
        n /= d[n];
    }
    return res;
}

int main(){

    Nkumbo
    crivo();

    int n;
    cin >> n; 

    int tb[n];
    for(int& i: tb) cin >> i;

    int x = 0;
    for(int i=0; i < n; i++)
        x = gcd(x, tb[i]);

    for(int i=0; i < n; i++)
        tb[i] /= x;

    map<int, int> mp;
    for(int i=0; i < n; i++){
        vi dv = fact(tb[i]);
        
        if(!dv.empty()) mp[dv[0]]++;
        for(int j=1; j < dv.size(); j++) 
            if(dv[j] != dv[j-1])
                mp[dv[j]]++;    
    }

    int ans = MAX;
    for(auto& [x, c]: mp){
        ans = min(ans, n - c );
    }

    cout << (ans == MAX ? -1 : ans) << endl;
}