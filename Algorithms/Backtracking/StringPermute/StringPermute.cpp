#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


/*
IDEA EXPLAINED:
Given a word w = c1c2c3c4c5 (we shall write it as w{1,5})
-   To find all permutations of a word w{1,5}, fix
    the character at the left most index of w{1,5}, this character can be any character after
    the leftmost index). 
-   Now, after fixing index 1, find all possible permutations of w{2,5}
    (how? just the way we did for w{1,5}).
    (i.e., fix the character at index 2, and find all possible permutations of w{3,5})
-   Keep doing this until we reach w{5,5}. When we reach there, print it out.

*/

void FindPermutations(string st, int l, int r)
{
    if(l==r)
    {
        cout << st << " ";
        return;
    }
    
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(st[l],st[i]);
            FindPermutations(st,l+1,r);
            swap(st[l],st[i]);		//backtracking
        }    
    }
    
}

int main() {

	    string st;
	    cin >> st;
	    int n = st.size();
	    FindPermutations(st,0,n-1);
	    cout << endl;
	    
	    return 0;
}
