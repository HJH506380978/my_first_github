#include<stdio.h>
int n,m,p,q,min=99999999;//定义全局变量，若无说明则默认为0
int a[51][51],book[51][51];
void dfs(int x,int y,int step)//定义子函数，深度优先搜索
{
        int next[4][2]={{0,1},
                        {1,0},
                        {0,-1},
                        {-1,0}};//定义向右下左上反向走
        int tx,ty,k;//定义变量，为探索下一步走法的变量
        if(x==p&&y==q)//判断是否走到所求的目标点
        {
                if(step<min)//若目前方法步数比之前所走的小
                        min=step;//替换最小步数
                return;//返回所得的最小值
        }
        for(k=0;k<=3;k++)//用循环探索向各个反向的可能
        {
                tx=x+next[k][0];//向上下方向的探索
                ty=y+next[k][1];//向左右反向的探索
                if(tx<1||tx>n||ty<1||ty>m)//判断是否出界
                        continue;//若出界，则跳出这次循环
                if(a[tx][ty]==0&&book[tx][ty]==0)//判断是否可走
                {
                        book[tx][ty]=1;//标记已经走过
                        dfs(tx,ty,step+1);//调用自身函数，为下一可能继续探索
                        book[tx][ty]=0;//探索完后清除已走记录
                }
        }
        return;
}
int main()
{
        int i,j,startx,starty;
        printf("请输入该地图有多少排，多少列\n");
        scanf("%d%d",&n,&m);
        printf("请输入该地图，可走的用0表示，有障碍物的用1表示，请一排一排的输入，数完一个数后用空格空开\n");
        for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                        scanf("%d",&a[i][j]);
        printf("请输入一开始所在的位置\n");
        scanf("%d%d",&startx,&starty);
        printf("请输入所要到达的目标地点\n");
        scanf("%d%d",&p,&q);
        book[startx][starty]=1;
        dfs(startx,starty,0);
        printf("到达目标所需最少步数为%d步\n",min);
        getchar();getchar();
        return 0;
}
