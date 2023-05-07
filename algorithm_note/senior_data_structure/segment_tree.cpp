#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int d[4*N];
int b[4*N];
int a[N];

// {10,11,12,13,14}

void build(int s,int t,int p){
    //对[s,t]区间建立线段树，当前根的编号为p
    if(s==t){
        d[p]=a[s];
        return;
    }
    int m=s+(t-s>>1); //防止超出int范围， 移位运算的优先级小于加减法
    build(s,m,p*2),build(m+1,t,p*2+1);
    // 递归对左右区间建树
    d[p]=d[p*2]+d[p*2+1];
}

int getSum(int l,int r,int s,int t,int p){
    //[l,r]为查询区间，[s,t]为当前节点包含的区间，p为当前节点的编号
    if(l<=s && t<=r)
        return d[p]; // 当前区间为查询区间的子集时直接返回当前区间的和
    int m=s+(t-s>>1), sum=0;
    if(l<=m) sum+= getSum(l,r,s,m,p*2);
    // 如果左儿子代表的区间[s,m] 与查询区间有交集，则递归查询左儿子
    if(r>m) sum+= getSum(l,r,m+1,t,p*2+1);
    // 如果右儿子代表的区间[m+1,t]与询问区间有交集，则递归查询右儿子
    return sum;
}

void update(int l,int r,int c,int s,int t,int p){
    //[l,r]为修改区间，c为被修改的元素的变化量，[s,t]为当前节点包含的区间
    // p为当前节点的编号
    if(l<=s && t<=r){
        d[p]+=(t-s+1)*c, b[p]+=c;
        return;
    } // 当前区间为修改区间的子集时直接修改当前节点的值，然后打标记,结束修改
    int m=s+(t-s>>1);
    if(b[p] && s!=t){
        //如果当前节点的懒标记非空，则更新当前节点两个子节点的值和懒标记
        d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p],b[p*2+1]+=b[p]; // 将标记下传给子节点
        b[p]=0; // 清空当前节点的标记
    }
    if(l<=m) update(l,r,c,s,m,p*2);
    if(r>m) update(l,r,c,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}

int getSum_update(int l,int r,int s,int t,int p){
    //[l,r]为修改区间，p为当前节点的编号，[s,t]为当前节点包含的区间
    if(l<=s&&t<=r) return d[p];
    //当前区间为查询区间的子集时直接返回当前区间的和
    int m=s+(t-s>>1);
    if(b[p]){
        //如果当前节点的懒标记非空，则更新当前节点的两个子节点的值和懒标记
        d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p],b[p*2+1]+=b[p]; //将标记下传给子节点
        b[p]=0; //清空当前节点标记
    }
    int sum=0;
    if(l<=m) sum = getSum_update(l,r,s,m,p*2);
    if(r>m) sum += getSum_update(l,r,m+1,t,p*2+1);
    return sum;
}

int main(){

    return 0;
}
