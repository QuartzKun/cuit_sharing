using System;

namespace 实验1._2
{
    class Program
    {
        static int Main(string[] args)
        {
			int i;
			int[] r= { 4, 3, 9, 2, 6, 1 };
			Console.WriteLine( "排序前：");
			for (i = 0; i < 6; i++)
				Console.Write(r[i] + " ");
			Console.WriteLine();
			BubbleSort(r, 6);
			Console.WriteLine("排序后：");
			for (i = 0; i < 6; i++)
				Console.Write(r[i] + " ");
			Console.WriteLine();
			Console.ReadKey();
			return 0;
		}
		public static void BubbleSort(int[] r, int n)
		{
			int bound, exchange = n - 1;          //第一趟起泡排序的区间是[0,-1]
			while (exchange != 0)                //当上一趟排序有记录交换时
			{
				bound = exchange; exchange = 0;
				for (int j = 0; j < bound; j++)   //一趟起泡排序区间是[0, bound]
					if (r[j] > r[j + 1])
					{
						int temp = r[j]; r[j] = r[j + 1]; r[j + 1] = temp;
						//交换记录
						exchange = j;              //记载每一次记录交换的位置
					}
			}
		}
	}
}
