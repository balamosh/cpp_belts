#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Person
{
	public:
		void	ChangeFirstName(int year, const string& first_name)
		{
			first_name_dict[year] = first_name;
			first_name_years.push_back(year);
			sort(first_name_years.begin(), first_name_years.end());
		}
		
		void	ChangeLastName(int year, const string& last_name)
		{
			last_name_dict[year] = last_name;
			last_name_years.push_back(year);
			sort(last_name_years.begin(), last_name_years.end());
		}
		
		string	GetFullName(int year)
		{
			if (first_name_dict.count(year) == 0 &&
				(first_name_years.size() == 0 || first_name_years[0] > year) &&
				last_name_dict.count(year) == 0 &&
				(last_name_years.size() == 0 || last_name_years[0] > year))
			{
				return ("Incognito");
			}
			else if (first_name_dict.count(year) == 0 &&
				(first_name_years.size() == 0 || first_name_years[0] > year))
			{
				string	out = "";
				out += FindLastName(year);
				out += " with unknown first name";
				return (out);
			}
			else if (last_name_dict.count(year) == 0 &&
				(last_name_years.size() == 0 || last_name_years[0] > year))
			{

				string	out = "";
				out += FindFirstName(year);
				out += " with unknown last name";
				return (out);
			}
			else
			{

				string	out = "";
				out += FindFirstName(year);
				out += " ";
				out += FindLastName(year);
				return (out);
			}
		}
	private:
		map<int, string>	first_name_dict;
		map<int, string>	last_name_dict;
		vector<int>		first_name_years;
		vector<int>		last_name_years;

		string	Find(int year, const map<int, string>& dict, const vector<int>& v)
		{
			if (dict.count(year))
				return (dict.at(year));
			int	max = -1;
			for (auto y : v)
			{
				if (y < year)
					max = y;
				else
					break ;
			}
			return (dict.at(max));
		}

		string	FindFirstName(int year)
		{
			return (Find(year, first_name_dict, first_name_years));
		}

		string	FindLastName(int year)
		{
			return (Find(year, last_name_dict, last_name_years));
		}
};
