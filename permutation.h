/*全排列，用next_Permutaion字典序排列思路*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,k;
        int len = nums.size();
        if(len <= 0)
            return;
        for(i=len-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
                break;
        }
        for(k=len-1;k>i;k--)
        {
            if(nums[k] > nums[i])
                break;
        }
        if(i>=0)
            swap(nums[i],nums[k]);
        reverse(nums.begin()+i+1,nums.end());
    }
};

/*用交换法思路来全排列*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int end = nums.size();
        int start = 0;
        vector<vector<int>> result;
        if(nums.size() < 1)
            return result;
        Permutation(result,nums,start,end-1);
        return result;
    }
    
    void Permutation(vector<vector<int>> &res,vector<int> &nums,int start,int end)
    {
        vector<int> tmp;
        if(start == end)
        {
            for(auto &c : nums)
                tmp.push_back(c);
            res.push_back(tmp);
        }
        else
        {
            for(int i=start;i<=end;i++)
            {
                int t = nums[start];
                nums[start] = nums[i];
                nums[i] = t;
                
                Permutation(res,nums,start+1,end);
                
                t = nums[start];
                nums[start] = nums[i];
                nums[i] = t;
            }
        }
    }
};

