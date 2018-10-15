package Exp2;



public class VectorDemo {

	/**
	 * @param args
	 */
	static Print p=new Print();
	public static void main(String[] args) {

		Vector v1=new Vector(10,45),v2,v3;
		v1.display();
		
		double normal=0,dp=0;
		
		v2=new Vector(v1);
		v2.display();
		v3=new Vector();
		
		p.print("adding: ");
		v3=v1.add(v2);
		v3.display();
		
		p.print("sub: ");
		v3=v1.sub(v2);
		v3.display();
		
		p.print("finding normalization: ");
		normal=v1.norm();
                p.print(normal);
		
		p.print("Dot Product:");
		dp=v1.product(v2);
		p.print(dp);
		
		p.print("Perp. check: ");
		p.print(v1.perpendicular(v2));
		
		p.print("Parallel check: ");
		p.print(v1.parallel(v2));
		
		
		
		

	}

}
