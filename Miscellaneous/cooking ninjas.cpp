#include<bits/stdc++.h>
using namespace std;
int minCookTime(vector<int> &rank, int m)
{
    int minTime, duration = 1;
    // Run loop till we don't find minimum time required to complete order of 'm' dishes.
    while (true)
    {
        int dishCooked = 0;

        // Calculate total number of dishes prepared in that duration by 'N' cooks.
        for (int i = 0; i < rank.size(); i++)
        {
            int timeRemain = duration, dishCount = 0;

            // Calculate number of dishes prepared by 'ith' cook.
            while (timeRemain > 0)
            {
                timeRemain -= (dishCount + 1) * rank[i];
                if (timeRemain >= 0)
                {
                    dishCount++;
                }
            }

            dishCooked += dishCount;
        }

        // Check whether order of 'm' dishes can be completed in this duration or not.
        if (dishCooked >= m)
        {
            minTime = duration;
            break;
        }

        duration++;
    }

    return minTime;
}

int main()
{

    return 0;
}