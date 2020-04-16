#include <iostream>
#include <vector>

using namespace std;

struct period {
	int begin, end;
};

bool intersection(period a, period b) {//узнаём, пересекаются ли периоды
	if (a.end > b.begin) {
		period c = a;
		a = b;
		b = c;
	}
	if (a.end > b.begin)
		return true;
	else
		return false;
}

int main() {
	int n{};
	vector<period> v;
	vector< vector<period> > rooms;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			period c;
			cin >> c.begin >> c.end;
			v.push_back(c);
		}
		for (int i = 0; i < v.size(); ++i) {
			int found_room = -1;
			for (int j = 0; j < (int)rooms.size(); ++j) {
				bool intersec = false;
				for (int q = 0; q < rooms[j].size(); ++q) {
					if (intersection(rooms[j][q], v[i])) {
						intersec = true;
						break;
					}
				}
				if (intersec == false) {
					found_room = j;
					break;
				}
			}
			if (found_room == -1) {
				vector<period> new_room(1, v[i]);
				rooms.push_back(new_room);
			}
			else
				rooms[found_room].push_back(v[i]);
		}
		cout << rooms.size() << endl;
	}
}