#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define compareBySecond [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }
#define desc greater<int>()
#define all(x) x.begin(), x.end()
#define MAX 500
#define ll long long
#define vi vector<int> 
#define endl '\n'
#define f first 
#define s second

using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main() {

    Nkumbo

    int t;
    cin >> t;

    map<int, string> mp = {{1, "Ashishgup"}, {2, "FastestFinger"}};

    while(t--){
        int n;
        cin >> n;

        bool r = (n == 1);

        if(n > 2 && n % 2 == 0){
            if((n & (n-1)) == 0) r = true;
            else if (n % 4 != 0 && isPrime(n/2)) r = true; 
        }
        cout << (r ? mp[2] : mp[1]) << endl;
    }

    return 0;
}