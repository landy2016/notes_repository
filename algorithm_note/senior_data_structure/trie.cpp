//
// Created by $barney on 2022/12/8.
//
#include "iostream"

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;

char str[N];

void insert(char str[])
{
    printf("idx: %d\n", idx);
    int p = 0;
    for (int i = 0; str[i] ; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    printf("idx: %d\n", idx);
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d\n", &n);
    while (n--) {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == '1') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}
