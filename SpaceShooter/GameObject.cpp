// 
// 
// 

#include "GameObject.h"


GameObject::GameObject(short x, short y): position(x, y)
{
}

GameObject::GameObject(const Point& position) : position(position)
{

}
