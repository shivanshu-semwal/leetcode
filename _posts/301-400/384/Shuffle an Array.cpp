

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *ans = (int*)malloc(sizeof(int)*n*2);
    
    int i=0, j=n;
    int counter=0;
    while(i<n){
        ans[counter++] = nums[i++];
        ans[counter++] = nums[j++];
    }
    *returnSize = 2*n;
    return ans;
}
