#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& output, const Movie& eventExample);
private:
	int year;
	string title;
public:
	Movie() : year(2019), title("Default") {}
	Movie(int year, string title) : year(year), title(title) {}
	int getYear() const { return year; }
	string getTitle() const { return title; }
};

ostream& operator<<(ostream& output, const Movie& eventExample)
{
	output << eventExample.getYear() << " " << eventExample.getTitle();
	return output;
}

int main()
{
	/*Practice unordered map, it usse hash table, it can be duplicate; it replace old value
	  It is O(1) because it hash table	
	*/
	unordered_map<int, Movie> eventMap;
	//Create the events
	Movie movie1(2012, "Avenger");
	Movie movie2(2015, "Avenger - Age Of Ultron");
	Movie movie3(2018, "Avenger - Infinity War");
	Movie movie4(2019, "Avenger - End Game");
	Movie movie5(2020, "Undifined String");
	//Adding pair
	eventMap.insert(make_pair(1, movie1));
	eventMap.insert(make_pair(5, movie5));
	eventMap.insert(make_pair(3, movie3));
	eventMap.insert(make_pair(2, movie2));
	eventMap.insert(make_pair(4, movie4));
	//Change pairS
	eventMap[5] = Movie(2021, "Waiting for Marvel Studio");
	cout << "Key\tValue" << endl;
	for (auto& pair : eventMap)
		cout << " " << pair.first << "\t" << pair.second << endl;
	//Erase Pair
	eventMap.erase(5);
	cout << "\nKey\tValue" << endl;
	for (auto& pair : eventMap)
		cout << " " << pair.first << "\t" << pair.second << endl;

	/*Practice map, it uses binary search tree, no duplicate
	  The benefit is sorted order	
	  It 0(logn) because binary search tree
	*/
	map<int, Movie> sortedEventMap;
	sortedEventMap.insert(make_pair(1, movie1));
	sortedEventMap.insert(make_pair(3, movie3));
	sortedEventMap.insert(make_pair(2, movie2));
	sortedEventMap.insert(make_pair(4, movie4));
	cout << "\nKey\tValue" << endl;
	for (auto& pair : sortedEventMap)
		cout << " " << pair.first << "\t" << pair.second << endl;

	//end
	getchar();
	return 0;
}