#include<iostream>

using namespace std;
int exhaustion_matrix[10000][502];
int d[10000];

int main() {
    int n,m;
    scanf("%d %d",&n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d",&d[i]);
    }

    exhaustion_matrix[0][1] = d[0];

    for(int i=1; i<n; i++) {
        exhaustion_matrix[i][0] = exhaustion_matrix[i-1][0];
        for(int j=1; j < m + 1; j++) {
            if (j < i+2) {
                exhaustion_matrix[i][0] = max(exhaustion_matrix[i][0],exhaustion_matrix[i-j][j]);
                exhaustion_matrix[i][j] = exhaustion_matrix[i-1][j-1] + d[i];
            }
        }
    }

    printf("%d\n", exhaustion_matrix[n-1][0]);
}