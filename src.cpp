class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        std::vector<std::vector<int>> graph(nums.size());

        // Build adjacency list
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= nums[i]; ++j) {
                if (i + j < nums.size()) {
                    graph[i].push_back(i + j);
                }
            }
        }

        std::unordered_set<int> unionSet;
        unionSet.insert(graph[0].begin(), graph[0].end());

        // Union operation to merge reachable nodes
        for (const auto& lst : graph) {
            for (int node : lst) {
                if (unionSet.count(node)) {
                    unionSet.insert(lst.begin(), lst.end());
                    break;
                }
            }
        }

        // Check if the last index is reachable
        return unionSet.count(nums.size() - 1);
    }
};
