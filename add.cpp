#include <iostream>
#include <string>
using namespace std;

int intConv( char x )
{
	if(x == '0')
		return 0;
	else if(x == '1')
		return 1;
	else if(x == '2')
		return 2;
	else if(x == '3')
		return 3;
	else if(x == '4')
		return 4;
	else if(x == '5')
		return 5;
	else if(x == '6')
		return 6;
	else if(x == '7')
		return 7;
	else if(x == '8')
		return 8;
	else
		return 9;
}

char charConv( int x )
{
	if(x == 0)
		return '0';
	else if(x == 1)
		return '1';
	else if(x == 2)
		return '2';
	else if(x == 3)
		return '3';
	else if(x == 4)
		return '4';
	else if(x == 5)
		return '5';
	else if(x == 6)
		return '6';
	else if(x == 7)
		return '7';
	else if(x == 8)
		return '8';
	else if(x == 10)
		return '0';
	else if(x == 11)
		return '1';
	else if(x == 12)
		return '2';
	else if(x == 13)
		return '3';
	else if(x == 14)
		return '4';
	else if(x == 15)
		return '5';
	else if(x == 16)
		return '6';
	else if(x == 17)
		return '7';
	else if(x == 18)
		return '8';
	else
		return '9';
}

bool check(string str)
{
	unsigned int count = 0;

	if(str.size() > 1 && str.at(0) == '-')
		count = 1;

	for(unsigned int i = count; i < str.size(); i++)
	{
		if(str.at(i) != '0' && str.at(i) != '1' && str.at(i) != '2' && str.at(i) != '3' && str.at(i) != '4' && str.at(i) != '5' && str.at(i) != '6' && str.at(i) != '7' && str.at(i) != '8' && str.at(i) != '9' )
			return false;
	}
	return true;
}

void reverse(string &rev)	// this switches the string to its inverse which is used in several places in the program
{
	string temp;
	for( unsigned int i = rev.size(); i > 0; i--)
		temp.push_back( rev.at(i-1) );
	rev = temp;
};

void grow(string &grow, string base)	// this makes both strings the same size
{
	unsigned int count = base.size() - grow.size();
	string temp;
	for( unsigned int i = 0; i < count; i++)
		temp.push_back('0');
	for( unsigned int i = 0; i < grow.size(); i++)
		temp.push_back( grow.at(i) );

	grow = temp;
}

string add(string one, string two)
{
	string S_ENT3;
	if( one.size() > two.size() ) // this only happens if one integer has more places than the other
		grow(two, one);
	else if( two.size() > one.size() ) // this only happens if one integer has more places than the other
		grow(one, two);

	reverse(one);
	reverse(two);

	int temp = 0;

	for( unsigned int i = 0; i < one.size(); i++ )
	{
			S_ENT3.push_back( charConv( temp + intConv( one.at(i) ) + intConv( two.at(i) ) ) );
			temp = ( temp + intConv( one.at(i) ) + intConv( two.at(i) ) ) / 10;
	}

	if(temp == 1)
		S_ENT3.push_back('1');

	reverse(S_ENT3);

	return S_ENT3;
};

bool big( string one, string two)
{
	if( one < two )
		return false;

	return true;
}

