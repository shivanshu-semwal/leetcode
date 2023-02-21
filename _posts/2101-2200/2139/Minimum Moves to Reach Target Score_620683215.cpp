class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while (maxDoubles != 0 && target != 1) {
            if (target % 2 != 0) {
                count++;
                target--;
                continue;
            }
            target /= 2;
            maxDoubles--;
            count++;
        }
        count += target - 1;
        return count;
    }
};
