#include <stdio.h>    
int board[65][65],tile=0; //tile Ϊ���Ʊ��  
void chessboard(int tr,int tc,int dr,int dc,int size){  
     int t,s;  
     if (size==1)  
     return ;  //�ݹ�߽� 
     t=tile++;  //L�͹��Ʊ�� 
     s=size/2;  //�ָ�����
	 
//�������Ͻ������� 
     if(tr+s>dr&&dc<tc+s){  //���ⷽ���ڴ������� 
            chessboard(tr,tc,dr,dc,s);  
         }  
     else{  //�������������ⷽ����t��L�Թ��Ƹ������½� 
          board[tr+s-1][tc+s-1]=t;  
          //���Ǳ��������е����෽�� 
          chessboard(tr,tc,tr+s-1,tc+s-1,s);  
          } 
		  
//�������Ͻ������� 
     if(dr<tr+s&&dc>=tc+s){  //���ⷽ���ڴ������� 
            chessboard(tr,tc+s,dr,dc,s);  
                }  
     else{  //�������������ⷽ��t��L�͹��Ƹ������½� 
          board[tr+s-1][tc+s]=t; 
		  //���Ǳ��������е����෽�� 
          chessboard(tr,tc+s,tr+s-1,tc+s,s);  
          } 

//�������½������� 
     if(dr>=tr+s&&dc<tc+s){  //�����ⷽ���ڴ������� 
            chessboard(tr+s,tc,dr,dc,s);  
                 }  
     else{  //�������������ⷽ��t��L�͹��Ƹ������Ͻ� 
          board[tr+s][tc+s-1]=t;  
          //���Ǳ��������е����෽�� 
          chessboard(tr+s,tc,tr+s,tc+s-1,s) ;  
          }  

//�������Ͻ������� 
     if(dr>=tr+s&&dc>=tc+s){  //���ⷽ���ڴ������� 
            chessboard(tr+s,tc+s,dr,dc,s);  
                 }  
     else{  //�������������ⷽ��t��L�͹��Ƹ������Ͻ�  
          board[tr+s][tc+s]=t; 
		  //���Ǳ��������е����෽��  
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
    printf("�������̴�С(4/8/16/64):\n");  
    scanf("%d",&size);  
    printf("�������ⷽ��λ��(x,y):\n");  
    scanf("%d%d",&dr,&dc);  
    board[dr][dc]=-1;  
    tile++;  
    chessboard(1,1,dr,dc,size);  
    printf("������̸��ǽ��: \n"); 
    prt1(board,size);  
    return 0;  
}  
