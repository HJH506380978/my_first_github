#include<stdio.h>
struct note//创建结构体
{
        int a;
        int b;
};
int a[51][51];//创建数组，存储地图
int n,m,i,j,flag;
int head,tail,sum;
struct note que[2501];//创建队列
void dfs(int x,int y)//定义函数，深度搜索
{
        int next[4][2]={{0,1},//定义方向数组
                        {1,0},
                        {0,-1},
                        {-1,0}};
        int tx,ty,k;
        if(flag==sum-1)//判断是否已经走完全地图
        {
                while(head<tail)//判断队列是否全部输出
                {
                        //printf("(%d,%d)",que[head].a,que[head].b);
                        if(que[head].b-que[head-1].b==1)//判断往哪里走
                                printf("右");
                        if(que[head].b-que[head-1].b==-1)
                                printf("左");
                        if(que[head].a-que[head-1].a==1)
                                printf("下");
                        if(que[head].a-que[head-1].a==-1)
                                printf("上");
                        head++;
                }
        }
        for(k=0;k<4;k++)//每个方向探索一次
        {
                tx=x+next[k][0];
                ty=y+next[k][1];
                if(tx>n||tx<1||ty>m||ty<1)//判断是否出界
                        continue;
                if(a[tx][ty]==0)//判断是否可走
                {
                        a[tx][ty]=1;//标志已走
                        flag++;//走过的步数加一
                        que[tail].a=tx;//用队列存储探索的路径
                        que[tail].b=ty;
                        tail++;//当前位置后移
                        dfs(tx,ty);//进行下一步探索
                        a[tx][ty]=0;//取消标志已走
                        flag--;//走过的步数减一
                        tail--;//指针位置指回当前的
                }
        }
        return;
}
int main()
{
        int startx,starty;
        printf("");
        printf("请输入你初始的位置坐标\n");
        scanf("%d%d",&startx,&starty);
        printf("请输入该地图的行数和列数\n");
        scanf("%d%d",&n,&m);
        printf("请输入地图，可以走的用0表示，不可以走的用1表示，出发点也用0表示\n");
        printf("输入时，输完一个数字后用空格隔开，输入完一行后按回车键\n");
        for(i=1;i<=n;i++)//读入地图
                for(j=1;j<=m;j++)
                        {
                                scanf("%d",&a[i][j]);
                                if(a[i][j]==0)
                                        sum++;
                        }
        a[startx][starty]=1;
        que[head].a=startx;
        que[head].b=starty;
        head++;
        tail++;
        dfs(startx,starty);
        return 0;
}
