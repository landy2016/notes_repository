//
// Created by $barney on 2022/11/19.
//
#include <iostream>


using namespace std;


/**
 * 1、确定分界点x，q[l]、q[(l + r) / 2]、q[r]都行。
 * 2、调整范围，左区间都 <= x, 右区间都 >= x。
 * 3、递归处理左右两段。
 *
 * @return  时间复杂度: O(log(n))
 */


const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int x = q[l], i = l - 1, j = r + 1; // 偏移量从空的地方开始, 所以下面使用do-while
    //    int m = l + r >> 1;
    //    int x = q[m], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
// 这里使用j， 是由于x取得是q[l]。若想使用i, 则x就不能取q[l]了，可以使用q[r]
// [1, 2] 若使用x = q[l], 使用 quick_sort(q, l, i - 1) 这种会死循环
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);

}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; ++i) printf("%d", q[i]);
    return 0;
}