#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

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
  int n = src.size();
  int m = dst.size();
  int max = n + m;
  std::vector<std::unordered_map<int, int>> trace; // array of [k value : best coordinate's x]
  int x, y;
  bool isFound = false;

  // 定義 d = 路徑長度
  // 定義 k = x - y
  // 最優座標 => d 與 k 固定，x 值最大之座標
  // 表示往右邊走最多步
  // 也就是優先刪除最多(最直觀)
  // 可利用動態規劃幫助取得最優座標
  for (int d = 0; d <= max; d++) {
    if (isFound)
      break;

    std::unordered_map<int, int> t;
    trace.push_back(t);

    // 先處理 d = 0 且對角線情況
    if (d == 0) {
      int t = 0;
      while (n > t && m > t && src[t] == dst[t])
        t++;

      trace.back()[0] = t;
      continue;
    }

    auto lastT = trace[d - 1];

    for (int k = -d; k <= d; k += 2) {
      if (k == -d || (k != -d && lastT[k - 1] < lastT[k + 1])) { // 向下
        x = lastT[k + 1];
      } else { // 向右
        x = lastT[k - 1] + 1;
      }

      y = x - k;

      while (x < n && y < m && src[x] == dst[y]) {
        x++;
        y++;
      }

      trace.back()[k] = x;
      if (x == n && y == m) {
        isFound = true;
        break;
      }
    }
  }

  // 反向回朔取回所有 operation
  std::vector<Operation> script;
  int rx = n, ry = m;
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