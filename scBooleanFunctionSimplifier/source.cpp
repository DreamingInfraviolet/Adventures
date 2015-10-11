#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <stack>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
#include "assert.h"

typedef char Token;
/**
Class designed to simplify a boolean function string.
String format:
& to represent AND.
| to represent OR.
() to represent brackets (duh).
! to represent NOT.
^ to represent XOR.
1 for true
0 for false
*/

/**A container for a minterm that overrides the comparison operators to sort by the number of 1's in binary.*/
class DistanceOrderedMinterm
{
public:
	unsigned minterm;
	int countOfOnes;

	DistanceOrderedMinterm(unsigned m) : minterm(m), countOfOnes(determineCount())
	{}

	int determineCount() const
	{
		const unsigned m1 = 0x55555555; //0101...
		const unsigned m2 = 0x33333333; //00110011...
		const unsigned m4 = 0x0f0f0f0f; //00001111...

		int x = minterm;
		x-=(x>>1)&m1;
		x=(x&m2)+((x>>2)&m2);
		x=(x+(x>>4))&m4;
		x+=x>>8;
		x+=x>>16;
		return x&0x7f;
	}

	void operator = (const DistanceOrderedMinterm& d)
	{
		minterm=d.minterm;
		countOfOnes=d.countOfOnes;
	}

	bool operator < (const DistanceOrderedMinterm& d) const
	{
		return countOfOnes<d.countOfOnes;
	}

	bool operator > (const DistanceOrderedMinterm& d) const
	{
		return countOfOnes>d.countOfOnes;
	}
};

class BooleanFunctionSimplifier
{
public:
	/**Sets the boolean function string, cleaning it automatically.*/
	bool setString(const std::string & str);

	/**Simplifies the boolean function*/
	void simplify();

	/**Returns the contained function string.*/
	std::string getString() const;

private:


	std::string mString;

	/**Removes rubbish data from string, such as spaces.*/
	void cleanString();

	/**Returns a set of the variables encountered in the string.*/
	std::set < Token > getAlphabet() const;

	/**Returns a copy of mString after the shunting yard algorithm*/
	std::string shuntingYard() const;

	/**Verifies whether the inputted string is valid. (basic checks)*/
	bool validateString();

	int getOperatorPrecedence(const Token t) const;

	/**Returns a vector of ints which represent possible bool combinations which result true when applied to the function.*/
	std::vector<DistanceOrderedMinterm> findMinterms(std::set < Token > &alphabet, std::string & str);

	/**Evaluates the function for a combination of inputs. map<variable name, value>.*/
	bool evaluate(std::string str, std::map < Token, bool > &value);
	
	/**Converts a given number into the corresponding string.*/
	std::string toString (int i) const;

	/**Creates a simplifier string using the method.*/
	std::string quineMcCluskey(std::vector <DistanceOrderedMinterm>& minterms) const;

	/**Recursively used by QM to find all prime implicants.*/
	std::string qmRecursion(std::vector <std::vector<std::pair<DistanceOrderedMinterm, unsigned> >>& minterms) const;

	/**
	* Generates indices of different bit counts in the form [first,last).
	* @param minterms vector<pair<Distance Ordered Minterms, locations of any dashes>>
*/
	std::vector<std::pair<int,int> > qmGenerateBitcountIndices(std::vector<std::pair<DistanceOrderedMinterm, unsigned> >& minterms) const;
};

std::string BooleanFunctionSimplifier::toString(int i) const
{
	std::ostringstream iss;
	iss << i;
	return std::string(iss.str());
}

bool BooleanFunctionSimplifier::validateString()
{
	bool lastCharOp = false;	// indicates whether the last character was an
	// operator, not including '!'

	for (unsigned i = 0; i < mString.size(); ++i)
	{
		if (getOperatorPrecedence(mString[i]) != -1 && mString[i] != '!')
		{
			if (lastCharOp)
				return false;
			else
				lastCharOp = true;
		}
		else
			lastCharOp = false;
	}
	return true;
}

int BooleanFunctionSimplifier::getOperatorPrecedence(const Token t) const
{
	switch (t)
	{
		case '^':
		return 2;
		case '&':return 1;
		case '|':return 0;
		case '!':return 3;
		default:return -1;	// not a token
	}
}

std::string BooleanFunctionSimplifier::shuntingYard() const
{
	std::string queue;
	std::string tokens = mString;
	std::stack < Token > stack;

	std::reverse(tokens.begin(), tokens.end());

	int operatorPrecedence;

	while (tokens.size())
	{
		// If letter or number
		if (isalnum(tokens.back()))
			queue.push_back(tokens.back());
		else if (tokens.back() == '!')
		{
			stack.push('!');
		}
		// If operator
		else if ((operatorPrecedence = getOperatorPrecedence(tokens.back())) != -1)
		{
			while (stack.size())
			{
				if (operatorPrecedence <= getOperatorPrecedence(stack.top()))
				{
					queue.push_back(stack.top());
					stack.pop();
				}
				else
					break;
			}
			stack.push(tokens.back());
		}
		else if (tokens.back() == '(')
		{
			stack.push('(');
		}
		else if (tokens.back() == ')')
		{
			while (stack.size()and stack.top() != '(')
			{
				queue.push_back(stack.top());
				stack.pop();
			}
			if (stack.size() == 0)
			{
				std::cout << "Mismatched parentheses! [1]";
				return "";
			}
			stack.pop();
		}

		tokens.pop_back();
	}

	// Pop final tokens and second parentheses check:
	while (stack.size())
	{
		if (stack.top() == '(' || stack.top() == ')')
		{
			std::cout << "Mismatched parentheses! [2]";
			return "";
		}

		queue.push_back(stack.top());
		stack.pop();
	}
	// std::cout<<queue;
	return queue;
}

