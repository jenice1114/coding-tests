729. My Calendar I
```
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
캘린더로 사용할 프로그램을 구현 중입니다.
새로운 이벤트 추가 시 중복 예약이 발생하지 않을 경우 새 이벤트를 추가할 수 있습니다.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
중복 예약은 두 이벤트가 겹치는 구간이 있을 경우 발생합니다.

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
이벤트는 두 개의 정수 start와 end로 나타낼 수 있으며, [start, end)에서의 예약을 나타냅니다. 이 범위는 실수 x가 start <= x < end 를 만족하는 구간을 의미합니다.
```

```
Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
MyCalendar()는 캘린더 객체를 초기화합니다.

boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
boolean book(int start, int end)는 이벤트를 중복 예약 없이 캘린더에 성공적으로 추가할 수 있으면 true를 반환합니다. 그렇지 않으면 false를 반환하고 이벤트를 캘린더에 추가하지 않습니다.
```

```
Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]

Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.


Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
```

***

풀이 과정
===
* [editorial](https://leetcode.com/problems/my-calendar-i/editorial)
```cpp
#include <string>
#include <vector> // vactor 사용하기 위함
#include <utility> // pair 사용하기 위함

class MyCalendar {
 private:
  // start값과 end값을 저장하는 calendar라는 vector를 만든다
  std::vector<std::pair<int, int>> calendar;

 public:
  bool book(int start, int end) {
    // calendar에 중복값이 있으면 false
    for (const auto [s, e] : calendar) {
      if (start < e && s < end) {
        return false;
      }
    }
    // 없으면 저장하고 true
    calendar.emplace_back(start, end);
    return true;
  }
};
```

***

##### 한줄평
* 처음 leetcode 접해보는데 editorial이 있어서 오히려 좋아...
* 근데 무지성이라고 욕먹었다...ㅋ... 복잡도 그래도 N이니까 패스한다^^