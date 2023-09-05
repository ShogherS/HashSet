#ifndef HASHSET
#define HASHSET
#include <string>
#include <vector>
#include <stdexcept>

class HashSet
{
	public:
	HashSet(size_t initSize = 11 ) : table{initSize}, size{} {}
	void add(const std::string&);	
	void remove(const std::string&);
	bool search(const std::string&);
	void visit(void (*visitor)(const std::string&));
	private:
	std::vector<std::string> table;
	int size;
	int hash(const std::string&);
	void rehash();
	int find(const std::string&);
};
void HashSet::add(const std::string& key) {
	if (size > table.size() / 2) {
		rehash();
	}
	int index{find(key)};
	if (index == -1) {
		index = hash(key);
		while (!table[index].empty()) {
			index = (index + 1) % table.size(); //linear probing
		}
		table[index] = key;
		++size;
	} else {
		throw std::runtime_error("Element already exists");
	} 
}	
void HashSet::remove(const std::string& key) {
	int index{find(key)};
	if (index == -1) {
		throw std::runtime_error("Element doesn't exists");
	} else {
		table[index] = "";
		--size;
		}
}	
bool HashSet::search(const std::string& key) {
	int index{find(key)};
	return index != -1;
}
int HashSet::hash(const std::string& key) {
	int index{};
	for (char i :key) {
		index = (index + i + 31) % table.size();
	}
	return index;
}
void HashSet::rehash() {
	std::vector<std::string> oldTable(table);
	table.clear();
	table.resize(oldTable.size() * 2);
	size  = 0;
	for (const std::string& key : oldTable) {
		if (!key.empty()) {
			add(key);
		}
	}
	oldTable.clear();
}
int HashSet::find(const std::string& key) {
	int index{hash(key)};
	int startIndex{index};
	while (!table[index].empty()) { //while (true)
		if (table[index] == key) {
			return index;
		}
		index = (index + 1) % table.size(); //linear probing
		if (index == startIndex) {
			return -1;
		}
	}
	return -1;
}
void HashSet::visit(void (*visitor)(const std::string&)) {
	for (auto& it : table) {
		visitor(it);
	}
	std::cout << "________________________________" << std::endl;
}
#endif
