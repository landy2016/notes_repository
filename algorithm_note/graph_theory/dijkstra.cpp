//
// Created by $barney on 2022/11/26.
//
#include "cstring"
#include "iostream"
#include <algorithm>

using namespace std;

const int N = 510;

int n, m; // n点个数，m边个数
int g[N][N]; // 点i和j之间的最小距离,若没有连接边则为无穷大
int dist[N]; // 1号点到其余点的最小距离
bool status[N]; // dijkstra算法遍历状态

// 迪克斯特拉算法: 定义dist[n],即原点u到vj的最小距离，所有点中和原点有直接连接的最小距离就是权重(边长), 否则设置为无穷大

//               从有直接连接的边中选取最短的一条，这个距离是最短距离(u,vj)，将该点的状态置为已完成，然后更新原点到除了该最短节点的其他点的距离
//               然后再从选出次短路径: 这里很关键，假设次短距离的终点是vk, 则路径是(u, vk)或者(u, vj, vk)
//               依次遍历最短边、次短边、次次短边，遍历完
int dijkstra() {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        int tmp = -1;
        for (int j = 1; j <= n; ++j) {
            // 寻找最开始最短边
            if (!status[j] && (tmp == -1 || dist[tmp] > dist[j])) {
                tmp = j;
            }
        }

        status[tmp] = true;

        for (int j = 1; j <= n; j++) {
            //寻找最短边，更新最短距离(u, vk) 或 (u, vj, vk)
            dist[j] = min(dist[j], dist[tmp] + g[tmp][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];



}

int main() {
    scanf("%d%d", &n, &m);

    // 给数组中所有的字节都设置为0x3f即无穷大, sizeof g，计算二维数组所有的字节总数
    memset(g, 0x3f, sizeof g);

    while (m--) {
        // 输入点a到点b的变长，取最小的
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}




