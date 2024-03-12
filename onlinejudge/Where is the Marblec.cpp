#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

//https://vjudge.net/problem/UVA-10474#author=0

#define 原神 啟動!


using namespace std;


int main(){

int N,Q,turn = 1;

while(cin>>N>>Q && N && Q){
	cout<<"CASE# "<<turn<<":"<<endl;
	turn++;
	vector<int> board(N);
	
	for(int i=0;i<N;i++){
		cin>>board[i];
	}
	sort(board.begin(),board.end());
	map<int,int> find_board;
	
	for(int i=0;i<N;i++){
		if(!find_board.count(board[i]))
			find_board[board[i]] = i;
	}
	int goal;
	for(int i=0;i<Q;i++){
		cin>>goal;
		if(find_board.count(goal)){
			cout<<goal<<" found at "<<find_board[goal]+1<<endl;
		}
		else{
			cout<<goal<<" not found"<<endl;
		}	
	}

}


return 0;
}
