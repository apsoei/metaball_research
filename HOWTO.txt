F21 research on marching cubes and intersections.

Written on 12/10/2021 by Jae seok Oh (jaeseoko)

main.cpp is the most recent file.

Executable can be compiled thru CMake.

Resulting executable needs at least one argument from the data folder.

For example, to run marching cube on a box model:
within the build folder,
    ./main.app/Contents/MacOS/main ../data/metaInputs/box.txt
To add input edges to recover boundaries,
    ./main.app/Contents/MacOS/main ../data/metaInputs/box.txt ../data/metaInputs/box_edges.txt
Other shapes:
    ./main.app/Contents/MacOS/main ../data/metaInputs/metaball.txt