class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            vector<int>seen( n , false);
               for(  int num : nums){
            if( num > 0 &&  num <= n){
                seen[ num - 1] = true;
            }

            
        }
            for( int i =0;i<nums.size();i++){
                if(!seen[i]){
                    return i + 1;
                }
            }
            return   n + 1;}
};