const delay = (n) => {
    return new Promise((resolve) => {
        setTimeout(resolve, n * 1000);
    });
};

const main = async () => {
    console.log("1번");
    const n = await delay(3);

    // 첫번째 콘솔('1번')이 찍힌 후 4초 후에 찍힘`
    // output
    // '1번'
    // ...4초 후...
    // '2번!!!'
    console.log("2번!!!");
};
main();

// resolve에 전달한 값이 n이 된다.

/*
 react의 suspense처럼 promise를 넘겨주어야 할 때는 then 을 사용해야함 
 await는 promise의 결과를 리턴하니까

*/

// abortController 이용한 useFetch

import { useReducer, useEffect } from "react";

function fetchReducer(state, action) {
    switch (action.type) {
        case "FETCH_INIT":
            return { ...state, isLoading: true, isError: false };
        case "FETCH_SUCCESS":
            return { ...state, isLoading: false, isError: false, data: action.payload };
        case "FETCH_FAILURE":
            return { ...state, isLoading: false, isError: true };
        default:
            throw new Error();
    }
}

function useFetch(url) {
    const [state, dispatch] = useReducer(fetchReducer, {
        data: null,
        isLoading: false,
        isError: false,
    });

    useEffect(() => {
        const controller = new AbortController();
        const signal = controller.signal;

        const fetchData = async () => {
            dispatch({ type: "FETCH_INIT" });
            try {
                const response = await fetch(url, { signal });
                if (!response.ok) {
                    throw new Error(`Error: ${response.status}`);
                }
                const data = await response.json();
                dispatch({ type: "FETCH_SUCCESS", payload: data });
            } catch (error) {
                if (error.name === "AbortError") {
                    console.log("Fetch aborted");
                } else {
                    dispatch({ type: "FETCH_FAILURE" });
                }
            }
        };

        fetchData();

        return () => {
            controller.abort();
        };
    }, [url]);

    return state;
}
