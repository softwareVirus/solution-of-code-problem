/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumProduct = function(nums) {
    let s = nums.sort(function(a,b){return a-b})
    let i = nums.length-1;
    if(s[i]*s[i-1]*s[i-2] > s[0]*s[1]*s[i]) {
        return s[i]*s[i-1]*s[i-2]
    } else {
        return s[0]*s[1]*s[i]
    }
};
