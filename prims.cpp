#include <cstring>
#include <iostream>
using namespace std;

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main() {
  int count;
  int selected[V];

  for(int i=0;i<V;i++)
    selected[i] = false;

  count = 0;

  selected[0] = true;

  int x,y;

  cout << "Edge"<< " : "<< "Weight"<<endl;
  while (count < V - 1) {
    int min = INT_MAX;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++)
    {
      if (selected[i])
      {
        for (int j = 0; j < V; j++)
        {
          if (!selected[j] && G[i][j])
          {
            if (G[i][j] < min)
            {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y]<<endl;
    selected[y] = true;
    count++;
  }

  return 0;
}
