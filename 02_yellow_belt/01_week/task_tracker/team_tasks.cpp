#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
#include "structures.h"

using namespace std;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const
  {
	  return (tasks.at(person));
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person)
  {
	  ++tasks[person][TaskStatus::NEW];
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count)
  {
	  task_count = min(task_count, TasksCountUnfinished(person));
	  /*cout << endl 
		  << "===========" << endl
		  << "task count = " << task_count<< endl 
		  << "===========" << endl;*/
	  TasksInfo	updated;
	  TasksInfo	rest;
	  int		i = 0;
	  for (const auto& [info, count] : tasks[person])
	  {
		  for (int j = 0; j < count; j++)
		  {
		  	if (i < task_count)
			{
				TaskStatus	new_info = static_cast<TaskStatus>(static_cast<int>(info) + 1);
				++updated[new_info];
				i++;
			}
			else
				++rest[info];
		  }
	  }
	  for (const auto& info : {TaskStatus::NEW,
			  	   TaskStatus::IN_PROGRESS,
				   TaskStatus::TESTING,
				   TaskStatus::DONE})
	  {
		  int	new_count = 0;
		  if (updated.count(info))
			  new_count += updated.at(info);
		  if (rest.count(info))
			  new_count += rest.at(info);
		  if (new_count)
		  	tasks[person][info] = new_count;
	  }
	  rest.erase(TaskStatus::DONE);
	  return {updated, rest};
  }
private:
  map<string, TasksInfo>	tasks;

  int	TasksCountUnfinished(const string& person) const
  {
	  int	count = 0;
	  if (tasks.at(person).count(TaskStatus::NEW))
		  count += tasks.at(person).at(TaskStatus::NEW);
	  if (tasks.at(person).count(TaskStatus::IN_PROGRESS))
		  count += tasks.at(person).at(TaskStatus::IN_PROGRESS);
	  if (tasks.at(person).count(TaskStatus::TESTING))
		  count += tasks.at(person).at(TaskStatus::TESTING);
	  return (count);

  }
};
