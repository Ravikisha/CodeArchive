class Solution {
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            vector<int> v  = vector<int>(i, 1);
            if(i > 2){
                for(int j = 1; j <= v.size()-2; j++){
                    v[j] = ans[ans.size()-1][j-1] + ans[ans.size()-1][j];
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

/*
Explaination:
1. Create a 2D vector ans.
2. Loop from 1 to numRows.
3. Create a vector v of size i and initialize all elements to 1.
4. If i > 2, loop from 1 to v.size()-2 and set v[j] = ans[ans.size()-1][j-1] + ans[ans.size()-1][j].
5. Push v to ans.
6. Return ans.
*/