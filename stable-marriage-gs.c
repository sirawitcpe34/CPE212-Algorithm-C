#include <stdio.h>
int couple1[5],couple2[5],out[5],num;
int one[5][5],two[5][5];
int Mone [3][3] = {{2, 1, 3}, {3, 1, 2}, {3, 2, 1}};
int Fone [3][3] = {{3, 1, 2}, {2, 3, 1}, {3, 1, 2}};
int Mtwo [3][3] = {{1, 2, 3}, {3, 1, 2}, {2, 3, 1}};
int Ftwo [3][3] = {{3, 1, 2}, {2, 3, 1}, {1, 2, 3}};
int Mthree [4][4] = {{1, 2, 3, 4}, {1, 4, 3, 2}, {2, 1, 3, 4}, {4, 2, 3, 1}};
int Fthree [4][4] = {{3, 4, 2, 1}, {3, 1, 4, 2}, {2, 4, 3, 1}, {3, 2, 1, 4}};

void menu (int set, int sel)
{
    if(set==1 && sel==0)
    { num = 3; for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            {one[i][j] = Mone[i][j];
            two[i][j] = Fone[i][j];}
    }
    if(set==1 && sel==1)
    { num = 3; for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            {one[i][j] = Fone[i][j]; two[i][j] = Mone[i][j];}
    }
    if(set==2 && sel==0)
    { num = 3; for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            {one[i][j] = Mtwo[i][j]; two[i][j] = Ftwo[i][j];}
    }
    if(set==2 && sel==1)
    { num = 3; for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            {one[i][j] = Ftwo[i][j]; two[i][j] = Mtwo[i][j];}
    }
    if(set==3 && sel==0)
    { num = 4; for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            {one[i][j] = Mthree[i][j]; two[i][j] = Fthree[i][j];}
    }
    if(set==3 && sel==1)
    { num = 4; for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            {one[i][j] = Fthree[i][j]; two[i][j] = Mthree[i][j];}
    }
}

void stablemarriage (int num) {
    int temp[5],pos[5], max = 1;
    int single = num;
    for(int i=0; i<num; i++)
        {couple1[i] = 0;
        couple2[i] = 0;}
    while(single>0)
    {
        for (int i=0; i<num; i++)
        {   for (int j=0; j<num && couple1[i]==0; j++)
            {
                //printf("Mone[%d][%d] = %d\n",i,j,one[i][j]);
                if(one[i][j] == max && couple2[j] == 0)
                    {
                    couple1[i] = 1;
                    couple2[j] = 1;
                    out[i] = j;
                        //printf("%d %d\n",i,j);
                    pos[j] = i;
                    temp[j] = two[j][i];
                    single = single - 1;
                    }
                else if (one[i][j] == max && couple2[j] == 1)
                    {
                    if(two[j][i] < temp[j])
                        {
                        couple1[pos[j]] = 0;
                        couple1[i] = 1;
                        out[i] = j;
                            //printf("%d %d\n",i,j);
                        pos[j] = i;
                        temp[j] = two[j][i];
                        }
                    else
                        {
                        max = max + 1;
                        j = -1;
                        //printf("Max = %d\n",max);
                        }
                    }
            } max = 1;
            //printf("Max = %d\n",max);
        }
    }
}

int main() {
    int set,sel;
    scanf("%d",&set);
    scanf("%d",&sel);
    menu(set,sel);
    stablemarriage(num);
    //for(int i=0;i<num;i++)
    //{
         //printf("(%d,%d)\n",i,out[i]);
    //}
    if(sel == 1)
    {
    for (int i=0; i<num; i++)
        for (int j=0; j<num; j++)
            if (i == out[j])
            printf("%d-%d\n",out[j],j+num);
    }
    else
    {
    for (int i=num; i<num+num; i++)
        for (int j=0; j<num; j++)
            if (i == out[j]+num)
            printf("%d-%d\n",out[j]+num,j);
    }
}
