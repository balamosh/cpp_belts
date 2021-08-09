#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Person
{
	public:
		void	ChangeFirstName(int year, const string& first_name)
		{
			first_name_dict[year] = first_name;
		}
		
		void	ChangeLastName(int year, const string& last_name)
		{
			last_name_dict[year] = last_name;
		}
		
		string	GetFullName(int year)
		{
			string	first_name = FindFirstName(year);
			string	last_name = FindLastName(year);
			if (first_name == "" && last_name == "")
			{
				return ("Incognito");
			}
			else if (first_name == "")
			{
				string	out = "";
				out += last_name;
				out += " with unknown first name";
				return (out);
			}
			else if (last_name == "")
			{

				string	out = "";
				out += first_name;
				out += " with unknown last name";
				return (out);
			}
			else
			{
				string	out = "";
				out += first_name;
				out += " ";
				out += last_name;
				return (out);
			}
		}
	private:
		map<int, string>	first_name_dict;
		map<int, string>	last_name_dict;

		string	Find(int year, const map<int, string>& dict)
		{
			auto	it = dict.upper_bound(year);
			if (it == begin(dict))
				return ("");
			return ((--it)->second);
		}

		string	FindFirstName(int year)
		{
			return (Find(year, first_name_dict));
		}

		string	FindLastName(int year)
		{
			return (Find(year, last_name_dict));
		}
};
