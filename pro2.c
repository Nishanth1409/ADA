#include<stdio.h> 
void main() 
{ 
    int i,j,ne,n,source,target,min,mincost=0; 
    int cost[10][10],visited[10],parent[10]; 
    printf("enter the number of vertices: "); 
    scanf("%d",&n); 
    for(i=0;i<n;i++) 
    { 
        parent[i]=0; 
 
    } 
    printf("enter the cost matrix:\n"); 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        { 
            scanf("%d",&cost[i][j]); 
        } 
    } 
    for(i=0;i<n;i++) 
    { 
        visited[i]=0; 
    } 
        printf("enter the source vertex:\n"); 
        scanf("%d",&source); 
            visited[source]=1; 
            ne=1; 
            while(ne<n) 
            { 
                min=999; 
                for(i=0;i<n;i++) 
                { 
                    if(visited[i]) 
                    { 
                        for(j=0;j<n;j++) 
                        { 
                            if(cost[i][j]<min && !visited[j]) 
                            { 
                                min=cost[i][j]; 
                                source=i; 
                                target=j; 
                            } 
                        } 
                    } 
                } 
                visited[target]=1; 
                printf("\n edge %d(%d->%d)%d \n",ne++,source,target,min); 
            mincost=mincost+min; 
        } 
        printf("mincost of spanning tree %d \n",mincost); 
}

// 4

// 0  2  0  6
// 2  0  3  8
// 0  3  0  5
// 6  8  5  0

// 0

