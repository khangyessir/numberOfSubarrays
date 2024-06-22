#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int numberOfSubarrays(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        for(int i=0; i<n; ++i){
            sum += (nums[i] % 2 == 1 ? 1 : 0);
            if(sum >= k){
                count += prefix[sum - k];
            }
            ++prefix[sum];
        }
        return count;
    }
};

//Example Testcase
int main(){
    Solution sol;
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}

