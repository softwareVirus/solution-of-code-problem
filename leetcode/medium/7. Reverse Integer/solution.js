/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let c = 1
    if (x < 0) c = -1
    x = Math.abs(x)
    x= x.toString().split("").reverse().join("")
    let b = c*parseInt(x)
    return -1 * (2**31) <= b && b <= 2**31-1 ? b : 0
};
