/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var maxBottlesDrunk = function(numBottles, numExchange) {
    let drink = numBottles
    let empty = numBottles
    while(empty >= numExchange) {
        empty -= numExchange
        drink += 1
        empty += 1
        numExchange += 1
    }
    return drink
};

console.log(maxBottlesDrunk(13, 6))