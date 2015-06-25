#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef std::pair<int,int> Coord;

int grid[9][9];


void printGrid()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout<<grid[i][j]<<" ";
		cout<<"\n";
	}
}

bool validateSquare(int x, int y)
{
	int n = grid[x][y];
	if (n==0)
		return false;

	int a=0,b=0,c=0;

	for (int i = 0; i < 9; ++i)
	{
		a += (grid[x][i]==n);
		b += (grid[i][y]==n);
	}

	pair<int,int> sectionCoord = make_pair(x/3, y/3); //needed because of truncation
	int endi = 3*sectionCoord.first+3;
	int endj = 3*sectionCoord.second+3;

	for (int i = 3*sectionCoord.first; i < endi; ++i)
		for(int j = 3*sectionCoord.second; j < endj; ++j)
			if (grid[i][j] == n)
				++c;

	return a<2 && b<2 && c<2;
}

int level = 0;

pair<bool,vector<int> > solve_rec(vector<Coord>& remainingEmpty, int startIndex=0)
{
		Coord current = remainingEmpty[startIndex]; //should have >1 elements

		//Find possible values that it could take.
		std::vector<int> possibleValues;
		possibleValues.reserve(9);
		int& square = grid[current.first][current.second];
		for(int i = 1; i < 10; ++i)
		{
			square=i;
			if (validateSquare(current.first, current.second))
				possibleValues.push_back(i);
			square=0; //reset to default
		}

		//impossible
		if (possibleValues.size()==0)
			return pair<bool,vector<int> >(false, {-1});

		//if done, should have only one solution:
		if (remainingEmpty.size()-startIndex==1)
			if (possibleValues.size()==1)
				return pair<bool,vector<int> >(true, {possibleValues[0]});
			else
				return pair<bool,vector<int> >(false,{-2});
				


		//If not done but possibility, try possibility n until it's valid.
		for (vector<int>::iterator pv = possibleValues.begin(); pv!=possibleValues.end(); ++pv)
		{			
			square = *pv;
			pair<bool,vector<int> > recAnswer = solve_rec(remainingEmpty, startIndex+1);
			square = 0;
			//if valid, return:
			if (recAnswer.first)
			{
				std::vector<int>vec = vector<int>{*pv};
				
				vec.insert(vec.end(), recAnswer.second.begin(), recAnswer.second.end());
				return pair<bool,vector<int> >(true, vec);
			}
		}
		
		//if reached here, no possibilities
	return pair<bool,vector<int> >(false, {-1});

}





int main(int argc, char**argv)
{
	if(argc != (1+9*9))
	{
		return -1;
	}

	

	for (int i = 0; i < 81; ++i)
		grid[i/9][i%9] = atoi(argv[1+i]);

	std::vector<Coord> blanks;
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			if(grid[i][j]==0)
				blanks.push_back(make_pair(i,j));
	pair<bool,vector<int> > answer = solve_rec(blanks);

	for(int i = 0; i < answer.second.size(); ++i)
		cout<<answer.second[i]<< " ";

	cout<<"\n\n"<<answer.second.size()<<"\n";

	//talk about recursion
}