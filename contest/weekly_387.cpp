// https://leetcode.com/contest/weekly-contest-387/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> nums1 { nums[0] };
        vector<int> nums2 { nums[1] };
        
        for(int i = 2; i < nums.size(); ++i) {
            if(nums1.back() > nums2.back())
                nums1.push_back(nums[i]);
            else
                nums2.push_back(nums[i]);
        }
        
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        return nums1;
    }
};

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        for(int i = 0; i < n; ++i)
            for(int j = 1; j < m; ++j)
                grid[i][j] += grid[i][j - 1];
        
        for(int i = 0; i < m; ++i)
            for(int j = 1; j < n; ++j)
                grid[j][i] += grid[j - 1][i];
            
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] <= k)
                    ++cnt;
                else
                    break;       
            }
        }
        
        return cnt;
    }
};

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int> y(3), non_y(3);
        int y_cnt = 0, non_y_cnt = 0;
        
        auto liesOnY = [&](int r, int c) {
            for(int i = 0; i <= n / 2; ++i) {
                if(r == i)
                    return c == i || c == n - i - 1;
            }  
            
            return r > n / 2 && c == n / 2;
        };
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(liesOnY(i, j)) {
                    ++y[grid[i][j]];
                    ++y_cnt;
                }
                else {
                    ++non_y[grid[i][j]];
                    ++non_y_cnt; 
                }
            }
        }
        
        int c1 = y_cnt - y[0] + non_y_cnt - max(non_y[1], non_y[2]);
        int c2 = y_cnt - y[1] + non_y_cnt - max(non_y[0], non_y[2]);
        int c3 = y_cnt - y[2] + non_y_cnt - max(non_y[0], non_y[1]);
                    
        return min({ c1, c2, c3 });
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef tree<array<int, 2>, null_type, less<array<int, 2>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
    int greaterCount(pbds& p, int num, int sz) {
        return p.size() - p.order_of_key({ num, sz });
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        int sz = nums.size();    
        
        vector<int> nums1 { nums[0] }, nums2 { nums[1] };
        
        pbds p1, p2;
        p1.insert({ nums[0], 0 });
        p2.insert({ nums[1], 1 });
        
        for(int i = 2; i < sz; ++i) {
            int cnt1 = greaterCount(p1, nums[i], sz);
            int cnt2 = greaterCount(p2, nums[i], sz);
            
            if(cnt1 > cnt2) {
                p1.insert({ nums[i], i});
                nums1.push_back(nums[i]);
            }
            else if(cnt2 > cnt1) {
                p2.insert({ nums[i], i });
                nums2.push_back(nums[i]);
            }
            else if(p1.size() > p2.size()) {
                p2.insert({ nums[i], i });
                nums2.push_back(nums[i]);
            }
            else {
                p1.insert({ nums[i], i });
                nums1.push_back(nums[i]);
            }
        }
        
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        return nums1;
    }
};