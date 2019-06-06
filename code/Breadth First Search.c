#include<stdio.h>
struct note//创建结构体
{
        int x;
        int y;
        int f;
        int s;
};
int main()
{
        struct note que[2501];//创建队列
        int startx,starty,i,k,n,m,j,p,q,tx,ty,flag;
        int head,tail;
        int a[51][51]={0};//定义数组，读入地图
        int book[51][51]={0};//定义数组，以记录是否走过
        int next[4][2]={{0,1},//右
                        {1,0},//下
                        {0,-1},//左
                        {-1,0}};//上
        printf("请输入该地图的行数和列数\n");
        scanf("%d%d",&n,&m);
        printf("请输入地图，空格用0表示，不可以走的用1表示，输完一个数后用空格空开，输入完一行数后按回车键\n");
        for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                        scanf("%d",&a[i][j]);
        printf("请输入地图的开始位置\n");
        scanf("%d%d",&startx,&starty);
        printf("请输入地图的目标位置\n");
        scanf("%d%d",&p,&q);
        flag=0;//若还没到达目标位置
        head=1;
        tail=1;
        que[tail].x=startx;//初始化队列的第一个位置
        que[tail].y=starty;
        que[tail].s=0;//开始步数为0
        que[tail].f=0;//第一个位置没有上一位置点，以便后面输出时决定结束
        tail++;
        book[startx][starty]=1;//记录位置已经走过
        while(head<tail)
        {
                for(k=0;k<4;k++)//各个方向探索下一位置
                {
                        tx=que[head].x+next[k][0];
                        ty=que[head].y+next[k][1];
                        if(tx<1||tx>n||ty<1||ty>m)//判断是否出界
                                continue;
                        if(a[tx][ty]==0&&book[tx][ty]==0)//判断是否可走，是否已经走过
                        {
                                book[tx][ty]=1;//标记已经走过，避免重复
                                que[tail].x=tx;
                                que[tail].y=ty;
                                que[tail].s=que[head].s+1;//步数加1，从上一位置加1
                                que[tail].f=head;//记录上一位置，以便找出路线
                                tail++;
                        }
                        if(tx==p&&ty==q)//判断是否到达
                        {
                                flag=1;
                                break;//跳出for循环
                        }
                }
                if(flag==1)
                        break;//跳出while循环
                head++;//头指针后移
        }
        printf("最少的步数是  ");
        printf("%d\n",que[tail-1].s);
        tail--;//回到队列的尾部
        head=que[tail].f;
        printf("最短的路线是\n");
        while(head!=0)
        {
                printf("(%d,%d)\n",que[head].x,que[head].y);
                head=que[head].f;//找回上一位置点
        }
        getchar();getchar();
        return 0;
}
