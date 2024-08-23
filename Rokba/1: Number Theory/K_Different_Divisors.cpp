#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 10000
#define MOD 3
#define ll long long
#define vll vector<ll> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

vector<int> divs;
map<int, int> div;

void make_divs(){

    vector<int> prime(MAX, 1);

    for(int i=2; i <= MAX; i++){
        if(prime[i])
            for(int j=i*i; j <= MAX; j+=i){
                prime[i] = 0;
            }
    }

    for(int i=2; i <= MAX; i++)
        if(prime[i]) divs.push_back(i);

    for(int d=0; d <= MAX; d++){
        for(int j=d+2; j <= MAX; j++){
        }
    }
}

int main() {
	
    Nkumbo
	
    int t;
    cin >> t;

    make_divs();

    while(t--){
        int d;
        cin >> d;

        cout << divs[d] << endl;
    }

	return 0;
}