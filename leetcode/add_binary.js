var addBinary = function(a, b) {
    let c,d;
    let answer = []
    for(let i = 0; i < Math.max(a.length,b.length)+1; i++) answer.push(0)
    if(a.length > b.length) {
        c = "0".repeat(a.length - b.length) + b;
        d = a;
    } else {
        c = "0".repeat(b.length - a.length) + a;
        d = b;
    } 
    for(let i = c.length-1,j = d.length-1,k = answer.length-1; i >= 0; i--,j--,k--) {
        answer[k-1] = Math.floor((Number(c[i])+Number(d[j])+answer[k])/2)
        answer[k] = (Number(c[i])+Number(d[j])+Number(answer[k]))%2
    }
    return answer[0] == 0 ? answer.slice(1,answer.length).join("") : answer.join("");
};
