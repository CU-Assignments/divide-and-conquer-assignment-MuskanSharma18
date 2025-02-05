class Solution {
public:
    vector<int> beautifulArray(int n) {
        return solve(n);
    }
    
    vector<int> solve(int n){
        if(n==1) {
            vector<int> k = {1};
            return k;
        }
        
        vector<int> ans = solve(n-1);
        vector<int> temp;
        for(int i = 0; i < ans.size(); i++){
            if(2*ans[i]-1 <= n) temp.push_back(2*ans[i]-1);
        }
        for(int i = 0; i < ans.size(); i++){
            if(2*ans[i] <= n) temp.push_back(2*ans[i]);
        }
        return temp;
    }
};
