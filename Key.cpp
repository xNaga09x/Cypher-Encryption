#include "Key.h"

Key::Key()
{
	this->word = "";
	this->order;
}

Key::Key(const std::string& word, const std::vector<int>& order)
	:word(word), order(order)
{
}

void Key::setWord(const std::string& word)
{
	this->word = word;
}

void Key::setOrder(const std::vector<int>& order)
{
	this->order = order;
}

std::string Key::getWord()
{
	return this->word;
}

std::vector<int> Key::getOrder()
{
	return this->order;
}

void Key::determineOrder()
{
	std::vector<int> positions;
	std::string word = this->word;
	for (int j = 0; j < word.size(); j++)
	{
		int min = 999;
		int pos = 0;
		for (int i = 0; i < word.size(); i++)
		{
			if (int(word[i]) < min)
			{
				min = int(word[i]);
				pos = i;
			}
		}
		positions.push_back(pos);
		word[pos] = '~';
	}

	for (int i = 0; i < word.size(); i++)
		this->order.push_back(0);

	int i = 0;
	for (int digit : positions)
	{
		order[digit] = i;
		++i;
	}

}

void Key::printWord()
{
	std::cout << "Key:\n";
	for (auto c : this->word)
		std::cout << c << " ";
	std::cout << "\n";
}

void Key::printOrder()
{
	std::cout << "Order:\n";
	for (int i = 0; i < this->order.size(); i++)
		std::cout << this->order[i] << " ";
	std::cout << "\n";
}
