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

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "BaseMovingPlatform.generated.h"


UCLASS()
class OBSTACLE_API ABaseMovingPlatform : public AActor
{
    GENERATED_BODY()

#pragma region Unreal
public:
    ABaseMovingPlatform();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float inDeltaTime) override;
#pragma endregion

#pragma region Moving Platform
private:
    UPROPERTY(EditAnywhere, Category = "Moving Platform")
    FVector MoveVelocity = FVector(100.f, 0.0f, 0.0f);

    UPROPERTY(EditAnywhere, Category = "Moving Platform")
    float MaximumMoveDistance = 500.0f;

    FVector StartLocation;

private:
    void MovePlatform(float inDeltaTime);
    bool ShouldPlatformReturn();
    float GetDistanceMoved();

    void RotatePlatform(float inDeltaTime);
#pragma endregion
};
