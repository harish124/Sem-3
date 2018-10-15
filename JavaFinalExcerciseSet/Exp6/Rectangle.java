package Exp6;

 class Triangle extends Shape{
	 Triangle(int l,int b)
		{
			setLen(l);
			setBred(b);
		}
	@Override
	double area() {
		//System.out.println("Rectangle Area = "+0.5*getLen()*getBred());
		return 0.5*getLen()*getBred();
	}
	
}
 class Circle extends Shape{

	 Circle(int l)
		{
			setLen(l);
			
		}
	@Override
	double area() {
		//System.out.println("Rectangle Area = "+Math.PI*getLen()*getLen());
		return Math.PI*getLen()*getLen();
	}
	
}
public class Rectangle extends Shape{
	static Print p=new Print();
	Rectangle(int l,int b)
	{
		setLen(l);
		setBred(b);
	}
	@Override
	double area() {
		//System.out.println("Rectangle Area = "+getLen()*getBred());
		return getLen()*getBred();
	}
	
	public static void main(String[] args) {
		Shape s=new Rectangle(10,20);
		p.print("Area of rect: "+s.area());
		s=new Triangle(10,20);
		p.print("Area of triangle: "+s.area());
		s=new Circle(10);
		p.print("Area of Circle: "+s.area());
	}
}
