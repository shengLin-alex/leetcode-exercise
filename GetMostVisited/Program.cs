using System.Collections.Generic;
using System.Linq;
using System;

namespace GetMostVisited
{
    class Program
    {
        static void Main(string[] args)
        {
            // var res = getMostVisited(10, new List<int> { 9, 7, 3, 1 });
            var res = punctuationMistakes("This sentence contains both lowercase and uppercase English letters , punctuation marks,and spaces.");

            Console.WriteLine(res);
        }

        public static string punctuationMistakes(string text)
        {
            int length = text.Length;
            for (int i = 0; i < length; i++)
            {
                if (i - 1 >= 0 && (text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!'))
                {
                    if (text[i - 1] == ' ')
                    {
                        text = text.Remove(i - 1, 1);
                    }
                }
            }

            int l = text.Length;
            for (int i = 0; i < l; i++)
            {
                if (i + 1 < length && i - 1 >= 0 && (text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!'))
                {
                    if (text[i + 1] != ' ')
                    {
                        text = text.Insert(i + 1, " ");
                        i++;
                    }
                }
            }

            return text;
        }


    public static int getMostVisited(int n, List<int> sprints)
    {
      var map = new int[n];
      var isBackwards = new List<bool>();

      for (var i = 0; i < sprints.Count; i++)
        if (i + 1 < sprints.Count)
          isBackwards.Add(sprints[i] > sprints[i + 1]);

      for (var i = 0; i < sprints.Count - 1; i++)
      {
        if (i + 1 < sprints.Count && isBackwards[i])
          for (var j = sprints[i]; j >= sprints[i + 1]; j--)
          {
            map[j] += 1;
          }
        else if (i + 1 < sprints.Count && !isBackwards[i])
          for (var j = sprints[i]; j <= sprints[i + 1]; j++)
          {
            map[j] += 1;
          }
      }

      return map.ToList().IndexOf(map.Max());
    }
  }
}
