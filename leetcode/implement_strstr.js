/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle.length == 0) return 0
    for(let i = 0; i < haystack.length; i++) {
        let j;
        for(j = i; j < haystack.length+i && j < needle.length+i; j++) {
            if(haystack[j] != needle[j-i]) break
        } 
        if(j == needle.length+i) return i
    }
    return -1;
};
