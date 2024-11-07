/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int n, int* returnSize) {
    int* result=(int*)malloc((n+1)*(sizeof(int)));
    int carry=1;
    for(int i=n-1;i>=0;i--){
        int sum=carry+digits[i];
        result[i+1]=sum%10;
        carry=sum/10;
    }
    if(carry==1){
        result[0]=1;
        *returnSize=n+1;
    }
    else{
        *returnSize=n;
        result++;
    }
    return result;
}