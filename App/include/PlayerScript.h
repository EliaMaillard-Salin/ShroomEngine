#ifndef APP_PLAYER_SCRIPT_H
#define APP_PLAYER_SCRIPT_H

#include "Components/ScriptComponent.h"

class PlayerScript : public shroom::ScriptComponent
{
public:
	PlayerScript(shroom::Actor* pOwner);

	void OnInputPressed(SDL_Event event) override;


	ScriptComponent* Duplicate() override { return nullptr; }

	void DuplicateValues(Component& out) override {};
	
private:
	float m_speed;

};

#endif
