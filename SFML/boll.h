#pragma once

#include <SFML/Audio.hpp>
#include "Paddler_play.h"
#include "scored.h"
#include "Enty.h"


class boll : public Entit
{
public:
	/**
 *	@brief constructer paddle_player .
 *	@param Scored* score1
 *	@param Scored* score2
 *	@param paddle_player* play1
 *	@param paddle_player* play2
 *
 */
	boll(Scored* score1, Scored* score2, paddle_player* play1, paddle_player* play2);
	/**
*	update function
*
*	uppdaterar
*
*/
	void Update();
	/**
*	Reset
*
*	resetar hela
*
*/
	void Reset();
	~boll();
private:
	Scored* score1;
	Scored* score2;
	paddle_player* play1;
	paddle_player* play2;

	sf::SoundBuffer* buffer;
	sf::Sound* sound;
};