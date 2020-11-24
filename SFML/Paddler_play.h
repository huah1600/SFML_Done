#pragma once
#pragma once

#include"Enty.h"



class paddle_player : public Entit
{



public:
	/**
 *	@brief constructer paddle_player .
 *	@param int playerNumber.
 *
 */
	paddle_player(int playerNumber);
	/**
 *	@brief  Update() .
 *	Update the functions
 *
 */
	void Update();
private:

	int playerNumber;


};
