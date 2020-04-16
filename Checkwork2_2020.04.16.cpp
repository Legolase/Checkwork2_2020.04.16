#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct period {
public:
	int begin, end;
};

bool intersection(period a, period b) {//узнаём, пересекаются ли периоды
	if (a.begin > b.begin)
		swap(a, b);
	if (a.end > b.begin)
		return true;
	else
		return false;
}

bool cmp1(period a, period b) {
	return a.begin < b.begin;
}

bool cmp2(period a, period b) {
	return abs(a.begin - a.end) >= abs(b.begin - b.end);
}

int main() {
	int n{};
	vector< vector<period> > rooms;
	vector<period> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		period c;
		cin >> c.begin >> c.end;
		v.push_back(c);
	}
	stable_sort(v.begin(), v.end(), cmp1);
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