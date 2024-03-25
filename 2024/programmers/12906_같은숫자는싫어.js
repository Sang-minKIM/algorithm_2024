function solution(arr) {
    const stk = [];
    for (let el of arr) {
        if (stk.length == 0 || stk[stk.length - 1] != el) stk.push(el);
    }

    return stk;
}
