/**
 * @param {number} num
 * @return {string}
 */

var split_number = (num) => {
    let answer = []
    let size = 0
    while(num > 0) {
        if((num%10) != 0)answer.push((num%10)*(10**size))
        num = Math.floor(num/10)
        size++
    }
    return answer
}

var roman_converter = (number) => {
    let power = number.toString().length-1
    let roman_chars = ["I","V","X","L","C","D","M"]
    let roman_numbers = [1,5,10,50,100,500,1000]
    if(number/(10**power) < 4) {
        return roman_chars[roman_numbers.indexOf((10**power))].repeat(number/(10**power))
    } else if(number/(10**power) == 4) {
        return roman_chars[roman_numbers.indexOf((10**power))]+roman_chars[roman_numbers.indexOf((number/(10**power)+1)*(10**power))]
    } else if(number/(10**power) == 5) {
        return roman_chars[roman_numbers.indexOf(number)]
    } else if(number/(10**power) < 9) {
        return roman_chars[roman_numbers.indexOf(5*(10**power))]+ roman_chars[roman_numbers.indexOf((10**power))].repeat(number/(10**power)-5)
    } else {
       return roman_chars[roman_numbers.indexOf((10**power))]+roman_chars[roman_numbers.indexOf((10**(power+1)))]
    }
}

var intToRoman = function(num) {
    var array = split_number(num).reverse();
    let answer = ""
    for(let i = 0; i < array.length; i++) {
        answer += roman_converter(array[i])
    }
    return answer
};
