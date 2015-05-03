


////////////////////////////////////////////////////////////////////////////////////////


vector<Town*> findArrangement_JumpToClosest(unsigned startingTown=0)
{
	vector<Town*> out;

	out.reserve(gtowns.size());
	out.push_back(gtowns[startingTown]);

	vector<Town*> available = gtowns;
	available.erase(available.begin()+startingTown);

	while(available.size())
	{
		size_t index = out.back()->findClosestIndex(available);
		out.push_back(available[index]);
		available.erase(available.begin()+index);
	}

	return out;
}


////////////////////////////////////////////////////////////////////////////////////////


vector<Town*> findArrangement_JumpToClosest_TryAllStartingPoints()
{
	vector<Town*> bestSolution = findArrangement_JumpToClosest(0);
	float bestDistance = findTotalDistance(bestSolution);

	for(size_t i = 1; i < gtowns.size(); ++i)
	{
		vector<Town*> solution = findArrangement_JumpToClosest(i);

		float distance = findTotalDistance(solution);
		if(distance < bestDistance)
		{
			bestSolution = solution;
			bestDistance = distance;
		}
	}


	return bestSolution;
}


////////////////////////////////////////////////////////////////////////////////////////



//For each x[i] in the array, swap with x[Chromosome[i]]
typedef vector<int> Chromosome;


#define PRIMITIVE_MUTATION_RATE_INVERSE 1000

struct Organism_Primitive
{
	Chromosome chromosome;
	mutable bool needsUpdating;
	mutable float performance;

	Organism_Primitive()
	{
		//randomly initialise chromosome
		chromosome.resize(gtowns.size());
		for(size_t i = 0; i < chromosome.size(); ++i)
			chromosome[i]=rand(0, gtowns.size()-1);

		needsUpdating = true;
		performance = 0.f;
	}

	bool operator < (const Organism_Primitive& o) const
	{
		return findPerformance()<o.findPerformance();
	}


	float findPerformance() const
	{
		if(needsUpdating)
			{
				needsUpdating=false;
				return performance = 1.f/(1.f+findTotalDistance(applyToTowns()));
			}
		else
			return performance;
	}


	//Apples its internal state to a town list
	virtual vector<Town*> applyToTowns() const
	{
		vector<Town*> out = gtowns;
		for(size_t i = 0; i < out.size(); ++i)
			swap(out[i], out[chromosome[i]]);
		return out;
	}

	virtual void mutate()
	{
		needsUpdating = true;
		for(size_t i = 0; i < chromosome.size(); ++i)
		{
			if(rand(0,PRIMITIVE_MUTATION_RATE_INVERSE)==0)
			{
				//Mutate gene:

				if(rand(0,1))
					chromosome[i] = (chromosome[i]+gtowns.size()-1) % gtowns.size();
				else
					chromosome[i] = (chromosome[i]+gtowns.size()+1) % gtowns.size();
			}
		}
	}
};




template <class Org>
vector<Town*> findArrangement_Evolution_Primitive(size_t generations, size_t organismCount, size_t topToKeep)
{
	static mutex mx;
	static int _id = 0;
	int id = _id;
	++_id;

	vector<Org> organisms;
	organisms.resize(organismCount);

	if(id==0)
	{
		cout<<"Running genetic simulation... \n";
		cout<<"Format: id:(percentage completed, best answer);\n";
	}
 

	for(size_t i = 0; i < generations; ++i)
	{
		//take the best half
		sort(organisms.rbegin(), organisms.rend());
		vector<Org> best (organisms.begin(), organisms.begin()+topToKeep);

		//Update organisms
		organisms = best;
		organisms.resize(organismCount);

		if(i%1000==0)
		{
			lock_guard<mutex> lock (mx);
			Org& bestOne = best.front();
			cerr<<id<<":("<<(float(i)/generations*100.f)<<", "<<findTotalDistance(organisms.front().applyToTowns())<<"); ";
		}
	}

	//Get best solution:
	sort(organisms.begin(), organisms.end());
	return organisms.back().applyToTowns();
};

template <class Org>
vector<Town*>  findArrangement_Evolution_Primitive_Multithreaded(size_t generations, size_t organismCount, size_t topToKeep, size_t noOfSimulations=4)
{
	vector<future<vector<Town*> > > futures;

	for(size_t i = 0; i < noOfSimulations; ++i)
		futures.push_back(async(launch::async, findArrangement_Evolution_Primitive<Org>, generations, organismCount, topToKeep) );

	//Quit threads and find best:
	vector<Town*> bestAnswer = futures[0].get();
	float bestDistance = findTotalDistance(bestAnswer);

	for(size_t i = 1; i < noOfSimulations; ++i)
	{
		vector<Town*> answer = futures[i].get();
		float distance = findTotalDistance(answer);
		if(distance < bestDistance)
		{
			bestDistance = distance;
			bestAnswer=answer;
		}
	}

	return bestAnswer;
}


