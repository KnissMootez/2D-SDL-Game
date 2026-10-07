#define SDL_MAIN_HANDLED
#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include<chrono>
#include<thread>
#include "SDL_Image.h"
#include "GameObject.h"
#include "Button.h"
using namespace std;  // Include this line at the beginning
GameObject* player;
GameObject* enemy;
SDL_Texture* playerTex;
SDL_Texture* playerBg;
Button* PlayButton;
Button* PlayButtonIdle;
Button* SettingsButtonIdle;
Button* QuitButtonIdle;
SDL_Rect srcR, destR;


Game::Game(){}

Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	
	/*playerTex = TextureManager::LoadTexture("Assets/smurf.png", renderer);*/

	playerBg = TextureManager::LoadTexture("Assets/forest.png", renderer);
	PlayButtonIdle= new Button("Assets/play button idle.png", renderer,165, 100, 232, 147);
	SettingsButtonIdle = new Button("Assets/settings button idle.png", renderer, 95, 240, 451, 145);
	QuitButtonIdle= new Button("Assets/quit button idle.png", renderer, 165, 380, 232, 144);
	player = new GameObject("Assets/smurf.png", renderer,0,0,221,137);
	enemy = new GameObject("Assets/azrael_cat.png", renderer,100,50,300,221);

	
}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEMOTION:
		// Check if the mouse is inside the play button rectangle
		SDL_Point mousePosition;
		SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
		if (PlayButtonIdle->IsHovered(mousePosition)) {
			// Update the textures of the buttons using the TextureManager
			PlayButtonIdle->ChangeButton("Assets/play button.png");
		}
		else {
			// Update the textures of the buttons using the TextureManager
			PlayButtonIdle->ChangeButton("Assets/play button idle.png");
		}
		if (SettingsButtonIdle->IsHovered(mousePosition)) {
			// Update the textures of the settings button
			SettingsButtonIdle->ChangeButton("Assets/settings button.png");
		}
		else {
			// Update the textures of the settings button to the idle state
			SettingsButtonIdle->ChangeButton("Assets/settings button idle.png");
		}

		// Check if the mouse is hovering over the quit button
		if (QuitButtonIdle->IsHovered(mousePosition)) {
			// Update the textures of the quit button
			QuitButtonIdle->ChangeButton("Assets/quit button.png");
			Uint32 mouseButtonState = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
			if (QuitButtonIdle->IsClicked(mousePosition, mouseButtonState)) {
				cout << "" << endl;
				SDL_Event quitEvent;
				quitEvent.type = SDL_QUIT;
				SDL_PushEvent(&quitEvent);
			}
		}
		else {
			// Update the textures of the quit button to the idle state
			QuitButtonIdle->ChangeButton("Assets/quit button idle.png");
		}
		break;
	default:
		break;
	}
}




void Game::update()
{
	/*cnt++;
	destR.y = 500;
	destR.h = 64;
	destR.w = 64;
	destR.x = cnt;

	cout << cnt << std::endl;*/
	player->Update(221,137);
	enemy->Update(300, 221);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerBg , NULL, NULL);
	PlayButtonIdle->Render();
	SettingsButtonIdle->Render();
	QuitButtonIdle->Render();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}