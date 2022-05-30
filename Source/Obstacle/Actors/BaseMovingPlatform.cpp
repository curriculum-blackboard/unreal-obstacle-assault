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

#include "Actors/BaseMovingPlatform.h"


#pragma region Unreal
ABaseMovingPlatform::ABaseMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABaseMovingPlatform::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = this->GetActorLocation();

#if WITH_EDITOR
    UE_LOG(LogTemp, Display, TEXT("%s: Begin Play"), *this->GetActorLabel());
#endif
}

void ABaseMovingPlatform::Tick(float inDeltaTime)
{
    Super::Tick(inDeltaTime);

    // Move platform forwards
    FVector CurrentLocation = this->GetActorLocation();
    CurrentLocation += PlatformVelocity * inDeltaTime;
    this->SetActorLocation(CurrentLocation);
    // Send platform back once it reaches the destination
    DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
    if (DistanceMoved > MaximumMoveDistance)
    {
        float OvershootDistance = DistanceMoved - MaximumMoveDistance;
#if WITH_EDITOR
        UE_LOG(LogTemp, Display, TEXT("%s overshot by: %f"), *this->GetActorLabel(), OvershootDistance);
#endif
        FVector MoveDirection = PlatformVelocity.GetSafeNormal();
        StartLocation += (MoveDirection * MaximumMoveDistance);
        this->SetActorLocation(StartLocation);
        PlatformVelocity = -PlatformVelocity;
    }
}
#pragma endregion
