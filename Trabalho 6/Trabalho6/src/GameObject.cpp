#include "GameObject.hpp"
#include "Game.hpp"
#include "Camera.hpp"

GameObject::GameObject() {
    constuct();
}

GameObject::~GameObject() {

}

void GameObject::constuct() {
    rotation = 0.0;
}
