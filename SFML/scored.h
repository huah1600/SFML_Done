#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Scored : public sf::Text
{
public:
	/**
 *	@brief constructer Scored .
 *	@param font used to draw the string.
 *	@param  size Base size of characters, in pixels
 *
 */
	Scored(sf::Font& font, unsigned int size);
	/**
 *increment values
 *
 */
	void IncrementScore();
	/**
.
 *Update values
 *
 */
	void Update();
	/**
*

*return  value int.
*
*/
	int Value() { return value; };
	/**
*
*initiet score.
*
*/
	void SetValue(int score) { value = score; };
private:
	int value;
};

