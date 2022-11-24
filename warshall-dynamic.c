#include <stdio.h>
int in[10000];
int warshall[10000][10000];

void input (int number, int total) {
    
    for (int i=0; i<number; i++) {
        for (int j=0; j<number; j++) {
            warshall[i][j] = 0;}}
    
    for (int i=0; i<number; i++) {
        for (int j=0; j<number; j++) {
            for (int k=0; k<total; k++) {
                int sum = ((number*(i+1))-(number-(j+1)));
                //printf("%d %d\n",in[k],sum);
                if(in[k] == sum)
                    {warshall[i][j] = 1;}}
            printf("%d ",warshall[i][j]);}
        printf("\n");}
    printf("\n");
}

void print (int number,int k){
    for (int i=0; i<number; i++) {
        for (int j=0; j<number; j++) {
            printf("%d ",warshall[i][j]);}
        printf("\n");}
    if(k!=number-1)
        printf("\n");
}

void warshallalgo (int number){
    for (int k=0; k<number; k++) {
        for (int i=0; i<number; i++) {
            for (int j=0; j<number; j++) {
                int result = warshall[i][k] + warshall[k][j];
                if(result == 2)
                    {warshall[i][j] = 1;}
            }
        } print(number,k);
    }
}

int main() {
    int number = 0, total = 0, i = -1;
    //printf("Enter Square Metrix : ");
    scanf("%d",&number);
    do
    {
        i = i+1;
        scanf("%d",&in[i]);
        total = i;
    } while (in[i]!=0);
    input(number,total);
    warshallalgo(number);
}
