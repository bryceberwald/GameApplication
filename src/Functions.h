/* ************************************************************
 * PROGRAMMER  :    BRYCE BERWALD
 * PROJECT     :    SAVAGE-ONLINE
 * VERSION     :    0.0.1
 * DESCRIPTION :    AN RPG GAME CREATED FOR LEARNING PURPOSES
 **************************************************************/

#ifndef Functions_h
#define Functions_h

// Pre-processor directives
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include "../include/raylib.h"
#include <string.h>

using namespace std;

// Constant & Global Declarations
const int screenWidth = 1280;
const int screenHeight = 720;

// Function Prototypes

/************************************************************
 * This function prototype is for ensuring that the scrolling 
 * background image stays within range. The player is prevented
 * from leaving the scrolling background, keeping the player 
 * on the map.
 * 
 * 1 Argument passed by reference -> Returns: Nothing
 ************************************************************/
void ScrollingBackroundRange(float &backgroundX);

/************************************************************
 * This function prototype is for loading texture resources
 * into the main program.
 * 
 * 1 Argument passed by literal -> Returns: Texture2D
 ************************************************************/
Texture2D LoadResources(string resourceLocation);

/************************************************************
 * This function prototype is for executing the algorithm for
 * the player to be able to jump. We use a few variables to 
 * help control our players jumping.
 * 
 * 3 Arguments passed by reference -> Returns: Nothing
 ************************************************************/
void PlayerJump(bool &Jump, int &JumpTimer, float &newCoordinateY);

/************************************************************
 * This function prototype is for the player being able to 
 * move via the arrow keys. This function breaks down the 
 * algorithm into a sub routine to shorten main.
 * 
 * 2 Arguments passed by value
 * 3 Arguments passed by reference -> Returns: Nothing
 ************************************************************/
void PlayerMovement(float &newCoordinateX, float &backgroundX, 
Texture2D &newPlayerTexture, Texture2D playerRight, Texture2D playerLeft);

/************************************************************
 * This function prototype is for ensuring the player stays
 * within bounds in the game.
 * 
 * 2 Argument passed by reference -> Returns: Nothing
 ************************************************************/
void KeepPlayerOnScreen(float &newCoordinateX, float &newCoordinateY);

/************************************************************
 * This function prototype is for displaying X & Y coordinates
 * to the screen. Used for debuging/testing purposes.
 * 
 * 2 Argument passed by value -> Returns: Nothing
 ************************************************************/
void DisplayCoordinates(float newCoordinateX, float newCoordinateY);

#endif /* Functions_h */
