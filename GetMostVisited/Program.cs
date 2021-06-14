using System.Collections.Generic;
using System.Linq;
using System;

namespace GetMostVisited
{
  class Program
    {
        static void Main(string[] args)
        {
            var res = getMostVisited(10, new List<int>{ 9, 7, 3, 1 });

            Console.WriteLine(res);
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
