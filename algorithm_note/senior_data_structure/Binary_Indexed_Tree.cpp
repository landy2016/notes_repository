#include <bits/stdc++.h>
using namespace std;

/**
 * ==============数组数组================
 */

const int N=100010;
int n; // 表示数组元素个数, 下标从1开始
int a[N]; // 原数组
int c[N]; // 树状数组

int lowbit(int x){
    return x&-x;
    // return x & ~i+1;
}

// 查询数组下标1～x的和
int getSum(int x){
    int ans=0;
    while(x>0){ // 当下标不为0时，将当前枚举到的树状数组中的值累加
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

/**
 * 单点修改
 */
// 管辖a[x]的c[y]包含c[x]
void add(int x,int k){
    while(x <= n){ // 直到下标超过边界为止
        c[x] += k; // 将对应树状数组的值更新
        x += lowbit(x); // 更新为父节点的下标，继续更新
    }
}

/**
 * 构建数组数组
 */
// 即单点修改 add(x,k)即可

/**
 * 求区间和
 * @return
 */
 int sumRange(int left,int right){
     return getSum(right) - getSum(left-1);
 }

 /**
  * TODO 修改区间建议使用线段树
  * @return
  */

int main(){

    return 0;
}
