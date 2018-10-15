package Exp2;

class Vector{
	Print p=new Print();
private int x;
private int y;
Vector()
{
	x=0;
	y=0;
}
Vector(Vector v)
{
	x=v.x;
	y=v.y;
}

Vector(int x,int y)
{
	this.x=x;
	this.y=y;
}
Vector add(Vector vec)
{
	Vector v=new Vector();
	v.x=x+vec.x;
	v.y=y+vec.y;
	return v;
}
Vector sub(Vector vec)
{
	Vector v=new Vector();
	v.x=x-vec.x;
	v.y=y-vec.y;
	return v;
	
}
double norm()
{
	return Math.sqrt(Math.pow(x,2)+Math.pow(y, 2));
}
double product(Vector vec)  //dot prod
{
	return (x*vec.x+y*vec.y);
}
boolean perpendicular(Vector vec)
{
	if(product(vec)==0)
	{
		return true;
	}
	return false;
}
boolean parallel(Vector vec)
{
	if(vec.x==0)
	{
		p.print("Vector 2 not defined or val=0");				
				
	}
	if(vec.y==0)
	{
		p.print("Vector 2 not defined or val=0");				
				
	}
	
	if(x/vec.x==y/vec.y)
	{
		return true;
	}
	return false;
}
void display()
{
	p.print("x: "+x+" y: "+y);
}
final int getX()
{
	return x;
	
}
final int getY()
{
	return y;
	
}
}
