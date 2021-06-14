using System;

namespace EightQueens
{
  class Program
    {
        /// <summary>
        /// 計算解的組數
        /// </summary>
        private int sum = 0;

        /// <summary>
        /// 設定 8 個皇后，並用於存放每一列皇后位置
        /// </summary>
        private int[] Queens = new int[8];

        static void Main(string[] args)
        {
            Program program = new();
            program.ResolveEightQueen(0);

            Console.ReadLine();
        }

        public void ResolveEightQueen(int row)
        {
            for (int i = 1; i < 9; i++)
            {
                if (row == 8) // 等於 8 時表示 Queens[0] ~ Queen[7] 都已經填好位置
                {
                    sum++;

                    PrintOutput();
                    break;
                }

                if (!IsConflict(row, i)) // 檢查是否產生當前 row 填入該位置是否會產生衝突
                {
                    Queens[row] = i;
                    ResolveEightQueen(row + 1); // 填下一 Row
                }
            }
        }

        public bool IsConflict(int row, int postion)
        {
            if (row == 0)
                return false; // 第一列一定沒衝突
            else
            {
                // 從第一列依序檢查
                for (int i = 0; i < row; i++)
                {
                    // 1. 檢查擺放位置是否重疊
                    // 2. 檢查擺放位置與已經放置的皇后是否在對角線
                    if ((Queens[i] == postion) || ((Queens[i] - postion) == row - i) || ((postion - Queens[i]) == row - i))
                        return true;
                }
                
                return false;
            }
        }

        /// <summary>
        /// 輸出解
        /// </summary>
        public void PrintOutput()
        {
            Console.WriteLine($"\n第{sum}組：");
            for (int i = 0; i < 8; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    // 皇后的位置輸出 "Q" 其餘輸出 "."
                    if (Queens[i] == j)
                        Console.Write("Q");
                    else
                        Console.Write(".");
                }

                Console.Write("\n");
            }
        }
    }
}
