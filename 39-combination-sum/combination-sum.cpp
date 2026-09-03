class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int>  temp;

        function<void(int, int)> solve  =[&] ( int start, int target){

            if( target == 0){
                ans.push_back(temp);
                return ;
            }

            if( target < 0){
                return;

            }

            for( int i = start ; i < candidates.size(); i++){

                temp.push_back(candidates[i]);

                solve(i, target - candidates[i]);

                temp.pop_back();
            }
        };

        solve(0, target);

        return ans;
           
    }
};