#include<bits/stdc++.h>
using namespace std;

int solve(int triangles, int cards) {      //Recursive solution to Number of Ways to Build House of Cards (LC - 2189)

    if(cards == 0)
        return 1;
    
    if(cards < 0 || triangles <= 0)
        return 0;
    
    int ans = 0;

    for(int i = 1; i <= triangles; i++) {

        int used = (i * 2) + (i - 1);

        if(used > cards)
            break;
        
        ans += solve((i - 1), (cards - used));
    }

    return ans;
}

int main() {

    int n = 16;

    int triangles = max(1.0, ceil(n / 3.0));

    int ans = solve(triangles, n);

    cout<<ans<<endl;

    return 0;
}
