
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Network.hpp>
#include <SFML/window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Enty.h"
#include "Paddler_play.h"
#include "Windows.h"
#include "scored.h"
#include "boll.h"
#include "background.h"




/**
 *		@brief Class for managing most of the game content..
 */
class Game
{

private:

	sf::RenderWindow* window;
	sf::Event sfEvent;
	Entit* paddle;
	paddle_player* play1;
	paddle_player* play2;
	Scored* scored1;
	Scored* scored2;
	sf::Font* font;
	boll* baller;
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
	bool paused, enterKey, quit, overflag1, overflag2;

	sf::Text* Pausetxt;
	sf::Text* Scoretxt;
	Background* back;
	sf::Clock startCountdown;
	sf::Time startElapsed;
	//Initializiotn
	void initWindow(sf::RenderWindow* window);



public:
	/**
	 *		@brief game constructor.
	 *		which we will  create pointer object
	 *
	 */
	Game();
	/**
	 *		@brief game constructor.
	 *		which we will  delete else there will be memory leak.
	 *
	 */
	~Game();
	/**
	 *		@brief updateSFMLevent
	 *		 updateSFMLevent is used to update
	 *
	 */
	void updateSFMLevent();
	void update();
	/**
	 *		@brief render
	 *		used to draw the game
	 *
	 */
	void render();
	/**
	 *		@brief run()
	 *		running the game
	 *
	 */
	void run();
	/**
	 *		@brief initializepos
	 *		setting the postion
	 *
	 */
	void initializepos();



};

#endif