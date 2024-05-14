#pragma once
#include <string>
#include <vector>
#include <iostream>

class Key
{
public:
	Key();
	Key(const std::string& word, const std::vector<int>& order);

	void setWord(const std::string& word);
	void setOrder(const std::vector<int>& order);

	std::string getWord();
	std::vector<int> getOrder();

	void determineOrder();
	void printWord();
	void printOrder();
private:
	std::string word;
	std::vector<int> order;
};

