#include "Game.h"
#include "Engine/Simulation.h"
#include "Platforms/WIN32/WinEntry.h"

class GameProject : public Cosmo::Simulation {
public:
	GameProject();
	~GameProject();
public:
	VOID SetupSettingsForGame();
	VOID Initialize();
	VOID Update();
};

ENTRYAPP(GameProject);

GameProject::GameProject(){}
GameProject::~GameProject(){}

VOID GameProject::SetupSettingsForGame()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortGameName(IDS_SHORTNAME);
	PerGameSettings::SetGameIcon(IDI_MAINICON);
	return VOID();
}

VOID GameProject::Initialize(){}
VOID GameProject::Update(){}
