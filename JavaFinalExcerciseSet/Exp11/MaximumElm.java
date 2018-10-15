package Exp11;
//Sorting not there // just for reference
class Max<T extends Comparable<T>>
{
	T arr[];
	Max(T ob[])
	{
		arr=ob;
	}
	T max()
	{
		T grt=arr[0];
		for(T x:arr)
		{
			if(grt.compareTo(x)<0)
			{
				grt=x;
			}
		}
		return grt;
	}
	void displayArray()
	{
		
		for(T x:arr)
			System.out.print(" "+x);
	}
	void bubSort()
	{
		int bub=1;
		while(bub==1)
		{
			bub=0;
			for(int i=0;i<=arr.length-2;i++)
			{
				if(arr[i].compareTo(arr[i+1])>0)
				{
					bub=1;
					T temp=arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
				}
			}
		}
	}
}
public class MaximumElm {
	static Print p=new Print();
	public static void main(String[] args) {
 
		Integer inums[]= {1,20,3,-4,155,67,100};
		String str[]= {"gods","harish","aravind","nitish","hello"};
		
		Max<Integer> ob1=new Max<>(inums);
		p.print("Max in inums: "+ob1.max());
		
		Max<String> ob2=new Max<>(str);
		p.print("Max in str array: "+ob2.max());
		
		p.print("\nBefore Sorting inums:");
		ob1.displayArray();
		ob1.bubSort();
		p.print("\nAfter Sorting inums:");
		ob1.displayArray();
		
		p.print("\nBefore Sorting str:");
		ob2.displayArray();
		ob2.bubSort();
		p.print("\nAfter Sorting str:");
		ob2.displayArray();
	}

}