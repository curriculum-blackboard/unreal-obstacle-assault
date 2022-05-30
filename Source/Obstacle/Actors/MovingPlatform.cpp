/*
** Copyright (c) 2022 Pratik Ghodasara.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*/

#include "Actors/MovingPlatform.h"


#pragma region Unreal
AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
}

void AMovingPlatform::Tick(float inDeltaTime)
{
    Super::Tick(inDeltaTime);

    FVector LocalVector = MyVector;

    LocalVector.Z += 100;

    MyVector.Y += 1;

    this->SetActorLocation(LocalVector);

    // Move platform forwards
        // Get current location
        // Add vector to that location
        // Set the location
    // Send platform back once it reaches the destination
        // Check distance the platform has moved
        // Check if the platform has moved far enough
        // Reverse the direction of movement
}
#pragma endregion
