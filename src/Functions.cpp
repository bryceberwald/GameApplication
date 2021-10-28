/* ************************************************************
 * PROGRAMMER  :    BRYCE BERWALD
 * PROJECT     :    SAVAGE-ONLINE
 * VERSION     :    0.0.1
 * DESCRIPTION :    AN RPG GAME CREATED FOR LEARNING PURPOSES
 **************************************************************/

#include "Functions.h"

/* ************************************************************
 * Function for loading Texture2D resources into the program.
 **************************************************************/
Texture2D LoadResources(string resourceLocation) {

    Texture2D texture = LoadTexture(resourceLocation.c_str());
    return texture;
}

/* ************************************************************
 * Function for controlling the scrolling game background.
 **************************************************************/
void ScrollingBackroundRange(float &backgroundX) { 

        // Keep scrolling background in proper zone.
        if (backgroundX <= 0) {
            backgroundX = 5;
        } else if (backgroundX >= 1280) {
            backgroundX = 1275;
        }
}

/* *****************************************************************
 * Function for implemting the player being able to jump in the game.
 *******************************************************************/
void PlayerJump(bool &Jump, int &JumpTimer, float &newCoordinateY) {

    int movement = 10;

    if(IsKeyPressed(KEY_SPACE)) {
        Jump = true;
    }

    if (Jump) {
        JumpTimer += 5;
        if (JumpTimer <= 150) {
            newCoordinateY -= movement;
        } else {
            newCoordinateY += movement;
        }
    }
    
     if (JumpTimer >= 300) {
        JumpTimer = 0;
         Jump = false;
    }
}


/* *****************************************************************
 * Function for player movement and allowing the player to move left
 or right with the arrow keys.
 *******************************************************************/
void PlayerMovement(float &newCoordinateX, float &backgroundX, 
                    Texture2D &newPlayerTexture, Texture2D playerRight, 
                    Texture2D playerLeft) {

    if (IsKeyDown(KEY_RIGHT)) {
        newPlayerTexture = playerRight;
        newCoordinateX += 5;
        backgroundX += 5.0;
    } else if (IsKeyDown(KEY_LEFT)) {
        newPlayerTexture = playerLeft;
        newCoordinateX -= 5;
        backgroundX -= 5.0;
    }
}


/* *****************************************************************
 * Function for keeping the player in bounds and on the screen.
 *******************************************************************/
void KeepPlayerOnScreen(float &newCoordinateX, float &newCoordinateY) {
    
    if (newCoordinateX > screenWidth - 50) {
        newCoordinateX = screenWidth - 50;
    } else if (newCoordinateX < 0) {
        newCoordinateX = 0;
    } else if (newCoordinateY > screenHeight - 55) {
        newCoordinateY = screenHeight - 55;
    } else if (newCoordinateY < 0) {
        newCoordinateY = 0;
    }
}


/************************************************************
 * This function will display X & Y Coordinates for testing.
 ************************************************************/
void DisplayCoordinates(float newCoordinateX, float newCoordinateY) {
        
        ostringstream ss;
        string mouseValues;
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        
        ss << "Mouse X Value is: " << mouseX << endl;
        ss << "Mouse Y Value is: " << mouseY << endl;
        ss << "Player X is: " << newCoordinateX << endl;
        ss << "Player Y is: " << newCoordinateY << endl;
        
        mouseValues = ss.str();
        DrawText(mouseValues.c_str(), 0, 0, 30, RED);
}