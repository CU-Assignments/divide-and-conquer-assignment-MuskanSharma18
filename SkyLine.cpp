class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return divideAndConquer(buildings, 0, buildings.size() - 1);
    }
private:
    vector<vector<int>> mergeSkylines(vector<vector<int>>& left, vector<vector<int>>& right) {
        vector<vector<int>> merged;
        int h1 = 0, h2 = 0, i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            int x;
            if (left[i][0] < right[j][0]) {
                x = left[i][0];
                h1 = left[i][1];
                i++;
            } else if (left[i][0] > right[j][0]) {
                x = right[j][0];
                h2 = right[j][1];
                j++;
            } else {
                x = left[i][0];
                h1 = left[i][1];
                h2 = right[j][1];
                i++;
                j++;
            }
            int maxHeight = max(h1, h2);
            if (merged.empty() || merged.back()[1] != maxHeight) {
                merged.push_back({x, maxHeight});
            }
        }
        while (i < left.size()) merged.push_back(left[i++]);
        while (j < right.size()) merged.push_back(right[j++]);

        return merged;
    }
    vector<vector<int>> divideAndConquer(vector<vector<int>>& buildings, int start, int end) {
        if (start == end) {
            return {{buildings[start][0], buildings[start][2]}, {buildings[start][1], 0}};
        }
        int mid = (start + end) / 2;
        vector<vector<int>> leftSkyline = divideAndConquer(buildings, start, mid);
        vector<vector<int>> rightSkyline = divideAndConquer(buildings, mid + 1, end);
        return mergeSkylines(leftSkyline, rightSkyline);
    }
};
