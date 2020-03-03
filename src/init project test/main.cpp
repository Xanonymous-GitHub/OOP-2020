#include <bits/stdc++.h>

using namespace std;
struct linklist {
    int data;
    struct linklist *next;
};
typedef linklist lk;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0);
    lk lnklst[50];
    int lnksize = (int) (sizeof(lnklst) / sizeof(lk));
    lnklst[lnksize - 1].next = NULL;
    lk *ptr = &lnklst[0];
    for (int i = 0; i < lnksize; i++) {
        lnklst[i].data = i;
        lnklst[i].next = &lnklst[i + 1];
    }
    cout << lnklst[lnksize - 1].next << endl;
    return 0;
}