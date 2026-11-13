#ifndef APP_BULLET_SCRIPT_H
#define APP_BULLET_SCRIPT_H

#include "Components/ScriptComponent.h"

#include "Define.h"

class BulletScript : public shroom::ScriptComponent
{
public:
	BulletScript(std::string name, shroom::Actor* pOwner);

	void Update() override;
	void OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther) override;

	shroom::Component* Duplicate() override;
	void DuplicateValues(shroom::Component& out) override;

	void SetIgnoredTarget(shroom::uint8 t);

	void SetSpeed(float speed);

private:
	float m_speed;
	shroom::uint8 m_target;

};

#endif
