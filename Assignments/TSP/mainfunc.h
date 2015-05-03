int main()
{

	freopen("towns.txt", "r", stdin);

	gtowns = readTowns();
//	freopen("out.txt", "w", stdout);

	cout << "Initial:\n";
	printOrderInfo(gtowns);

/*	cout << "\n\nSingle starting point, greedy algorithm:\n";
	vector<Town*> answer1 = findArrangement_JumpToClosest();
	printOrderInfo(answer1);
*/
	cout << "\n\nMultiple starting point, greedy algorithm:\n";
	vector<Town*> answer2 = findArrangement_JumpToClosest_TryAllStartingPoints();
	printOrderInfo(answer2);

	cout << "\n\nDone.\n\n";
}
