/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n < 0) {
        x = 1/x
        n=-n
    } 
    return Math.pow(x,n)
};