////////////////////////////////////////////////////////////////////////////////////////

vector<Town*> findArrangement_Evolution_SelectBestMutation(size_t generations, size_t organismCount)
{
	//Organisms:
	vector<vector<Town*> > organisms;
	organisms.reserve(organismCount);
	for (size_t i = 0; i < organismCount; ++i)
	{
		organisms.push_back(gtowns);
		shuffle(organisms.back().begin(), organisms.back().end(), randEngine);
	}

	for (size_t iGen = 0; iGen < generations; ++iGen)
	{
		for (size_t iOrg = 0; iOrg < organismCount; ++iOrg)
		{
			//Mutate organism:
			float initialDistance = findTotalDistance(organisms[iOrg]);
			size_t swapa = rand(0, organisms[iOrg].size() - 1);
			size_t swapb;

			do
			{
				swapb = rand(0, organisms[iOrg].size() - 1);
			} while (swapa == swapb);

			swap(organisms[iOrg][swapa], organisms[iOrg][swapb]);

			if (findTotalDistance(organisms[iOrg]) > initialDistance)
			{
				//swap back
				swap(organisms[iOrg][swapa], organisms[iOrg][swapb]);

			} //else keep
		}

		//Print once and again:
		if (iGen % 1000 == 0)
		{
			sort(organisms.begin(), organisms.end(), [](const vector<Town*>& t1, const vector<Town*>& t2)
			{return findTotalDistance(t1) < findTotalDistance(t2); });

			cerr << "(" << (float(iGen) / generations*100.f) << ", " <<
				findTotalDistance(organisms.front()) << "); ";

			//Also, shuffle the worst 1/4th:
			size_t sindex = organisms.size() - organisms.size() / 4;
			for (size_t i = sindex; i < organisms.size(); ++i)
				shuffle(organisms[i].begin(), organisms[i].end(), randEngine);
		}
	}

	sort(organisms.begin(), organisms.end(), [](const vector<Town*>& t1, const vector<Town*>& t2)
	{return findTotalDistance(t1) < findTotalDistance(t2); });
	return organisms.front();
}


////////////////////////////////////////////////////////////////////////////////////////

//Temperature is the percentage chance of accepting a bad answer. It slowly reduces until zero.
vector<Town*> findArrangement_Evolution_SelectBestMutation_Temperature(size_t generations, size_t organismCount, size_t startTemp = 50)
{
	size_t currentTemp = startTemp;

	//Organisms:
	vector<vector<Town*> > organisms;
	organisms.reserve(organismCount);
	for (size_t i = 0; i < organismCount; ++i)
	{
		organisms.push_back(gtowns);
		shuffle(organisms.back().begin(), organisms.back().end(), randEngine);
	}

	vector<Town*> best = organisms[0];
	float bestDistance = findTotalDistance(organisms[0]);

	for (size_t iGen = 0; iGen < generations; ++iGen)
	{
		currentTemp = (size_t)(1.f - (float)iGen / generations) * startTemp;
		for (size_t iOrg = 0; iOrg < organismCount; ++iOrg)
		{
			//Mutate organism:
			float initialDistance = findTotalDistance(organisms[iOrg]);
			size_t swapa = rand(0, organisms[iOrg].size() - 1);
			size_t swapb;

			do
			{
				swapb = rand(0, organisms[iOrg].size() - 1);
			} while (swapa == swapb);

			swap(organisms[iOrg][swapa], organisms[iOrg][swapb]);

			if (rand(0, 100) < currentTemp && findTotalDistance(organisms[iOrg]) > initialDistance)
			{
				//swap back if temperature accepts
				swap(organisms[iOrg][swapa], organisms[iOrg][swapb]);

			} //else keep
		}

		sort(organisms.begin(), organisms.end(), [](const vector<Town*>& t1, const vector<Town*>& t2)
		{return findTotalDistance(t1) < findTotalDistance(t2); });

		float currentDistance;
		if ((currentDistance = findTotalDistance(organisms.front())) < bestDistance)
		{
			bestDistance = currentDistance;
			best = organisms.front();
		}

		//Print once and again:
		if (iGen % 2000 == 0)
		{

			cerr << "(" << (float(iGen) / generations*100.f) << ", " <<
				findTotalDistance(best) << "); ";

			//Also, shuffle the worst 1/5th:
			size_t sindex = organisms.size() - organisms.size() / 5;
			for (size_t i = sindex; i < organisms.size(); ++i)
				shuffle(organisms[i].begin(), organisms[i].end(), randEngine);
		}
	}

	return best;
}

////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////