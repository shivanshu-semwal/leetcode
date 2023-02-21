class Solution {
public:
    int solve2(vector<int>& a, int i, int j){ // how much player1 make her chance
        if(i>j) return 0; if(i==j) return a[i];
        int choicei = solve(a, i+1, j); int choicej = solve(a, i, j-1);
        if(choicei > choicej) return choicej; else return choicei;
    }
    int solve(vector<int>& a, int i, int j){ // how much player1 make his chance
        if(i>j) return 0; if(i==j) return a[i];
        int choicei = solve2(a, i+1, j); int choice1 = a[i] + choicei;
        int choicej = solve2(a, i, j-1); int choice2 = a[j] + choicej;
        if(choice1 > choice2) return choice1; else return choice2;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int player1 = solve(nums, 0, nums.size() - 1); // player 1 amount
        int player2 = sum - player1;
        return player1>= player2;
    }
};
