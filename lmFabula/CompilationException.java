
public class CompilationException extends Exception
{
	String mMessage;
	int mLine, mCharPos;
	
	public CompilationException(String message, int line, int charpos)
	{
		mMessage = message;
		mLine = line;
		mCharPos = charpos;
	}
	
	@Override
	public String toString()
	{
		return "line "+mLine+","+mCharPos+": "+mMessage;
	}
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

}
