#include <string>

#include "functions.cpp"

using namespace std;

class INotifier
{
	public:
		INotifier(const string& new_id) : id(new_id) {}

		virtual void	Notify(const string& message) const = 0;

		const string	id;
};

class SmsNotifier : public INotifier
{
	public:
		SmsNotifier(const string& new_id) : INotifier(new_id) {}

		void	Notify(const string& message) const
		{
			SendSms(id, message);
		}
};

class EmailNotifier : public INotifier
{
	public:
		EmailNotifier(const string& new_id) : INotifier(new_id) {}

		void	Notify(const string& message) const
		{
			SendEmail(id, message);
		}
};
