

void sortByDistanceFromTown(vector<Town*>& list, Town* town)
{
	sort(list.begin(), list.end(), [&] (const Town* t1, const Town* t2)
		{return t1->getTownDistance(*town) < t2->getTownDistance(*town);});
}


vector<Town*> readTowns()
{
	vector<Town*> towns;

	string town;

	while(getline(cin, town))
		towns.push_back(new Town(town));

	for(size_t i = 0; i < towns.size(); ++i)
	{
		towns[i]->initTownsByDistance(towns);
		for(size_t j = 0; j < towns.size(); ++j)
			towns[i]->addDistancePrecalulation(*towns[j]);
	}

	return towns;
}


float findTotalDistance(const vector<Town*>& towns)
{
	float total = towns.front()->getTownDistance(*towns.back());

	for (size_t i = 1; i < towns.size(); ++i)
		total+=towns[i]->getTownDistance(*towns[i-1]);

	return total;
}


string getTownString(const vector<Town>& towns)
{
	ostringstream ss;

	for(size_t i = 0; i < towns.size(); ++i)
		ss << towns[i].id()<<(i==(towns.size()-1) ? "":".");

	return ss.str();
}


string getTownString(const vector<Town*> towns)
{
	ostringstream ss;

	for(size_t i = 0; i < towns.size(); ++i)
		ss << towns[i]->id()<<(i==(towns.size()-1) ? "":".");

	return ss.str();
}


vector<Town*> getTownPointers(vector<Town>& towns, int exclude=-1)
{
	vector<Town*> pointers;

	if(exclude!=-1)
	{
		pointers.reserve(towns.size()-1);
		for (int i = 0; i < exclude; ++i)
			pointers.push_back(&towns[i]);
		for(size_t i = exclude+1; i < towns.size(); ++i)
			pointers.push_back(&towns[i-1]);
	}
	else
	{
		pointers.reserve(towns.size());
		for(size_t i = 0 ; i < towns.size(); ++i)
			pointers.push_back(&towns[i]);
	}

	return pointers;
}


void printArrangement(vector<Town*> towns)
{
	for(size_t i = 0; i < towns.size(); ++i)
		cout<<(*towns[i])<<"\n";
}


void printOrderInfo(vector<Town*> order)
{
	cout<<"Towns: ";
	for(size_t i = 0; i < order.size(); ++i)
		cout<<order[i]->id()<<(i==order.size()-1 ? "\n":".");

	float distance = findTotalDistance(order);
	cout<<"Distance: "<<distance;
}

