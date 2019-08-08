#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// myers diff algorithm
// source: A B C A B B A (行為單位)
// destination: C B A B A C
// 將來源與目標輸入行轉為 Graph
// 向右表示刪除 -
// 向下表示新增 +
// 對角線表示不變

//      A     B     C     A     B     B     A
//   o-----o-----o-----o-----o-----o-----o-----o 0
//   |     |     |\    |     |     |     |     |
// C |     |     |  \  |     |     |     |     |
//   |     |     |    \|     |     |     |     |
//   o-----o-----o-----o-----o-----o-----o-----o 1
//   |     |\    |     |     |\    |\    |     |
// B |     |  \  |     |     |  \  |  \  |     |
//   |     |    \|     |     |    \|    \|     |
//   o-----o-----o-----o-----o-----o-----o-----o 2
//   |\    |     |     |\    |     |     |\    |
// A |  \  |     |     |  \  |     |     |  \  |
//   |    \|     |     |    \|     |     |    \|
//   o-----o-----o-----o-----o-----o-----o-----o 3
//   |     |\    |     |     |\    |\    |     |
// B |     |  \  |     |     |  \  |  \  |     |
//   |     |    \|     |     |    \|    \|     |
//   o-----o-----o-----o-----o-----o-----o-----o 4
//   |\    |     |     |\    |     |     |\    |
// A |  \  |     |     |  \  |     |     |  \  |
//   |    \|     |     |    \|     |     |    \|
//   o-----o-----o-----o-----o-----o-----o-----o 5
//   |     |     |\    |     |     |     |     |
// C |     |     |  \  |     |     |     |     |
//   |     |     |    \|     |     |     |     |
//   o-----o-----o-----o-----o-----o-----o-----o 6
//   0     1     2     3     4     5     6     7
//                       圖1

// 選擇路徑：
// a. (0, 0) -> (1, 0)
// b. (1, 0) -> (2, 0) -> (3, 1)
// c. (3, 1) -> (3, 2) -> (4, 3) -> (5, 4)
// d. (5, 4) -> (6, 4) -> (7, 5)
// e. (7, 5) -> (7, 6)

// 輸出結果為：
// - A
// - B
//   C
// + B
//   A
//   B
// - B
//   A
// + C

// 定義 d = 路徑長度
// 定義 k = x - y
// 最佳座標 => d 與 k 固定，x 值最大之座標
// 表示往右邊走最多步
// 也就是優先刪除最多(最直觀)
// 可利用動態規劃幫助取得最佳座標

// 由上面範例得知 d = 5，k = 1時到達 (7, 6)目標座標
// 其路徑為最短最直觀路徑

enum Operation { INSERT = 1, DELETE, MOVE };

std::vector<Operation> shortestEditScript(std::vector<std::string>, std::vector<std::string>);

void generateDiff(std::vector<std::string> src, std::vector<std::string> dst) {
  auto script = shortestEditScript(src, dst);
  int srcIdx = 0, dstIdx = 0;

  for (const auto &oper : script) {
    switch (oper) {
    case Operation::INSERT: {
      std::cout << "+" << dst[dstIdx] << std::endl;
      dstIdx++;
      break;
    }

    case Operation::MOVE: {
      std::cout << " " << src[srcIdx] << std::endl;
      srcIdx++;
      dstIdx++;
      break;
    }

    case Operation::DELETE: {
      std::cout << "-" << src[srcIdx] << std::endl;
      srcIdx++;
      break;
    }

    default:
      break;
    }
  }
}

/**
 * @param src Source file lines
 * @param dst Destination file lines
 */
std::vector<Operation> shortestEditScript(std::vector<std::string> src, std::vector<std::string> dst) {
  int m = src.size();
  int n = dst.size();
  int max = m + n;
  std::vector<std::unordered_map<int, int>> trace; // array of [k value : best coordinate's x]
  int x, y;
  bool isFound = false; // flag for check if is found sol.

  // 定義 d = 路徑長度
  // 定義 k = x - y
  // 最佳座標 => d 與 k 固定，x 值最大之座標
  // 表示往右邊走最多步
  // 也就是優先刪除最多(最直觀)
  // 可利用動態規劃幫助取得最佳座標
  // 以座標 (0,0) 開始，d = 0，k = 0，逐步增加 d 求得每個 k 對應的最佳座標 x
  for (int d = 0; d <= max; d++) {
    if (isFound)
      break;

    std::unordered_map<int, int> tr; // [k's value (x - y) : best coordinate's x]
    trace.push_back(tr);

    // 先處理 d = 0 且對角線情況
    if (d == 0) {
      int t = 0;
      while (t < m && t < n && src[t] == dst[t])
        t++;

      trace.back()[0] = t;
      continue;
    }

    auto lastT = trace[d - 1];

    // 從 -d 開始 step 2
    // d = 1，k = 1 or -1;
    // d = 2，在 d = 1 的基礎上再走一步 k = 2 or 0 or -2
    // 依此類推直到找到一組 d k 到達最終座標 (m,n)
    // 解說：
    // 以上圖1為例，繪出下圖 橫軸為 d，縱軸為 k 值，中間為最佳座標
    //     |      0     1     2     3     4     5
    // ----+-------------------------------------- d
    //     |
    //  4  |                             7,3
    //     |                           /
    //  3  |                       5,2
    //     |                     /
    //  2  |                 3,1         7,5
    //     |               /     \     /     \
    //  1  |           1,0         5,4         7,6
    //     |         /     \           \
    //  0  |     0,0         2,2         5,5
    //     |         \                       \
    // -1  |           0,1         4,5         5,6
    //     |               \     /     \
    // -2  |                 2,4         4,6
    //     |                     \
    // -3  |                       3,6
    //     |
    //     k
    //                      圖2
    // 由上圖2可以發現固定 d 值時 k 值的變動為 step 2
    for (int k = -d; k <= d; k += 2) {
      if (k == -d || (k != -d && lastT[k - 1] < lastT[k + 1])) { // 向下(即 i 值不變)
        x = lastT[k + 1];
      } else { // lastT[k - 1] > lastT[k + 1] 時向右，因為要選擇較遠的 x
        x = lastT[k - 1] + 1;
      }

      y = x - k;

      // 處理對角線
      while (x < m && y < n && src[x] == dst[y]) {
        x++;
        y++;
      }

      trace.back()[k] = x;
      if (x == m && y == n) {
        isFound = true;
        break;
      }
    }
  }

  // 反向回朔取回所有 operation
  std::vector<Operation> script;
  int rx = m, ry = n;
  int k, prevK, prevX, prevY;

  for (int d = trace.size() - 1; d > 0; d--) {
    k = rx - ry;
    auto lastT = trace[d - 1];

    if (k == -d || (k != d && lastT[k - 1] < lastT[k + 1])) {
      prevK = k + 1;
    } else {
      prevK = k - 1;
    }

    prevX = lastT[prevK];
    prevY = prevX - prevK;

    while (rx > prevX && ry > prevY) {
      script.push_back(Operation::MOVE);
      rx--;
      ry--;
    }

    if (rx == prevX) {
      script.push_back(Operation::INSERT);
    } else {
      script.push_back(Operation::DELETE);
    }

    rx = prevX;
    ry = prevY;
  }

  if (trace[0][0] != 0) {
    for (int i = 0; i < trace[0][0]; i++) {
      script.push_back(Operation::MOVE);
    }
  }

  std::reverse(script.begin(), script.end());
  return script;
}

int main() {
  generateDiff({"A", "B", "C", "A", "B", "B", "A"}, {"C", "B", "A", "B", "A", "C"});

  return 0;
}