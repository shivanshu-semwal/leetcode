class Solution {
public:
int numOfWays(std::vector<int>& numbers) {
        return (helper(numbers) - 1) % mod;
}

private:
    int mod = std::pow(10, 9) + 7;
    
    int mypow(long x) {
        int n = 1e9 + 5, mod = 1e9 + 7;
        long res = 1;
        while(n) {
            if (n & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
    }
    long combinations(int m, int n, int temp) {
        if(m==0 || n==0) return 1;
        if(m==n) return 1;
        int mod = 1e9 + 7;
        long num = 1, dem = 1;
        for (int i=m; i>= m - n + 1; --i)
            num = (num * i) % mod;
        for (int i=1; i<=n; ++i)
            dem = (dem * mypow(i)) % mod;
        return (num * dem) % mod;
    }

    int ways_to_interleave(int sequence_1_length, int sequence_2_length) {
        return combinations(sequence_1_length + sequence_2_length, sequence_2_length, mod); 
        // combinations function is omitted as it's not really relevant to core issue of the question.
    }

    long helper(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            return 1;
        }
        int root_value = numbers[0];
        std::vector<int> left, right;
        std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(left), 
                     [root_value](int number){return number < root_value;});
        std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(right), 
                     [root_value](int number){return number > root_value;});
        long  ways_to_arrange_left = helper(left) % mod;
        long ways_to_arrange_right = helper(right) % mod;
        long duck_this = (ways_to_arrange_left * ways_to_arrange_right) % mod;
        long duck_this_too = (duck_this * ways_to_interleave(left.size(), right.size())) % mod;
        return duck_this_too;
     }
};
