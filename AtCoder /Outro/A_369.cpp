#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(){

    Nkumbo

    int a, b;
    cin >> a >> b;
    int c = 3; 

    if(a == b) c = 1;
    else if((a % 2 == 1 && b % 2 == 1) || (a % 2 == 0 && b % 2 == 0)) c = 3;
    else c = 2;

    cout << c << endl;
}