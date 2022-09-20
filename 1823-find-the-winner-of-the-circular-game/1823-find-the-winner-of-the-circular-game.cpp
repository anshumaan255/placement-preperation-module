class Solution {
public:
    int findTheWinner(int n, int k) {
   
        k--;
        int index = 0 ; 
        int ans =-1;
             vector <int> v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
    
        solve(v,k,index,ans);
        return ans;
    }
    void solve(vector<int> v,int k,int index,int& ans)
    {
        if(v.size() == 1){
        ans = v[0];
            return;
        }
        index = ((index+k)%v.size());
        v.erase(v.begin()+index);
        
        solve(v,k,index,ans);
        return;
        
        
        
    }
};