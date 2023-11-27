#include "game.hpp"
#include <SDL_mixer.h>
#include <iostream>

// Implementation of WelcomeScreen
// WelcomeScreen class

//show method takes in SDL renderer object and reference to screentype enum variable(different screens)
void WelcomeScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    //Load background music(path on device)
    //Mix_LoadMUS-->function from SDL_Mixer library which loads the music
    //music is a pointer to the loaded Mix_Music object
    Mix_Music* music = Mix_LoadMUS("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\audio2.mp3");
    //If music is not found or loading fails then show error
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }

    // Play music 
    if (Mix_PlayMusic(music, -1) == -1) {
        //Mix_GetError() function is used to retrieve the last SDL_mixer error message.
        std::cout << "Unable to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Mix_FreeMusic(music);  // Free music if playing fails and -1 is returned 
        return;
    }
    //Load images for the welcome screen
    SDL_Surface* image=IMG_Load("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen1.png");
    SDL_Surface* imageClicked = IMG_Load("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\screen2.png");
    SDL_Surface* rulesImage = IMG_Load("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rulesblink.png");

    //If image fails to load then IMG_GetError() gives the error
    if (!image || !imageClicked || !rulesImage) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    //textures are created from the images which are to be rendered on the screen
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture* textureClicked = SDL_CreateTextureFromSurface(renderer, imageClicked);
    SDL_Texture* rulesTexture = SDL_CreateTextureFromSurface(renderer, rulesImage);

    //Error message if texture fails to get created
    if (!texture || !textureClicked || !rulesTexture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    //Free the surface after textures are created from them
    SDL_FreeSurface(image);
    SDL_FreeSurface(imageClicked);
    SDL_FreeSurface(rulesImage);

    //This function clear the entire rendering target window
    SDL_RenderClear(renderer);
    //This function copies the texture to the target window(null means the whole source rectangle is copied to the whole destination window)
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    //This function clears the screen first and presents the current image
    SDL_RenderPresent(renderer);

    //flag to keep track of whether game should start or not
    bool startGame = false;

    //Handle user events
    SDL_Event event;//variable to store the current event
    while (SDL_PollEvent(&event)) {//loop until there are events present
        if (event.type == SDL_QUIT) {//If event is a window close event
            nextScreen = ScreenType::EXIT;  // Set nextScreen to EXIT 
            break;
        } 
        //If the event is a mouse down button
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;//variables to store mouse coordinates
            SDL_GetMouseState(&x, &y);//get mouse coordinates
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
            //If mouse is clicked on the Start button
            if (x >= 222 && x <= 560 && y >= 246 && y <= 299) {
                // Create a blinking effect for the "Start" button
                for (int i = 0; i < 3; ++i) {
                    SDL_RenderClear(renderer);//clear renderer
                    SDL_RenderCopy(renderer, textureClicked, NULL, NULL);//render the image on the screen
                    SDL_RenderPresent(renderer);//Update the display
                    SDL_Delay(250);//Delay for 250 milliseconds

                    SDL_RenderClear(renderer);//clear renderer
                    SDL_RenderCopy(renderer, texture, NULL, NULL);//render the image on the screen
                    SDL_RenderPresent(renderer);//Update the display
                    SDL_Delay(250);//Delay for 250 milliseconds
                }
                startGame = true;//game has started
                break;//break out of the loop
            } 
            //If the rules button is clicked
            else if (x >= 222 && x <= 558 && y >= 438 && y <= 490) {
                // Create a blinking effect for the "Rules" button(3 times)
                for (int i = 0; i < 3; ++i) {
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, rulesTexture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    SDL_Delay(250);
                }

                // Set the next screen to the rules screen
                nextScreen = ScreenType::RULES;
                break;  // Break out of the loop after showing the rules
            }
        }
    }

    //Destory the textures created before
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureClicked);
    SDL_DestroyTexture(rulesTexture);

    //if the startGame is true
    if (startGame) {
        // Stop the music when transitioning to the player selection screen
        Mix_HaltMusic();
        //Player Selection screen is displayed
        nextScreen = ScreenType::PLAYER_SELECTION;
    }
    // Free the music at the end
    Mix_FreeMusic(music);
}

