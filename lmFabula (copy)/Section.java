import java.util.ArrayList;

public class Section
{
	ArrayList<Section> mNestedSections = new ArrayList<Section>();
	ArrayList<Scene>   mScenes         = new ArrayList<Scene>();
	String mName = new String();

	Section()
	{

	}

	void addSection(Section section)
	{
		mNestedSections.add(section);
	}

	void addScene(Scene scene)
	{
		mScenes.add(scene);
	}

	Section findSection(String name)
	{
		for (int i = 0; i < mNestedSections.size(); ++i)
			if (mNestedSections.get(i).mName.equals(name))
				return mNestedSections.get(i);
		return null;
	}


	Scene findScene(String name)
	{
		for (int i = 0; i < mScenes.size(); ++i)
			if (mScenes.get(i).getName().equals(name))
				return mScenes.get(i);
		return null;
	}

	String getName()
	{
		return mName;
	}

}