import java.util.ArrayList;

//starting location is the null location.
//destination is the final item on the stack.

public class SectionLocation
{
	//format:
	//origin, (section list)*, scene
	ArrayList<String> mLocationStack = new ArrayList<>(); //a stack representing the location as a series of steps from the Parent.
	String mScene = "";
	String mOrigin = "";
	
	
	//Adds a location to the back of the stack, essentially adding a starting location condition.
	void addLocation(String locationName)
	{
		mLocationStack.add(locationName);
	}
	
	void setOrigin(String origin)
	{
		mOrigin = origin;
	}
	
	void setScene(String scene)
	{
		mScene = scene;
	}
	
}
