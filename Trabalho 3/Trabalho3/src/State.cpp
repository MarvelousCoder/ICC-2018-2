#include "State.hpp"
#include "Game.hpp"
#include "Face.hpp"

State::State() : quitRequested(false), bg("img/ocean.jpg"), tileSet(64, 64, "img/tileset.png"),
    tileMap("map/tileMap.txt", &tileSet) {

}

State::~State() {
    objectArray.clear();
}

void State::Update(float dt) {
    Input();

    for(auto it = objectArray.begin(); it != objectArray.end(); it++)
        (*it)->Update(dt);

    for(unsigned int i = 0; i < objectArray.size(); i++)
        if(objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
            i -= 1;
        }
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::Render() {
    bg.Render(0,0);

    tileMap.RenderLayer(0, 0, 0);
    for(auto it = objectArray.begin(); it != objectArray.end(); it++)
        (*it)->Render();
    tileMap.RenderLayer(1, 0, 0);
}

Sprite State::getBg(){
    return bg;
}

void State::Input() {

    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contr�rio
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para termina��o
        if(event.type == SDL_QUIT) {
            quitRequested = true;
        }

        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de tr�s pra frente pra sempre clicar no objeto mais de cima
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                Face* face = (Face*) objectArray[i].get();
                /* Nota: Desencapsular o ponteiro � algo que devemos evitar ao m�ximo.
                O prop�sito do unique_ptr � manter apenas uma c�pia daquele ponteiro,
                ao usar get(), violamos esse princ�pio e estamos menos seguros.
                Esse c�digo, assim como a classe Face, � provis�rio. Futuramente, para
                chamar fun��es de GameObjects, use objectArray[i]->fun��o() direto. */

                if(face->box.IsInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    face->Damage(rand() % 10 + 10);
                    // Sai do loop (s� queremos acertar um)
                    break;
                }
            }
        }
        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequested = true;
            }
            // Se n�o, crie um objeto
            else {
                AddObject((float)mouseX, (float)mouseY);
            }
        }
    }
}

void State::AddObject(float mouseX, float mouseY) {
    objectArray.emplace_back(new Face(Vec2(mouseX, mouseY) + Vec2::getVec2FromPolar(200, (rand()%360)*3.14159265358979323846/180.0)));
}
