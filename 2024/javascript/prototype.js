/*
 prototype이란? 
 JavaScript에서 모든 객체는 내부적으로 다른 객체를 참조하는 [[Prototype]]이라는 숨겨진 속성을 가지고 있습니다. 
 이 참조된 객체를 프로토타입이라고 합니다. 
 객체의 프로퍼티를 읽으려고 하면, 프로퍼티가 없다면 자동으로 프로토타입에서 프로퍼티를 찾습니다. 
 이런 방식을 프로토타입 상속이라고 합니다.

 call, bind, apply 등으로 this를 명시적으로 설정가능
*/

function greet(greeting, punctuation, method) {
    console.log(`${method}: ${greeting}, I am ${this.name}${punctuation}`);
}
const user = { name: "Sangmin" };

// call
greet.call(user, "Hello", "!", "call");

// apply
greet.apply(user, ["Hi", "!", "apply"]);

// bind
const greetUser = greet.bind(user, "Hello", "!", "bind");
greetUser();
function debounce(func, delay) {
    let debounceTimer;
    return function (...args) {
        clearTimeout(debounceTimer);
        debounceTimer = setTimeout(() => func(...args), delay);
    };
}

// 사용 예시
inputElement.addEventListener(
    "input",
    debounce(function () {
        console.log("Input event handler invocation after 300ms of inactivity past the last event.");
    }, 300)
);
