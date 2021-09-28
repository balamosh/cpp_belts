#include <iostream>
#include <cstdint>
#include <map>
#include <queue>

using namespace std;

struct BookingInfo {
	int64_t	time;
	int		client_id;
	int		room_count;
};

class HotelInfo {
private:
	queue<BookingInfo>	booking_queue;
	map<int, int>		client_bookings_count;
	size_t				total_rooms;
public:
	void		Book(const BookingInfo& new_booking) {
		booking_queue.push(new_booking);
		client_bookings_count[new_booking.client_id] += 1;
		total_rooms += new_booking.room_count;
		RemoveOld(new_booking.time);
	}

	size_t		Clients(int64_t curr_time) {
		RemoveOld(curr_time);
		return (client_bookings_count.size());
	}

	size_t		Rooms(int64_t curr_time) {
		RemoveOld(curr_time);
		return (total_rooms);
	}

	void		RemoveOld(int64_t curr_time) {
		while (booking_queue.size() > 0 && curr_time - booking_queue.front().time >= 86400) {
			const BookingInfo&	booking = booking_queue.front();
			if (client_bookings_count[booking.client_id] == 1) {
				client_bookings_count.erase(booking.client_id);
			}
			else {
				client_bookings_count[booking.client_id] -= 1;
			}
			total_rooms -= booking.room_count;
			booking_queue.pop();
		}
	}
};

int	main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, HotelInfo>	manager;
	int64_t					curr_time;
	
	int query_count;
	cin >> query_count;

	for (int query_id = 0; query_id < query_count; ++query_id) {
		string	query_type, hotel_name;
		cin >> query_type;
		
		if (query_type == "BOOK") {
			int64_t	time;
			int		client_id, room_count;
			cin >> time >> hotel_name >> client_id >> room_count;
			manager[hotel_name].Book({time, client_id, room_count});
			curr_time = time;
		} else if (query_type == "CLIENTS") {
			cin >> hotel_name;
			cout << manager[hotel_name].Clients(curr_time) << "\n";
		} else if (query_type == "ROOMS") {
			cin >> hotel_name;
			cout << manager[hotel_name].Rooms(curr_time) << "\n";
		}
	}
	return 0;
}