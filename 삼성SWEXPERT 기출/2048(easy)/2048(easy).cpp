#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int block[20][20];
int N;
int maxblock;
void input_block(){
    ifstream input;
    input.open("input.txt");
    input>>N;
    //fill_n(block[0], 21*21, -1); // 1차원 배열이랑 2차원 배열 초기화 방법 다름
    // ex : fill_n(array, 100, -1);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            input>>block[i][j];
}

void thousand(int num){
    queue <int> q;
    switch(num){
    case 0 : // 왼쪽 이동
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(block[i][j]) q.push(block[i][j]);
                block[i][j] = 0;
            }

            int index = 0;

            while(!q.empty()){
                //cout<<0<<endl;
                int temp = q.front();
                q.pop();

                if(block[i][index] == 0) block[i][index] = temp;
                else if(block[i][index] == temp){
                    block[i][index] *= 2;
                    index++;
                }
                else{
                    index++;
                    block[i][index] = temp;
                }
            }
        }
        break;

    case 1 : // 오른쪽
        for(int i = 0; i < N; ++i){
            for(int j = N-1; j>=0; --j){
                if(block[i][j]) q.push(block[i][j]);
                block[i][j] = 0;

            }
                int index = N-1;
                while(!q.empty()){
                    //cout<<1<<endl;
                    int temp = q.front();
                    q.pop();

                    if(block[i][index] == 0) block[i][index] = temp;
                    else if(block[i][index] == temp){
                        block[i][index] *= 2;
                        index--;
                    }
                    else{
                        index--;
                        block[i][index] = temp;
                    }
                }
        }
        break;
    case 2 : // 위쪽
        for(int i = 0; i < N; ++i){
            //cout<<2<<endl;
            for(int j = 0;j < N ; ++j){
                if(block[j][i]) q.push(block[j][i]);
                block[j][i] = 0;
            }

            int index = 0;

            while(!q.empty()){
                int temp = q.front();
                q.pop();

                if(block[index][i] == 0) block[index][i] = temp;
                else if(block[index][i] == temp){
                    block[index][i] *= 2;
                    index++;
                }
                else{
                    index++;
                    block[index][i] = temp;
                }
            }
        }
        break;
    case 3 : // 아래쪽
        for(int i = 0; i < N; ++i){
            for(int j = N-1; j>=0 ;--j){
                if(block[j][i]) q.push(block[j][i]);
                block[j][i] = 0;
            }

            int index = N-1;

            while(!q.empty()){
                //cout<<3<<endl;
                int temp = q.front();
                q.pop();

                if(block[index][i] == 0) block[index][i] = temp;
                else if(block[index][i] == temp){
                    block[index][i] *= 2;
                    index--;
                }
                else{
                    index--;
                    block[index][i] = temp;
                }
            }
        }
        break;
    }
}

void DFS(int cnt){
    if(cnt == 5){
        for(int i = 0; i < N; ++i)
            for( int  j = 0; j< N; ++j)
                maxblock = max(maxblock, block[i][j]);
        return;
    }
    int copyblock[20][20]; //현 보드 저장하기 위해

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            copyblock[i][j] = block[i][j];

    for(int i = 0 ; i < 4; ++i){
        thousand(i);
        DFS(cnt+1);
        for(int i = 0 ; i < N; ++i) // 배열 원상복구
            for(int j = 0; j < N; ++j)
                block[i][j] = copyblock[i][j];
    }
}

int main(void)
{
    input_block();
    DFS(0);
    cout<<maxblock<<endl;
    return 0;
}
