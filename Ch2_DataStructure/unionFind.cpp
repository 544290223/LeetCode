/*
并查集：将两个集合合并；查询两个元素是否在同一个集合中
朴素并查集：

    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);
*/
#include <iostream>
using namespace std;


const int N = 100010;
int p[N];

int find(int a){  //核心 找到根节点+路径压缩
    if(a != p[a]) p[a] = find(p[a]);  // if不是while，while会死循环
    return p[a];
}

void merge(int a, int b){
    p[find(a)] = find(b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        p[i] = i;
    }
    while(m --){
        int a, b;
        char op[2];
        scanf("%s%d%d", op, &a, &b);
        if(op[0] == 'M'){
            merge(a,b);
        }else{
            if(find(a) == find(b)){
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }
    return 0;
}
