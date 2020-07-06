# 2020 / 07 / 04 (토) 코드포스 연습문제

## A. Board Moves

![image](https://user-images.githubusercontent.com/50068946/86549158-d09b2d00-bf79-11ea-8d57-0176e4234f86.png)

A번 문제 이해를 못해가지고 틀렸다. 칸에 있는 걸 움직여서 하나의 칸에 몰아주는 건 알겠는데 난 이동횟수만 계산해서 n^2-1인 줄 알았음. 알고보니 칸이 다른 칸으로 가는 최종 목적지와의 거리를 구해야 했다. 

![image](https://user-images.githubusercontent.com/50068946/86549634-1efcfb80-bf7b-11ea-9eb1-ebdd4ad69404.png)

최소 횟수는 중간에 값을 모으면 구할 수 있다. 중간 상자를 기준으로 한 칸 떨어져 있는 상자의 이동횟수 두 칸 떨어져 있는 상자의 개수.. 이렇게 개수를 계산해서 이동 횟수를 더해주면 답이 나온다. 

**코드**

<details>
    <summary>코드 보기</summary>

[내 코드](https://github.com/mimseong/CodeforcePractice/blob/master/Round80_200704/A_Board_Moves.cpp)


</details>

## B. Buying Shovels

![image](https://user-images.githubusercontent.com/50068946/86550087-6768e900-bf7c-11ea-85c2-4c9db6f223ce.png)

package를 하나만 고를 수 있으므로 n의 약수 package를 선택해야 하고 최소 개수 여야 하므로 약수 중 package값이 가장 큰 걸 선택해야 한다. 

**코드**

<details>
    <summary>코드 보기</summary>

[내 코드](https://github.com/mimseong/CodeforcePractice/blob/master/Round80_200704/B_Buying_Shovels.cpp)


</details>

## C. Little Dima and Equation

![image](https://user-images.githubusercontent.com/50068946/86550688-093d0580-bf7e-11ea-94c2-d3c8c4b8415e.png)

x의 범위는 1부터 10^9사이의 값이라 확인하기 어렵지만 s(x)값은 1부터 81까지의 수밖에 나오지 않는다. s(x)값을 전부 확인하면서 이 때의 x값을 다시 만들어보고 x와 b x s(x)^a + c의 값이 일치하는 지 확인한다. 

대회 중 이 문제를 많이 틀렸고 원인을 못 찾았는데 알고보니 최댓값인 10^9를 10e^9라 표현해서 문제였다. e^9가 10^9과 같은데 여기에 10을 곱해서 10^10이 되었다. 앞으로 주의해서 풀어봐야겠다. 

**코드**

<details>
    <summary>코드 보기</summary>

[내 코드](https://github.com/mimseong/CodeforcePractice/blob/master/Round80_200704/C_Little_Dima_and_Equation.cpp)


</details>