string sub(string pos, string neg)
{
	string S_ENT3;
	if( pos.size() > neg.size() ) // this only happens if one integer has more places than the other
		grow(neg, pos);
	else if( neg.size() > pos.size() ) // this only happens if one integer has more places than the other
		grow(pos, neg);

	if(pos == neg)
		S_ENT3 = '0';

	else if(big(neg,pos) == true)	// neg is big than pos
	{
		reverse(pos);
		reverse(neg);

		for(unsigned int i = 0; i < neg.size(); i++)
		{
			if( neg.at(i) < pos.at(i) && neg.at(i+1) != '0' )	// what if the next one == 0?!?!
			{
				neg.at(i+1) = charConv( intConv( neg.at(i+1) ) - 1 );
				S_ENT3.push_back( charConv( intConv( neg.at(i) ) + 10 - intConv( pos.at(i) ) ) );
			}
			else if( neg.at(i) < pos.at(i) && pos.at(i+1) == '0' )	// if pos.at(i+1) = 0 move on to the next one
			{
				unsigned int count = 1;

				while( neg.at(i+count) == '0' )
				{
					neg.at(i+count) = '9';
					count++;
				}
				neg.at(i+count) = charConv( intConv( neg.at(i+count) ) - 1 );
				S_ENT3.push_back( charConv( intConv( neg.at(i) ) + 10 - intConv( pos.at(i) ) ) );
			}
			else
				S_ENT3.push_back( charConv( intConv(neg.at(i)) - intConv(pos.at(i)) ) );
		}

		S_ENT3.push_back('-');
		reverse(S_ENT3);

		while( S_ENT3.at(1) == '0' )
			S_ENT3.erase( S_ENT3.begin() + 1 );

	}
	else	// pos is greater than neg
	{
		reverse(pos);
		reverse(neg);

		for(unsigned int i = 0; i < pos.size(); i++)
		{
			if( pos.at(i) < neg.at(i) && pos.at(i+1) != '0' )	// what if the next one == 0?!?!
			{
				pos.at(i+1) = charConv( intConv( pos.at(i+1) ) - 1 );
				S_ENT3.push_back( charConv( intConv( pos.at(i) ) + 10 - intConv( neg.at(i) ) ) );
				
			}
			else if( pos.at(i) < neg.at(i) && pos.at(i+1) == '0' )	// if pos.at(i+1) = 0 move on to the next one
			{
				unsigned int count = 1;

				while( pos.at(i+count) == '0' )
				{
					pos.at(i+count) = '9';
					count++;
				}
				pos.at(i+count) = charConv( intConv( pos.at(i+count) ) - 1 );
				S_ENT3.push_back( charConv( intConv( pos.at(i) ) + 10 - intConv( neg.at(i) ) ) );
			}
			else
				S_ENT3.push_back( charConv( intConv(pos.at(i)) - intConv(neg.at(i)) ) );
		}

		reverse(S_ENT3);
	}

	if( S_ENT3.size() > 1 )
		while( S_ENT3.at(0) == '0' )
			S_ENT3.erase( S_ENT3.begin() );

	return S_ENT3;
}

int main()
{
	string S_ENT1;	//first integer to be added
	string S_ENT2;	//second integer to be added

	cout << "\"exit\" to exit\nEnter 2 numbers to be added:\n";
	cin >> S_ENT1;	// input first string
	if(S_ENT1 == "exit")
		return 0;
	else
		while(check(S_ENT1) == false)	// check first string for correctness
		{
			cout << "ERROR: incorrect input\n\"exit\" to exit\nEnter 2 numbers to be added:\n";
			cin >> S_ENT1;
			if(S_ENT1 == "exit")
				return 0;
			else
				check(S_ENT1);
		}

	cin >> S_ENT2;	// input second string
	if(S_ENT2 == "exit")
		return 0;
	else
		while(check(S_ENT2) == false)	// check second string for correctness
		{
			cout << "ERROR: incorrect input\n\"exit\" to exit\nEnter second number to be added:\n";
			cin >> S_ENT2;
			if(S_ENT2 == "exit")
				return 0;
			else
				check(S_ENT2);
		}

	if(S_ENT1.at(0) == '-' && S_ENT2.at(0) == '-')
	{
		cout << S_ENT1 << " + " << S_ENT2 << " = ";
		S_ENT1.erase(S_ENT1.begin());
		S_ENT2.erase(S_ENT2.begin());
		cout << add(S_ENT1, S_ENT2) << endl;
	}
	else if(S_ENT1.at(0) == '-' && S_ENT2.at(0) != '-')
	{
		cout << S_ENT1 << " + " << S_ENT2 << " = ";
		S_ENT1.erase(S_ENT1.begin());
		cout << sub(S_ENT2, S_ENT1) << endl;	// 2 minus 1
	}
	else if(S_ENT2.at(0) == '-' && S_ENT1.at(0) != '-')
	{
		cout << S_ENT1 << " + " << S_ENT2 << " = ";
		S_ENT2.erase(S_ENT2.begin());
		cout << sub(S_ENT1, S_ENT2) << endl;	// 1 minus 2
	}
	else
		cout << S_ENT1 << " + " << S_ENT2 << " = " << add(S_ENT1, S_ENT2) << endl;

	main();

	return 0;
}
