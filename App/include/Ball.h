#ifndef APP_BULLET_SCRIPT_H
#define APP_BULLET_SCRIPT_H

#include "Components/ScriptComponent.h"
#include "Vectors.h"

#include "Define.h"

class BallScript : public shroom::ScriptComponent
{
public:
	BallScript(std::string name, shroom::Actor* pOwner);

	void Update() override;
	void OnCollision(shroom::Collider* pOwned, shroom::Collider* pOther) override;

	void SetScreenDimensions(shroom::Vector2<shroom::uint16> screenDimansions);

	shroom::Component* Duplicate() override;
	void DuplicateValues(shroom::Component& out) override;

private:
	float m_collisionCD;
	float m_speed;
	shroom::Vector2f m_direction;
	shroom::Vector2<shroom::uint16> m_screenDimansions;

};

#endif
