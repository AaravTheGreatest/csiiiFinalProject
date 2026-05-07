# csiiiFinalProject  
Final project for my CS III class (making a repo because I switch between computers)  
  
## Dependencies:  
SFML 3.0.0  
C++  
homebrew (on mac)  
  
## Build:  
Clone repo  
cd csiiiFinalProject  
### Linux:  
g++ -o main main.cpp $(pkg-config --cflags --libs sfml-all) -Iinclude  
./main  
### Mac:  
brew install pkg-config  
clang++ -o main main.cpp $(pkg-config --cflags --libs sfml-all) -Iinclude  
./main  


## Current features:  
Tilemap with a combination of 121x127 tiles that are 32x32 pixels, some for grass and some for path blocks  
Player movement with WASD/Arrow keys, sprint increases speed  
Bounds player to window  
  
## Working on:  
Enemy logic  
Fighting logic  
Scrolling map  
More art  

## Plans:
Physics simulation + user input for physics to fight  
New regions  
Animations  
HUD with quest menu and other settings  
