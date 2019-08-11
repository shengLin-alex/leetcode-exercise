/**
 * 回朔法，尋找解並塞回 res
 * @param {string[]} res Result 結果
 * @param {string} sol 一組符合條件的解，條件為每個字符不重複且長度等於輸入的字串
 * @param {boolean[]} used 用於紀錄某個字符(char)是否已經選過 
 * @param {number} dimension 用於紀錄目前 call stack 在哪一維度
 * @param {string} input 輸入
 */
function backtracking(res, sol, used, dimension, input) {
  // 檢查維度是否等於輸入長度，相等表示已經湊出一組解答
  if (dimension === input.length) {
    res.push(sol); // 將解答塞回 result
    return; // 跳出
  }

  // 利用 for loop 幫助選字
  for (var i = 0; i < input.length; i++) {
    // 檢查目前遍歷的字符使否使用過，沒用過才進入
    if (used[i])
      continue;

    if (i > 0 && input[i] === input[i - 1] && !used[i - 1])
      continue;

    used[i] = true; // 設為已經使用
    sol = sol.concat(input[i]); // 將該字符串接到 sol
    backtracking(res, sol, used, dimension + 1, input); // 遞迴進入下一層選字
    sol = sol.slice(0, -1); // 回朔，將字符串最後一個字符移除
    used[i] = false; // 設為未使用，以便維度重新開始計算時(回朔時)選不到字
  }
}

function generateAnagram(input) {
  var res = [];
  var sol = "";
  var used = [];
  for (var i = 0; i < input.length; i++) {
    used.push(false);
  }

  backtracking(res, sol, used, 0, input);

  return res;
}

console.log(generateAnagram("ooo"));