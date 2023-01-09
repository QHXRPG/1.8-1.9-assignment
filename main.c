#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 100
#define STR "hello world"
#define MAX(x,y) (x>y?x:y)

typedef unsigned int uint;

struct student
{
    char name[20];
    int age;
    char id[15];
    float score;
}student;

//针对每行输入，输出两个整数及其大小关系
void com(int a,int b)
{
    while(scanf("%d %d",&a,&b)!=EOF)  //重点
    {
        if(a>b)
        {
            printf("%d>%d\n",a,b);
        }
        else if(a==b)
        {
            printf("%d=%d\n",a,b);
        }
        else
        {
            printf("%d<%d\n",a,b);
        }
    }
}

void test1()
{
    int a=1;
    printf("%d\n",a);
    a++;
    
    static int b=1;  //静态变量存放在全局区，一次赋值定义之后不会再赋值定义，影响了变量的作用域
    printf("%d\n",b);
    b++;
    
    extern int c;  //只能使用其他文件的全局变量 (外部声明)
    printf("%d\n",c);
}

extern int add(int,int);  //也可以使用其他文件的子函数

void test2()
{
    int a=10;
    int *q=&a; //int:q指向的对象是int类型
    char *c;
    int *cc;
    float *ccc;
    printf("%d,%d,%d\n",sizeof(c),sizeof(cc),sizeof(ccc)); //ARM的指针是8个字节
    printf("%p\n",q);  //a的地址 0x16fdff20c
    printf("%d\n",*q); //解引用
    
    *q = 100;  //通过这个指针找到a的地址上的内容并对其进行更改
    printf("%d\n",a);
}

void test3()
{
    struct student s2={"qwe",12,"234234",234.1};
    struct student *p=&s2;
    printf("%s\n",s2.name);
    printf("%s,%f,%d,%s\n",p->name,p->score,p->age,p->id);
}

//打印3的倍数的数
void beishu3()
{
    int y=0;
    for(y=1;y<100;y++)
    {
        if(y%3==0)
        {
            printf("%d ",y);
        }
    }
    printf("\n");
}

//写代码将三个整数数按从大到小输出。
void paixu3(int x, int y, int z)
{
    if(x>y&&x>z&&y>z)
    {
        printf("%d %d %d",x,y,z);
    }
    else if (x>y&&x>z&&y<z)
    {
        printf("%d %d %d",x,z,y);
    }
    else if(y>x&&y>z&&x>z)
    {
        printf("%d %d %d",y,x,z);
    }
    else if(y>x&&y>z&&z>x)
    {
        printf("%d %d %d",y,z,x);
    }
    else if(z>x&&z>y&&y>x)
    {
        printf("%d %d %d",z,y,x);
    }
    else if(z>x&&z>y&&x>y)
    {
        printf("%d %d %d",y,x,y);
    }
    printf("\n");
}

//打印100~200之间的素数
void sushu100_200()
{
    int temp=0;
    for(int i=100;i<200;i++)
    {
        for(int j=2;j<i-1;j++)
        {
            if(i%j==0)
            {
                temp=1;
                break;
            }
        }
        if(temp==0)
        {
            printf("%d ",i);
        }
        temp=0;
    }
    printf("\n");
}

//打印1000年到2000年之间的闰年
void runnian1000_2000()
{
    for(int i=1000;i<2001;i++)
    {
        if(i%4==0)
        {
            printf("%d ",i);
        }
    }
}

//最大公约数
void Greatest_common_divisor(int x, int y)
{
    int temp=0;
    for(int i=0;i<(x+1)&&i<(y+1);i++)
    {
        if(x%i==0&&y%i==0)
        {
            temp = i;
        }
    }
    printf("%d\n",temp);
}

//乘法口诀表
void chengfabiao()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<i+1;j++)
        {
            printf("%dx%d=%d  ",i,j,i*j);
        }
        printf("\n");
    }
}

//随机数生成器
int suijishu()
{
    srand((unsigned int)time(NULL));
    int a=rand()%100+1;
    printf("%d\n",a);
    return a;
}

//求10个整数中最大值
int max_10(char k[])
{
    int temp;
    int l = sizeof(k);
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(k[j]>=k[i])
            {
                temp=k[j];
                k[j]=k[i];
                k[i]=temp;
            }
        }
    }
    return k[9];
}

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
void fenshuqiuhe()
{
    int sum=0;
    int flag=0;
    for(int i=1;i<101;i++)
    {
        if(flag==0)
        {
            sum+=(1/i);
            flag=1;
        }
        else if(flag==1)
        {
            sum+=-(1/i);
            flag=0;
        }
    }
    printf("%d\n",sum);
}

//数一下 1到 100 的所有整数中出现多少个数字9
void shugeshu_9()
{
    int num=0;
    for(int i=1;i<100;i++)
    {
        if((i-9)%10==0||((i-90)<10&&(i-90)>0))
        {
            num++;
        }
    }
    printf("%d\n",num);
}

//猜数字游戏
void game_caishuzi()
{
    int flag;
    int num;
    int guess;
    while(1)
    {
        printf("猜数字游戏，开始游戏请按1，退出游戏请按任意键:  ");
        scanf("%d",&flag);
        if(flag==1)
        {
        a:
            num = suijishu();
            while(1)
            {
                printf("1-100随机数已生存，请猜数字:  ");
            c:
                scanf("%d",&guess);
                if(guess==num)
                {
                    printf("恭喜你，猜对了！按1继续游戏，任意键提出游戏:   ");
                    scanf("%d",&flag);
                    if(flag==1)
                    {
                        goto a;
                    }
                    else
                    {
                        goto b;
                    }
                }
                if(guess>num)
                {
                    printf("数字过大，请重新输入:  ");
                    goto c;
                }
                else
                {
                    printf("数字过小，请重新输入:  ");
                    goto c;
                }
            }
        }
        else
        {
        b:
            break;
        }
    }
}

//二分查找,编写代码在一个整形有序数组中查找具体的某个数
int erfenchazhao(char k[])
{
    int num;
    printf("输入你要查找的数字：  ");
    scanf("%d",&num);
    int right = sizeof(k)-1;
    int left = 0;
    int mid = left+(right-left)/2;
    while(left+1<right)
    {
        mid = left+(right-left)/2;
        if(k[mid]==num)
        {
            return mid;
        }
        else if(k[mid]>num)
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }
    printf("对不起，找不到");
    return -1;
}

int main()
{
    char k[]={1,3,5,7,9,10,13,23};
    int num =erfenchazhao(k);
    printf("%d\n",num);
}
