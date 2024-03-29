#ifndef KEYBOARDCONTORLLER_H
#define KEYBOARDCONTROLLER_H

#include "Engine.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	SpriteComponent* spriteJar;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void update() override
	{
		if (Engine::event.type == SDL_KEYDOWN)
		{
			switch (Engine::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_SPACE:
				break;
			default:
				break;
			}
		}

		if (Engine::event.type == SDL_KEYUP)
		{
			switch (Engine::event.key.keysym.sym)
			{
			case SDLK_w:
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			case SDLK_a:
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			case SDLK_SPACE:

				break;
			default:
				break;
			}
		}
	}

};
#endif KEYBOARDCONTROLLER_H