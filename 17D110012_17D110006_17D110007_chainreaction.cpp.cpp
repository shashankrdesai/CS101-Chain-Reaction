#include<simplecpp>
int crit(int i, int j){
    if((i==0 || i==8) && ((j==0) || (j==5)))return 2;
    else if ((i==0 || i==8) && ((j!=0) && (j!=5))) return 3;
    else if ((i!=0 && i!=8) && ((j==0)||(j==5))) return 3;
    else return 4;
}
int winnerwinnerchickendinner(int a[9][6]){
    int flag1=0,flag2=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<6;j++){
            if(a[i][j]>0){
                flag1=1;
            }
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<6;j++){
            if(a[i][j]<0){
                flag2=1;
            }
        }
    }
    if(flag1==1 && flag2==1)
        return 0;
    else if(flag1==1 || flag2==1)
        return 1;
}
void mov(int a[9][6], int turn, int i, int j){
a[i][j]=abs(a[i][j])*turn+turn;
    if(winnerwinnerchickendinner(a)!=1){

            if(abs(a[i][j])==crit(i,j)){
                a[i][j]=0;
                if(crit(i,j)==2){
                    if(i==0 && j==0){
                        mov(a,turn,i,j+1);
                        mov(a,turn,i+1,j);
                        }
                    else if(i==0 && j==5){
                        mov(a,turn,i,j-1);
                        mov(a,turn,i+1,j);
                    }
                    else if(i==8 && j==0){
                        mov(a,turn,i,j+1);
                        mov(a,turn,i-1,j);
                    }
                    else if(i==8 && j==5){
                        mov(a,turn,i,j-1);
                        mov(a,turn,i-1,j);
                    }
                        }
                else if(crit(i,j)==4){
                        mov(a,turn,i,j+1);
                        mov(a,turn,i+1,j);
                        mov(a,turn,i,j-1);
                        mov(a,turn,i-1,j);
                        }
                else if(crit(i,j)==3){
                if((j!=0) && (j!=5)){
                        mov(a,turn,i,j-1);
                        mov(a,turn,i,j+1);
                        if(i==0)
                            mov(a,turn,i+1,j);
                        if(i==8)
                            mov(a,turn,i-1,j);
                }
                else if((i!=0) && (i!=8)){
                    mov(a,turn,i+1,j);
                    mov(a,turn,i-1,j);
                    if(j==5)
                        mov(a,turn,i,j-1);
                    if (j==0)
                        mov(a,turn,i,j+1);
                }
                }
            }
    }
}

void printMa(int a[9][6]){
    for(int i=0;i<9;i++){
        for(int j=0;j<6;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}


main_program{
int a[9][6];
for(int i=0;i<9;i++){
    for(int j=0;j<6;j++)
    a[i][j]=0;
}
int i, j;
int chance=0;
bool flag=1;
int turn=1;
while(flag){
    chance++;
    cin>>i;
    if(i!=-1)
    {
        cin>>j;

            if(i<9 && i>=0 && j>=0 && j<6)
            {
                if(a[i][j]*turn>=0 )
                    {
                        mov(a,turn,i,j);
                        printMa(a);
                    }
                else{
                    cout<<"Illegal move"<<endl;
                    turn=-turn;
                    }
            turn=-turn;
            if(winnerwinnerchickendinner(a)==1 && chance>2)
                flag=0;
            }
        else{
                cout<<"Illegal move"<<endl;
            }
    }
    else{
    flag=0;
    }
}
}
