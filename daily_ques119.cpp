class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedBitmask;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reservedBitmask[row] |= (1 << (col - 2));
            }
        }

        int maxGroups = (n - reservedBitmask.size()) * 2;

        for (const auto& [row, mask] : reservedBitmask) {
            bool leftPossible   = !(mask & 0b00001111); 
            bool rightPossible  = !(mask & 0b11110000); 
            bool middlePossible = !(mask & 0b00111100); 

            if (leftPossible && rightPossible) {
                maxGroups += 2;
            } else if (leftPossible || rightPossible || middlePossible) {
                maxGroups += 1;
            }
        }

        return maxGroups;
    }
};
