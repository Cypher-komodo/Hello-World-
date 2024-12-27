clear 
#Build File 
#!/bin/bash
set -xe
#gcc -o GTK main.c -Wall -Wextra -lm  `pkg-config --cflags --libs gtk+-3.0`
#gcc $( pkg-config --cflags gtk+-3.0 ) -o example-1 main.c $( pkg-config --libs gtk+-3.0 )
#gcc -o myapp1 main.c `pkg-config --cflags --libs gtk+-3.0`

#gcc -o SDL sdlmain.c -Wall -Wextra -lm  `sdl2-config --cflags --libs`
#gcc sdlmain.c -o SDL `sdl2-config --cflags --libs`

gcc -o editor Edutor.c `pkg-config --cflags --libs gtk+-3.0`
