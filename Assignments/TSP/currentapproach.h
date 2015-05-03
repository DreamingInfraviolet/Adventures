vector<Town*> findArrangement_SelectNClosest(size_t n, size_t currentIndex, vector<Town*> townsLeft = gtowns)
{
	//If last 2 towns.
	if (townsLeft.size() == 2)
		return townsLeft;

	//Remove current town from towns left.
	Town* currentTown = townsLeft[currentIndex];
	townsLeft.erase(townsLeft.begin() + currentIndex);

	sort(townsLeft.begin(), townsLeft.end(), [&](const Town* t1, const Town* t2)
	{return t1->getTownDistance(*currentTown) < t2->getTownDistance(*currentTown); });

	//The minimum town choice
	vector<Town*> min = findArrangement_SelectNClosest(n, 0, townsLeft);
	float minDistance = findTotalDistance(min);

	//Go through n closest towns.
	for (size_t iChoice = 1; iChoice < n; ++iChoice)
	{
		vector<Town*> current = findArrangement_SelectNClosest(n, iChoice, townsLeft);

		float newDistance = findTotalDistance(current);
		if (newDistance < minDistance)
		{
			min = current;
			minDistance = newDistance;
		}
	}

	vector<Town*> out;
	out.push_back(currentTown);
	out.insert(out.end(), min.begin(), min.end());
	return out;
}