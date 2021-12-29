
void sortColors(int* nums, int numsSize){
    int high = 1;
    while(high != 0) {
        high = 0;
        for(int i = 0; i < numsSize-1; i++) {
            if(nums[i] > nums[i+1]) {
                swap(&nums[i],&nums[i+1]);
                high = i+1;
            }
        }
        numsSize = high;
    }
}
