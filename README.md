# Simon
Simon is a 2D side-scrolling platformer game made using SDL and C++

In its current state, it does not function as a game, but rather a solid framework to build a game on.

In order to run this code on visual studio, you will need to download the SDL and SDL Image development libraries and properly install them for your project. I recommend following the instructions on this page: 
https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php 

and then this page:
https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/windows/msvc2019/index.php

You will also need to make sure that the assets in the folder Simon each have the right filepath in Game.cpp for whatever location you choose to store the file. I recommend keeping them all in the same location as the source and header files.

After following these steps, the project should run with no issues.

NOTE: The files contained in the TinyXML folder were not written by me but are necessary for parsing the xml file for the game.

Upon running the game, you will see two animated images. The little blue man can be controlled by you (the user), while the chicken is the enemy and runs across the screen. If the user collides with the chicken, the game is over.
