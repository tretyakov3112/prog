#include <vector>
#include <queue>

using std::vector;

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
  // Создаем граф на основе списка ребер
  vector<vector<int>> graph(N+1);
  for (const auto& dislike : dislikes){
    graph[dislike[0]].push_back(dislike[1]);
    graph[dislike[1]].push_back(dislike[0]);
  }

  // Создаем вектор цветов вершин (0 - не раскрашена, 1 - красный, -1 - синий)
  vector<int> colors(N+1, 0);

  // Проходим по всем вершинам и запускаем обход в ширину для каждой нераскрашенной вершины
  for (int i = 1; i <= N; i++){
    if (colors[i] != 0) continue;

    colors[i] = 1;
    std::queue<int> q;
    q.push(i);

    while (!q.empty()){
      int cur = q.front();
      q.pop();

      // Раскрашиваем всех соседей текущей вершины в противоположный цвет и добавляем их в очередь
      for (int neighbor : graph[cur]) {
        if (colors[neighbor] == 0){
          colors[neighbor] = -colors[cur];
          q.push(neighbor);
        }
        // Если сосед уже раскрашен в тот же цвет, что и текущая вершина, то это значит, что граф не двудольный
        else if (colors[neighbor] == colors[cur]) return false;
      }
    }
  }

  // Если все вершины были раскрашены без конфликтов, значит, граф двудольный
  return true;
}
