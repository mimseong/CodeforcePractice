# 2020 / 07 / 03 (금) 코드포스 연습문제

## 후기

처음으로 0 솔브를 했다. 오랜만에 풀어서 감이 떨어졌는지 아니면 그냥 낯선 문제만 만났는지. 시간은 20분 기준으로 잘 넘겼는데 풀지를 못해ㅋㅋㅋ 문제 만났는데 어떻게 풀지 몰라서 다 넘겼다ㅠ 다시 돌아와도 해결 못했다ㅠ

## A. Lesha and array splitting

![image](https://user-images.githubusercontent.com/50068946/86440868-330be780-bd46-11ea-9308-3b329f42033b.png)

주어진 배열을 sub배열로 나누는데 sub배열의 합이 0이 되면 안 된다. 전체 0인 경우는 NO를 출력하면 된다는 걸 알겠는데 그 다음을 어떻게 해야할지 몰라서 해맸다. 이걸 하나씩 출력하려고 했는데 그럼 중간에 0이 있으면 또 단위를 크게 해서 묶어줘야 하고. 0이 아니게 묶어주는 기준을 못 찾아서 결국 못 풀었다. 


이 문제는 일단 전체 합이 0이 아니면 범위를 전체로 해서 구할 수 있다. 다음으로 전체 합이 0인 경우가 문제인데, 이 경우는 두 개의 구간을 사용하면 해결할 수 있다. 임의의 좌표 i를 기준으로 오른쪽의 합이 k라고 하면 왼쪽은 -k일 것이다. (전체의 합이 0이어야 하므로) 그래서 왼쪽에서 합이 0이 아닌 지점을 찾아서 그 지점을 기준으로 왼쪽, 오른쪽을 나누면 된다.

**코드**

<details>
    <summary>코드 보기</summary>

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

## B. Chat Online


![image](https://user-images.githubusercontent.com/50068946/86460299-1a5dfa80-bd63-11ea-9cc4-b22eade22f35.png)

아니 왜!! 안 풀리지!!! 싶었는데 그냥 내가 예시를 잘 못 생각해서 문제였다. a, b가 2-3이고 c, d가 0-1이라 t가 2, 3이어야 한다고 생각했다. 그래서 답이 2인데 왜 3이지 계속 생각하다가 패스.. 


이 문제는 가능한 모든 t의 개수를 구해야 해서 복잡했다. 그런데 값이 50이 최대이다? 그래서 그냥 다 구했음. l부터 r까지 범위가 1000이라 1000번 확인하고 구간 50개 * 50개 확인하면 최대 2,500,000번 반복문을 돈다. 1초에 1~2억번까지 루프를 돌 수 있으므로 시간 내에 돌아간다. 


<details>
    <summary>코드 보기</summary>

[내 코드](https://github.com/mimseong/CodeforcePractice/blob/master/Practice22_200703/B_Chat_Online.cpp)

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
    int p, q, l, r;
    scanf("%d %d %d %d", &p, &q, &l, &r);
 
    vector<ii> a(p);
    vector<ii> c(q);
 
    for (int i = 0; i < p; i++)
        scanf("%d %d", &a[i].xx, &a[i].yy);
    for (int i = 0; i < q; i++)
        scanf("%d %d", &c[i].xx, &c[i].yy);
 
    int count = 0;
    for (int i = l ; i <= r; i++)
    {
        bool is_find = false;
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < q; k++)
            {
                if (a[j].xx <= (c[k].yy + i) && (c[k].yy + i) <= a[j].yy)
                {
                    is_find = true;
                    break;
                }
                else if (a[j].xx <= (c[k].xx + i) && (c[k].xx + i) <= a[j].yy)
                {
                    is_find = true;
                    break;
                }
            }
            if (is_find)
            {
                count++;
                break;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}
```

처음 작성한 코드이다. l부터 r까지 확인하면서 a와 c의 범위가 겹치는지 확인했다. 

![image](https://user-images.githubusercontent.com/50068946/86467758-f3a6c080-bd70-11ea-825e-db820ccdc4bc.png)

위 사진처럼 겹치는 부분을 확인했는데 틀렸다.. 오만 범위 테스트 했는데 도저히 모르겠어서 북님에게 물어봤더니 c가 a를 포함하는 범위를 빼먹었다고(!) 알려줬다.

```
else if ((c[k].xx + i) <= a[j].xx && a[j].yy <= (c[k].yy + i))
{
    is_find = true;
    break;
}
```

그래서 c가 a를 확인하는 부분을 추가했고 통과했다! 그리고 이렇게 범위 확인하는 부분은 조건을 아래와 같이 하면 편하다고 추천 받았다. 

```
if (max(a[j].xx, (c[k].xx + i)) <= min(a[j].yy, (c[k].yy + i)))
{
    is_find = true;
    break;
}
```

</details>


## C. Alice, Bob, Two Teams

![image](https://user-images.githubusercontent.com/50068946/86528406-65524c00-bee2-11ea-852a-453e949788b4.png)

구해야 하는 값이 연속적으로 있어서 구간합이나 투포인터가 떠오르긴 했는데 구간합은 시작과 끝을 정하는 부분이 많아서 패스하고 투포인터는 l, r이 움직이는 기준을 잡기 어려워서 포기했다. 시간 촉박한 와중에 투포인터 ppt도 봤는데 거기서도 투포인터는 주로 구간의 길이를 구한다고 했고 최댓값을 구하는 데 적합하지 않아서 패스했음.


이 문제도 내가 잘못 이해했다. 여기서 prefix랑 suffix란 용어가 나왔는데 이걸 찾아보니 접두사 접미사였다. 그래서 구간을 선택하면 그 구간의 처음과 끝을 바꾸는 건가 싶었는데 예시를 보니 아니었다. 도저히 어떤 값인지 알 수 없어서 패스하고 풀기 시작했는데 알고보니 prefix가 문자열의 처음부터 특정 위치까지의 문자열을 뜻하는 것 같았다. suffix는 반대로 특정 위치에서 맨 끝까지의 문자열이다. 이러면 이제 부분합 쓸 수 있겠다. 미리 점수 합 구한 다음 최댓값은 처음부터 끝까지 훑으면서 찾으면 되겠다.

![image](https://user-images.githubusercontent.com/50068946/86528466-03461680-bee3-11ea-83b8-5418fa906170.png)

점수의 변화량을 담는 배열을 만들어두고 그 변화량 중 가장 큰 값을 저장한다. 가장 큰 변화량과 기존의 값을 더한 값과 기존의 값 두 개를 비교해서 (변하지 않았을 때 값이 더 클 수 있으므로) 큰 값을 출력하면 된다. 

**코드**

<details>
    <summary>코드 보기</summary>

[내 코드](https://github.com/mimseong/CodeforcePractice/blob/master/Practice22_200703/C_Alice_Bob_Two_Teams.cpp)

북님 코드

![image](https://user-images.githubusercontent.com/50068946/86528793-608f9700-bee6-11ea-8cfd-fdfea4262dca.png)

나는 값의 변화량을 저장했는데 a, b값을 따로 저장했다. 뒤집는 걸 a 점수의 합이라 생각할 수 있구나. 신기하다.

```
int main() {
    int n;
    scanf("%d", &n);
    
    vector<i64> a(n+1);
    vector<i64> b(n+1);

    vector<int> p(n+1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i+1] = a[i];
        b[i+1] = b[i];

        if (s[i] == 'A')
            a[i+1] += p[i+1];
        else
            b[i+1] += p[i+1];
    }

    i64 ans = b[n];

    for (int i = 1; i <= n; i++)
        ans = max({ans, a[i] + b[n] - b[i], b[i] + a[n] - a[i]});
    
    printf("%lld\n", ans);
    return 0;
}
```


</details>


## E. Restaurant

![image](https://user-images.githubusercontent.com/50068946/86511964-b4dc3d80-be38-11ea-83d7-9b91e012f65a.png)

운영체제 스케줄링이 먼저 생각났지만 그리디 문제였다. 그리디는 왜이리 어렵지? 다른 기법들에 비해 많이 안 접해봐서 너무 낯설고 증명도 어렵다. 처음에는 먼저 도착한 순으로 처리를 하되, 시간이 많이 걸리지 않는 것부터 처리하려 했다. 하지만 9-25, 10-11, 12-13 같은 경우에 9-25를 먼저 처리하게 되면 하나 밖에 수행하지 못한다. 이 경우에는 끝나는 시점 순서대로 순서를 세면 해결할 수 있다. 






