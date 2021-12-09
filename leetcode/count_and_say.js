/**
 * @param {number} n
 * @return {string}
 */
var count = (k) => {
    let first = k.split("")
    let answer = []
    let v = first[0]
    let calculate = 1;
    for(let i = 1; i < first.length; i++) {
        if(first[i] != v) {
            answer.push(calculate);
            answer.push(v);
            calculate = 1;
            v = first[i];
        } else {
            calculate++;
        }
    }
    answer.push(calculate)
    answer.push(v)
    return answer.join("")
}
var countAndSay = function(n) {
    var value = "1"
    for(let i = 2; i <= n; i++) {
        value = count(value);
    }
    return value.toString()
};