// Function to load an SDL_Texture from a specified path(access it easily by reference) and renderer
SDL_Texture* PlayerSelectionScreen::loadTexture(const std::string& path, SDL_Renderer* renderer) {
    //Load image from the given path using IMG_Load function
    //c_str which returns a constant pointer to the null terminated char array,path.c_str converts the std::string object to a null char array as image load function needs a const char* argument(pointer to a null terminated char array)
    SDL_Surface* surface = IMG_Load(path.c_str());

    //If image fails to load give an error and return nullptr
    if (!surface) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    //Create texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    //free surface
    SDL_FreeSurface(surface);
    //return texture
    return texture;
}

// Function to render an SDL_Texture at a specified position on the renderer
void PlayerSelectionScreen::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
    // Define an SDL_Rect structure to represent the destination rectangle for rendering
    SDL_Rect destination;
    //x and y coordinates of the destination rectangle
    destination.x = x;
    destination.y = y;

    // Query the width and height of the texture using SDL_QueryTexture and store values in destination.w and destination.h
    SDL_QueryTexture(texture, nullptr, nullptr, &destination.w, &destination.h);
    // Render the texture onto the renderer using SDL_RenderCopy
    SDL_RenderCopy(renderer, texture, nullptr, &destination);
}

// PlayerSelectionScreen class
void PlayerSelectionScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    // Load the board image
    SDL_Surface* boardImage = IMG_Load("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\board.png");
    //give an error if image fails to load
    if (!boardImage) {
        std::cout << "Unable to load board image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    //create texture from the board
    SDL_Texture* boardTexture = SDL_CreateTextureFromSurface(renderer, boardImage);
    if (!boardTexture) {
        std::cout << "Unable to create texture from board image! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(boardImage);
        return;
    }

    SDL_FreeSurface(boardImage);

    // Load textures for different colored tokens
    SDL_Texture* redTokenTexture = loadTexture("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\red.png",renderer);
    SDL_Texture* greenTokenTexture = loadTexture("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\green.png",renderer);
    SDL_Texture* blueTokenTexture = loadTexture("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\blue.png",renderer);
    SDL_Texture* yellowTokenTexture = loadTexture("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\yellow.png",renderer);


    // Check if loading any texture failed
    if (!redTokenTexture || !greenTokenTexture || !blueTokenTexture || !yellowTokenTexture) {
        // Handle error
        SDL_DestroyTexture(boardTexture);
        return;
    }

    // Render the board
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, boardTexture, NULL, NULL);
    //Renders all the tokens at four edges of each colored area in the board
    // Render red tokens at different positions
    renderTexture(redTokenTexture, renderer, 0, 0);
    renderTexture(redTokenTexture, renderer, 0, 260);
    renderTexture(redTokenTexture, renderer, 260, 260);
    renderTexture(redTokenTexture, renderer, 260, 0);

    // Render green tokens at different positions
    renderTexture(greenTokenTexture, renderer, 450, 0);
    renderTexture(greenTokenTexture, renderer, 710, 0);
    renderTexture(greenTokenTexture, renderer, 450, 260);
    renderTexture(greenTokenTexture, renderer, 710, 260);

    // Render blue tokens at different positions
    renderTexture(blueTokenTexture, renderer, 0, 450);
    renderTexture(blueTokenTexture, renderer, 0, 710);
    renderTexture(blueTokenTexture, renderer, 260, 450);
    renderTexture(blueTokenTexture, renderer, 260, 710);

    // Render yellow tokens at different positions
    renderTexture(yellowTokenTexture, renderer, 450, 450);
    renderTexture(yellowTokenTexture, renderer, 450, 710);
    renderTexture(yellowTokenTexture, renderer, 710, 710);
    renderTexture(yellowTokenTexture, renderer, 710, 450);

    SDL_RenderPresent(renderer);
   

    bool running = true;
    SDL_Event event;
    while (running) {//while running is true
        while (SDL_PollEvent(&event)) {
            //if event is window closed then make the running flag false and exit
            if (event.type == SDL_QUIT) {
                running = false;
                nextScreen = ScreenType::EXIT;  // Update nextScreen if the user quits
            }
            //if the event is mouse down button then get the x and y coordinated 
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";
                // Add logic for player selection if needed
            }
        }
    }
    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(redTokenTexture);
    SDL_DestroyTexture(greenTokenTexture);
    SDL_DestroyTexture(blueTokenTexture);
    SDL_DestroyTexture(yellowTokenTexture);
    // SDL_DestroyTexture(texture);
}

