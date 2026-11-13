#ifndef APP_ENEMY_SCRIPT_H
#define APP_ENEMY_SCRIPT_H

#include "Components/ScriptComponent.h"

class EnemyScript : public shroom::ScriptComponent
{
public:
	EnemyScript(std::string name, shroom::Actor* pOwner);

	void Update() override;

	void SpawnBullet();

	shroom::Component* Duplicate() override;
	void DuplicateValues(shroom::Component& out) override;

private:
	float m_shootCD = 0.0f;
	float m_shootDelay = 2.0f;

};

#endif
