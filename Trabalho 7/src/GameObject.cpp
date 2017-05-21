#include "GameObject.hpp"
#include "Game.hpp"
#include "Camera.hpp"

GameObject::GameObject() {
    construct();
}

GameObject::~GameObject() {

}

void GameObject::construct() {
    rotation = 0.0;
}
