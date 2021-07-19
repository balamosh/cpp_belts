#include <string>
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

		string	GetFullNameWithHistory(int year)
		{
			string	first_name = FindFirstName(year);
			string	last_name = FindLastName(year);
			string	first_name_history = HistoryFirstName(year, first_name);
			string	last_name_history = HistoryLastName(year, last_name);
			return (JoinFullNameHistory(first_name,
						last_name,
						first_name_history,
						last_name_history));
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
			if (max == -1)
				return ("");
			return (dict.at(max));
		}
		
		string	History(int year, const string& name, const map<int, string>& dict, const vector<int>& v)
		{
			vector<string>	history;
			string		prev = "";
			for (auto y : v)
			{
				string	curr;
				if (y <= year)
				{
					curr = dict.at(y);
					if (curr != prev)
					{
						history.push_back(curr);
						prev = curr;
					}
				}
			}
			int	len = history.size() - 1;
			string	out = "";
			if (len <= 0)
				return (out);
			for (int i = len - 1; i > 0; i--)
			{
				out += history[i];
				out += ", ";
			}
			out += history[0];
			return (out);
		}

		string	FindFirstName(int year)
		{
			return (Find(year, first_name_dict, first_name_years));
		}

		string	FindLastName(int year)
		{
			return (Find(year, last_name_dict, last_name_years));
		}

		string	HistoryFirstName(int year, const string& first_name)
		{
			return (History(year, first_name, first_name_dict, first_name_years));
		}
		
		string	HistoryLastName(int year, const string& last_name)
		{
			return (History(year, last_name, last_name_dict, last_name_years));
		}

		string	JoinNameHistory(const string& name, const string &history)
		{
			if (history == "")
				return (name);
			string	out = name;
			out += " (";
			out += history;
			out += ")";
			return (out);
		}

		string	JoinFullNameHistory(const string& first_name, const string& last_name,
					const string& first_name_history, const string& last_name_history)
		{
			string	first = JoinNameHistory(first_name, first_name_history);
			string	last = JoinNameHistory(last_name, last_name_history);
			if (first == "" && last == "")
				return ("Incognito");
			string	out = "";
			if (first == "")
			{
				out += last;
				out += " with unknown first name";
				return (out);
			}
			if (last == "")
			{
				out += first;
				out += " with unknown last name";
				return (out);
			}
			out += first;
			out += " ";
			out += last;
			return (out);
		}
};
