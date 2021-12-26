/******************************************************************************
卡片
递归 ：
4.3 例题 ：小游戏（POJ 2802）

问题描述：你决定编写一个小游戏,游戏在一个分割成w x h 个正方形格子的矩形板上进行
每个正方形格子上可以有一张游戏卡片，当然也可以没有，当下面情况满足时候
认为两个游戏卡片之间有一条路径相连：路径只包含水平或者竖直线段，路径不能穿过游戏卡片
只允许路径临时离开矩形板：

输入数据：输入包含多组数据，一个矩形板对应一组数据，每组数据的第一行包含两个整数，w 和 h
         w h f分别表示矩形板长和宽，下面的h 行，每行包括w字符，表示矩形板板上游戏卡片分布情况
         使用X表示某个地方某个游戏卡片，使用空格表示某个地方没有游戏卡片
         
         之后若干行 每行包括4 个整数 x1 x2 y1 y2        给出两个卡片在矩形板上的位置
         主义矩形左上角坐标是（1，1）输入保证这两个游戏卡片所处的位置不同，如果一个行上有4 个 2802
         表示这组测试数据结束，如果一个行给出的 w = h = 0 那么表示输入结束
         
         
输出数据：
        对每一个矩形板，输出一行 Board #n ，这里n是输入数据的编号，任何每个一个组需要测试的游戏卡片输出每一行
        这一行开头是 Pair m,z这里m是测试卡片的编号，这里的m是测试卡片的编号
        （对于每个矩形板 编号都的从1开始）接下来可以相连，找到连接这两个卡片所有路径中包含线段最少的路径，
        输出 k segments
        这里 k 是找到最优路径中包含线段的数目
        如果不能相连 则输出 impossible
    

输入示例： 5        4
            XXXXXX
          X         X
          XXX      X    
                XXX
        2 3 5 3
        1 3 4 4
        2 3 3 4
        0 0 0 0 
        0 0 

输出示例：
    Board #1:
    Pair1:4 segments 
    Pair2:3 segments
    Pair3:impossible


----------------------------------------------------
解题思路：
    
    迷宫求解问题，自相似性表现在每走一步的探测方式相同， 因此可以用递归方法求解
    通过穷举方法找到从起点到终点的方法：朝一个方向走下去，如果走不通 就换一个方向走
    四个方向都走不通 则回到上一步的地方，再换一个方向走，依次走下去
    如果上一步先走的方向相同
    递归搜索路径数不变， 否则路径数加1
    
    另外根据题意：路径只包含水平或者竖直的线段，路径不能穿过别的游戏卡片，但是允许路径临时离开矩形板
    所有可以在矩形板最外层加一圈格子，路径可以通过这些新增加的格子
    
    可以设置一个二维数组来表示迷宫，空格表示无游戏卡片，X表示有游戏卡片，用另一个二维数组来标记每个位置格子已经变了
*******************************************************************************/

// example 43

#include <iostream>
#include <cstring>
using namespace std;

#define MAXIN 75
char board[MAXIN + 2][MAXIN + 2]; //定义矩形板
int minStep,w,h,to[4][2] ={ {0,1},{1,0},{0,-1},{-1,0}};
//定义方向
bool mark[MAXIN + 2][MAXIN + 2] ;//定义标志数组

void Search(int  currentX,int currentY,int endX,int endY,int step,int f){
    //当前路径数大于minstep 返回优化策略
    if(step > minStep)return;
    if(currentX == endX && currentY == endY) {
        //到达终点
        if(minStep >step){
            minStep = step;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int x = currentX+ to[i][0];
            //得到新的位置
            int y = currentY + to[i][1];
            //如果新的位置有效
            
            if((x > -1)&&(x < w + 2)&&(y > -1)&&(y < h +2)&&
                (((board[y][x] == ' ')&&(mark[y][x] == false))||
                ((x == endX)&&(y == endY)&&(board[y][x] == 'X'))))
                {
                    mark[y][x] = true ;//标记该位置已经经过
                    // 上一步方向和当前方向相同
                    // 则递归搜索时step不变，否则step +1 
                    if(f==i)Search(x,y,endX,endY,step,i);
                        else Search(x,y,endX,endY,step+1,i);
                        mark[y][x] = false ;
                        //回溯 ： 该位置未曾走过
                    }
                }
        }
    }


int main()
{
    int boardNum = 0;
    while (std::cin >> w>>h){
        if(w==0 && h == 0) break;
        boardNum ++;
        
        std::cout << "Board #" << boardNum <<":" << std::endl;
        int i,j;
        
        for(i =0 ; i <MAXIN +2;i ++)
            board[0][i]=board[i][0]=' ';
            
        for ( i=0;i <MAXIN + 2;i++) {
            getchar();
            for(j=1;j<=w;j++)
            board[i][j] =getchar();
        }
        
        //所有可以在矩形板最外层加一圈格子
        for(i = 0;i<=w ;i++)
            board[h+1][i+1]=' ';
        for (int i = 0; i <= h; i++) {
            /* code */
            board[h + 1][i + 1] = ' ';
        for (int i = 0; i <= h; i++) {
             board[i + 1][w + 1] = ' ';           
        }
        int startX,startY,endX,endY,count = 0;
        while((cin>>startX>>startY>>endX>>endY)&&startX>0){
            count ++ ;
            minStep = 100000 ; //初始化minstep为一个很大的值
           memset(mark,false,sizeof(mark));
            // 递归搜索
            Search(startX,startY,endY,endX,0,-1);
            // 输出结果
            if(minStep < 100000)
                cout <<"Pair"<<count<<" : "<<minStep<<" segments "<<endl;
            else
                std::cout << "Pair"<< count << " : impossible " << std::endl;    
        }
            cout << endl;
        }
        return 0;
        
    }
}    


    







