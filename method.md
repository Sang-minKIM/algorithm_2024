# string

-   begin()
-   end()
-   size()
-   insert(위치, 문자열)
-   erase(위치, 크기)
-   pop_back()
-   find(문자열) string::npos
-   substr(위치, 크기)
-   reverse(시작 위치, 끝 위치)(STL 함수임 나머지는 메서드라 `str.~~` reverse만 `reverse(str.begin(), str.end())`)

## split

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimeter) {
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while ((pos = input.find(delimeter)) != string::npos) {
    token = input.substr(0, pos);
    ret.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  ret.push_back(input);
  return ret;
}
```

## atoi(s.c_str())

문자 숫자 판별

# bool

bool(a) 형변환

# int

20억.
최대값 987654321로 둬도 됨
또는 1e9

# long long

2^63 - 1
최대값 1e18

# pair

```cpp
pair<int, int> p = {1, 2}
tie(a, b) = p
```

# 이터레이터

-   begin()
-   end()
-   advance(iterator, cnt)
-

# function

-   fill(시작 이터레이터, 끝 이터레이터, 초기화하는값)
-   memset(배열 이름, k, 배열의 크기)
    -   0, -1, char로만 초기화
-   memcpy(destination, source, size) => array
-   copy(v.begin(), v.end(), ret.begin()) => vector
-   copy(v, v+5, ret) => array
-   sort(first, last, \*커스텀 비교 함수)
    -   sort(a.begin(), a.end(), less<int>())
-   unique(v.begin(), v.end())
-   lower_bound(), upper_bound()

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
vector<int> a {1, 2, 3, 3, 3, 4};
cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 2
cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 5
return 0;
}
```

-   accumulate(v.begin(), v.end(), 0)
-   max_element(v.begin(), v.end()) => 이터레이터 반환

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int a = *max_element(v.begin(), v.end());
auto b = max_element(v.begin(), v.end());
cout << a << '\n'; // 10
cout << (int)(b - v.begin()) << '\n'; // 9
}

```

-   min_element()

# vector

-   `vector<int> v;`
    -   vector<int> v3[10]; => 이차원 배열 정적할당
-   push_back(value)
-   pop_back()
-   erase(from, to)
-   find(from, to, value)
-   clear()
-   fill(from, to, value)

# Array

-   int a[10]
-   메서드 없음

# linked list

```cpp
class Node {
public:
  int data;
  Node* next;
  Node(){
    data = 0;
    next = NULL;
  }
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};
```

-   list<int> a;
-   push_front(value)
-   push_back(value)
-   insert(idx, value)
-   erase(idx)
-   pop_front()
-   pop_back()
-   front()
-   back()
-   clear()

# map

-   map<string, int> mp
-   insert({key, value})
-   [key] = value
-   [key]
-   size()
-   erase(key)
-   find(key)
-   for(auto it : mp)
-   clear()
-   참조만 해도 값이 할당됨

# set

map과 메서드 똑같음

# stack

-   push(value)
-   pop()
-   size()
-   top()

# queue

-   push(value)
-   pop()
-   size()
-   front()

# deque

-   push_front()
-   push_back()
-   front()
-   back()
-   pop_back()
-   pop_front()
-   size()

# struct

-   커스텀 자료구조

# priority queue

-   priority_queue<int, vector<int>, greater<int> > pq; //오름차순
-   priority_queue<int> pq2; // 내림차순
-   스택과 동일한 메서드
