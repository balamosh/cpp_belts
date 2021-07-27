#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>
//#include "structures.h"

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
		  tasks[person][info] = updated[info] + rest[info];
	  }
	  rest.erase(TaskStatus::DONE);
	  EraseZeros(tasks[person]);
	  EraseZeros(updated);
	  EraseZeros(rest);
	  return {updated, rest};
  }
private:
  map<string, TasksInfo>	tasks;

  int	TasksCountUnfinished(const string& person)
  {
		  return (tasks[person][TaskStatus::NEW]
			+ tasks[person][TaskStatus::IN_PROGRESS]
			+ tasks[person][TaskStatus::TESTING]);
  }

  void	EraseZeros(TasksInfo& map_to_erase)
  {
	  vector<TaskStatus>	statuses_to_remove;
	  for (const auto& [info, count] : map_to_erase)
	  {
		  if (count == 0)
			  statuses_to_remove.push_back(info);
	  }
	  for (const TaskStatus& status : statuses_to_remove)
	  {
		  map_to_erase.erase(status);
	  }
  }
};