void BooleanFunctionSimplifier::cleanString()
{
	std::string newStr;
	for (unsigned i = 0; i < mString.size(); ++i)
	{
		if (!isalpha(mString[i]) and getOperatorPrecedence(mString[i]) == -1 and mString[i] !=
				'(' and mString[i] != ')' and mString[i] != '1' and mString[i] != '0')
			continue;
		else
			newStr.push_back(mString[i]);
	}
	mString = newStr;
}

bool BooleanFunctionSimplifier::setString(const std::string & str)
{
	mString = str;
	cleanString();
	if (!validateString())
	{
		std::cout << "Invalid string!\n";
		return false;
	}
	return true;
}

std::set < Token > BooleanFunctionSimplifier::getAlphabet() const
{
	std::set < Token > out;

	for (unsigned i = 0; i < mString.size(); ++i)
	{
		if (isalpha(mString[i]))
			out.insert(Token(mString[i]));
	}
	return out;
}

std::vector <DistanceOrderedMinterm >BooleanFunctionSimplifier::findMinterms
			(std::set < Token > &alphabet,std::string & str)
{
	// Create a certesian product of possibilities and evaluate all.
	unsigned numberOfCombinations = std::pow(2, alphabet.size());
	std::vector < DistanceOrderedMinterm >minterms;

	std::map < Token, bool > combination; //The current combination of tokens

	for (unsigned i = 0, currentCombinationBits=0; i < numberOfCombinations; ++i, ++currentCombinationBits)
	{
		unsigned index = 0;
		for (auto it = alphabet.begin(); it != alphabet.end(); ++it)
		{
			combination[*it] = (currentCombinationBits >> index) & 1;
			++index;
		}

		if (evaluate(str, combination))
			minterms.push_back(DistanceOrderedMinterm(currentCombinationBits));
	}

	std::sort(minterms.begin(),minterms.end());
	return minterms;
}

bool BooleanFunctionSimplifier::evaluate(std::string str, std::map < Token, bool > &value)
{
	for (unsigned i = 0; i < str.size(); ++i)
		if (isalpha(str[i]))
			str[i] = value[str[i]] ? '1' : '0';	// Replace variable with its
	// value

	// Evaluate using the algorithm XD
	std::stack<bool> stack; //Keeps track of values
	for (unsigned iStr=0; iStr<str.size(); ++iStr)
	{
		Token token = str[iStr];
		if (token=='1'||token=='0') //if a number
			stack.push(token=='1');
		else //operator
		{
			unsigned argcount = token=='!' ? 1:2;
			if (stack.size()<argcount)
			{
				std::cout<<"Binary operator missing value!\n";
				return false;
			}
			
			bool a1 = stack.top()==true;
			stack.pop();
			bool a2;
			if (token!='!')
			{
				a2=stack.top()==1;
				stack.pop();
			}
			
			switch (token)
			{
				case '!':
					stack.push(!a1);
				break;
				case '&':
					stack.push(a1&&a2);
				break;
				case '^':
					stack.push(a1!=a2);
				break;
				case '|':
					stack.push(a1||a2);
				break;
				default:
				{
					std::cout<<"ERROR";
					return false;
				}
			}
		}
	}
	if (stack.size()!=1)
	{
		std::cout<<"ERROR2";
		return false;
	}
	else
		return stack.top();
}

std::string BooleanFunctionSimplifier::getString() const
{
	return mString;
}

std::vector<std::pair<int,int> > BooleanFunctionSimplifier::qmGenerateBitcountIndices
																			(std::vector <std::pair<DistanceOrderedMinterm, std::vector<unsigned> > >& minterms) const
{
	std::vector<std::pair<int,int> > bitLocations; //Bit count ranges. 0th element is the range for combinations with 0 ones, etc. [first,last)
	bitLocations.resize(minterms.back().countOfOnes+1,{-1,-1});
	int prevOneCount=-1;
	for (unsigned i = 0; i < minterms.size();++i)
	{
		if (minterms[i].countOfOnes>prevOneCount)
		{
			prevOneCount=minterms[i].countOfOnes;
			bitLocations[prevOneCount] = std::make_pair(i,i);
		}
		++bitLocations[prevOneCount].second;
	}

	//Remove unused bit counts:
	std::vector<std::pair<int,int> > bitLocationsTemp;
	bitLocationsTemp.reserve(bitLocations.size());
	for (unsigned i = 0; i < bitLocations.size();++i)
	{
		if (bitLocations[i].first!=-1)
			bitLocationsTemp.push_back(bitLocations[i]);
	}
	std::vector<std::pair<int,int> >out = bitLocationsTemp;
	return out;
}

//vector<pair<combination, vector<dashes>>>
std::vector<unsign,std::vector<unsigned> > BooleanFunctionSimplifier::quineMcCluskey(
std::vector <std::pair<DistanceOrderedMinterm,std::vector<unsigned> > > in) 
const
{
	//minterms vector<pair<Distance Ordered Minterms, locations of any dashes>>
	std::vector<std::pair<int,int> > indices = qmGenerateBitcountIndices(in);

return ":P";
}

/*Do I need it?
std::vector<qmRecursion(std::vector <std::vector<std::pair<DistanceOrderedMinterm, unsigned> >>& minterms) const
{

}
*/


void BooleanFunctionSimplifier::simplify()
{
	std::set < Token > alphabet = getAlphabet();
	std::string str = shuntingYard();
	std::vector <DistanceOrderedMinterm>minterms = findMinterms(alphabet, str);
	std::string simplified = quineMcCluskey(minterms);

}

int main()
{

	BooleanFunctionSimplifier simplify;
	simplify.setString("a&a|b");
	simplify.simplify();
	//std::cout << simplify.getString()<<"\nDone.\n";
}