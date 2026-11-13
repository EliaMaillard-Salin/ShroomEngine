#ifndef APP_PLAYER_SCRIPT_H
#define APP_PLAYER_SCRIPT_H

#include "Components/ScriptComponent.h"

class PlayerScript : public shroom::ScriptComponent
{
public:
	PlayerScript(std::string name, shroom::Actor* pOwner);

	void Update() override;
	void OnInputPressed(SDL_Event event) override;
	void OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther) override;

	shroom::Component* Duplicate() override;
	void DuplicateValues(shroom::Component& out) override;

	void SpawnBullet();
	void SetKeyToMove(SDL_KeyCode up, SDL_KeyCode down);

private:
	float m_speed;
	bool m_move;
	float dir;
	SDL_KeyCode keyUp;
	SDL_KeyCode keyDown;
};

#endif
