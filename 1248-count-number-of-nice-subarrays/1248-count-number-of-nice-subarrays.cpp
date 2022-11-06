class Solution {
public:

    int atMost(vector<int> &nums, int k) {
        if(k < 0) return 0;

        int start = 0, odd_count = 0, n_subarrays = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            int curr_element = nums[i];
            if(curr_element % 2) odd_count++;

            while(odd_count > k) {
                if(nums[start] % 2) odd_count--;
                start++;
            }

            n_subarrays += (i - start + 1);
        }

        return n_subarrays;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};