public class Scene
{
	String mName;
	FString[] mStrings;
	ChoiceList mChoiceList;
	
	Scene(String name)
	{
		mName = name;
	}
	
	String getName()
	{
		return mName;
	}
	
	void setSceneContent(FString[] strings, ChoiceList choicelist)
	{
		mStrings = strings;
		mChoiceList = choicelist;
	}
}