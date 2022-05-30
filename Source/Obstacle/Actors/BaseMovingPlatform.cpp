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

    this->MovePlatform(inDeltaTime);

    this->RotatePlatform(inDeltaTime);
}
#pragma endregion

#pragma region Moving Platform
void ABaseMovingPlatform::MovePlatform(float inDeltaTime)
{
    if (this->ShouldPlatformReturn())
    {
        FVector MoveDirection = MoveVelocity.GetSafeNormal();
        StartLocation += (MoveDirection * MaximumMoveDistance);
        this->SetActorLocation(StartLocation);
        MoveVelocity = -MoveVelocity;
    }
    else
    {
        FVector CurrentLocation = this->GetActorLocation();
        CurrentLocation += MoveVelocity * inDeltaTime;
        this->SetActorLocation(CurrentLocation);
    }
}

bool ABaseMovingPlatform::ShouldPlatformReturn()
{
    return this->GetDistanceMoved() > MaximumMoveDistance;
}

float ABaseMovingPlatform::GetDistanceMoved()
{
    return FVector::Distance(StartLocation, this->GetActorLocation());
}

void ABaseMovingPlatform::RotatePlatform(float inDeltaTime)
{
#if WITH_EDITOR
        UE_LOG(LogTemp, Display, TEXT("%s is rotating"), *this->GetActorLabel());
#endif
}
#pragma endregion
