package Exp1;
import java.util.Scanner;


public class Box {

	/**
	 * @param args
	 */
	double l,b,h,vol,sa;
	Box(int len,int br,int ht)
	{
		
		this.l=len;
		this.b=br;
		this.h=ht;
	}
	static Scanner s=new Scanner(System.in);
	static void print(Object o)
	{
		
			System.out.println(o);
		
	}
	
	void volume()
	{
		this.vol=this.l*this.b*this.h;
		print("\nVol = "+this.vol);
	}
	void sa()
	{
		this.sa=2*(this.l*this.b+this.b*this.h+this.h*this.l);
		print("\nSA = "+this.sa);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int l,b,h;
		print("\nEnter Box 1 details: ");
		print("\nEnter length: ");
		l=s.nextInt();
		print("\nEnter breadth: ");
		b=s.nextInt();
		print("\nEnter height: ");
		h=s.nextInt();
		Box b1=new Box(l,b,h);
		b1.sa();
		b1.volume();
		
		print("\nEnter Box 2 details: ");
		print("\nEnter length: ");
		l=s.nextInt();
		print("\nEnter breadth: ");
		b=s.nextInt();
		print("\nEnter height: ");
		h=s.nextInt();
		Box b2=new Box(l,b,h);
		b2.sa();
		b2.volume();
		
		print("\nb1.vol= "+b1.vol+" b2.vol ="+b2.vol);
		
		if(b1.vol>b2.vol)
		{
			print("\nBox 1 has greater volume");
		}
		else if(b1.vol<b2.vol)
		{
			print("\nBox 1 has lesser volume");
		}
		else
		{
			print("\nThey have equal volume");
		}
		
		print("\nb1.surf.area= "+b1.sa+" b2.surf.area ="+b2.sa);
		
		if(b1.sa>b2.sa)
		{
			print("\nBox 1 has greater surface area");
		}
		else if(b1.sa<b2.sa)
		{
			print("\nBox 1 has lesser surface area");
		}
		else
		{
			print("\nThey have equal surface area");
		}
		
		

	}

}
