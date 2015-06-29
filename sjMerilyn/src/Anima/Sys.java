package Anima;


public class Sys
{
	static Window window;

	public static void main(String[] args)
	{
		if (!initialise())
			return;
		
		shutdown();
		return;
	}
	
	private static boolean initialise()
	{
		window = new Window();
		if (!window.initialise())
			return false;
		
		return true;
	}
	
	private static void shutdown()
	{
		
	}

}
