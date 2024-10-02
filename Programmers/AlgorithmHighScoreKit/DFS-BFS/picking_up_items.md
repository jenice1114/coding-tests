# 문제

```
지형은 각 변이 x축, y축과 평행한 직사각형이 겹쳐진 형태로 표현하며, 캐릭터는 이 다각형의 둘레(굵은 선)를 따라서 이동합니다.
만약 직사각형을 겹친 후 다음과 같이 중앙에 빈 공간이 생기는 경우, 다각형의 가장 바깥쪽 테두리가 캐릭터의 이동 경로가 됩니다.

단, 서로 다른 두 직사각형의 x축 좌표 또는 y축 좌표가 같은 경우는 없습니다.
즉, 위 그림처럼 서로 다른 두 직사각형이 꼭짓점에서 만나거나, 변이 겹치는 경우 등은 없습니다.

다음 그림과 같이 지형이 2개 이상으로 분리된 경우도 없습니다.
한 직사각형이 다른 직사각형 안에 완전히 포함되는 경우 또한 없습니다.

지형을 나타내는 직사각형이 담긴 2차원 배열 rectangle, 초기 캐릭터의 위치 characterX, characterY, 아이템의 위치 itemX, itemY가 solution 함수의 매개변수로 주어질 때, 캐릭터가 아이템을 줍기 위해 이동해야 하는 가장 짧은 거리를 return 하도록 solution 함수를 완성해주세요.

제한사항
rectangle의 세로(행) 길이는 1 이상 4 이하입니다.
rectangle의 원소는 각 직사각형의 [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y] 좌표 형태입니다.
직사각형을 나타내는 모든 좌표값은 1 이상 50 이하인 자연수입니다.
서로 다른 두 직사각형의 x축 좌표, 혹은 y축 좌표가 같은 경우는 없습니다.
문제에 주어진 조건에 맞는 직사각형만 입력으로 주어집니다.
charcterX, charcterY는 1 이상 50 이하인 자연수입니다.
지형을 나타내는 다각형 테두리 위의 한 점이 주어집니다.
itemX, itemY는 1 이상 50 이하인 자연수입니다.
지형을 나타내는 다각형 테두리 위의 한 점이 주어집니다.
캐릭터와 아이템의 처음 위치가 같은 경우는 없습니다.

전체 배점의 50%는 직사각형이 1개인 경우입니다.
전체 배점의 25%는 직사각형이 2개인 경우입니다.
전체 배점의 25%는 직사각형이 3개 또는 4개인 경우입니다.

입출력 예
rectangle	characterX	characterY	itemX	itemY	result
[[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]]	1	3	7	8	17
[[1,1,8,4],[2,2,4,9],[3,6,9,8],[6,3,7,7]]	9	7	6	1	11
[[1,1,5,7]]	                                1	1	4	7	9
[[2,1,7,5],[6,4,10,10]]	                    3	1	7	10	15
[[2,2,5,5],[1,3,6,4],[3,1,4,6]]	            1	4	6	3	10
```

```cpp
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 동 서 남 북
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    
    // 1. 캐릭터 좌표, 아이템 좌표 모두 2배로 늘린다.
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    // board: 직사각형을 표현할 배열이다.(문제에 직사각형을 나타내는 모든 좌표값은 50이하라고 했지만, 
    // 우리는 모든 좌표값에 대해 2배를 할 것이므로 50*2=100이므로 좌표값은 최대 100이 될 것이다.)
    vector<vector<int>> board(110, vector<int>(110));
    
    // 직사각형의 시작점과 끝점
    int x1, y1, x2, y2;
    
    // 2. 직사각형을 board 배열에 모두 입력해준다.
    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] = rectangle[i][j] * 2;

        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                board[y][x] = 1;
    }

    // 3. 직사각형의 내부는 모두 0으로 채워준다.
    for (int i = 0; i < rectangle.size(); i++)
    {
        x1 = rectangle[i][0], y1 = rectangle[i][1];
        x2 = rectangle[i][2], y2 = rectangle[i][3];

        for (int y = y1 + 1; y < y2; y++)
            for (int x = x1 + 1; x < x2; x++)
                board[y][x] = 0;
    }

    // 4. BFS
    queue<pair<int, int>> q;
    q.emplace(characterY, characterX);
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == itemY && x == itemX)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (board[nextY][nextX] == 1)
            {
                q.emplace(nextY, nextX);
                board[nextY][nextX] = board[y][x] + 1;
            }
        }
    }

    // 좌표를 모두 2배로 늘려서 계산했으니 answer에는 2로 나눈 아이템의 좌표값을 넣어주면 정답이다.
    answer = board[itemY][itemX] / 2;
    return answer;
}
```

* 도저히 모르겠어서 CPP 솔루션보고 짜보도록 하자.
* 최단거리 하자마자 BFS(FIFO) 생각하긴 했는데, 지형이 고정값이 아니므로 지형 먼저 생각 필요
* 최대 map set 해놓고 직사각형 들어올때마다 테두리는 1, 안에는 0으로 도색
  * 근데 여기서 주의할 점이 겹치는 부분이 발생해서 최단거리가 이상하게 나온다는 점.. 그래서 맵을 애초에 2배로 선언하고 구현해야한다고 함
* 또 문제는? C는 queue를 직접 구현해야한다 ㅎㅎ ㅎㅎ ㅎㅎ ㅎㅎ ... 자료구조... 오랜만에 옛날 생각난다
* 나머지는 비슷하다 음 얼추 짜진 것 같다
* 큐/스택 자료구조를 C로 구현하는 부분을 좀 더 연습해야 할 것 같다