struct node
{
    int to, w;                       // 連接點編號, 邊權重
};

vector<node> edge[N];                // 存放有權重的邊
vector<long long> d(N, LLONG_MAX);   // d[i] 紀錄點 i 最短路徑長
...

/*------ 1. 使用 priority_queue 儲存，並以較小路徑長優先 ------*/
priority_queue<pair<long long, long long>> q;  // 儲存 {負路徑長, 編號點}
q.push({0, 起始點});
d[起始點] = 0;

/*------ 2. 只要 priority_queue 不是空的就繼續 ------*/
while(!q.empty())
{
    /*--- 3. 取出(負路徑長w, 編號點u)，並檢查 -w 是否和 d[u] 一致 ---*/
    tie(w, u) = q.top();    q.pop();
    if(-w != d[u])	continue;

    /*--- 4. 對於 d[新的點v] > d[目前點u] + 邊權重w 更新 ---*/
    for(auto i: edge[u])
        if(d[i.to] > d[u] + i.w)
        {
            d[i.to] = d[u] + i.w;
            q.push({-d[i.to], i.to});
        }
}
cout << d[目標點] << "\n";
