#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double getdouble(){
    double dec;
    printf("Enter number : ");
    scanf("%lf",&dec);
    return dec;}

int checksign(double get){
    char str[300],sign[0];
    sign[0] = '-';
    sprintf(str, "%lf",get);
        if (str[0] == '-' && sign[0] == '-')
            {return 1;}
        else
            {return 0;}}

int binaryint(long inte,int fun){
    int a[200],i,count = 0,check = 0;
    long n;
    n = inte;
    for (i=1;n>0;i++){
        a[i]=n%2;
        n=n/2;
        count=i;}//checkint
        if(fun==1){//printint
            printf("Binary of Number is = ");
            for(i=i-1;i>0;i--)
                { printf("%d",a[i]);}
            printf(".");
            return count;}
        else{//sciencetific
            printf("\nScientific Notation is = ");
            for(i=i-1;i>0;i--)
                {   if(check==0){
                        printf("%d.",a[i]);
                        check = 1;}
                    else
                        printf("%d",a[i]);}
            return i;}}

int binaryfloat(double floa,int pos,int fun){
    int a[200],i,count0 = 0,check = 0;
    double floa1;
    for (i=1;i<(53-pos);i++){
        floa1 = floa*2;
        if(floa1<1)
            a[i] = 0;
        else
            { a[i] = 1;
            floa1 = floa1-1; }
    floa = floa1;}
        if(fun==1){//checkfloat
            for(i=1;i<(53-pos);i++)
            {   if(a[i]==0 && check==0)
                {count0 = count0 + 1 ;}
                else
                {check = 1;}}
        return count0;}
        else if(fun==2){//printfloat+,IEEE754man+
            for(i=1;i<(53-pos);i++)
            { printf("%d",a[i]);}
        return i;}
        else if (fun==3){//printfloat-
            for(i=-pos;i<(53-pos);i++)
            {   if(check == 0)
                    {printf("%d",a[i]);
                    printf(".");
                    check = 1;}
                else
                    printf("%d",a[i]);}
        return i;}
        else//IEEE754man-
            for(i=-pos+1;i<(53-pos);i++)
            { printf("%d",a[i]);}
        return i;}

void ieee754sign(int check){
    if(check==0)
        printf("IEEE754 = 0 ");
    else
        printf("IEEE754 = 1 ");}

int ieee754expo(long inte){
    int a[200],i,count = 0;
    long n;
    n = inte;
    for (i=1;n>0;i++){
        a[i]=n%2; n=n/2; count=i;}
    if (inte<1024)
        {printf("0");}
        for(i=i-1;i>0;i--)
            { printf("%d",a[i]);}
    return count;}

void ieee754man(long inte,double floa,int last){
        int a[200],i;
        long n;
        n = inte;
            for (i=1;n>0;i++){
                a[i]=n%2; n=n/2;}
            printf(" ");
            for(i=i-2;i>0;i--)
        {printf("%d",a[i]);}}

int main() {
    double get,floa,absget;
    long inte;
    int head,expo,check,last;
    printf("--------------------------------------- IEEE754 -------------------------------------------\n");
    get = getdouble();
    check = checksign(get);
    absget = fabs(get);
    inte = absget;
    floa = absget-inte;
    if(inte>=1) {
        head = binaryint(inte,1); //แปลงเป็นฐานสองเฉพาะจำนวนเต็ม และค้นหามีหน้าจุดกี่หลัก
        binaryfloat(floa,head-1,2); //แปลงเป็นฐานสองเฉพาะทศนิยม
            binaryint(inte,2); //แปลงเป็นสัญกรณ์ส่วนจำนวนเต็ม
            binaryfloat(floa,head-1,2); //ตามด้วยเลขฐานสองส่วนทศนิยม
            printf(" * (2^%d)\n",head-1);
        printf("-------------------------------------------------------------------------------------------\n");
            ieee754sign(check); //การแปลงเป็น IEEE754
            expo = 1023+(head-1);
            ieee754expo(expo);
            ieee754man(inte,0,0);
            binaryfloat(floa,head-1,2);
        printf("\n-------------------------------------------------------------------------------------------\n");}
    else {
        binaryint(inte,1); //แปลงเป็นฐานสองเฉพาะจำนวนเต็ม
        binaryfloat(absget,-1,2); //แปลงเป็นฐานสองเฉพาะทศนิยม
        last = binaryfloat(absget,-1,1); //ค้นหามีหลังจุดกี่หลัก
            binaryint(inte,2); //แปลงเป็นสัญกรณ์ส่วนจำนวนเต็ม
            binaryfloat(absget,-last-1,3); //ตามด้วยเลขฐานสองส่วนทศนิยม
            printf(" * (2^%d)\n",-last-1);
        printf("-------------------------------------------------------------------------------------------\n");
            ieee754sign(check); //การแปลงเป็น IEEE754
            if(absget==0)
                printf("00000000000");
            else
                {expo = 1023+(-last-1);
                ieee754expo(expo);}
            ieee754man(inte,0,0);
            binaryfloat(absget,-last-1,4);
        printf("\n-------------------------------------------------------------------------------------------\n");}
    }
