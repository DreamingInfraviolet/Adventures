package Anima;

public class Pair <A,B>
{
	private A a;
	private B b;
	
	Pair() {}
	
	Pair(A a_, B b_)
	{
		a=a_;
		b=b_;
	}
	
	
	A first ()
	{
		return a;
	}
	
	B second ()
	{
		return b;
	}
}
