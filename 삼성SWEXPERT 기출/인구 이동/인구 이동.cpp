#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

int N,L,R,intflag = 1,cnt = 0,visit = 0;
vector < vector <int> > gr;
queue< pair<int,int> > q;

void input_test(){
    ifstream input;
    input.open("input_file.txt");
    input>>N>>L>>R;
    printf("%d",N);
    for(int i = 0; i < N; ++i){
        vector< int > temp;
        int tempint;
        for(int j = 0; j < N; ++j){
            input>>tempint;
            temp.push_back(tempint);
        }
        gr.push_back(temp);
    }
}

void BFS(){
    int flag[N][N] = {0,};
    while(1){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(!flag[i][j]){
                    q.push(make_pair(i,j));
                    visit++;
                    flag[i][j] = intflag;
                    while(!q.empty()){
                        if(q.front().first != N-1 && abs(gr[q.front().first+1][q.front().second] - gr[q.front().first][q.front().second]) >= L &&
                           abs(gr[q.front().first+1][q.front().second] - gr[q.front().first][q.front().second]) <= R){
                            q.push(make_pair(q.front().first+1,q.front().second));
                            visit++;
                            flag[q.front().first+1][q.front().second] = 1;
                            cout<<"hello1"<<endl;
                        }

                        if(q.front().second != N-1 && abs(gr[q.front().first][q.front().second+1] - gr[q.front().first][q.front().second]) >= L &&
                           abs(gr[q.front().first][q.front().second+1] - gr[q.front().first][q.front().second]) <= R){
                            q.push(make_pair(q.front().first,q.front().second+1));
                            visit++;
                            flag[q.front().first][q.front().second+1] = 1;
                            cout<<"hello2"<<endl;
                        }
                        cout<<q.front().first<<" "<<q.front().second<<endl;
                        q.pop();
                        cout<<q.front().first<<" "<<q.front().second<<endl;
                        cout<<q.size()<<endl;
                    }
                    intflag++;
                    cout<<visit<<endl;
                }
                if(visit == N*N) break;
            }
            if(visit == N*N) break;
        }
    }
}

int main(void)
{
    input_test();
    BFS();
    return 0;
}
