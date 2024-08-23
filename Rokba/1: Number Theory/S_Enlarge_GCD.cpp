#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 1.5e7+10
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

const int MOD = 1000000007;
vector<int> dv(MAX, 1);

void primos(){
    for(int i=2; i <= MAX; i++){
        if(dv[i] == 1)
            for(int j = i; j <= MAX; j += i){
                dv[j] = i;
            }
    }
}

vector<int> fact(int n){
    vector<int> res;
    while(n > 1){
        res.push_back(dv[n]);
        n /= dv[n];
    }
    return res;
}

int main() {

    Nkumbo
	
	int n;
    cin >> n;

    primos();

    vector<int> a(n);
    int gcd = 0;
    for(auto& i: a) {
        cin >> i;
        gcd = __gcd(gcd, i);
    }
    for(auto& i: a) i /= gcd;

    map<int, int> pc;
    for(auto& i: a){
        vi p = fact(i);

        if(!p.empty()) pc[p[0]]++; 
        for(int i=1; i < p.size(); i++){
            if(p[i] != p[i-1]){
                pc[p[i]]++;
            }
        }
    }

    int ans = n;
    for(auto i: pc){
        ans = min(ans, n - i.s);
    }

    cout << (ans == n ? -1 : ans) << endl;

    return 0;
}