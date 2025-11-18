#pragma once

#include "Update.h"

using namespace sf;
using namespace std;

class LevelUpdate : public Update
{
private:
	// Tracks whether the game is currently paused.
	// 
	// 
	//bool m_IsPaused = true;
	bool m_IsPaused = false; /// Temporarily change
	//
	//
	//

	// Holds the position and size of all platforms in the level.
	vector<FloatRect*> m_PlatformPositions;

	// Shared camera time value
	float* m_CameraTime = new float;

	// Holds the player's current position (provided/updated externally).
	FloatRect* m_PlayerPosition;

	// Time interval (in seconds) between automatic platform spawns.
	float m_PlatformCreationInterval = 0;
	
	// Time interval (in seconds) between automatic platform spawns.
	// m_TimeSinceLastPlatform works in conjunction with m_PlatformCreationInterval.
	float m_TimeSinceLastPlatform = 0;

	// Index of the next platform to move/update
	int m_NextPlatformToMove = 0;
	
	// Total number of platforms currently active.
	int m_NumberOfPlatforms = 0;

	// Movement offset relative to a given platform
	int m_MoveRelativeToPlatform = 0;

	bool m_GameOver = true;

	// Initializes the starting positions of all level/game objects at the beginning of a run
	void positionLevelAtStart();

public:

	// Adds a new platform bounding rectangle to the level.
	void addPlatformPosition(FloatRect* newPosition);

	// Connects the level logic to an external camera time float.
	void connectToCameraTime(float* cameraTime);
	
	// Returns a pointer to the pause
	bool* getIsPausedPointer();

	// Returns a random integer between minHeight and maxHeight 
	int getRandomNumber(int minHeight, int maxHeight);

	// From Update : Component
	void update(float fps) override;
	void assemble(
		shared_ptr<LevelUpdate> levelUpdate,
		shared_ptr<PlayerUpdate> playerUpdate
	) override;


};