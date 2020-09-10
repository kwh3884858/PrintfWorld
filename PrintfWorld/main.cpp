//
//  main.cpp
//  PrintfWorld
//
//  Created by 威化饼干 on 11/9/2020.
//  Copyright © 2020 威化饼干. All rights reserved.
//

#include <iostream>
#include <time.h>


class vector3{

public:
    vector3():x(0),y(0),z(0)
    {}

    vector3(float aX, float aY ,float aZ):x(aX),y(aY),z(aZ)
    {}

    vector3(const vector3& vector){
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }

    vector3& operator=(vector3& vector)
    {
        if (this != &vector) {
              x = vector.x;
              y = vector.y;
              z = vector.z;
        }
        return *this;
    }

private:
    float x;
    float y;
    float z;
};

/*

   | Y
   |
   |_______
  /       Z
 /
/  X

 */


void SwapFrame(int windowHeight , int windowWidht){
    for (int i = 0; i < windowHeight; i++) {
        for (int j = 0; j < windowWidht; j++) {
            //todo
        }
    }
}


void ClearFrame(char*const frame,int height, int width, char emptyPrimitive = ' '){
    memset(frame, emptyPrimitive, height * width);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
    int windowHeight = 5;
    int windowWidht = 5;

    char primitiveStar = '*';
    char primitiveCrossbar = '-';
    char primitiveStick = '|';

    vector3 cameraPos(0, 0, 1);
    vector3 boxPos(0, 0, 0);

    vector3 boxData[4];
    boxData[0] = vector3{1.0f, 0.0f, 0.0f};
    boxData[1] = vector3{-1.0f, 0.0f, 0.0f};
    boxData[2] = vector3{1.0f, 2.0f, 0.0f};
    boxData[3] = vector3{-1.0f, 2.0f, 0.0f};

    char* currentCache = nullptr;
    char frameCache[2][windowHeight * windowWidht];
    bool isUseFirstFrameCache = true;

    ClearFrame(frameCache[0], windowHeight, windowWidht);
    currentCache = frameCache[0];

    while (true) {

        char input;
        input = getchar();

        if (input == 0x1B) {
            break;
        }

        //Clear frame
        if (isUseFirstFrameCache) {
            ClearFrame(frameCache[1], windowHeight, windowWidht);
        }else{
            ClearFrame(frameCache[0], windowHeight, windowWidht);
        }

        SwapFrame(windowHeight, windowWidht);
        isUseFirstFrameCache =! isUseFirstFrameCache;
    }


}

