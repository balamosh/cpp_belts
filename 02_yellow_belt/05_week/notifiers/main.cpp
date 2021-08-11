#include <iostream>

#include "notifiers.cpp"

using namespace std;

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}
