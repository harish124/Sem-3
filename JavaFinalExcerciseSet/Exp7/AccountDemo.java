package Exp7;

class MyException extends Exception
{
	String msg;
	MyException(String m)
	{
		msg=m;
	}
	
	@Override
	public String toString()
	{
		return msg;		
	}
}
class Account
{
	private long accno;
	private double bal;
	Account(){
		accno=0;
		bal=0;
	}
	Account (long id, double amount){
		accno=id;
		bal=amount;
	}
	void deposit (double amount){
		bal+=amount;
	}
	boolean withdraw (double amount) throws MyException{
		if(amount > bal)
			throw new MyException("Insufficient Balance");
		else
		{
			bal-=amount;
			return true;
		}
	}
	long get_id (){
		return accno;
	}
	
	double get_balance (){
			return bal;
	}
}
public class AccountDemo {
	static Print p=new Print();
	 public static void main(String[] args) {
		Account a1=new Account(12,50000);
		try {
			p.print("Withdraw 25K: "+a1.withdraw(25000));
			p.print("Bal = "+a1.get_balance());
			p.print("Withdraw 30K: "+a1.withdraw(30000));  //these below two lines will not execute due to exception
			p.print("Bal = "+a1.get_balance());
		} catch (MyException e) {
			// TODO Auto-generated catch block
			p.print(""+e);
		}
	}
}
