#include "scored.h"


Scored::Scored(sf::Font& font, unsigned int size) : sf::Text("Score: 0", font, size)
{
	this->value = 0;
}

void Scored::IncrementScore()
{

	this->value += 1;
}

void Scored::Update()
{
	this->setString("Score: " + std::to_string(this->value));
}