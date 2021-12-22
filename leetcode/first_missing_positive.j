/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    nums = nums.sort(function(a,b){return a-b}) // complexity O(nlogn)
    let h = 1
    for(let i = 0; i < nums.length; i++) { //complexity O(n)
        console.log(h)
        if((nums[i]>0)) {
            if(nums[i] != h) return h
            else {
                if(i < nums.length - 1) {
                    if(nums[i+1] != h) h++
                } else {
                    h++
                }
            }
        }
    }
    return h
};

//Therefore nlogn+n => O(nlogn)
