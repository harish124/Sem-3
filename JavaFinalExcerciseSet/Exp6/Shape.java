package Exp6;

public abstract class Shape {
	private int len,bred;
	abstract double area();
	public int getLen() {
		return len;
	}
	public void setLen(int len) {
		this.len = len;
	}
	public int getBred() {
		return bred;
	}
	public void setBred(int bred) {
		this.bred = bred;
	}
}
