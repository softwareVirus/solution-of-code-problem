/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let max = ""
    let c = ""
    for(let j = 0; j < s.length; j++) {
        c = ""
        for(let i = j; i < s.length; i++) {
            if(c.indexOf(s[i]) === -1) c += s[i]
            else {
                break
            }
        }
        if(c.length > max.length) max = c
    }
    return max.length
};
