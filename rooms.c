#include<stdio.h>
#include<math.h>

int main(){
    int n, N=0;
    scanf("%d", &n);
    int k[n];
    int check[n];
    for (int i=0;i<n;i++){
        scanf("%d", &k[i]);
        check[i] = 0;
    }

    int room[n][n];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            room[i][j] = 0;

    for(int first=0 ; first<n ; first++){
        if (check[first] == 1) // whether this room have arrived
            continue;
        int index = 1;
        int next = first;
        room[N][0] = first;
        
        do{
            check[next] = 1;
            next = k[next];
            room[N][index] = next;
            index++;
        } while(first != next);
        room[N][index] = -1;
        N++;
    }
    printf("%d rings\n", N);
    for(int i=0, j=0;i<N;i++, j=0)
        while(room[i][j] != -1){
            printf("%d", room[i][j]);
            if (room[i][j+1] != -1)
                printf(" -> ");
            else   
                printf("\n");
            j++;
        }
    return 0;
}
