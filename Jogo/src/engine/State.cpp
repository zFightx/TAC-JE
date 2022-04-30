#include "../../header/engine/State.h"
// #include "../../header/engine/Face.h"
#include "../../header/engine/Sound.h"
#include "../../header/engine/TileMap.h"
#include "../../header/engine/TileSet.h"
#include "../../header/engine/InputManager.h"
#include "../../header/engine/Camera.h"
#include "../../header/engine/CameraFollower.h"
#include "../../header/engine/Alien.h"

#define PI 3.14159265358979323846  /* pi */

State::State(){
    this->quitRequested = false;
	this->started = false;

    GameObject *gameObject = new GameObject();

    // Instanciar Sprite aqui
    this->bg = new Sprite(*gameObject);
    this->music = Music();

	CameraFollower *cameraFollower = new CameraFollower(*gameObject);
	gameObject->AddComponent((Component *) cameraFollower);
    gameObject->AddComponent((Component *) this->bg);

    gameObject->box.x = 0.0;
    gameObject->box.y = 0.0;

	this->AddObject(gameObject);
    // this->objectArray.emplace_back(gameObject);
}
State::~State(){
    this->objectArray.clear();
}

void State::Start(){
	this->LoadAssets();

	for(unsigned i = 0; i < this->objectArray.size(); i++){
        this->objectArray[i]->Start();
	}

	this->started = true;
}

bool State::QuitRequested(){
    return this->quitRequested;
}

void State::LoadAssets(){
    this->bg->Open("assets/img/ocean.jpg");
    this->music.Open("assets/audio/stageState.ogg");

    if(this->music.IsOpen()){
        this->music.Play();
    }

	GameObject *gameObjectTile = new GameObject();
	TileSet *tileSet = new TileSet(64, 64, "assets/img/tileset.png");
	TileMap *tileMap = new TileMap(*gameObjectTile, "assets/map/tileMap.txt", tileSet);

	gameObjectTile->AddComponent((Component*) tileMap );
	gameObjectTile->box.x = 0.0;
    gameObjectTile->box.y = 0.0;

	// this->objectArray.emplace_back(gameObjectTile);
	this->AddObject(gameObjectTile);

	// Teste de Alien
	GameObject *alienObject = new GameObject();
	Sprite *alienImg = new Sprite(*alienObject, "assets/img/alien.png");
	Alien *alien = new Alien(*alienObject, 10);

	alienObject->AddComponent((Component*) alienImg);
	alienObject->AddComponent((Component*) alien);

	alienObject->box.x = 512;
    alienObject->box.y = 300;

	this->AddObject(alienObject);
	// this->objectArray.emplace_back(gameObject);
}

void State::Update(float dt){
    // this->Input();

	Camera::Update(dt);

	if(InputManager::GetInstance().KeyPress(ESCAPE_KEY))
		this->quitRequested = true;
	
	if(InputManager::GetInstance().QuitRequested())
		this->quitRequested = true;
    
	if(InputManager::GetInstance().KeyPress(SPACE_KEY)){
		int mouseX = InputManager::GetInstance().GetMouseX();
		int mouseY = InputManager::GetInstance().GetMouseY();

		Vec2 objPos = Vec2( 200, 0 ).GetRotate( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
		// this->AddObject((int)objPos.x, (int)objPos.y);
	}

    for(unsigned i = 0; i < this->objectArray.size(); i++)
        this->objectArray[i]->Update(dt);

    for(unsigned i = 0; i < this->objectArray.size(); i++){
        if(this->objectArray[i]->IsDead()){
            this->objectArray.erase(this->objectArray.begin() + i);
            i--;
        }
    }
}

void State::Render(){
    for(unsigned i = 0; i < this->objectArray.size(); i++){
        this->objectArray[i]->Render();
	}
}

std::weak_ptr<GameObject> State::AddObject (GameObject *go){
	std::shared_ptr<GameObject> goPointer (go);

	if(this->started)
		go->Start();

    this->objectArray.push_back(goPointer);
	return std::weak_ptr<GameObject> (goPointer);
}

std::weak_ptr<GameObject> State::GetObjectPtr(GameObject *go){
	for(unsigned i = 0; i < this->objectArray.size(); i++){
        if(this->objectArray[i].get() == go){
			return std::weak_ptr<GameObject> (this->objectArray[i]);
		}
	}
	return std::weak_ptr<GameObject> ();
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			this->quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = this->objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) this->objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.IsCoordInRect( {(float)mouseX, (float)mouseY} ) ) {
					// Face *face = (Face*) go->GetComponent( "Face" );
					// if ( nullptr != face ) {
					// 	// Aplica dano
					// 	face->Damage(std::rand() % 10 + 10);
					// 	// Sai do loop (só queremos acertar um)
					// 	break;
					// }
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				this->quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotate( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				// this->AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}