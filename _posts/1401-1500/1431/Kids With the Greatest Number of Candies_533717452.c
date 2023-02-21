

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    *returnSize = candiesSize;
    bool *ans=(bool*)malloc(sizeof(bool)*candiesSize);
    int max=INT_MIN;
    for(int i=0;i<candiesSize;i++){
        if(max < candies[i]){
            max = candies[i];
        }
    }
    
    for(int i=0;i<candiesSize;i++){
        if(max > candies[i] + extraCandies){
            ans[i] = false;
        } else{
            ans[i] = true;
        }
    }
    return ans;
}
