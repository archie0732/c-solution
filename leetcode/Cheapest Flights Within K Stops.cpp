//Cheapest Flights Within K Stops
//mid

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //拜訪花費
        vector<int>board(n+1,INT_MAX);
        //路線 || from || to || cost
        map<int,vector<pair<int,int>>> road;
        //填充路線&價錢
        for(const auto it : flights){
            road[it[0]].push_back({it[1],it[2]});
        }
        //
        queue<pair<int,int>> qp;
        //初始化出發點與花費
        qp.push({src,0});

        while(k>=0){
            // 經典BFS走法
            int size = qp.size();
            while(size--){
                // 這一步的花費
                int curr_cost = qp.front().second;
                for(auto it:road[qp.front().first]){
                    // 往前走的花費
                    int new_cost = it.second+curr_cost;
                    int next_step = it.first;
                    if(new_cost<board[next_step]){
                        board[next_step] = new_cost;
                        qp.push({next_step,new_cost});
                    }
                }
                qp.pop();
            }
            k--;
        }
        return board[dst]==INT_MAX?-1:board[dst];
    }
};
