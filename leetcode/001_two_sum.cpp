#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> ans = {-1,-1};

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapp;
        // Store nums
        for(int i = 0; i < nums.size(); i++)
        {
            cout << i << ":\t" << nums[i] << '\n';
            mapp.insert(make_pair(nums[i], i));
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if(mapp.count(x) == 1)
            {
                ans[0] = i;
                ans[1] = mapp.find(x)->second;
                cout << nums[i] << " + " << x << " = " << target << '\n';
                break;
            }
        }

        return ans;
    }

    void printAns() {
        cout << ans[0] << ", " << ans[1] << '\n';
    }
};

int test01();
int test02();
int test03();

int main()
{
    int ret = 0;

    std::cout << "Hello World!\n" << std::endl;    
        
    test01();
    test02();
    test03();

    return ret;
}

int test01()
{
    int ret = 0;
    vector<int> nums = {1,2,3,4,7};
    int tgt = 9;
    Solution sln01;

    sln01.twoSum(nums, tgt);
    sln01.printAns();

    return ret;
}

int test02()
{
    int ret = 0;
    vector<int> nums = {1,2,3,4,7};
    int tgt = 3;
    Solution sln01;

    sln01.twoSum(nums, tgt);
    sln01.printAns();

    return ret;
}

int test03()
{
    int ret = 0;
    vector<int> nums = {1,2,3,4,7};
    int tgt = 11;
    Solution sln01;

    sln01.twoSum(nums, tgt);
    sln01.printAns();

    return ret;
}