// RulesScreen class--show funtion to show the rules screen
void RulesScreen::show(SDL_Renderer* renderer, ScreenType& nextScreen) {
    SDL_Surface* rules1 = IMG_Load("C:\Users\786 COMPUTERS\\Documents\\GitHub\\OOP_Project_Group9\\assets\\rules1.png");
    if (!rules1) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* rules1Texture = SDL_CreateTextureFromSurface(renderer, rules1);
    if (!rules1Texture) {
        std::cout << "Unable to create texture from image! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(rules1);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, rules1Texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Wait for a quit event or a mouse click
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            nextScreen = ScreenType::EXIT;  // Update nextScreen if the user quits
            break;
        } 
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Mouse clicked at (" << x << ", " << y << ")\n";

            // Check if the BACK button is clicked
            if (x >= 504 && x <= 700 && y >= 700 && y <= 735) {
                nextScreen = ScreenType::WELCOME;
                return;  // Return to the previous screen (Welcome screen)
            }
        }
    }

    SDL_DestroyTexture(rules1Texture);
}


// Implementation of ScreenManager
//constructor for the screenManager screen
ScreenManager::ScreenManager(): currentScreen(ScreenType::WELCOME), music(nullptr) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        // Handle initialization failure as needed
    }

    // Initialize SDL_mixer for audio(freq,format,no.of audio channels,chunksize of the audio)
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        // Handle initialization failure as needed
    }
    //Create main window using SDL_CreateWindow(title,x of window,y of window,width,height,flag that controls window's initial state)
    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        // Handle window creation failure as needed
    }
    //Create renderer using SDL_CreateRenderer(window object,index of rendering driver which is -1 so that SDL can choose the best driver,flag that controls the render's creation)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        // Handle renderer creation failure as needed
    }

    // Load music
    music= Mix_LoadMUS("C:\\Users\\hp\\Downloads\\oop project assets\\audio2.mp3");
    if (!music) {
        std::cout << "Unable to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    // Play music only if it's not already playing
    playMusic();
}

//destructor
ScreenManager::~ScreenManager() {
    // Free music
    if (music) {
        Mix_FreeMusic(music);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
}

void ScreenManager::playMusic() {
    if (music) {
        // Play music only if it's not already playing
        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic(music, -1);
        }
    }
}

void ScreenManager::run() {
    //loop runs until current screen is exit screen
    while (currentScreen != ScreenType::EXIT) {
        switch (currentScreen) {
        case ScreenType::WELCOME: {
            WelcomeScreen welcomeScreen;//object of welcome screen class
            welcomeScreen.show(renderer, currentScreen);
            break;
        }
        case ScreenType::PLAYER_SELECTION: {
            PlayerSelectionScreen playerSelectionScreen;//object of playerselectionscreen class
            playerSelectionScreen.show(renderer, currentScreen);
            break;
        }
        case ScreenType::RULES: {
            RulesScreen rulesScreen;//object of rulesscreen class
            rulesScreen.show(renderer, currentScreen);
            break;
        }
        // Add more cases for other screens as needed
        default:
            // Handle unknown screen type
            break;
        }
    }
}


WelcomeScreen::~WelcomeScreen() {
    // Add any cleanup code if needed
}


// PlayerSelectionScreen destructor
PlayerSelectionScreen::~PlayerSelectionScreen() {
    // Add any cleanup code if needed
}

// RulesScreen destructor
RulesScreen::~RulesScreen() {
    // Add any cleanup code if needed
}
