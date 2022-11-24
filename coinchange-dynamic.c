#include <stdio.h>
int coin[51000];

void input (int coinsum)
{
    for(int i=0 ; i<coinsum ; i++)
        {
        //printf("Enter COIN [%d] : ",i);
        scanf("%d",&coin[i]);
        }
}

void coinchange (int number, int coinsum)
{
    int min[number+1];
    min[0] = 0;
    int out[number+1];
    out[0] = 0;
    
    int i,j;
    for(j=1; j<=number; j++)
    {
        int minimum = 51000;
        int total = 0;
        for(i=0; i<=coinsum; i++)
        {
            //printf("[%d][%d] : %d",coin[i],j,1+min[j-coin[i]]);
            //printf("\n");
            if(j >= coin[i])
            {
                //printf("%d : %d",j,1+min[j-coin[i]]);
                //printf("\n");
            if((1+min[j-coin[i]]) <= minimum)
                {
                minimum = 1+min[j-coin[i]];
                    //printf("%d\n",minimum);
                total = i;
                }
            }
        }
        min[j] = minimum;
        out[j] = total;
    }
    
    int l = number;
    int result;
    int count[51000] ;
    for(int i=0; i<=coinsum; i++)
    {count[i] = 0;}
    while(l > 0)
        {
        result = coin[out[l]];
            //printf("%d\n",result);
        l = l-coin[out[l]];
            for (int i=0; i<=coinsum; i++)
                {
                    //printf("\n%d ",coin[i]);
                    if(result == coin[i])
                    count[i] = count[i] + 1;
                }
        }
    
    for (int i=0; i<=coinsum; i++)
    {
        printf("%d: %d\n",coin[i],count[i]);
    }
}

int main() {
    int number = 0, coinsum = 0;
    //printf("---Coin Change---\n");
    //printf("Enter BAHT: ");
    scanf("%d",&number);
    //printf("Enter COIN: ");
    scanf("%d",&coinsum);
    input(coinsum);
    coinchange(number, coinsum-1);
    return 0;
}
