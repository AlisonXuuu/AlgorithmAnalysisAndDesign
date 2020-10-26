#include <stdio.h>    
int board[65][65],tile=0; //tile 为骨牌编号  
void chessboard(int tr,int tc,int dr,int dc,int size){  
     int t,s;  
     if (size==1)  
     return ;  //递归边界 
     t=tile++;  //L型骨牌编号 
     s=size/2;  //分割棋盘
	 
//覆盖左上角子棋盘 
     if(tr+s>dr&&dc<tc+s){  //特殊方格在此棋盘中 
            chessboard(tr,tc,dr,dc,s);  
         }  
     else{  //此棋盘中无特殊方格，用t号L性骨牌覆盖右下角 
          board[tr+s-1][tc+s-1]=t;  
          //覆盖本子棋盘中的其余方格 
          chessboard(tr,tc,tr+s-1,tc+s-1,s);  
          } 
		  
//覆盖右上角子棋盘 
     if(dr<tr+s&&dc>=tc+s){  //特殊方格在此棋盘中 
            chessboard(tr,tc+s,dr,dc,s);  
                }  
     else{  //此棋盘中无特殊方格，t号L型骨牌覆盖左下角 
          board[tr+s-1][tc+s]=t; 
		  //覆盖本子棋盘中的其余方格 
          chessboard(tr,tc+s,tr+s-1,tc+s,s);  
          } 

//覆盖左下角子棋盘 
     if(dr>=tr+s&&dc<tc+s){  //此特殊方格在此棋盘中 
            chessboard(tr+s,tc,dr,dc,s);  
                 }  
     else{  //此棋盘中无特殊方格，t号L型骨牌覆盖右上角 
          board[tr+s][tc+s-1]=t;  
          //覆盖本子棋盘中的其余方格 
          chessboard(tr+s,tc,tr+s,tc+s-1,s) ;  
          }  

//覆盖右上角子棋盘 
     if(dr>=tr+s&&dc>=tc+s){  //特殊方格在此棋盘中 
            chessboard(tr+s,tc+s,dr,dc,s);  
                 }  
     else{  //此棋盘中无特殊方格，t号L型骨牌覆盖左上角  
          board[tr+s][tc+s]=t; 
		  //覆盖本子棋盘中的其余方格  
          chessboard(tr+s,tc+s,tr+s,tc+s,s) ;  
          }  
}  
void prt1(int b[65][65],int n){  
     int i,j;  
     for(i=1;i<=n;i++){  
            for(j=1;j<=n;j++)  
                printf("%3d",b[i][j]);  
                    printf("\n");  
                       }  
}  
int main(){  
    int size,dr,dc;  
    printf("输入棋盘大小(4/8/16/64):\n");  
    scanf("%d",&size);  
    printf("输入特殊方格位置(x,y):\n");  
    scanf("%d%d",&dr,&dc);  
    board[dr][dc]=-1;  
    tile++;  
    chessboard(1,1,dr,dc,size);  
    printf("输出棋盘覆盖结果: \n"); 
    prt1(board,size);  
    return 0;  
}  
