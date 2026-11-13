
#include "Components/ScriptComponent.h"

#include "Actor.h"

using namespace shroom;

ScriptComponent::ScriptComponent(std::string name, Actor* pOwner):
	Component(name,pOwner)
{
	pOwner->AddScript(this);
}

ScriptComponent::~ScriptComponent()
{
}

void ScriptComponent::DuplicateValues(Component& out)
{
	Component::DuplicateValues(out);
}