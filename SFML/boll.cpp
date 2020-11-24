
#include "boll.h"

boll::boll(Scored* score1, Scored* score2, paddle_player* play1, paddle_player* play2)
{
	this->Load("ball2.png");
	this->score1 = score1;
	this->score2 = score2;
	this->play1 = play1;
	this->play2 = play2;

	this->velocity.y = 1.9f;//bollen studsar make sure up
	this->velocity.x = 1.9f;//bollen studsar make sure rakt.
	this->buffer = new sf::SoundBuffer();
	this->buffer->loadFromFile("grapfics/bounce.wav");
	this->sound = new sf::Sound(*this->buffer);


}

void boll::Update()
{
	if (this->CheckCollision(this->play1))
	{
		this->velocity.x *= -1;
		sound->play();
		if (this->velocity.y > 0) {
			if (this->play1->velocity.y > 0) {
				this->velocity.y *= 1.5;

			}
			else if (this->play1->velocity.y < 0) {
				this->velocity.y *= -1.5;

			}
		}

		else if (this->velocity.y < 0) {
			if (this->play1->velocity.y > 0) {
				this->velocity.y *= -1.5;

			}
			else if (this->play1->velocity.y < 0) {
				this->velocity.y *= 1.5;

			}
		}
	}
	if (this->CheckCollision(this->play2))
	{
		this->velocity.x *= -1;
		sound->play();
		if (this->velocity.y > 0) {
			if (this->play2->velocity.y > 0) {
				this->velocity.y *= 1.5;

			}
			else if (this->play2->velocity.y < 0) {
				this->velocity.y *= -1.5;

			}
		}

		else if (this->velocity.y < 0) {
			if (this->play2->velocity.y > 0) {
				this->velocity.y *= -1.5;

			}
			else if (this->play2->velocity.y < 0) {
				this->velocity.y *= 1.5;

			}
		}

	}

	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height>600) {//längden på skärmen

		this->velocity.y *= -1;


	}

	if (this->getPosition().x < this->play1->getGlobalBounds().width - 5 /*+ 5*/)// hur långt bollen når 
	{
		this->score2->IncrementScore();

		this->Reset();
	}
	if (this->getPosition().x + this->getGlobalBounds().width > 1300 - this->play2->getGlobalBounds().width + 5)//
	{
		this->score1->IncrementScore();

		this->Reset();
	}
	Entit::Update();
}

void boll::Reset()
{
	this->velocity.x = ((rand() % 2) == 0) ? 1.9f : -1.9f;
	this->velocity.y = ((rand() % 2) == 0) ? 1.9f : -1.9f;
	this->setPosition(1300 / 2, 600 / 2);
	this->play1->setPosition(this->play1->getGlobalBounds().width / 1300, 600 / 3);//-----  ->sätter postionen player 1 andra sidan    
	this->play2->setPosition(1300 - this->play2->getGlobalBounds().width / 1, 600 / 3);//------>sätter postionen player 2 andra sidan

}

boll::~boll()
{
	delete(this->buffer);
	delete(this->sound);
}
//