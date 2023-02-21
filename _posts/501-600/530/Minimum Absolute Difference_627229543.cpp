class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min=arr[1] - arr[0];
        for(int i=0;i<arr.size()-1;i++){
            if(min > arr[i+1] - arr[i])
                min = arr[i+1] - arr[i];
        }
        vector<vector<int>> sol;
        for(int i=0;i<arr.size()-1;i++){
            if(min == arr[i+1] - arr[i])
                sol.push_back(vector<int> {arr[i], arr[i+1]});
        }
        return sol;
    }
};
