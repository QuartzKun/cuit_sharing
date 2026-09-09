using System;

namespace 实验1._1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入一个数字：");
            int n = Convert.ToInt32(Console.ReadLine());
            int[] a = new int[n];
            Console.WriteLine("请输入数组中的各个数字：");
            for (int i = 0; i < n; i++)
            {
                int number = Convert.ToInt32(Console.ReadLine());
                a[i] = number;
            }
            Console.WriteLine("请输入第二个数字：");
            int k = Convert.ToInt32(Console.ReadLine());
            int num = seqSearch(n, k, a);
            Console.WriteLine(num);
            Console.ReadKey();
        }
        public static int seqSearch(int n, int k, params int[] a)
        {
            int i = 0;
            while (i < n && a[i] != k)
                i++;
            if (i < n) 
                return i;
            else 
                return -1;
        }
    }
}
