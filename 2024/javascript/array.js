// duplicate([1,2,3,4,5]) => [1,2,3,4,5,1,2,3,4,5]
const test = [1, 2, 3, 4, 5];
const test2 = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5];

const duplicate = (arr) => {
    return arr.concat(arr);
};
console.log("duplicate", duplicate(test));

// reduce()
// reduce의 인터페이스는? arr.reduce(callback, initialValue), callback은 acc, cur, idx, arr를 인자로 받는다.
// reduce의 기능은? acc에 callback의 반환 값이 할당된다.
// initialValue가 있을때는 initialValue를 acc에 할당하고 배열의 첫번째를 cur로 지정, 없을때는 배열의 첫번째가 acc가 된다.
// 배열을 순회하면서 acc에 callback의 반환값을 할당한다.
// acc를 반환한다.

Array.prototype.myReduce = function (callback, initialValue) {
    let acc = initialValue ? initialValue : this[0];
    for (let i = initialValue ? 0 : 1; i < this.length; i++) {
        acc = callback(acc, this[i], i, this);
    }
    return acc;
};

console.log(
    "reduce",
    test.myReduce((acc, cur) => acc + cur, 0)
);

// map()
// 1. map의 인터페이스는? map(callback), callback은 value, index, array를 인자로 받는다.
// 2. map의 기능은? 배열의 각 요소에 대해 callback 함수를 실행하고 그 결과를 모아 새로운 배열을 반환한다.
// 3. 기존 배열은 this로 접근한다.
// 4. 반복문을 돌면서 배열의 처음부터 끝까지 callback 실행
// 5. 새로운 배열을 만들어서 callback의 결과를 넣어준다.

Array.prototype.myMap = function (callback) {
    const result = [];
    for (let i = 0; i < this.length; i++) {
        const newElement = callback(this[i], i, this);
        result.push(newElement);
    }
    return result;
};

console.log(
    "map",
    test.myMap((v, i) => 2 * v)
);

// filter()
// 1. filter의 인터페이스는? array.filter(callback), callback은 value, index, array를 인자로 받는다.
// 2. filter의 기능은? 배열의 각 요소에 대해 callback을 실행하고 callback이 true인 인자만 새로운 배열에 담아 반환한다.
// 3. 기존 배열은 this로 접근한다.
// 4. 반복문을 돌면서 배열의 처음부터 끝까지 callback을 실행한다.
// 5. 결과가 참인 요소들만 새로운 배열에 담는다.
// 6. 배열을 반환한다.

Array.prototype.myFilter = function (callback) {
    const result = [];
    for (let i = 0; i < this.length; i++) {
        const flag = callback(this[i], i, this);
        if (flag) result.push(this[i]);
    }
    return result;
};

console.log(
    "filter",
    test2.myFilter((val, idx, arr) => arr.indexOf(val) === idx)
);
console.log(
    "reduce filter",
    test2.myReduce((acc, cur, idx, arr) => {
        if (arr.indexOf(cur) === idx) {
            acc.push(cur);
        }
        return acc;
    }, [])
);

// forEach()
// 1. forEach()의 인터페이스는? array.forEach(callback), callback은 value, index, array를 인자로 받음
// 2. forEach의 기능은? return값 없음 배열 요소에 대해 callback 실행

Array.prototype.myForEach = function (callback) {
    for (let i = 0; i < this.length; i++) {
        callback(this[i], i, this);
    }
};
test.myForEach((val) => console.log("forEach", val));

// some()
// 1. some()의 인터페이스는? array.some(callback), callback은 value, index, array를 인자로 받음
// 2. some()의 기능은? 배열의 요소 중 callback의 조건을 만족하는 요소가 하나라도 있으면 true를 반환하고, 그렇지 않으면 false를 반환한다.
// 3. 배열을 순회하면서 callback을 실행한다.
// 4. callback의 결과가 true인 경우 true를 반환한다.

Array.prototype.mySome = function (callback) {
    for (let i = 0; i < this.length; i++) {
        if (callback(this[i], i, this)) {
            return true;
        }
    }
    return false;
};

console.log(
    "some",
    test.mySome((val) => val > 5)
);

// every()
// 1. every()의 인터페이스는? array.every(callback), callback은 value, index, array를 인자로 받음
// 2. every()의 기능은? 배열의 모든 요소가 callback의 조건을 만족하면 true를 반환하고, 그렇지 않으면 false를 반환한다.
// 3. 배열을 순회하면서 callback을 실행한다.
// 4. callback의 결과가 false인 경우 false를 반환한다.

Array.prototype.myEvery = function (callback) {
    for (let i = 0; i < this.length; i++) {
        if (!callback(this[i], i, this)) {
            return false;
        }
    }
    return true;
};

console.log(
    "every",
    test.myEvery((val) => val > 0)
);

// find()
// 1. find()의 인터페이스는? array.find(callback), callback은 value, index, array를 인자로 받음
// 2. find의 기능은? 배열의 요소 중 callback의 조건을 만족하는 첫 번째 요소를 반환한다.
// 3. 배열을 순회하면서 callback을 실행한다.
// 4. callback의 결과가 true인 경우 해당 요소를 반환한다.

Array.prototype.myFind = function (callback) {
    for (let i = 0; i < this.length; i++) {
        if (callback(this[i], i, this)) return this[i];
    }
};

console.log(
    "find",
    test.find((v, i) => v == i * 2)
);

// slice()
// 1. slice의 인터페이스? arr.slice(start, end)
// 2. 반복문 시작과 끝 넣어주고 새로운배열에 push
// 3. 새로운 배열 리턴

Array.prototype.mySlice = function (start, end) {
    const result = [];
    for (let i = start; i < end; i++) {
        result.push(this[i]);
    }
    return result;
};

console.log("slice", test.mySlice(1, 3));
