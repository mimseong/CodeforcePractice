# 2020 / 07 / 03 (금) 코드포스 연습문제

## 후기

처음으로 0 솔브를 했다. 오랜만에 풀어서 감이 떨어졌는지 아니면 그냥 낯선 문제만 만났는지. 시간은 20분 기준으로 잘 넘겼는데 풀지를 못해ㅋㅋㅋ 문제 만났는데 어떻게 풀지 몰라서 다 넘겼다ㅠ 다시 돌아와도 해결 못했다ㅠ

## A. Lesha and array splitting

![image](https://user-images.githubusercontent.com/50068946/86440868-330be780-bd46-11ea-9308-3b329f42033b.png)

주어진 배열을 sub배열로 나누는데 sub배열의 합이 0이 되면 안 된다. 전체 0인 경우는 NO를 출력하면 된다는 걸 알겠는데 그 다음을 어떻게 해야할지 몰라서 해맸다. 이걸 하나씩 출력하려고 했는데 그럼 중간에 0이 있으면 또 단위를 크게 해서 묶어줘야 하고. 0이 아니게 묶어주는 기준을 못 찾아서 결국 못 풀었다. 


이 문제는 일단 전체 합이 0이 아니면 범위를 전체로 해서 구할 수 있다. 다음으로 전체 합이 0인 경우가 문제인데, 이 경우는 두 개의 구간을 사용하면 해결할 수 있다. 임의의 좌표 i를 기준으로 오른쪽의 합이 k라고 하면 왼쪽은 -k일 것이다. (전체의 합이 0이어야 하므로) 그래서 왼쪽에서 합이 0이 아닌 지점을 찾아서 그 지점을 기준으로 왼쪽, 오른쪽을 나누면 된다.

**코드**

<details>
    <summary>자세히</summary>

[내 코드](https://github.com/mimseong/CodeforcePractice/blob/master/Practice22_200703/A_Lesha_and_array_splitting.cpp)


북님 코드

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
 
using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
 
int main() {
    int n;
    scanf("%d", &n);

    vector<int> psum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &psum[i]);
        psum[i] += psum[i-1];
    }

    if (psum[n] != 0)
    {
        printf("YES\n1\n1 %d", n);
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (psum[i] != 0)
        {
            printf("YES\n2\n%d %d\n%d %d\n", 1, i, i+1, n);
            return 0;
        }
    }
    
    printf("NO\n");
    return 0;
}

```

오! 합을 구하는 부분을 부분합으로 미리 계산해놨다. 생각해보니 기존 배열이 필요 없었네. psum[n]이 전체 합이 될 거거라 psum[n]이 0이 아니면 전체를 답으로 삼고 아니라면 배열 전체를 다 확인하면서 psum 배열이 0이 아닌 값을 찾는다. 찾지 못한다면 이 때는 배열이 전부 0일 때 이므로 NO를 출력한다. 



</details>
