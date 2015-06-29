class Choice
{
	FString mHeading;
	FString mDescription;
	SectionLocation mLocation;
	
	Choice(FString heading, FString description)
	{
		mHeading = heading;
		mDescription = description;
	}
	
	void setSceneLocation(SectionLocation location)
	{
		mLocation = location;
	}
}