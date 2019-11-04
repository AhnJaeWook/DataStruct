#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_NODE 100
#define MAX_EDGE 10000
#define MAX_NUM 200000


double Node[MAX_NODE * 2];   //Vertices

int size;

double Edge[MAX_EDGE * 3];   //Graph

int edgeCount;

int parent[MAX_NODE];

double len(int i, int j){
   double xLen = abs(Node[i * 2] - Node[j * 2]);
   double yLen = abs(Node[i * 2 + 1] - Node[j * 2 + 1]);
   return sqrt(pow(xLen, 2) + pow(yLen, 2));
}

int set_find(int curr)
{
   while (parent[curr] != -1) curr = parent[curr];
   return curr;
}

void set_union(int a, int b)
{
   int root1 = set_find(a);   // 노드 a의 루트를 찾는다. 
   int root2 = set_find(b);   // 노드 b의 루트를 찾는다. 
   if (root1 != root2)    // 합한다. 
      parent[root1] = root2;
}

int compare(const void* a, const void* b)
{
   return *((double *)a + 2) - *((double *)b + 2);
}

double kruskal()
{
   int edge_accepted = 0;   // 현재까지 선택된 간선의 수   
   int uset, vset;         // 정점 u와 정점 v의 집합 번호
   
   double sum = 0;

   int i = 0;
   for(i = 0; i < size; ++i){
      parent[i] = -1;
   }
   
   qsort(Edge, sizeof(Edge) / (sizeof(double) * 3), sizeof(double) * 3, compare);
   
   i = 0;
    while (edge_accepted < (edgeCount - 1))   // 간선의 수 < (n-1)
   {   
        uset = set_find(Edge[i * 3]);      // 정점 u의 집합 번호 
      vset = set_find(Edge[i * 3 + 1]);      // 정점 v의 집합 번호
      if (uset != vset) {         // 서로 속한 집합이 다르면
         sum += Edge[i * 3 + 2];
         edge_accepted++;
         set_union(uset, vset);   // 두개의 집합을 합친다.
      }
      i++;
   }
   
   return sum;
}

int main(void){
   edgeCount = 0;

   scanf("%d", &size);
   
   int i;
   
   for(i = 0; i < MAX_EDGE; ++i){
      Edge[i * 3 + 2] = MAX_NUM;
   }
   
   for(i = 0; i < size; ++i){
      parent[i] = -1;
      
      scanf("%lf", &Node[i * 2]);
      scanf("%lf", &Node[i * 2 + 1]);
      
      int j;
      for(j = 0; j < i; ++j){
         Edge[edgeCount * 3] = (double)i;
         Edge[edgeCount * 3 + 1] = (double)j;
         Edge[edgeCount * 3 + 2] = len(i, j);
         ++edgeCount;
      }
   }
   printf("%.2f", kruskal());
   return 0;
}
