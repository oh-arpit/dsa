// https://leetcode.com/contest/weekly-contest-385/

class Solution {
    bool isPrefixAndSuffix(string& a, string& b) {
        int n = a.size(), m = b.size();
        
        if(n > m) 
            return false;
        
        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i])
                return false;
            
            if(a[i] != b[m - n + i])
                return false;
        }
        
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        
        for(int i = 0; i + 1 < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                cnt += (isPrefixAndSuffix(words[i], words[j]));
            }
        }
        
        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> nums;
        int best = 0;
        
        for(int num : arr1) {
            while(num) {
                nums.insert(num);
                num /= 10;
            }
        }
        
        for(int num : arr2) {
            while(num) {
                if(nums.count(num)) {
                    best = max(best, num);
                    break;
                }
                num /= 10;
            }
        }
        
        return best == 0 ? 0 : to_string(best).size();
    }
};

class Solution {
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const static int MAX = 1000006;
    bitset<MAX> isPrime;
    
    void genPrimes() {
        isPrime.set();
        
        for(int i = 10; i < MAX; i += 2)
            isPrime[i] = 0;
        
        for(long i = 3; i * i < MAX; i += 2)
            for(long j = i * i; j < MAX; j += 2 * i)
                isPrime[j] = 0;
    }
public:
    Solution() {
        genPrimes();
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, int> freq;
        int mx_cnt = 0, best = -1;
        
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;  
        };
        
        for(int x = 0; x < n; ++x) {
            for(int y = 0; y < m; ++y) {                                
                for(int k = 0; k < 8; ++k) {
                    int num = mat[x][y];
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    while(isValid(nx, ny)) {
                        num = num * 10 + mat[nx][ny];
                        if(isPrime[num]) ++freq[num];
                        nx += dx[k];
                        ny += dy[k];
                    }                    
                }
            }
        }
        
        for(auto& [num, cnt] : freq) {
            if(cnt > mx_cnt) {
                mx_cnt = cnt; 
                best = num;                
            } 
            else if(cnt == mx_cnt)
                best = max(best, num);
        }
        
        return best;
    }
};