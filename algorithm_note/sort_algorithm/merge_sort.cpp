#include "iostream"

using namespace std;

const int N = 1000010;

int n;
int q[N], tmp[N];

/** 分治
 * 1、确定分界点，mid = (l + r) / 2
 * 2、递归排序左边、右边
 * 3、归并，将两个有序的合并为一个有序的
 * @return  时间复杂度O(nlog(n))
 */

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    // 归并
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i ++];
        else tmp[k++] = q[j++];
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (i = l,j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
}
