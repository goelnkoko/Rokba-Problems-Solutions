#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long


using namespace std;

int dist(int a1, int a2, int b1, int b2){
    
    return (a1-b1)*(a1-b1) + (a2-b2)*(a2-b2);
}

int main() {

    Nkumbo
  
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    int d1 = dist(a1, a2, b1, b2);
    int d2 = dist(a1, a2, c1, c2);
    int d3 = dist(c1, c2, b1, b2);

    int h = max(d1, max(d2, d3));
    int co = min(d1, min(d2, d3));

    int ca = d1 + d2 + d3 - h - co;
    
    bool ans = false;

    if(h == ca + co) ans = true;
    if(d1 == d2 && d1 == d3) ans = false;
    
    cout << (ans? "Yes":"No") << endl;

    return 0;
}