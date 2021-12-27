/**
 * @param {number} n
 * @return {number}
 */
var bitwiseComplement = function(num) {
    return parseInt(num.toString(2).split("").map(x=>{return (Number(x)+1)%2}).join(""),2)
};
