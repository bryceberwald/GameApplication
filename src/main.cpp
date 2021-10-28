/* ************************************************************
 * PROGRAMMER  :    BRYCE BERWALD
 * PROJECT     :    SAVAGE-ONLINE
 * VERSION     :    0.0.1
 * DESCRIPTION :    AN RPG GAME CREATED FOR LEARNING PURPOSES
 **************************************************************/

#include "Functions.h"

int main()
{

    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Version 0.0.1");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    // Load ALL Player Resources.
    Texture2D playerLeft = LoadResources("resources/player_left.png");
    Texture2D playerRight = LoadResources("resources/player_right.png");
    Texture2D playerDown = LoadResources("resources/player_down.png");
    Texture2D playerUp = LoadResources("resources/player_up.png");
    
    // Load Game Map Resource.
    Texture2D scrollingGameBackground = LoadResources("resources/scrolling_background_layout.png");
    
    // Scrolling background variables used.
    float backgroundX = 0;
    Rectangle backgroundStartingRec = {backgroundX, 0, 2560, 720};
    Rectangle backgroundEndingRec = {0,0, 2560, 720};

    
    // Create a interchangable texture for the player.
    Texture2D newPlayerTexture = playerDown;
    
    // Players X & Y Coordinates
    float newCoordinateX = 0;
    float newCoordinateY = 540;

    // Variables used for player jumping.
    int JumpTimer = 0;
    bool Jump = false;
    
    SetTargetFPS(60);
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        
        // Call Function to Keep Game Map in Range.
        ScrollingBackroundRange(backgroundX);
        
        // Call Function for Player Movement.
        PlayerMovement(newCoordinateX, backgroundX, newPlayerTexture, playerRight, playerLeft);

        // Call Function for Player Jumping.
        PlayerJump(Jump, JumpTimer, newCoordinateY);
        
        // Keeping player on the screen.
        KeepPlayerOnScreen(newCoordinateX, newCoordinateY);
        
        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        
        //----------------------------------------------------------------------------------
        // BEGIN DRAWING
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        // Draw the scrolling game background to the screen.
        DrawTexturePro(scrollingGameBackground, backgroundStartingRec, backgroundEndingRec, Vector2{backgroundX,0}, 0.0f, WHITE);
        
        // Draw the player on the scrolling game background.
        DrawTexturePro(newPlayerTexture, Rectangle{0, 0, 50, 55}, Rectangle{newCoordinateX, newCoordinateY, 50, 55}, Vector2{0,0}, 0.0f, WHITE);
        
        // Call Function to Display Mouse X & Y and Player's X & Y Coordinates.
        DisplayCoordinates(newCoordinateX, newCoordinateY);

 
        EndDrawing();
        //----------------------------------------------------------------------------------
        // END DRAWING
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(playerLeft);                // Texture unloading
    UnloadTexture(playerRight);               // Texture unloading
    UnloadTexture(playerUp);                  // Texture unloading
    UnloadTexture(playerDown);                // Texture unloading
    UnloadTexture(scrollingGameBackground);   // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

