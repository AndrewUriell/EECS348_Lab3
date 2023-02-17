#include <stdio.h>

void possibleScores(int TD_2, int TD_FG, int TD, int FG, int safety) 
{
    printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d FG, %d Safety\n", TD_2, TD_FG, TD, FG, safety);
}

int main() 
{
    int score = -1;

    while (score > 1 || score == -1) 
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score == 1 || score == 0) 
        {
            break;
        }
        
        if (score < 0) 
        {
            printf("Invalid Score");
            break;
        }

        printf("Possible combinations of scoring plays:\n");

        for (int TD_2 = 0; TD_2 <= score/8; TD_2++) 
        {
            for (int TD_FG = 0; TD_FG <= score/7; TD_FG++)
            {
                for (int TD = 0; TD <= 6; TD++)
                {
                    for (int FG = 0; FG <= score/3; FG++)
                    {
                        for (int safety = 0; safety <= score/2; safety++) 
                        {
                            if ((TD_2*8 + TD_FG*7 + TD*6 + FG*3 + safety*2) == score) 
                            {
                                possibleScores(TD_2, TD_FG, TD, FG, safety);
                            }
                        }
                    } 
                }
            }
        }
    }

    return 0;
}
