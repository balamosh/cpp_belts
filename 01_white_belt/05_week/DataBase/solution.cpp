#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date
{
	public:
		Date()
		{
			year = 0;
			month = 1;
			day = 1;
		}

		Date(int new_year, int new_month, int new_day)
		{
			if (new_month < 1 || new_month > 12)
				throw runtime_error("Month value is invalid: " + to_string(new_month));
			else if (new_day < 1 || new_day > 31)
				throw runtime_error("Day value is invalid: " + to_string(new_day));
			else
			{
				year = new_year;
				month = new_month;
				day = new_day;
			}
		}

		int	GetYear() const
		{
			return (year);
		}

		int	GetMonth() const
		{
			return (month);
		}

		int	GetDay() const
		{
			return (day);
		}
	
	private:
		int	year;
		int	month;
		int	day;
};

bool		operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return (lhs.GetDay() < rhs.GetDay());
		}
		else
			return (lhs.GetMonth() < rhs.GetMonth());
	}
	else
		return (lhs.GetYear() < rhs.GetYear());
}

istream&	operator>>(istream& stream, Date& date)
{
	string	date_str;
	stream >> date_str;
	stringstream	read(date_str);
	int		year, month, day;
	char		sep1, sep2;
	if (read >> year &&
		read >> sep1 &&
		read >> month &&
		read >> sep2 &&
		read >> day &&
		sep1 == '-' &&
		sep2 == '-' &&
		read.peek() == EOF)
	{
		date = Date(year, month, day);
	}
	else
		throw runtime_error("Wrong date format: " + date_str);
	return (stream);
}

ostream&	operator<<(ostream& stream, const Date& date)
{
	stream << setw(4) << setfill('0') << date.GetYear()
		<< '-'
		<< setw(2) << setfill('0') << date.GetMonth()
		<< '-'
		<< setw(2) << setfill('0') << date.GetDay();
	return (stream);
}

class Database
{
	public:
		void		ExecCommand(string command_full)
		{
			if (command_full == "")
				return ;
			stringstream	stream(command_full);
			string		command;
			stream >> command;
			if (command == "Add")
			{
				Date	date;
				string	event;
				stream >> date >> event;
				AddEvent(date, event);
			}
			else if (command == "Del")
			{
				Date	date;
				string	event;
				stream >> date;
				if (stream >> event)
				{
					if (DeleteEvent(date, event))
						cout << "Deleted successfully" << endl;
					else
						cout << "Event not found" << endl;
				}
				else
				{
					cout << "Deleted "
						<< DeleteDate(date)
						<< " events" << endl;
				}
			}
			else if (command == "Find")
			{
				Date		date;
				stream >> date;
				set<string>	found_events = Find(date);
				for (const auto& event : found_events)
					cout << event << endl;
			}
			else if (command == "Print")
				Print();
			else
				throw runtime_error("Unknown command: " + command);
		}

		void		AddEvent(const Date& date, const string& event)
		{
			events[date].insert(event);
		}

		bool		DeleteEvent(const Date& date, const string& event)
		{
			if (events.count(date) && events[date].count(event))
			{
				events[date].erase(event);
				return (true);
			}
			else
				return (false);
		}

		int		DeleteDate(const Date& date)
		{
			if (events.count(date) == 0)
				return (0);
			int	size = events[date].size();
			events[date].clear();
			return (size);
		}

		set<string>	Find(const Date& date) const
		{
			if (events.count(date))
				return (events.at(date));
			else
				return set<string>();
		}

		void		Print() const
		{
			for (const auto& date : events)
			{
				for (const auto& event : date.second)
				{
					cout << date.first << ' ' << event << endl;
				}
			}
		}
	
	private:
		map<Date, set<string>>	events;
};

int	main()
{
	Database db;

	string	command;
	while (getline(cin, command))
	{
		// Считайте команды с потока ввода и обработайте каждую
		try
		{
			db.ExecCommand(command);
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
	return (0);
}
