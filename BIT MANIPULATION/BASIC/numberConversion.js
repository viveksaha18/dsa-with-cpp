let n = 13
var toString = (n) => {
    let res = ""
    while(n > 0){
        if(n % 2 == 1) res += '1'
        else res += '0'
        n = Math.floor(n/2)
    }
    return res.split("").reverse().join("")
}
console.log(toString(n))

// Time Complexity : O(log2(n))
// Space Complexity : O(log2(n))


// Binary to Decimal conversion 

var toDecimal = (s) => {
    let len = s.length
    let n = 0
    for(let i = len - 1; i >= 0; i--){
        if(s[i] == '1'){
            n += Math.pow(2, len - 1 - i)
        }
    }
    return n
}

console.log(toDecimal("1101"))

// Time Complexity : O(n)
// Space Complexity : O(1)

// Data type ranges 
// int 32 bits long long 64 bits 


// 1's complement - flip all the bits 

toOneComplement = (n) => {
    let res = ""
    while(n > 0){
        if(n % 2 == 1) res += '0'
        else res += '1'
        n = Math.floor(n/2)
    }
    res = res.split("").reverse().join("")
    return res.split("").reverse().join("")
}

console.log(toOneComplement(13)) // 0010
