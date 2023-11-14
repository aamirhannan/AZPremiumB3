class Solution {
public:


    int bs(int l, int h, vector<int>&nums, int target)
    {
        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target)
            {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }


    bool check(int x, vector<int>&nums)
    {
        return nums[x] < nums[0];
    }

    int search(vector<int>& nums, int target)
    {

        // step - 1 :- find peak
        int l = 0, h = nums.size() - 1, peak = -1, n = nums.size();
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (check(mid, nums))
            {
                peak = mid;
                h =  mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (peak == -1)
            return bs(0, n - 1, nums, target); //searching on full arraya
        int left = bs(0, peak - 1, nums, target); //searching on left half of the array
        return left != -1 ? left : bs(peak, n - 1, nums, target); //searching on right half of the array
    }
};