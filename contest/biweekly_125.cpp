// https://leetcode.com/contest/biweekly-contest-125/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return count_if(begin(nums), end(nums), [&](int num) {
            return num < k; 
        });
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums));
        int cnt = 0;
        
        while(pq.size() > 1 && pq.top() < k) {
            long mn1 = pq.top(); pq.pop();
            long mn2 = pq.top(); pq.pop();
            pq.push(2 * mn1 + mn2);
            ++cnt;
        }
        
        return cnt;
    }
};

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<array<int, 2>>> adj(n);
        vector<int> res(n);
        
        for(auto& e : edges) {
            adj[e[0]].push_back({ e[1], e[2] });
            adj[e[1]].push_back({ e[0], e[2] });
        } 
        
        function<void(int, int, int, int&, int&)> calc = [&](int node, int par, int wt, int& dist, int& cnt) {
            dist += wt;
            cnt += (dist % signalSpeed == 0);
            
            for(auto& [nbr, wt] : adj[node]) {
                if(nbr != par)
                    calc(nbr, node, wt, dist, cnt);
            }
            
            dist -= wt;
        };  
        
        function<void(int)> dfs = [&](int node) {
            vector<int> nbrs;
            
            for(auto& [nbr, wt] : adj[node]) {
                int dist = 0, cur = 0;
                calc(nbr, node, wt, dist, cur);
                
                if(cur)
                    nbrs.push_back(cur);
            }
            
            if(nbrs.size() > 1) {
                int prev = nbrs[0];
                
                for(int i = 1; i < nbrs.size(); ++i) {
                    res[node] += nbrs[i] * prev;
                    prev += nbrs[i];
                }
            }
        };  
        
        for(int i = 0; i < n; ++i)
            dfs(i);
        
        return res;
    }
};