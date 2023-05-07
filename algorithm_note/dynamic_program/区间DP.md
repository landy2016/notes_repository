## 区间dp模板

```c++
void helper(vector<int> v){
    int n=v.size();
    int dp[n+1];
    memset(dp,0,sizeof dp);
    for(int l=2;l<=n;l++)//长度从小到大
        for(int i=0;i<n-l;i++){//以i为开头
            int j=i+l; //以j为终点
            for(int k=i;k<j;k++){//以k为分割点,进行分治
                //TODO业务逻辑
            }
        }
}
```

但是我习惯记忆化搜索啊

