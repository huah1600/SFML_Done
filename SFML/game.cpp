#include "game.h"

#define MAX_SCORE 2
// Create the window of the application
void Game::initWindow(sf::RenderWindow* window)
{
	this->window = new sf::RenderWindow(sf::VideoMode(1300, 600), "SFML works!");
}




Game::Game()
{
	// creating pointer object
	this->initWindow(window);
	this->back = new Background("s.png");
	this->play1 = new paddle_player(0);
	this->play2 = new paddle_player(1);
	this->font = new sf::Font();
	this->font->loadFromFile("grapfics/font.ttf");
	this->scored1 = new Scored(*font, 30U);
	this->scored2 = new Scored(*font, 30U);
	this->baller = new boll(this->scored1, this->scored2, this->play1, this->play2);
	this->Pausetxt = new sf::Text(" Play = p  Freeze = f  Quit= q", *font, 25);
	this->Scoretxt = new sf::Text("", *font, 50);
	this->buffer = new sf::SoundBuffer();
	this->buffer->loadFromFile("grapfics/win.wav");
	this->sound = new sf::Sound(*this->buffer);

	initializepos();
}

void Game::initializepos()

{

	this->play1->setPosition(this->play1->getGlobalBounds().width / 1300, 600 / 3);
	this->play2->setPosition(window->getSize().x - this->play2->getGlobalBounds().width / 1, 600 / 3);
	this->scored1->setPosition(this->scored1->getGlobalBounds().width / 2.8, 0); //ändra postionen på score
	this->scored2->setPosition(window->getSize().x - this->scored2->getGlobalBounds().width / 0.7, 0); //ändra postionen på score
	this->baller->setPosition(window->getSize().x / 2, window->getSize().y / 2);//sätter bollen i mitten
	this->Pausetxt->setOrigin(this->Pausetxt->getGlobalBounds().width / 2, this->Pausetxt->getGlobalBounds().height / 2);
	this->Pausetxt->setPosition(window->getSize().x - this->play2->getGlobalBounds().width / 0.1, 600 / 1.09);
	this->Scoretxt->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

Game::~Game()
{
	std::cout << "Destroy" << std::endl;
	delete this->window;
	delete this->play1;
	delete this->play2;
	delete this->baller;
	delete this->font;
	delete this->Pausetxt;
	delete this->scored1;
	delete this->scored2;
	delete this->buffer;
}

void Game::updateSFMLevent()
{
	if (this->paused == false)
	{


		if (overflag1 || overflag2) {

			startElapsed = startCountdown.getElapsedTime();
			if (startElapsed.asSeconds() > 5)
			{
				overflag1 = false;
				overflag2 = false;
				scored1->SetValue(0);
				scored2->SetValue(0);
				initializepos();
				this->back->Update();
				this->play1->Update();
				this->play2->Update();
				this->baller->Update();
				this->scored1->Update();
				this->scored2->Update();
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && !this->enterKey)
		{
			this->paused = true;
		}
	}
	else
	{
		this->back->Update();
		this->play1->Update();
		this->play2->Update();
		this->baller->Update();
		this->scored1->Update();
		this->scored2->Update();

		if (scored1->Value() == MAX_SCORE)
		{
			this->paused = false;
			overflag1 = true;

			Scoretxt->setString("Player One Win!!!");
			Scoretxt->setFillColor(sf::Color::Magenta);
			Scoretxt->setOutlineColor(sf::Color::Black);
			Scoretxt->setOutlineThickness(10);


			sound->play();
			this->Scoretxt->setOrigin(this->Scoretxt->getGlobalBounds().width / 2, this->Scoretxt->getGlobalBounds().height / 2);
			startCountdown.restart();
		}
		else if (scored2->Value() == MAX_SCORE)
		{
			this->paused = false;
			overflag2 = true;
			Scoretxt->setString("Player Two Win!!!");
			Scoretxt->setFillColor(sf::Color::Red);
			Scoretxt->setOutlineColor(sf::Color::Black);
			Scoretxt->setOutlineThickness(10);
			sound->play();
			this->Scoretxt->setOrigin(this->Scoretxt->getGlobalBounds().width / 2, this->Scoretxt->getGlobalBounds().height / 2);
			startCountdown.restart();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F) && !this->enterKey)
		{
			this->paused = false;

		}
	}

	while (this->window->pollEvent(this->sfEvent))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) || this->sfEvent.type == sf::Event::Closed) {

			this->window->close();
		}
	}

}

void Game::update()
{
	this->updateSFMLevent();
}

void Game::render()
{

	this->window->clear();
	window->draw(*this->back);
	window->draw(*this->play1);
	window->draw(*this->play2);
	window->draw(*this->scored1);
	window->draw(*this->scored2);
	window->draw(*this->Pausetxt);
	if (overflag1 || overflag2)
	{
		window->draw(*this->Scoretxt);
	}
	else
	{
		window->draw(*this->baller);
	}
	this->window->display();

	//render items

}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->update();
		this->render();
		Sleep(5);
	}

}
