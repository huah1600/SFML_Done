#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entit : public sf::Sprite
{
public:

	Entit()
	{
		this->texture = new sf::Texture();//this create trexture
	}

	void Load(std::string filename)
	{
		this->texture->loadFromFile("grapfics/char/" + filename);
		this->setTexture(*this->texture);
	}

	bool CheckCollision(Entit* entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());//när det träffar
	}

	virtual void Update()
	{
		this->move(this->velocity);//move the object based on its velocity
	}


	~Entit()
	{
		delete this->texture;//delete texture and stuff picture everything about char
	}



	sf::Vector2f velocity;// telling how to move
private:
	sf::Texture* texture;

};
#pragma once
