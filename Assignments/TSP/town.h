
class Town
{
	string _name;
	vec2 _pos;
	Town* _back, *_next;
	size_t _id;
	vector<float> townDistancesTable;
	

	void initFromLine(string line)
	{
		removeCommas(line);

		stringstream ss;
		ss<<line;
		ss>>_id;
		ss>>_name;
		ss>>_pos.x;
		ss>>_pos.y;
	}

	void removeCommas(string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
			if(s[i]==',')
				s[i]=' ';
	}

	

	static size_t counter;

public:

	vector<Town*> townsByDistance;

	void addDistancePrecalulation(Town& t)
	{
		townDistancesTable[t._id-1] = haversine(_pos,t._pos);
	}

	float getTownDistance(const Town& t) const
	{
		return townDistancesTable[t._id-1];
	}

	void initTownsByDistance(vector<Town*>& globalTowns)
	{
		townsByDistance = globalTowns;
		sort(townsByDistance.begin(), townsByDistance.end(), [&] (const Town* t1, const Town* t2)
		{return t1->getTownDistance(*this) < t2->getTownDistance(*this);});
	}



	Town (const string& line)
	{
		_back = _next = NULL;
		initFromLine(line);
		townDistancesTable.resize(1000);
		townsByDistance.resize(1000);
	}

	friend ostream& operator << (ostream& str, const Town& town)
	{
		str<<town._name<<": ("<<town._pos.x<<", "<<town._pos.y<<")";
		return str;
	}

	size_t id() const
	{
		return _id;
	}

	size_t findClosestIndex (const vector<Town*>& towns)
	{
		float min = haversine(_pos,towns[0]->_pos);
		size_t index = 0;

		for(size_t i = 1; i < towns.size(); ++i)
		{
			float current = getTownDistance(*towns[i]);
			if(current<min)
			{
				min = current;
				index = i;
			}
		}
		return index;
	}
};
