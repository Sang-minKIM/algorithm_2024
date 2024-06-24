/* sum()()()
    sum(1)(2)(3)() => 6;
    sum(1)(2)(3)(4)() => 10;
    1. 클로저를 활용해서 함수를 반환하는 함수를 만들어 인자를 받는다.
    2. 이때 내부 함수 인자가 없을 때 까지 계속 함수를 재귀호출
    2-1. 인자가 있을 경우 해딩 인자와 외부 함수 인자를 더해서 sum을 재귀호출
    2-2. 인자가 없을 경우 외부함수 인자 return
*/

function sum(a) {
    return function (b) {
        if (b) return sum(a + b);
        else return a;
    };
}

console.log("sum", sum(1)(2)(3)(4)());

/*
 multi(1)(2)(3) => 6;
 multi(4)(3)(4) => 48;
*/
function multi(a) {
    return function (b) {
        return function (c) {
            return a * b * c;
        };
    };
}

console.log("multi", multi(4)(3)(4));

/* 
const addSix = createBase(6);
addSix(10) => 16
addSix(32) => 38

*/
function createBase(a) {
    return function (b) {
        return a + b;
    };
}

const addTen = createBase(10);
console.log("addTen", addTen(12));
