#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main() {
    //問題作成フラグ
    bool game=true;

    int tryCount = 0;

    while (game)
    {
        game = false;
   
    int t = (int)time(nullptr);

    int answer = t % 10;

    printf("数あてゲーム\n");
    printf("数字を入力してね\n");
    printf("\n");
    //printf("%d\n", answer);

    //回答受付フラグ
    bool number = true;

    int onemore = 0;

    //正解まで繰り返す
    while (number)
    {
        int input;

        //入力
        scanf_s("%d", &input);

        int rank = 0;


        if (answer == input)
        {
            rank = 2;
            printf("一致！\n");
        }
        else if (answer < input) {
            printf("大きい！\n");
        }
        else if (answer > input) {
            printf("小さい！\n");
        }

        // まずは answer と input の数値の差を計算する
        int sub = answer - input;

        // 「マイナス3より大きく」「且つ」「プラス３より小さい」
        if (sub > -3 && sub < 3 && answer != input)
        {
            rank = 1;
            printf("惜しい！\n");
        }
        switch (rank)
        {
        case 2:
            printf("ランクS\n");

            tryCount += 1;

            printf("\n");

            printf("もう一度遊ぶ場合は１を入力\n");
            printf("終了する場合はほかのキーを入力\n");
            scanf_s("%d", &input);
            printf("\n");
            //コンティニュー"１"、終了"その他"
            if (input == 1) 
            {
                game = true;
                number = false;
            }
            else
            {
                number = false;
            }
            break;

        case 1:
            printf("ランクA\n");

            printf("\n");

            break;
        default:
            printf("ランクB\n");

            printf("\n");

            break;
            }

        }
    }

    printf("正解数%d", tryCount);
    printf("\n");
    printf("ゲーム終了！\n");
    printf("\n");
}