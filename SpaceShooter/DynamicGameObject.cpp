#include "DynamicGameObject.h"


DynaminGameObject::DynaminGameObject(const Point& position): GameObject(position), next(nullptr)
{

}

DynaminGameObject* DynaminGameObject::GetNext()
{
	DynaminGameObject* next = this->next;
	while (next != nullptr && !next->IsAlive())
	{
		DynaminGameObject* formerNext = next;
		next = next->GetNext();
		delete formerNext;
	}
	this->next = next;
	return next;
}

void DynaminGameObject::SetNext(DynaminGameObject* next)
{
	this->next = next;
}
